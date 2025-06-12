/* File: PrecisionThermostat.ino
   Three-Zone Precision Digital Thermostat
*/

#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ===== User Config =====
#define ONE_WIRE_PIN     2      // DS18B20 bus
#define OLED_RESET      -1      // not used
#define OLED_ADDR       0x3C    // SSD1306 I2C address
#define BUTTON_ZONE_PIN 3      // Select zone
#define BUTTON_UP_PIN   4      // Increase setpoint
#define BUTTON_DN_PIN   5      // Decrease setpoint
#define RELAY_PIN_1     8      // Zone 1 relay
#define RELAY_PIN_2     9      // Zone 2 relay
#define RELAY_PIN_3    10      // Zone 3 relay

const float HYSTERESIS = 1.0;  // °C total window
const float STEP       = 0.5;  // °C per button press
const float SP_DEFAULT = 22.0; // °C default setpoint

// ===== Globals =====
OneWire oneWire(ONE_WIRE_PIN);
DallasTemperature sensors(&oneWire);
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

uint8_t  currentZone = 0;               // 0,1,2
float    setpoint[3] = {SP_DEFAULT, SP_DEFAULT, SP_DEFAULT};
DeviceAddress probeAddr[3];             // store each sensor’s ROM

// Debounce
unsigned long lastBtnTime = 0;
const unsigned long DEBOUNCE = 200;     // ms

// ===== Helpers =====
bool isPressed(uint8_t pin) {
  if (digitalRead(pin) == HIGH && millis() - lastBtnTime > DEBOUNCE) {
    lastBtnTime = millis();
    return true;
  }
  return false;
}

void drawScreen(float temp) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Zone ");
  display.print(currentZone + 1);
  display.setCursor(0, 12);
  display.print("Temp: ");
  display.print(temp, 1);
  display.print(" C");
  display.setCursor(0, 24);
  display.print("Set : ");
  display.print(setpoint[currentZone], 1);
  display.print(" C");
  display.setCursor(0, 36);
  bool relayOn = (digitalRead(RELAY_PIN_1 + currentZone) == LOW);
  display.print("Relay: ");
  display.print(relayOn ? "HEAT" : "OFF");
  display.display();
}

void setup() {
  // I/O
  pinMode(BUTTON_ZONE_PIN, INPUT);
  pinMode(BUTTON_UP_PIN,   INPUT);
  pinMode(BUTTON_DN_PIN,   INPUT);
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  pinMode(RELAY_PIN_3, OUTPUT);
  // Relays are active LOW
  digitalWrite(RELAY_PIN_1, HIGH);
  digitalWrite(RELAY_PIN_2, HIGH);
  digitalWrite(RELAY_PIN_3, HIGH);

  // Initialize display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();

  // Initialize sensors
  sensors.begin();
  // discover up to 3 sensors
  for (uint8_t i = 0; i < 3; i++) {
    if (!sensors.getAddress(probeAddr[i], i)) {
      // no more sensors found
      break;
    }
  }
  delay(500);
}

void loop() {
  // 1) Handle button presses
  if (isPressed(BUTTON_ZONE_PIN)) {
    currentZone = (currentZone + 1) % 3;
  }
  if (isPressed(BUTTON_UP_PIN)) {
    setpoint[currentZone] += STEP;
  }
  if (isPressed(BUTTON_DN_PIN)) {
    setpoint[currentZone] -= STEP;
  }

  // 2) Read all temps
  sensors.requestTemperatures();
  float temp = sensors.getTempC(probeAddr[currentZone]);

  // 3) Relay control with hysteresis
  float sp = setpoint[currentZone];
  float low  = sp - HYSTERESIS / 2.0;
  float high = sp + HYSTERESIS / 2.0;
  uint8_t relayPin = RELAY_PIN_1 + currentZone;

  if (temp <= low) {
    digitalWrite(relayPin, LOW);  // ON
  } else if (temp >= high) {
    digitalWrite(relayPin, HIGH); // OFF
  }
  
  // 4) Update display
  drawScreen(temp);

  delay(1000); // update every second
}
