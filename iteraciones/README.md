# Historial de Iteraciones

## Propósito

Esta carpeta documenta la evolución del prototipo **Monitor Verde** durante las distintas etapas de desarrollo del proyecto, mostrando las mejoras implementadas en hardware, software y diseño 3D.

El objetivo es evidenciar el proceso iterativo seguido para llegar a la versión final del sistema.

---
  
  # Estructura de Carpetas
  
  ```
iteraciones/
  ├── iteracion_1/
  ├── iteracion_2/
  └── iteracion_3/
  ```

---
  
  # Contenido de Cada Iteración
  
  Cada iteración incluye:
  
- README.md con la descripción de la versión.
- Fotografías del prototipo.
- Esquemas del circuito (cuando hubo modificaciones).
- Código correspondiente a la versión desarrollada.
- Registro de mejoras implementadas.

---
  
  # Tabla Comparativa de Iteraciones
  
  | Aspecto | v1 | v2 | v3 |
  |---------|----|----|----|
  | **Fecha** | 30/04/2026 | 28/05/2026 | 18/06/2026 |
  | **Sensores** | SEN0193 | SEN0193 + DS18B20 | SEN0193 + DS18B20 |
  | **Conectividad** | Sin conexión | WiFi | WiFi + Plataforma Web |
  | **Encapsulado** | Sin encapsulado | Primer modelo 3D | Encapsulado final |
  | **Testing** | Pruebas funcionales | Validación del sistema | Integración completa |
  | **Funcionalidad** | Lectura de humedad | Lectura de humedad y temperatura | Sistema IoT completo |
  
  ---
  
  # Evolución del Diseño
  
  ## Versión 1 (Iteración 1)
  
  **Fecha:** 30/04/2026

**Estado:** Prueba de concepto.

### Características

- Lectura inicial del sensor capacitivo de humedad.
- Desarrollo del primer firmware.
- Pruebas de calibración del sensor.

### Problemas identificados

- No existía monitoreo de temperatura.
- No había comunicación con un servidor.
- El sistema no contaba con encapsulado.

### Aprendizajes

- Calibración del sensor SEN0193.
- Configuración del ADC del ESP32.

---
  
## Versión 2 (Iteración 2)
  
**Fecha:** 28/05/2026

**Estado:** Prototipo funcional.

### Mejoras implementadas

- Incorporación del sensor DS18B20.
- Conexión WiFi del ESP32.
- Envío de datos al servidor.
- Desarrollo inicial del encapsulado en Fusion 360.

### Problemas pendientes

- Encapsulado aún en desarrollo.
- Organización interna de componentes.
- Plataforma web en proceso.

---
  
## Versión 3 (Iteración 3)
  
**Fecha:** 18/06/2026

**Estado:** Prototipo final.

### Mejoras implementadas

- Integración completa del hardware.
- Encapsulado definitivo impreso en 3D.
- Plataforma web funcionando.
- Visualización histórica de datos.
- Alimentación mediante batería portátil.

### Resultado

- Sistema IoT completamente funcional.
- Diseño preparado para futuras pruebas en terreno.

---
  
# Justificación de Cambios
  
## Hardware
  
### De v1 a v2
  
**Cambio**
  
- Incorporación del sensor DS18B20 y conexión WiFi.

**Razón**
  
- Obtener una caracterización más completa del estado del suelo y permitir la transmisión remota de datos.

**Impacto**
  
- El sistema pasó de realizar mediciones locales a enviar información en tiempo real.

---
  
  ### De v2 a v3
  
  **Cambio**
  
  - Integración del encapsulado, batería y organización definitiva del hardware.

**Razón**
  
  - Mejorar la protección del sistema y facilitar su uso en exteriores.

**Impacto**
  
  - Prototipo completamente integrado y portátil.

---
  
  ## Software
  
  ### De v1 a v2
  
- Desarrollo de funciones para lectura de temperatura.
- Conexión WiFi.
- Envío de datos mediante HTTP POST.

### De v2 a v3

- Optimización del código.
- Integración con la plataforma web.
- Mejor documentación y comentarios del firmware.

---
  
## Diseño 3D
  
### De v1 a v2
  
- Diseño inicial del encapsulado.
- Definición del espacio para los componentes.

### De v2 a v3

- Incorporación de soportes internos.
- Compartimiento para la batería.
- Protector frontal.
- Ranuras de ventilación.
- Diseño preparado para impresión 3D.

---
  
# Incorporación de Feedback
  
## Avance 1 → Iteración 2
  
- Se incorporó un encapsulado para proteger los componentes electrónicos.
- Se mejoró la organización del circuito.

---
  
## Avance 2 → Iteración 3
  
- Se integró una batería portátil.
- Se mejoró la distribución interna del hardware.
- Se desarrolló la plataforma web para visualizar las mediciones.
- Se completó la documentación técnica del proyecto.

---
  
# Métricas de Mejora
  
  | Característica | v1 | v2 | v3 |
  |---------------|----|----|----|
  | Medición de humedad | ✅ | ✅ | ✅ |
  | Medición de temperatura | ❌ | ✅ | ✅ |
  | Comunicación WiFi | ❌ | ✅ | ✅ |
  | Envío al servidor | ❌ | ✅ | ✅ |
  | Plataforma web | ❌ | Parcial | ✅ |
  | Encapsulado | ❌ | Parcial | ✅ |
  | Alimentación portátil | ❌ | ❌ | ✅ |
  
  ---
  
# Lecciones Aprendidas
  
## Técnicas
  
- La calibración de los sensores es fundamental para obtener mediciones confiables.
- La integración entre hardware, software y diseño mecánico requiere pruebas continuas.

## De Proceso

- La documentación permanente facilita el desarrollo del proyecto.
- El diseño iterativo permitió corregir problemas antes de la versión final.

## Trabajo en Equipo

- La distribución de responsabilidades permitió avanzar en paralelo en hardware, software, modelado 3D y documentación.
- La integración periódica del trabajo de cada integrante fue clave para completar el prototipo.
