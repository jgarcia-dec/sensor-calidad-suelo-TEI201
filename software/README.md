# Software - Documentación

## Contenido

Esta carpeta contiene la documentación técnica del software utilizado en el proyecto **Monitor Verde**, sistema IoT para medir humedad volumétrica y temperatura del suelo mediante un ESP32.

### 📁 Carpetas

#### `src/`
Contiene el código fuente del ESP32 en formato `.ino`.

#### `librerias/`
Contiene información sobre las librerías utilizadas en el proyecto. No se incluyen librerías externas manuales, ya que fueron instaladas desde Arduino Cloud/Arduino IDE.

#### `docs/`
Contiene la documentación técnica del software, incluyendo arquitectura, configuración, endpoints y funcionamiento general.

---
  
  ## Stack Tecnológico
  
**Plataforma:** ESP32  
**Lenguaje:** C/C++  
**Entorno de desarrollo:** Arduino Cloud / Arduino IDE  
**Servidor:** Node.js + Express  
**Despliegue:** Railway  
**Formato de datos:** JSON  
**Librerías principales:**
  
- OneWire.h - Versión 2.3.8
- DallasTemperature.h - Versión 4.0.6
- WiFi.h - Incluida en ESP32 Core
- HTTPClient.h - Incluida en ESP32 Core
- WiFiClientSecure.h - Incluida en ESP32 Core

---
  
## Instalación y Configuración
  
### 1. Instalar Arduino IDE o usar Arduino Cloud
  
  El código puede cargarse desde Arduino Cloud o Arduino IDE, configurando previamente la placa ESP32.

### 2. Configurar ESP32

Seleccionar la placa ESP32 correspondiente y conectar el dispositivo mediante cable USB.

### 3. Instalar librerías

Instalar desde el gestor de librerías:
  
  - OneWire
- DallasTemperature

### 4. Cargar código

1. Abrir el archivo `src/main.ino`.
2. Configurar las credenciales WiFi.
3. Verificar la URL del servidor.
4. Compilar y subir el código al ESP32.

---
  
## Configuración de Parámetros
  
  Editar las siguientes constantes en el código:
  
  ```cpp
// WiFi
const char* WIFI_SSID = "nombre_red";
const char* WIFI_PASSWORD = "contraseña_red";

// Servidor
const char* SERVER_URL = "https://monitor-suelo-production.up.railway.app/datos";

// Pines
#define PIN_TEMP 5
#define SENSOR_PIN 2

// Calibración humedad
const int VALOR_SECO = 3200;
const int VALOR_AGUA = 1842;

// Tiempo de muestreo
const unsigned long INTERVALO_MS = 5000;

---
## Arquitectura del Software
  
  [Sensores SEN0193 y DS18B20
   ↓
   ESP32
   ↓
   Lectura y procesamiento de datos
   ↓
   Envío HTTP POST en formato JSON
   ↓
   Servidor Node.js / Express en Railway
   ↓
   Plataforma web]

### Módulos Principales
1. **Inicialización**: configura sensores, comunicación serial y conexión WiFi.
2. **Lectura de Sensores**: obtiene temperatura y humedad del suelo.
3. **Procesamiento**: convierte la lectura ADC a porcentaje de humedad volumétrica.
4. **Actuación**: interpreta el estado del suelo según el porcentaje de humedad.
5. **Comunicación**: envía los datos al servidor mediante HTTP POST.

---
  ## API / Endpoints
  
  | Endpoint     | Método | Descripción                                         |
  |--------------|--------|-----------------------------------------------------|
  | `/datos`     | POST   | Recibe datos enviados por el ESP32.                 |
  | `/api/datos` | GET    | Entrega el último dato recibido a la plataforma web.|
  | `/`          | GET    | Sirve la página web principal.                      |
  