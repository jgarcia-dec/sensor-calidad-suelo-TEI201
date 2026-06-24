# Librerías

## Librerías Estándar (Arduino IDE)

Las siguientes librerías fueron utilizadas para el desarrollo del firmware del proyecto y deben instalarse desde el **Library Manager** de Arduino IDE o Arduino Cloud.

### 1. OneWire - v2.3.8

- **Propósito:** Permite la comunicación mediante el protocolo OneWire con el sensor de temperatura DS18B20.
- **Instalación:** Sketch → Include Library → Manage Libraries → Buscar **"OneWire"**.

### 2. DallasTemperature - v4.0.6

- **Propósito:** Facilita la lectura de temperatura desde el sensor DS18B20 utilizando la librería OneWire.
- **Instalación:** Sketch → Include Library → Manage Libraries → Buscar **"DallasTemperature"**.

### 3. WiFi

- **Versión:** Incluida en ESP32 Core.
- **Propósito:** Permite conectar el ESP32 a una red WiFi.

### 4. HTTPClient

- **Versión:** Incluida en ESP32 Core.
- **Propósito:** Permite enviar solicitudes HTTP al servidor.

### 5. WiFiClientSecure

- **Versión:** Incluida en ESP32 Core.
- **Propósito:** Permite realizar comunicaciones HTTPS de forma segura.

---
  
  ## Librerías Personalizadas/Modificadas
  
  Este proyecto **no utiliza librerías personalizadas ni modificadas**. Todas las dependencias fueron instaladas mediante el gestor de librerías de Arduino IDE o están incluidas en el paquete ESP32 Core.

---
  
  ## Dependencias Completas
  
  | Librería          | Versión                 | Fuente                  | Obligatoria |
  |-------------------|:-----------------------:|-------------------------|:--:|
  | OneWire           | 2.3.8                   | Arduino Library Manager | ✅ |
  | DallasTemperature | 4.0.6                   | Arduino Library Manager | ✅ |
  | WiFi              | Incluida en ESP32 Core  | ESP32 Core              | ✅ |
  | HTTPClient        | Incluida en ESP32 Core  | ESP32 Core              | ✅ |
  | WiFiClientSecure  | Incluida en ESP32 Core  | ESP32 Core              | ✅ |
  | Arduino           | Incluida en Arduino IDE | Arduino Core            | ✅ |