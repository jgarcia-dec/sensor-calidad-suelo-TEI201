# Código Fuente

## Archivo Principal

### `main.ino`

Archivo principal del firmware del sistema de monitoreo de humedad y temperatura del suelo.

El programa controla la adquisición de datos desde los sensores, procesa la información y la envía al servidor mediante conexión WiFi para su almacenamiento y visualización en la plataforma web.

### Estructura del programa

#### Setup()

Realiza la inicialización del sistema:
  
  - Inicializa la comunicación serial.
- Configura el sensor de temperatura DS18B20.
- Configura el conversor ADC del ESP32.
- Establece la conexión a la red WiFi.
- Verifica la disponibilidad del servidor.

#### Loop()

Ejecuta continuamente las tareas principales del sistema:
  
- Controla el intervalo de muestreo.
- Lee la temperatura del suelo.
- Lee la humedad del suelo.
- Convierte la lectura ADC a porcentaje de humedad (VWC).
- Clasifica el estado del suelo.
- Envía las mediciones al servidor mediante HTTP POST.
- Muestra la información en el Monitor Serial.

---
  
## Organización del código
  
El firmware está dividido en funciones para facilitar su comprensión y mantenimiento.

| Función | Descripción |
  |----------|-------------|
  | `calcularVWC()` | Convierte la lectura ADC en porcentaje de humedad volumétrica (VWC). |
  | `interpretarVWC()` | Clasifica el nivel de humedad del suelo. |
  | `leerSensores()` | Obtiene las mediciones de humedad y temperatura. |
  | `enviarDatos()` | Envía las mediciones al servidor mediante HTTP POST. |
  | `setup()` | Inicializa el sistema y establece la conexión WiFi. |
  | `loop()` | Ejecuta periódicamente la lectura y transmisión de datos. |
  
  ---
  
## Estándares de Código
  
### Comentarios
  
El código se encuentra documentado mediante comentarios en español, describiendo la función de cada bloque, las variables principales y el propósito de cada función para facilitar su comprensión y mantenimiento.

### Convenciones utilizadas

- **Variables globales:** prefijo `g_` (ejemplo: `g_temp`, `g_vwc`).
- **Constantes:** mayúsculas con guion bajo (`VALOR_SECO`, `INTERVALO_MS`).
- **Funciones:** camelCase (`leerSensores()`, `enviarDatos()`).

---
  
  ## Testing y Depuración
  
  ### Monitor Serial
  
  Se utiliza el Monitor Serial para verificar el funcionamiento del sistema durante el desarrollo.

**Baudrate:** `115200`

Los mensajes permiten verificar:
  
- Estado de la conexión WiFi.
- Dirección IP obtenida.
- Lecturas de humedad y temperatura.
- Estado del suelo.
- Confirmación del envío de datos.
- Códigos de error en caso de fallas de comunicación.

Ejemplo de salida:
  
  ```text
[OK] WiFi conectado
Temp: 24.8 C | VWC: 46.2 % | ADC: 1895 | Humedad alta
[OK] Datos enviados al servidor
```

---
  
## Comunicación
  
El firmware transmite la información mediante solicitudes **HTTP POST** hacia el servidor desplegado en Railway.

Formato de transmisión:
  
  ```json
{
  "temperatura": 24.8,
  "vwc": 46.2,
  "adc": 1895,
  "estado": "Humedad alta"
}
```