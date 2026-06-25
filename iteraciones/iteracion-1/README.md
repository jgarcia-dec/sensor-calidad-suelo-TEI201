# Iteración 1 - Concepto Inicial

## Información General

**Fecha:** 30 / 04 / 2026  
**Versión:** v1.0  
**Estado:** Prototipo alpha - Prueba de concepto  
**Avance asociado:** Avance #1

---

## Descripción

Primera versión del prototipo, enfocada en validar el funcionamiento del sistema de adquisición de datos mediante un ESP32 y un sensor capacitivo de humedad del suelo.

El objetivo principal fue comprobar la viabilidad del proyecto y establecer una base funcional para futuras iteraciones.

### Objetivos de esta iteración

- Validar la lectura del sensor  SEN0193.
- Lectura del sensor DS18B20.
- Verificar la comunicación entre el sensor y el ESP32-S3.
- Calibrar el sensor de humedad.
- Visualizar las mediciones mediante el Monitor Serial.

---

## Componentes Utilizados

### Hardware

**Microcontrolador**

- ESP32-S3

**Sensores**

- Sensor capacitivo de humedad SEN0193
- Sensor de temperatura DS18B20

**Otros**

- Protoboard
- Cables Dupont
- Cable USB

---

### Software

- Arduino IDE 2.x
- Arduino Core para ESP32

**Versión del firmware:** v1.0

---

## Fotos del Prototipo

Archivos sugeridos:

- `v1_circuito_protoboard.jpeg`
- `v1_detalle_conexiones.jpeg`

---

## Resultados de Testing Inicial

### Funcionalidad Lograda

✅ Lectura del sensor de humedad y de temperatura.

✅ Comunicación entre el ESP32 y el Monitor Serial.

✅ Calibración inicial del sensor capacitivo.

❌ Envío de datos mediante WiFi.

❌ Plataforma web.

---

## Problemas Identificados

### Problema 1

**Descripción**

Las mediciones del sensor presentaban variaciones importantes entre distintas condiciones de humedad.

**Causa probable**

El sensor requería un proceso de calibración utilizando valores de referencia para suelo seco y húmedo.

**Solución propuesta**

Realizar la calibración experimental del sensor SEN0193 e incorporar la conversión a porcentaje de humedad (VWC).

---

### Problema 2

**Descripción**

El sistema únicamente permitía visualizar la información mediante el Monitor Serial.

**Causa probable**

Aún no existía un mecanismo para transmitir la información de forma remota.

**Solución propuesta**

Incorporar conectividad WiFi y desarrollar un servidor para almacenar las mediciones.

---

## Aprendizajes

### Técnicos

- Comprender el funcionamiento del conversor ADC del ESP32.
- Calibrar correctamente un sensor capacitivo de humedad.

### De Diseño

- La distribución de los componentes debía planificarse considerando un futuro encapsulado.
- Era necesario incorporar sensores adicionales para obtener una caracterización más completa del suelo.

---

## Plan para Iteración 2

### Hardware

- [ ] Mejorar la organización del circuito.

### Software

- [ ] Implementar conexión WiFi.
- [ ] Enviar datos mediante HTTP al servidor.

### Diseño

- [ ] Iniciar el modelado del encapsulado en Fusion 360.
- [ ] Definir la distribución interna de los componentes.

---

## Archivos en esta Carpeta

- `v1_codigo_temperatura.ino`
- `v1_codigo_humedad.ino`
- `v1_circuito_protoboard.jpeg`
- `v1_detalle_conexiones.jpeg`
- `README.md`