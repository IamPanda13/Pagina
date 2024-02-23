#include <FastIO.h>
#include <I2CIO.h>
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_I2C_ByVac.h>
#include <LiquidCrystal_SR.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
OneWire onewire(9);
DallasTemperature sensors(&onewire);

void setup()
{
  // preparar serial
  Serial.begin(115200);
  while (!Serial); 
  
  sensors.begin();
  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("   Bienvenido  ");
  lcd.setCursor(0, 1);
  lcd.print("Monitoreo EMI");
}

void loop()
{
  
  Serial.println(F("Solicitando temperaturas... "));
  sensors.requestTemperatures();
  Serial.println(F("LISTO!"));
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hola EMI");
  lcd.clear();
  lcd.print("Temp: ");
  float temperatura;
  temperatura = sensors.getTempCByIndex(0);
  lcd.print(temperatura);
  lcd.print("C");
  delay(3000);
  
  Serial.println(F("La temperatura del sensor : "));
  Serial.print(temperatura);
  Serial.println(" °C");
  Serial.println("Sensor de Humedad");
  //Serial.println(analogRead(0));
  int humedad = analogRead(A0);
  //Serial.print(humedad);
  if(humedad >=700 & humedad <=1023){
    Serial.print("La humedad es: ");
    Serial.print(humedad);
    Serial.println(" El Suelo esta seco");
    lcd.setCursor(0,0);
    lcd.print("Humedad: ");
    lcd.print(humedad);
    lcd.setCursor(0,1);
    lcd.println("Suelo seco");
    }else if (humedad>600 & humedad <=699){
      Serial.print("La humedad es: ");
      Serial.print(humedad);
      Serial.println(" El Suelo esta húmedo");
      lcd.setCursor(0,0);
      lcd.print("Humedad: ");
      lcd.print(humedad);
      lcd.setCursor(0,1);
      lcd.println("Suelo humedo");
      }else if (humedad<=600){
        Serial.print("El valor de humedad es: ");
        Serial.print(humedad);
        Serial.println(" El Suelo tiene exceso de humedad");
        lcd.setCursor(0,0);
        lcd.print("Humedad: ");
        lcd.print(humedad);
        lcd.setCursor(0,1);
        lcd.println("Suelo mojado");
        }
  delay(3000);
}
