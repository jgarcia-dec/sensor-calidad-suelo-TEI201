# Iteración 2 - Primera Mejora Significativa

## Información General

**Fecha:** 28 / 05 / 2026  
**Versión:** v2.0  
**Estado:** Prototipo funcional mejorado  
**Avance asociado:** Avance #2

---
  
## Descripción
  
En esta segunda iteración se incorporaron mejoras importantes tanto en hardware como en software, permitiendo que el sistema evolucionara desde una prueba de concepto hacia un prototipo funcional. Además, se inició el diseño mecánico del encapsulado y se implementó la transmisión de datos mediante conexión WiFi.

### Objetivos de esta iteración

- Corregir los problemas identificados en la versión 1.
- Incorporar la medición de temperatura.
- Implementar la comunicación WiFi.
- Desarrollar la primera versión del encapsulado en Fusion 360.

---
  
# Cambios Respecto a v1
  
## Hardware
  
### Componentes agregados
  
- Primer diseño del encapsulado.

### Componentes modificados

- Reorganización del cableado para facilitar el montaje.
- Calibración del sensor capacitivo SEN0193 para mejorar la precisión de las mediciones.

### Componentes removidos

- Ninguno.

---
  
## Software
  
### Nuevas funcionalidades
  
- Conexión del ESP32-S3 a una red WiFi.
- Envío de datos al servidor mediante solicitudes HTTP POST.
- Conversión de la lectura analógica a porcentaje de humedad (VWC).

### Optimizaciones

- Organización del código en funciones independientes.
- Promedio de múltiples lecturas del sensor para disminuir el ruido eléctrico.

### Problemas corregidos

- Mejora en la estabilidad de las mediciones del sensor de humedad.
- Corrección de la calibración del sensor SEN0193.

---
  
  ## Diseño Mecánico
  
- Desarrollo del primer modelo del encapsulado en Autodesk Fusion 360.
- Definición de la ubicación del ESP32 y los sensores.
- Diseño inicial del compartimiento para la batería.

---
  
# Fotos del Prototipo
  
Esta carpeta puede incluir:
  
- `v2_codigo_completo.ino`
- `v2_detalle_conexiones.jpeg`
- `v2_modelado.pdf`

---
  
# Resultados de las Pruebas Funcionales
  
### Funcionalidad Lograda
  
✅ Lectura de humedad del suelo.

✅ Lectura de temperatura.

✅ Conexión WiFi.

✅ Envío de datos al servidor.

⚠️ Plataforma web en desarrollo.

⚠️ Encapsulado aún en proceso de refinamiento.

---
  
# Problemas Pendientes
  
## Problema 1
  
**Descripción**
  
El encapsulado aún no permitía integrar todos los componentes de manera definitiva.

**Prioridad**
  
Alta.

**Plan para v3**
  
Rediseñar el encapsulado considerando la ubicación del ESP32, sensores y batería. 
Incorporar un protector en caso de lluvia.

---
  
## Problema 2
  
**Descripción**
  
La plataforma web aún no mostraba toda la información requerida.

**Prioridad**
  
Alta.

**Plan para v3**
  
Completar el desarrollo de la interfaz web e incorporar el historial de mediciones.

---
  
  # Comparación v1 vs v2
  
  | Aspecto | v1 | v2 |
  |---------|----|----|
  | Sensor de humedad | ✅ | ✅ |
  | Sensor de temperatura | ❌ | ✅ |
  | Comunicación WiFi | ❌ | ✅ |
  | Envío al servidor | ❌ | ✅ |
  | Plataforma web | ❌ | Parcial |
  | Encapsulado | ❌ | Prototipo |
  
  ---
  
# Plan para Iteración 3
  
## Hardware
  
- [ ] Integrar definitivamente todos los componentes dentro del encapsulado.
- [ ] Incorporar la batería portátil.

## Software

- [ ] Finalizar la plataforma web.
- [ ] Optimizar la transmisión y visualización de datos.

## Diseño

- [ ] Refinar el encapsulado.
- [ ] Incorporar soportes internos.
- [ ] Agregar ventilación y accesibilidad para mantenimiento.

## Validación

- [ ] Verificar el funcionamiento del sistema completamente ensamblado.
- [ ] Validar la comunicación entre el ESP32 y la plataforma web.

---
  
  # Archivos en esta Carpeta
  
- `v2_codigo_completo.ino`
- `v2_detalle_conexiones.jpeg`
- `v2_modelado.pdf`
- `v2_cuerpo_inferior.jpeg`
- `v2_cuerpo_superior.jpeg`
- `README.md`
