# Iteración 3 - Versión Final

## Información General

**Fecha:** 18 / 06 / 2026  
**Versión:** v3.0  
**Estado:** Prototipo final  
**Avance asociado:** Avance #3

---
  
## Descripción
  
La tercera iteración corresponde a la versión final del proyecto **Monitor Verde**, en la cual se integraron el hardware, el firmware, el encapsulado y la plataforma web en un único sistema funcional para el monitoreo de humedad y temperatura del suelo.

### Objetivos alcanzados

- Integración completa del hardware y software.
- Encapsulado definitivo diseñado en Fusion 360 e impreso en 3D.
- Comunicación WiFi estable con el servidor.
- Visualización de datos mediante plataforma web.
- Sistema portátil alimentado mediante batería.

---
  
# Cambios Respecto a v2
  
## Hardware
  
### Mejoras implementadas
  
### Integración de batería portátil
  
**Razón**
  
Permitir el funcionamiento autónomo del sistema sin depender de una fuente de alimentación externa.

**Impacto**
  
El prototipo puede operar de forma portátil durante las pruebas.

---
  
### Integración definitiva de los componentes
  
**Razón**
  
Mejorar la organización interna y facilitar el montaje del sistema.

**Impacto**
  
Mayor protección de los componentes y mejor distribución dentro del encapsulado.

---
  
## Cambios finales
  
- Integración completa del ESP32-S3, sensores y batería.
- Optimización del cableado interno.
- Montaje definitivo del prototipo.

---
  
## Software
  
### Nuevas funcionalidades
  
- Plataforma web para visualizar las mediciones.
- Almacenamiento de datos mediante archivos JSON.
- Actualización periódica de la información.
- Clasificación automática del estado del suelo.

### Optimizaciones

- Organización modular del firmware.
- Mejora en la estabilidad del envío HTTP.
- Promedio de lecturas para reducir ruido eléctrico.
- Comentarios y documentación del código.

### Manejo de errores

- Verificación de conexión WiFi.
- Validación de respuesta HTTP.
- Mensajes informativos en el Monitor Serial.

---
  
## Diseño Mecánico
  
### Encapsulado Final
  
- Diseño optimizado para impresión 3D.
- Acceso al puerto USB del ESP32 para programación.
- Protector para lluvia.

---
  
  # Fotografías del Prototipo
  
  Esta carpeta puede incluir:
  
- `v3_prototipo_frontal.jpg`
- `v3_prototipo_lateral.jpg`
- `v3_prototipo_superior.jpg`
- `v3_componentes_internos.jpeg`

---
  
# Resultados Finales
  
## Funcionalidad Alcanzada
  
✅ Medición de humedad del suelo.

✅ Medición de temperatura.

✅ Comunicación WiFi.

✅ Envío de datos al servidor.

✅ Plataforma web operativa.

✅ Almacenamiento histórico de mediciones.

✅ Encapsulado completamente ensamblado.

---
  
# Validación del Sistema
  
Durante esta iteración se realizaron pruebas funcionales para verificar:
  
- Correcta lectura del sensor SEN0193.
- Correcta lectura del sensor DS18B20.
- Conexión estable a la red WiFi.
- Envío de datos mediante HTTP POST.
- Recepción y almacenamiento de datos en el servidor.
- Visualización de las mediciones en la plataforma web.

Todas las funciones principales operaron correctamente durante las pruebas del prototipo.

---
  
  # Comparación de las Iteraciones
  
  | Característica | v1 | v2 | v3 |
  |---------------|:--:|:--:|:--:|
  | Lectura de humedad | ✅ | ✅ | ✅ |
  | Lectura de temperatura |✅ | ✅ | ✅ |
  | Comunicación WiFi | ❌ | ✅ | ✅ |
  | Envío al servidor | ❌ | ✅ | ✅ |
  | Plataforma web | ❌ | Parcial | ✅ |
  | Encapsulado | ❌ | Prototipo | Finalizado |
  | Alimentación portátil | ❌ | ❌ | ✅ |
  
  ---
  
  # Fortalezas del Prototipo Final
  
  ## Integración del sistema
  
  El hardware, el software y el encapsulado funcionan como un único sistema de monitoreo.

---
  
  ## Diseño modular
  
  Los componentes pueden desmontarse para facilitar tareas de mantenimiento y futuras mejoras.

---
  
  ## Plataforma IoT
  
  El sistema permite registrar y visualizar las mediciones de manera remota mediante una plataforma web.

---
  
  # Limitaciones Identificadas
  
  ## Autonomía
  
  La duración del sistema depende de la capacidad de la batería utilizada.

**Posible mejora**
  
  Incorporar paneles solares o una batería de mayor capacidad.

---
  
  ## Comunicación
  
  El funcionamiento requiere disponibilidad de una red WiFi.

**Posible mejora**
  
  Implementar tecnologías de comunicación de mayor alcance, como LoRa o NB-IoT.

---
  
  # Aprendizajes
  
  ## Técnicos
  
- La correcta calibración de los sensores mejora significativamente la calidad de las mediciones.
- La integración entre hardware y software requiere pruebas continuas para asegurar la estabilidad del sistema.

## Diseño

- El modelado 3D permitió optimizar la distribución interna de los componentes antes de la fabricación.
- La impresión 3D facilitó realizar modificaciones rápidas en el encapsulado.

## Trabajo en Equipo

- La división de tareas permitió desarrollar simultáneamente el hardware, el firmware, el diseño mecánico y la documentación.
- La integración periódica del trabajo de cada integrante fue fundamental para completar el proyecto.

## Gestión del Proyecto

- La planificación por iteraciones permitió incorporar mejoras de forma progresiva.
- La documentación constante facilitó la organización del proyecto.

---
  
  # Trabajo Futuro
  
  ## Mejoras a Corto Plazo
  
- [ ] Optimizar el consumo energético.
- [ ] Incorporar una interfaz gráfica con mayor cantidad de indicadores.

## Mejoras a Mediano Plazo

- [ ] Integrar sensores adicionales (pH, conductividad o luminosidad).
- [ ] Implementar almacenamiento en una base de datos.

## Escalabilidad

- [ ] Implementar monitoreo simultáneo de múltiples sensores.
- [ ] Integrar la plataforma con sistemas municipales de gestión de áreas verdes.
- [ ] Incorporar modelos predictivos para apoyar la planificación del riego.

---
  
  # Archivos en esta Carpeta
  
- `v3_prototipo_frontal.jpg`
- `v3_prototipo_lateral.jpg`
- `v3_prototipo_superior.jpg`
- `v3_componentes_internos.jpeg`
- `v3_codigo_final.ino`
- `v3_monitor_verde.f3d`
- `README.md`