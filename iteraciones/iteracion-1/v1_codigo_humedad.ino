#include <Arduino.h>

// Pin ADC del sensor capacitivo
#define SENSOR_PIN 34

// Valores crudos del ADC calibrados para el sensor v1.2
// Medir en aire seco y en agua para calibrar los tuyos
const int VALOR_SECO  = 3200;  // sensor al aire (0% VWC aprox)
const int VALOR_AGUA  = 1200;  // sensor sumergido en agua (saturación)

// Rango de humedad volumétrica (VWC) para suelos agrícolas típicos
const float VWC_MIN = 0.0;    // 0%  → suelo completamente seco
const float VWC_MAX = 60.0;   // 60% → saturación (varía según tipo de suelo)

float calcularVWC(int lecturaADC) {
  // Mapeo lineal de ADC a VWC (%)
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

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);          // ADC de 12 bits en ESP32 (0–4095)
  analogSetAttenuation(ADC_11db);    // Rango completo: 0–3.3V
  Serial.println("Sensor capacitivo de humedad iniciado");
  Serial.println("Unidad: VWC (Humedad Volumétrica del Suelo, %)");
  Serial.println("------------------------------------------------");
}

void loop() {
  // Promedio de 10 lecturas para reducir ruido
  long suma = 0;
  for (int i = 0; i < 10; i++) {
    suma += analogRead(SENSOR_PIN);
    delay(10);
  }
  int lecturaADC = suma / 10;

  float vwc = calcularVWC(lecturaADC);
  String estado = interpretarVWC(vwc);

  Serial.print("ADC raw:  ");
  Serial.println(lecturaADC);
  Serial.print("VWC:      ");
  Serial.print(vwc, 1);
  Serial.println(" %");
  Serial.print("Estado:   ");
  Serial.println(estado);
  Serial.println("------------------------------------------------");

  delay(2000);
}