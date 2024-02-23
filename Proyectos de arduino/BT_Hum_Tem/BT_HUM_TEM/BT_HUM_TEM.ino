#include <LiquidCrystal.h>
LiquidCrystal lcd(11,10,9,8,7,6);
#include <Wire.h> 
#include <DHT.h>
#define DHTPIN 3
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

//--- BLUETOOTH ---

#include <SoftwareSerial.h>

SoftwareSerial blue(2, 3);  
int btdato; 

void setup () {
    lcd.begin(16, 2);
    Serial.begin(9600);
    blue.begin(9600);
    dht.begin(); 
    Wire.begin(); 

  }
  
void loop () 
  {


//--- LEER SENSOR DHT11 ---

int h = dht.readHumidity();// Lee la humedad
int t = dht.readTemperature();//Lee la temperatura
//Humedad
Serial.print(h);
Serial.println(" %");
lcd.setCursor(0,0);
lcd.print("Humedad ");
lcd.print(h);         
//Temperatura              
Serial.print(t);
Serial.println(" C");
lcd.setCursor(0,5);
lcd.print("Temperatura ");
lcd.print(t);   
delay(1000);
lcd.clear();                   
             

//----- BLUETOOTH ----------

 if (blue.available()>0) 
    {        
      btdato= blue.read();  
 
      switch(btdato)  
     {  
        case 't': 
        {
         blue.print(t);
         delay(1000); 
         
         break; 
        }
       case 'h': 
        {
         blue.print(h);
         delay(1000); 
         
         break; 
        }
     }
    }
  
  }
  
//btdato=0;
//  }
//--- fin bluetooth ---
