# Hardware - Documentación

## Contenido

Esta carpeta contiene toda la documentación técnica del hardware del proyecto.

### 📁 Carpetas

#### `esquemas/`

Diagramas de conexión eléctrica y esquemáticos del sistema.

#### `bom/`

Lista de materiales (Bill of Materials) con los componentes utilizados en el prototipo.

#### `fotos/`

Fotografías del prototipo ensamblado y de sus principales componentes.

---
  
# Instrucciones de Ensamble
  
## Componentes Principales
  
1. **ESP32-S3 DevKit** – Controlador principal encargado de la adquisición de datos, procesamiento y comunicación con el servidor.

2. **Sensor capacitivo de humedad SEN0193** – Mide la humedad volumétrica del suelo mediante una salida analógica.

3. **Sensor de temperatura DS18B20** – Registra la temperatura del suelo mediante comunicación OneWire.

4. **Batería recargable** – Proporciona la alimentación eléctrica del sistema.

5. **Resistencia de 4.7 kΩ** – Pull-up para la comunicación del sensor DS18B20.

6. **Encapsulado impreso en PLA** – Protege los componentes electrónicos frente a golpes y condiciones ambientales.

---
  
## Pasos de Ensamblaje
  
1. Instalar el sensor capacitivo SEN0193 y el sensor DS18B20 en sus respectivos alojamientos del encapsulado.

2. Fijar el ESP32-S3 y la batería en las posiciones diseñadas dentro del encapsulado.

3. Realizar las conexiones eléctricas entre los sensores y el ESP32 según el esquema del proyecto.

4. Instalar la resistencia pull-up de 4.7 kΩ entre la línea de datos del DS18B20 y la alimentación.

5. Verificar el funcionamiento eléctrico antes de cerrar el encapsulado.

6. Ensamblar la tapa superior y comprobar el correcto ajuste del dispositivo.

---
  
## Precauciones
  
- ⚠️ Verificar la polaridad de alimentación antes de energizar el sistema.

- ⚠️ Evitar esfuerzos mecánicos sobre el sensor capacitivo para prevenir daños durante el montaje.

- ⚠️ No aplicar tensión al circuito mientras se realizan modificaciones en el cableado.

- ⚠️ Comprobar que no existan cortocircuitos antes de conectar la batería.

---
  
# Especificaciones Técnicas
  
**Microcontrolador:** ESP32-S3 DevKit

**Sensor de humedad:** SEN0193 (Capacitive Soil Moisture Sensor)

**Sensor de temperatura:** DS18B20

**Alimentación:** ________ V

**Corriente de operación:** ________ mA

**Consumo aproximado:** ________ W

**Comunicación inalámbrica:** WiFi 2.4 GHz

**Dimensiones externas:** ________ mm × ________ mm × ________ mm

**Peso aproximado:** ________ g

**Material del encapsulado:** PLA

---
  
# Troubleshooting
  
  | Problema | Posible causa | Solución |
  |----------|---------------|----------|
  | El ESP32 no enciende | Batería descargada o alimentación incorrecta | Verificar voltaje de alimentación, conexiones y estado de la batería. |
  | El sensor de humedad entrega valores erróneos | Sensor mal conectado o requiere recalibración | Revisar conexiones y verificar los valores de calibración del código. |
  | El sensor DS18B20 no responde | Resistencia pull-up ausente o conexión incorrecta | Comprobar la resistencia de 4.7 kΩ y las conexiones del bus OneWire. |
  | No existe conexión WiFi | Credenciales incorrectas o red fuera de alcance | Revisar SSID, contraseña y cobertura de la red inalámbrica. |
  | No se envían datos al servidor | Sin acceso a Internet o URL incorrecta | Verificar la conexión WiFi y la dirección del servidor configurada en el firmware. |
  
  ---
  
# Archivos incluidos
  
Esta carpeta debe contener:
  
  ```
hardware/
  │
├── esquemas/
  │   ├── esquema_electrico.pdf
│   ├── conexiones.png
│   └── README.md
│
├── bom/
  │   ├── BOM.xlsx
│   ├── BOM.pdf
│   └── README.md
│
├── fotos/
  │   ├── prototipo_frontal.jpg
│   ├── prototipo_lateral.jpg
│   ├── interior.jpg
│   └── README.md
│
└── README.md
```