#include <FastIO.h>
#include <I2CIO.h>
#include <LiquidCrystal_I2C_ByVac.h>
#include <LiquidCrystal_SR.h>
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include  <Wire.h>
#include <DHT.h>
#include <SoftwareSerial.h>
LiquidCrystal_I2C  lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
#define SensorPinPH A0 
#define DHTPIN 2
#define DHTTYPE DHT11

SoftwareSerial I2CBT(10,11);
DHT dht(DHTPIN, DHTTYPE);
const int sensorPin=A1;
unsigned long int avgValue;
float b;
int buf[10],temp;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 Serial.println("Valor del sensor de humedad");
 dht.begin();
 lcd.begin(16, 2);
 lcd.setCursor(0, 0);
 lcd.print("   Bienvenido  ");
  lcd.setCursor(0, 1);
 lcd.print("Monitoreo Elid  ");
 I2CBT.begin(9600);
 delay(2000);
 lcd.clear();
}

void loop() {
 HumTem();
 
  Suelo();
  Ph();
 }
void HumTem()
{
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
  // Leemos la temperatura en grados Fahrenheit
  float f = dht.readTemperature(true);
  // Calcular el índice de calor en Fahrenheit
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
 
  float hif = dht.computeHeatIndex(f, h);
  // Calcular el índice de calor en grados centígrados
  float hic = dht.computeHeatIndex(t, h, false);
 
  Serial.print("Humedad: ");
  Serial.print(h);
  lcd.setCursor(0,0);
  lcd.print("Humedad=%");
  lcd.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  lcd.setCursor(0,1);
  lcd.print("Temp= ");
  lcd.print(t);
  lcd.print("°C");
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F"); 
  delay(500); 
 
  }
void Suelo()
{
 int humidity = analogRead(A1);
    Serial.print("Lectura Suelo:");
    Serial.println(humidity);
    //Paso 3
    if(humidity >= 0 & humidity <= 300){
        Serial.println("Sensor en suelo seco");  
    } else if(humidity > 301 & humidity <= 700){
        Serial.println("Sensor en suelo húmedo");
    }else if(humidity >= 701){
        Serial.println("Sensor en agua");
    }
    delay(500);
    lcd.clear();
}
void Ph(){
   for(int i=0;i<10;i++) 
 { 
  buf[i]=analogRead(SensorPinPH);
   }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf[i]>buf[j])
   {
    temp=buf[i];
    buf[i]=buf[j];
    buf[j]=temp;
   }
  }
 }
 avgValue=0;
 for(int i=2;i<8;i++)
 avgValue+=buf[i];
 float pHVol=(float)avgValue*5.0/1024/6;
 float phValue = -5.70 * pHVol + 21.34;
 Serial.print("Sensor PH= ");
 Serial.println(phValue);
 lcd.setCursor(0,0);
 lcd.print("El PH es:");
 lcd.print(phValue);
 delay(500);
}
