#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DallasTemperature.h>

LiquidCrystal_I2C lcd(0x27,16, 2);
const int oneWireBus = D3;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire); 

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  lcd.clear();
  lcd.print(temperatureC);
  lcd.print(" \337C");
  delay(5000);
}