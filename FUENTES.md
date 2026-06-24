# Fuentes del Proyecto

## Librerías utilizadas

| Librería            | Versión                 | Fuente                     |
|---------------------|-------------------------|----------------------------|
| Arduino.h           | Incluida en Arduino IDE | Arduino Core               |
| OneWire.h           | 2.3.8                   | Librería OneWire           |
| DallasTemperature.h | 4.0.6                   | Librería DallasTemperature |
| WiFi.h              | Incluida en ESP32 Core  | Arduino ESP32 Core         |
| HTTPClient.h        | Incluida en ESP32 Core  | Arduino ESP32 Core         |
| WiFiClientSecure.h  | Incluida en ESP32 Core  | Arduino ESP32 Core         |

## Código externo adaptado

No se utilizó código externo copiado directamente. El firmware fue desarrollado específicamente para este proyecto utilizando Arduino Cloud AI.

## Uso de Inteligencia Artificial

Durante el desarrollo del proyecto se utilizó Arduino Cloud AI como herramienta de apoyo para acelerar la implementación del firmware del ESP32. La inteligencia artificial se empleó como asistente para generar propuestas de código, resolver dudas de programación y optimizar la estructura del software, sin reemplazar el proceso de desarrollo realizado por el equipo.

### Desarrollo del firmware

- Herramienta: Arduino Cloud AI.
- Uso: apoyo en la generación de funciones para la lectura de los sensores SEN0193 y DS18B20, configuración de la conexión WiFi del ESP32, implementación de la comunicación HTTP con el servidor y organización modular del código.
- Adaptación: todas las propuestas generadas fueron revisadas, probadas y modificadas por el equipo para adecuarlas a los requerimientos del proyecto, incorporando la calibración del sensor de humedad, el intervalo de muestreo, el formato JSON para el envío de datos y la integración con el servidor desplegado en Railway.
- Validación: el funcionamiento del firmware fue comprobado mediante pruebas experimentales de lectura, transmisión y almacenamiento de datos, verificando que el sistema operara correctamente antes de su integración con la plataforma web.
- Comprensión: todos los integrantes revisaron el código final, comprendieron la función de sus principales módulos y son capaces de explicar su funcionamiento durante la presentación del proyecto.
