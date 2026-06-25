
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// ── Pines ────────────────────────────────────────────────────────────────────
#define PIN_TEMP     2   // DS18B20  → GPIO 2  (OneWire)
#define SENSOR_PIN   4   // SEN0193  → GPIO 4  (ADC)

// ── Sensor de temperatura DS18B20 ────────────────────────────────────────────
OneWire ourWire(PIN_TEMP);
DallasTemperature sensors(&ourWire);

// ── Calibración sensor de humedad SEN0193 ────────────────────────────────────
// Mide el ADC raw con el sensor al aire (seco) y sumergido en agua, y ajusta:
const int VALOR_SECO = 3200;   // ADC al aire  → 0 % VWC
const int VALOR_AGUA = 1200;   // ADC en agua  → saturación

const float VWC_MIN = 0.0;     //  0 % → suelo completamente seco
const float VWC_MAX = 60.0;    // 60 % → saturación (varía según tipo de suelo)

// ── Funciones auxiliares ──────────────────────────────────────────────────────
float calcularVWC(int lecturaADC) {
  float vwc = map(lecturaADC, VALOR_SECO, VALOR_AGUA,
                  (int)(VWC_MIN * 100), (int)(VWC_MAX * 100));
  vwc /= 100.0;
  return constrain(vwc, VWC_MIN, VWC_MAX);
}

String interpretarVWC(float vwc) {
  if (vwc < 10.0) return "Suelo seco — riego necesario";
  if (vwc < 20.0) return "Humedad baja";
  if (vwc < 35.0) return "Humedad optima para cultivos";
  if (vwc < 50.0) return "Humedad alta";
  return "Suelo saturado";
}

// ── Setup ─────────────────────────────────────────────────────────────────────
void setup() {
  delay(1000);
  Serial.begin(9600);

  // DS18B20
  sensors.begin();

  // ADC ESP32-S3
  analogReadResolution(12);       // 12 bits → 0-4095
  analogSetAttenuation(ADC_11db); // Rango 0-3.3 V

  Serial.println("================================================");
  Serial.println("  Monitor de suelo — Temperatura + Humedad VWC");
  Serial.println("  Sensor temp : DS18B20  (GPIO 2)");
  Serial.println("  Sensor hum  : SEN0193  (GPIO 4)");
  Serial.println("================================================");
}

// ── Loop ──────────────────────────────────────────────────────────────────────
void loop() {

  // — Temperatura ——————————————————————————————
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);

  // — Humedad (promedio 10 lecturas para reducir ruido) ————————————————————
  long suma = 0;
  for (int i = 0; i < 10; i++) {
    suma += analogRead(SENSOR_PIN);
    delay(10);
  }
  int lecturaADC = suma / 10;
  float vwc      = calcularVWC(lecturaADC);
  String estado  = interpretarVWC(vwc);

  // — Salida Serial —————————————————————————————
  Serial.println("------------------------------------------------");
  Serial.print("Temperatura:  ");
  Serial.print(temp, 1);
  Serial.println(" °C");

  Serial.print("Humedad VWC:  ");
  Serial.print(vwc, 1);
  Serial.println(" %");
  Serial.print("Estado:       ");
  Serial.println(estado);
  Serial.println("------------------------------------------------");

  delay(2000); // Lectura cada 2 segundos
}
