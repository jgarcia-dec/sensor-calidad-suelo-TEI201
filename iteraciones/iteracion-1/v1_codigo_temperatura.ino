#include <OneWire.h>
#include <DallasTemperature.h>

// Pin de datos del DS18B20
#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();
  Serial.println("Sensor DS18B20 iniciado");
}

void loop() {
  sensors.requestTemperatures();
  float temperatura = sensors.getTempCByIndex(0);

  if (temperatura == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: sensor no detectado");
  } else {
    Serial.print("Temperatura del suelo: ");
    Serial.print(temperatura, 2);
    Serial.println(" °C");
  }

  delay(2000);
}