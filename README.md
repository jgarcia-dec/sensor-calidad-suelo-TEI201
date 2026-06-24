# Sensor IoT de Humedad y Temperatura del Suelo

Sistema IoT para el monitoreo en tiempo real de la humedad y temperatura del suelo en áreas verdes urbanas. El sistema permite visualizar el estado del suelo mediante una plataforma web y almacenar los datos para su posterior análisis y apoyo a la toma de decisiones.

## Equipo

| Integrante      | Rol                   | GitHub       |
|-----------------|-----------------------|--------------|
| Sebastián Bravo | Hardware              | @usuario     |
| Vicente Ramírez | Diseño 3D             | @usuario     |
| Javier García   | Software/Firmware     | @jgarcia-dec |
| Diego Jaque     | Integración y pruebas | @usuario     |

## Descripción del problema

La falta de información en tiempo real sobre las condiciones del suelo dificulta la gestión eficiente de las áreas verdes urbanas. Esto limita la detección oportuna de zonas con baja humedad y reduce la capacidad de planificar el riego y mantención de manera eficiente.

## Arquitectura del sistema

Sensor de humedad SEN0193 + Sensor de temperatura DS18B20 → ESP32 → Servidor Web (Node.js) → Base de datos JSON → Dashboard Web

## Instrucciones de uso

### Cargar el firmware
1. Abrir el proyecto en Arduino IDE.
2. Instalar las librerías indicadas en ´FUENTES.md´.
3. Configurar las credenciales de la red WiFi.
4. Conectar el ESP32 mediante USB.
5. Compilar y cargar el programa.

### Ejecutar el servidor
1. Instalar Node.js.
2. Abrir una terminal en la carpeta del servidor.
3. Ejecutar:

```bash
npm install
npm start
```

4. Acceder al dashboard desde el navegador mediante la dirección IP del servidor.

## Estructura del repositorio

- `diseno-3d/` — Modelos de Fusion 360, renders y planos técnicos.
- `docs/` — Informes y documentación del proyecto.
- `hardware/` — Esquemático, BOM y selección de componentes.
- `iteraciones/` — Evidencia del desarrollo e iteraciones del diseño.
- `software/` — Código fuente del ESP32, servidor web y dashboard.
- `testing/` — Protocolos de prueba y evidencias experimentales.
- `FUENTES.md` — Bibliografía, datasheets y referencias utilizadas.

## Tecnologías utilizadas

- ESP32
- Arduino IDE
- Node.js
- Express.js
- HTML, CSS y JavaScript
- JSON
- Autodesk Fusion 360

## Licencia

Este proyecto se distribuye bajo la licencia MIT.
