# Diseño 3D - Documentación

## Requisito del Modelo

El modelo 3D incluye todos los componentes principales del prototipo:
  
- ✅ Encapsulado exterior completo
- ✅ Placa ESP32-S3
- ✅ Sensor capacitivo de humedad SEN0193
- ✅ Sensor de temperatura DS18B20
- ✅ Batería
- ✅ Protector frontal
- ⬜ Cableado (representación simplificada)
- ✅ Sistema de montaje mediante pestañas de ensamble
- ✅ Orificios de ventilación superiores

---
  
# Carpetas
  
## fusion360/
  
  Contiene el archivo nativo del proyecto de Autodesk Fusion 360 (.f3d), incluyendo el historial completo de modelado y todas las modificaciones realizadas durante el diseño.

## renders/

Imágenes renderizadas del prototipo desde distintos ángulos para visualizar el diseño final y el ensamblaje de los componentes.

Archivos incluidos:
  
- 01_isometrica_exterior_v3.png
- 02_vista_interior_v3.png
- 03_ensamble_explosionado_v3.png
- 04_vista_lateral_v3.png
- 05_vista_superior_v3.png

## planos/

Planos técnicos acotados del encapsulado y sus componentes para facilitar la fabricación y el montaje.

---
  
# Especificaciones
  
**Software de diseño:** Autodesk Fusion 360

**Unidades:** Milímetros (mm)

**Escala:** 1:1

**Dimensiones externas:**

- Largo: 145.9 mm
- Ancho: 57.5 mm
- Alto: 51.1 mm

**Peso estimado:** 180–220 g

**Material de impresión:** PLA

---
  
# Consideraciones de Diseño
  
## Funcionales
  
- ✅ Acceso al sensor capacitivo de humedad.
- ✅ Acceso al sensor de temperatura DS18B20.
- ✅ Acceso al puerto USB para programación y alimentación del ESP32.
- ✅ Ranuras superiores para ventilación del sistema.
- ✅ Protección de los componentes electrónicos mediante encapsulado.
- ✅ Diseño desmontable para facilitar mantenimiento y reemplazo de componentes.

## Fabricación

- ✅ Diseño optimizado para impresión FDM.
- ✅ Tolerancia aproximada de ensamble: +0.2 mm.
- ✅ Grosor mínimo de pared: 2 mm.
- ✅ Diseño pensado para minimizar deformaciones durante la impresión.
- ✅ Se requieren soportes únicamente en las zonas con voladizos del encapsulado.

---
  
# Configuración de Impresión 3D
  
**Impresora utilizada:** _______________________

**Material:** PLA

**Altura de capa:** ______ mm

**Relleno:** ______ %

**Soportes:** Sí

**Temperatura del nozzle:** ______ °C

**Temperatura de la cama:** ______ °C

**Velocidad de impresión:** ______ mm/s

**Tiempo de impresión:** Aproximadamente 7 horas.

**Peso de material utilizado:** ______ g

---
  
  # Observaciones
  
  El encapsulado fue diseñado específicamente para alojar un ESP32-S3, un sensor capacitivo de humedad SEN0193, un sensor de temperatura DS18B20 y una batería recargable. El diseño incorpora ranuras de ventilación en la cubierta superior, acceso para los sensores y un sistema de cierre mediante pestañas de ensamble, permitiendo proteger los componentes internos y facilitar futuras tareas de mantenimiento o reemplazo.