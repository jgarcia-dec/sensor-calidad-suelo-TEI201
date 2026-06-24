# Esquemas de Circuito

## Archivos Incluidos

### Diagrama del Circuito
- `esquema_circuito_v3.png` - Esquema de conexiones del sistema.
- `wokwi_link.txt` - contiene el enlace público al proyecto utilizado durante el desarrollo

---

## Descripción del Circuito

El sistema utiliza un microcontrolador ESP32-S3 como unidad principal de procesamiento. El ESP32 adquiere las mediciones del sensor capacitivo de humedad SEN0193 y del sensor de temperatura DS18B20. Posteriormente, los datos son procesados y enviados mediante conexión WiFi a un servidor para su almacenamiento y visualización.

---

## Conexiones Principales

| Componente | Conexión |
|------------|----------|
| ESP32-S3 DevKitC-1 | Microcontrolador principal |
| Sensor SEN0193 | GPIO 2 (Entrada analógica) |
| Sensor DS18B20 | GPIO 5 (OneWire) |
| Resistencia 4.7 kΩ | Pull-up entre DATA y 3.3 V del DS18B20 |
| Alimentación | 3.3 V |
| Tierra | GND común |

---

## Notas de Diseño

- El sensor DS18B20 utiliza el protocolo OneWire y requiere una resistencia pull-up de 4.7 kΩ entre la línea de datos y la alimentación.
- El sensor SEN0193 entrega una señal analógica que es leída por el convertidor ADC del ESP32.
- Todos los componentes comparten una referencia común de tierra (GND).
- El circuito fue validado mediante simulación en Wokwi antes de su implementación física en el prototipo.

---

## Software Utilizado

- Wokwi (simulación y validación del circuito).
- Arduino IDE 2.x (desarrollo y carga del firmware).
