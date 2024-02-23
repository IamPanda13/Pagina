#include <DHT.h>//La libreria DHT

//Sensor DHT / temperatura y humedad Bluetooth Arduino

#define DHTPIN 13 // El pin DATA del DHT

#define DHTTYPE DHT11 //EL tipo de DHT en este caso es el 11 puede ser 22

DHT dht (DHTPIN, DHTTYPE);

int Pin_de_alimentacion= 12; //El pin VCC del DHT con el que alimentaremos a 5 v.

void setup() {

Serial.flush();

Serial.begin(9600);

pinMode(Pin_de_alimentacion, OUTPUT);

delay(2000);

digitalWrite(Pin_de_alimentacion, HIGH);

Serial.println("Sensor DHT11");

dht.begin(); }

void loop() {

float h= dht.readHumidity(); //Lee la humedad

float t= dht.readTemperature(); //Lee la temperatura

//Revisa que los datos obtenidos sean validos, si no lo son(no un numero) algo sale mal!

if (isnan (t) || isnan (h)) {

Serial.println("Falla de lectura del DHT");

}else {

Serial.print("Humedad: ");

Serial.print(h);

Serial.print(" %\t"); //Escribe el valor de la humedad

Serial.print("Temperatura: ");

Serial.print(t);

Serial.println(" °C"); //Escribe el valor de la temperatura en grados celcius

}

delay(2000);

}
