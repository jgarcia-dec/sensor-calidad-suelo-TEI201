# Documentación de Software

## Contenido

Esta carpeta contiene la documentación técnica del software desarrollado para el sistema de monitoreo de humedad y temperatura del suelo.

---
  
# Diagramas de Flujo
  
  Se incluye en la misma carpeta

---
  
# Documentación de Funciones
  
## calcularVWC()
  
  **Propósito:**
  
  Convierte la lectura analógica del sensor SEN0193 en porcentaje de humedad volumétrica (VWC) utilizando los valores de calibración obtenidos experimentalmente.

**Parámetros**
  
  - `int lecturaADC`: lectura analógica obtenida desde el sensor.

**Retorna**
  
  - `float`: porcentaje de humedad volumétrica (VWC).

**Ejemplo**
  
  ```cpp
float humedad = calcularVWC(lecturaADC);
```

---
  
## interpretarVWC()
  
**Propósito**
  
  Clasifica el estado del suelo según el porcentaje de humedad obtenido.

**Parámetros**
  
  - `float vwc`: porcentaje de humedad volumétrica.

**Retorna**
  
  - `String`: estado del suelo.

**Ejemplo**
  
  ```cpp
String estado = interpretarVWC(g_vwc);
```

---
  
## leerSensores()
  
**Propósito**
  
Obtiene las mediciones de temperatura y humedad del suelo.

**Parámetros**
  
No recibe parámetros.

**Retorna**
  
No retorna valores. Actualiza las variables globales del sistema.

---
  
## enviarDatos()
  
**Propósito**
  
Envía las mediciones al servidor mediante una solicitud HTTP POST utilizando formato JSON.

**Parámetros**
  
No recibe parámetros.

**Retorna**
  
No retorna valores.

---
  
## setup()
  
**Propósito**
  
Inicializa la comunicación serial, sensores, conexión WiFi y configuración del sistema.

---
  
## loop()
  
**Propósito**
  
Ejecuta continuamente la lectura de sensores y el envío periódico de datos al servidor.

---
  
# Manual de Instalación
  
## Requisitos
  
- Arduino IDE o Arduino Cloud.
- ESP32 configurado en el gestor de placas.
- Librerías:
- OneWire 2.3.8
- DallasTemperature 4.0.6

## Instalación

1. Instalar Arduino IDE o acceder a Arduino Cloud.
2. Instalar las librerías necesarias.
3. Abrir el archivo `main.ino`.
4. Configurar las credenciales WiFi.
5. Verificar la dirección del servidor (`SERVER_URL`).
6. Seleccionar la placa ESP32.
7. Compilar y cargar el firmware.

---
  
# Manual de Operación
  
## Encendido del sistema
  
1. Conectar el ESP32 mediante alimentación USB o Power Bank.
2. Esperar el inicio del sistema.
3. Verificar en el Monitor Serial que la conexión WiFi sea exitosa.

---
  
## Operación normal
  
1. El sistema realiza una lectura de humedad y temperatura.
2. Convierte la humedad a porcentaje VWC.
3. Clasifica el estado del suelo.
4. Envía los datos al servidor cada 5 segundos.
5. La plataforma web actualiza la información aproximadamente cada 30 segundos.

---
  
## Apagado del sistema
  
1. Finalizar la ejecución del programa.
2. Desconectar la alimentación del ESP32.

---
  
# Troubleshooting
  
## Problemas comunes
  
### El ESP32 no conecta a WiFi
  
**Causa probable**
  
- SSID o contraseña incorrectos.
- Red WiFi fuera de alcance.

**Solución**
  
- Verificar las credenciales WiFi.
- Confirmar que exista cobertura inalámbrica.

---
  
### El sensor de temperatura no responde
  
**Causa probable**
  
- Error en la conexión OneWire.
- Resistencia pull-up ausente o incorrecta.

**Solución**
  
- Verificar el cableado.
- Confirmar la resistencia de 4,7 kΩ.

---
  
### El sensor de humedad entrega valores incorrectos
  
**Causa probable**
  
- Sensor mal calibrado.
- Conexión deficiente.

**Solución**
  
- Repetir el procedimiento de calibración.
- Revisar las conexiones del sensor.

---
  
### No se envían datos al servidor
  
**Causa probable**
  
- Servidor fuera de servicio.
- Error en la URL configurada.

**Solución**
  
- Verificar la dirección `SERVER_URL`.
- Comprobar que el servidor en Railway esté activo.
- Revisar la conexión a Internet.