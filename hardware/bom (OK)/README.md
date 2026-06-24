# Bill of Materials (BOM)

## Descripción

Este documento reúne la lista completa de materiales utilizados en la construcción del prototipo **Sensor IoT de Humedad y Temperatura del Suelo**, incluyendo sus especificaciones técnicas y costos estimados.

---

# Componentes

| Cantidad | Componente | Especificación | Fabricante | Código / SKU | Proveedor | Precio Unitario (CLP) | Precio Total (CLP) | Datasheet |
|----------|------------|---------------|------------|--------------|-----------|----------------------:|-------------------:|-----------|
| 1 | ESP32-S3 DevKit | Microcontrolador con WiFi y Bluetooth, alimentación 3.3 V | Espressif | __________ | Universidad Adolfo Ibáñez | $8.000 | $8.000 | ESP32-S3.pdf |
| 1 | Sensor capacitivo SEN0193 | Versión 1.2, alimentación 3.3–5.0 V, salida analógica | DFRobot | SEN0193 | Universidad Adolfo Ibáñez | $2.776 | $2.776 | SEN0193.pdf |
| 1 | Sensor de temperatura DS18B20 | Alimentación 3.0–5.5 V, rango −55 °C a 125 °C | Maxim Integrated | DS18B20 | Universidad Adolfo Ibáñez | $2.500 | $2.500 | DS18B20.pdf |
| 1 | Batería PAW-68 | Batería portátil recargable, voltaje nominal 3.7 V | __________ | PAW-68 | Universidad Adolfo Ibáñez | $7.990 | $7.990 | PAW-68.pdf |
| 1 | Resistencia | 4.7 kΩ (4700 Ω), 1/4 W, ±5 % | __________ | __________ | Universidad Adolfo Ibáñez | $1.098 | $1.098 | __________ |
| 1 | Cable USB | USB-A a USB-C para alimentación y programación | __________ | __________ | Universidad Adolfo Ibáñez | $1.000 | $1.000 | __________ |
| 6 | Cable Dupont macho-hembra | Cable de conexión para prototipado | __________ | __________ | Universidad Adolfo Ibáñez | $50 | $300 | __________ |

---

# Archivos incluidos

```
bom/
│
├── bom_completo.xlsx
├── bom_completo.pdf
├── README.md
└── datasheets/
    ├── ESP32-S3.pdf
    ├── SEN0193.pdf
    ├── DS18B20.pdf
    └── PAW-68.pdf
```

---

# Presupuesto Total

**Costo Total Estimado:** **$23.664 CLP**

## Desglose por Categoría

| Categoría | Costo (CLP) |
|-----------|------------:|
| Microcontrolador | $8.000 |
| Sensores | $5.276 |
| Alimentación | $7.990 |
| Componentes electrónicos | $1.398 |
| Cables | $1.300 |
| Encapsulado impreso 3D | Proporcionado por la Universidad |
| **Total** | **$23.664** |

---

# Observaciones

- Todos los componentes electrónicos utilizados en el proyecto fueron proporcionados por los laboratorios de la Universidad Adolfo Ibáñez.
- La fabricación del encapsulado mediante impresión 3D también se realizó utilizando los recursos disponibles en la universidad, por lo que su costo no fue incorporado al presupuesto total.
- Los precios indicados corresponden a valores referenciales de mercado para estimar el costo del prototipo.
- Los datasheets de los componentes principales deben almacenarse en la carpeta `datasheets/` para facilitar futuras consultas técnicas.


