// ── LIBRERIAS UTILIZADAS ────────────────────────────────────────────────────
// Arduino.h           : Funciones básicas del Arduino.
// OneWire.h           : Comunicación con dispositivos OneWire.
// DallasTemperature.h : Lectura del sensor de temperatura DS18B20.
// WiFi.h              : Conexión del ESP32 a una red WiFi.
// HTTPClient.h        : Envío de solicitudes HTTP al servidor.
// WiFiClientSecure.h  : Comunicación segura mediante HTTPS.
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <HTTPClient.h>   // cambia WebServer por HTTPClient
#include <WiFiClientSecure.h>

// ── CONFIGURACIÓN DE RED WiFi ────────────────────────────────────────────────────
// Credenciales utilizadas para conectar el ESP32 a internet.
const char* WIFI_SSID     = "S24 FE de Sebastian";
const char* WIFI_PASSWORD = "i98208731";

// ── URL DE TU SERVIDOR EN RAILWAY ─────────────────────────────────────────
// URL donde el ESP32 enviará las mediciones en formato JSON.
const char* SERVER_URL = "https://monitor-suelo-production.up.railway.app/datos";

// ── CONFIGURACIÓN DE PINES ─────────────────────────────────────────────────────────────────
// PIN_TEMP : Sensor de temperatura DS18B20.
// SENSOR_PIN : Sensor capacitivo de humedad SEN0193.
#define PIN_TEMP    5   // DS18B20  → GPIO 5
#define SENSOR_PIN  2   // SEN0193  → GPIO 2 (ADC)

// ── INICIALIZACIÓN DEL SENSOR DE TEMPERATURA DS18B20 ─────────────────────────────────────────
OneWire ourWire(PIN_TEMP);
DallasTemperature sensors(&ourWire);

// ── PARÁMETROS DE CALIBRACIÓN DEL SENSOR DE HUMEDAD SEN0193 ─────────────────────────────────
// Los valores fueron obtenidos experimentalmente para convertir la
// lectura ADC en porcentaje de humedad volumétrica (VWC).
const int   VALOR_SECO = 3200;
const int   VALOR_AGUA = 1842;
const float VWC_MIN    = 0.0;
const float VWC_MAX    = 100.0;

// ── VARIABLES GLOBALES ────────────────────────────────────────────────────
// Almacenan la última medición obtenida por los sensores.
float   g_temp   = 0.0;
float   g_vwc    = 0.0;
int     g_adc    = 0;
String  g_estado = "";

// ── CONFIGURACIÓN DEL TIEMPO DE MUESTREO ─────────────────────────────────────
// El sistema realiza una nueva medición y la envía al servidor cada
// INTERVALO_MS milisegundos
const unsigned long INTERVALO_MS = 5000;
unsigned long ultimoEnvio = 0;

// ── FUNCIÓN: calcularVWC() ──────────────────────────────────────────────────
// Convierte la lectura analógica del sensor SEN0193 en porcentaje de
// humedad volumétrica (VWC), utilizando los valores de calibración.
float calcularVWC(int lecturaADC) {
  float vwc = map(lecturaADC, VALOR_SECO, VALOR_AGUA,
                  (int)(VWC_MIN * 100), (int)(VWC_MAX * 100));
  vwc /= 100.0;
  return constrain(vwc, VWC_MIN, VWC_MAX);
}

// ── FUNCIÓN: interpretarVWC() ──────────────────────────────────────────────────
// Clasifica el nivel de humedad del suelo según el porcentaje obtenido.
String interpretarVWC(float vwc) {
  if (vwc < 10.0) return "Suelo seco";
  if (vwc < 20.0) return "Humedad baja";
  if (vwc < 35.0) return "Humedad optima";
  if (vwc < 50.0) return "Humedad alta";
  return "Suelo saturado";
}

// ── FUNCIÓN: leerSensores() ──────────────────────────────────────────────────
// Lee la temperatura del DS18B20 y la humedad del suelo.
// Para disminuir el ruido eléctrico se promedian 10 lecturas ADC.
void leerSensores() {

  // Solicita la temperatura al sensor DS18B20.
  sensors.requestTemperatures();
  g_temp = sensors.getTempCByIndex(0);

  // Promedio de 10 lecturas del sensor de humedad.
  long suma = 0;
  for (int i = 0; i < 10; i++) {
    suma += analogRead(SENSOR_PIN);
    delay(10);
  }

  // Conversión de la lectura promedio a porcentaje VWC.
  g_adc    = suma / 10;
  g_vwc    = calcularVWC(g_adc);

  // Obtiene una interpretación del estado del suelo.
  g_estado = interpretarVWC(g_vwc);
}

// ── FUNCIÓN: enviarDatos() ──────────────────────────────────────────────
// Envía las mediciones al servidor mediante una solicitud HTTP POST
// utilizando un mensaje en formato JSON.
void enviarDatos() {

  // Verifica que exista conexión WIFI.
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("[!] Sin WiFi, no se puede enviar");
    return;
  }

  WiFiClientSecure client;

  // Se omite la validación del certificado HTTPS.
  client.setInsecure();

  HTTPClient http;
  http.begin("https://monitor-suelo-production.up.railway.app/datos");
  http.addHeader("Content-Type", "application/json");

  // Construcción del mensaje JSON.
  String json = "{";
  json += "\"temperatura\":" + String(g_temp, 2) + ",";
  json += "\"vwc\":"         + String(g_vwc,  2) + ",";
  json += "\"adc\":"         + String(g_adc)      + ",";
  json += "\"estado\":\""    + g_estado           + "\"";
  json += "}";

  // Envío de la solicitud HTTP.
  int httpCode = http.POST(json);

  // Verificación de la respuesta del servidor.
  if (httpCode == 200) {
    Serial.println("[OK] Datos enviados al servidor");
  } else {
    Serial.printf("[!] Error al enviar. Código HTTP: %d\n", httpCode);
  }

  // Finaliza la conexión HTTP.
  http.end();
}

// ── SETUP() ─────────────────────────────────────────────────────────────────
// Inicializa sensores, comunicación serial y conexión WIFI.
void setup() {
  delay(1000);
  Serial.begin(115200);

  sensors.begin();
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);

  Serial.println("\n================================================");
  Serial.println("  Monitor de suelo — Modo Nube");
  Serial.println("================================================");

  Serial.print("Conectando a WiFi: ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Espera la conexión WIFI.
  int intentos = 0;
  while (WiFi.status() != WL_CONNECTED && intentos < 30) {
    delay(500);
    Serial.print(".");
    intentos++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n[OK] WiFi conectado");
    Serial.print("  IP local: ");
    Serial.println(WiFi.localIP());
    Serial.print("  Enviando datos a: ");
    Serial.println(SERVER_URL);
  } else {
    Serial.println("\n[!] No se pudo conectar al WiFi.");
  }
  Serial.println("================================================\n");
}

// ── LOOP ──────────────────────────────────────────────────────────────────
// Ejecuta periódicamente la lectura de sensores y el envío de datos.
void loop() {
  unsigned long ahora = millis();

  // Comprueba si ya transcurrió el intervalo de muestreo.
  if (ahora - ultimoEnvio >= INTERVALO_MS) {
    ultimoEnvio = ahora;
    
    // Adquisición de datos.
    leerSensores();

    // Muestra las mediciones por el monitor serial.
    Serial.printf("Temp: %.1f C  |  VWC: %.1f %%  |  ADC: %d  |  %s\n",
                  g_temp, g_vwc, g_adc, g_estado.c_str());

    // Envía la información al servidor.
    enviarDatos();
  }
}
