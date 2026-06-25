# Archivos Fusion 360

## Archivo Principal

### `monitor_verde_v3.f3d`

Archivo principal del diseño mecánico desarrollado en Autodesk Fusion 360.

**Incluye:**
  
- Modelo completo del encapsulado.
- Ensamble de todos los componentes.
- Historial de diseño (Timeline).
- Componentes independientes.
- Relaciones de ensamblaje.
- Diseño preparado para impresión 3D.

---
  
# Estructura del Modelo
  
## Componentes
  
  ```
Monitor_Verde_v3
├── Base
├── Tapa
├── Protector
├── Soporte
├── ESP32-S3 DevKit
├── Sensor Capacitivo SEN0193
├── Sensor DS18B20
├── Batería PAW-68
└── Orificios de montaje
```

---
  
  # Componentes del Ensamble
  
- Base del encapsulado.
- Tapa superior ventilada.
- Protector frontal del sensor.
- Soporte interno para los componentes electrónicos.
- ESP32-S3 DevKit.
- Sensor capacitivo de humedad del suelo SEN0193.
- Sensor de temperatura DS18B20.
- Batería portátil PAW-68.
- Orificios para fijación y montaje.

---
  
# Uniones
  
El ensamblaje considera:
  
- Tapa ensamblada sobre la base.
- Soporte fijado al interior del encapsulado.
- ESP32 montado sobre el soporte.
- Sensores posicionados para permitir la medición del suelo.
- Batería ubicada en el compartimiento posterior.
- Protector instalado para resguardar los sensores.

---
  
# Parámetros principales

| Parámetro | Valor |
|-----------|------:|
| Ancho total | 57.5 mm |
| Largo total | 145.9 mm |
| Alto total | 51.1 mm |
| Grosor de pared | 2.8 mm |
| Diámetro orificio DS18B20 | 4.3 mm |

---
  
# Instrucciones de Apertura
  
1. Abrir Autodesk Fusion 360.
2. Seleccionar **Archivo → Abrir**.
3. Cargar el archivo **monitor_verde_v3.f3d**.
4. Esperar la carga completa del ensamblaje.
5. Revisar el Timeline para visualizar la secuencia de construcción del modelo.

---
  
  # Versiones
  
  | Versión  | Cambios  |
  |----------|----------|
  | v1       | Diseño inicial del encapsulado. |
  | v2       | Incorporación del soporte interno y ajustes dimensionales. |
  | v3       | Diseño final con batería, sensores, protector y mejoras para impresión 3D. |