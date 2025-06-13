# Precision Digital Thermostat (3 Zones)
#### Author: Bocaletto Luca

**Files**  
- `README.md`  
- `PrecisionThermostat.ino`

## 1. Concept  
A three-zone thermostat that reads three DS18B20 temperature probes, displays each zone’s real-time temperature and setpoint on an OLED screen, and drives three relay outputs for heating/cooling. Users navigate zones and adjust setpoints via three push-buttons.

**Key Features**  
- 3 × DS18B20 sensors on one wire bus  
- OLED display (SSD1306 128×64) shows zone, temp, setpoint, relay status  
- 3 push-buttons: Zone-select, Increase, Decrease  
- Relay outputs with configurable hysteresis  
- Non-blocking code for smooth UI and precise timing  

## 2. Bill of Materials  
- Arduino Uno (or Nano)  
- 3 × DS18B20 waterproof probes + 3 × 4.7 kΩ resistors (pull-up)  
- 1 × SSD1306 128×64 I²C OLED display  
- 3 × SPDT relay modules (5 V coil)  
- 3 × push-buttons + 3 × 10 kΩ pull-down resistors  
- Breadboard, jumper wires, USB cable (5 V)  

## 3. Wiring Diagram

    DS18B20 Probes (all in parallel):
      ┌─────────────┐
      │ Data ──┬──► D2 (OneWire)
      │ VCC  ──┴─► 5 V
      │ GND ─────► GND
      └─────────────┘
      (4.7 kΩ pull-up from D2 to 5 V)

    Push-buttons:
      ┌───────────┐       ┌─────────┐
      │ Select ─► D3   ──┤ Button  │
      │ Up     ─► D4   ──┤ Button  │
      │ Down   ─► D5   ──┤ Button  │
      └───────────┘       └─────────┘
      (Each button to 5 V, with 10 kΩ to GND)

    OLED Display (I²C):
      ┌────────────┐
      │ SDA ──► A4 │
      │ SCL ──► A5 │
      │ VCC ──► 5 V│
      │ GND ──► GND│
      └────────────┘

    Relays:
      ┌─────────────┐
      │ IN1 ──► D8  │ Zone 1 relay
      │ IN2 ──► D9  │ Zone 2 relay
      │ IN3 ──► D10 │ Zone 3 relay
      │ VCC ──► 5 V │
      │ GND ──► GND │
      └─────────────┘

## 4. Software Setup  
1. In Arduino IDE, install libraries:  
   - **OneWire**  
   - **DallasTemperature**  
   - **Adafruit SSD1306** (and **Adafruit GFX**)  
2. Create folder `PrecisionThermostat` and save these two files.  
3. Open `PrecisionThermostat.ino` in Arduino IDE.  
4. Select **Arduino Uno** and the correct COM port.  

## 5. Usage  
1. Power board via USB.  
2. The OLED shows Zone 1 on startup.  
3. Press **Select** to cycle Zones 1→2→3→1.  
4. Press **Up/Down** to adjust the setpoint in 0.5 °C steps.  
5. Relay engages when temp < (setpoint − hysteresis/2) and disengages when > (setpoint + hysteresis/2).  
6. Zone temperatures and relay status update every second.

---

Say **continua** to move on to project #6!  
