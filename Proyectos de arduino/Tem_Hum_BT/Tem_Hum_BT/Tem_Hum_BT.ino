#include <SoftwareSerial.h> //Incluimos una librería para usar
                            //otros pines como puerto serie
SoftwareSerial BT1(4,2);  //Nombramos el puerto, y asignamos los pines que
                          //usaremos. Harán de RX Y TX, respectivamente.

byte serialA; //Declaramos una variable tipo Byte

#include <DHT.h> //Librería para usar el DHT11
#define DHTPIN 6 //Indicamos el pin que usaremos
#define DHTTYPE DHT11
//#define DHTTYPE DHT22 //Solo escribe este si usa el DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {     //Todo lo que se programe aquí se repetirá
  
  BT1.begin(9600); //Ajustamos la velocidad de nuestro puerto serie
  dht.begin();     //Comunicación con DHT
}

void loop() {
  delay(2000); //Espera 2 segundos
  float h = dht.readHumidity();       //Se lee la humedad
  float t = dht.readTemperature();    //Se lee la temperatura en Celsius
  float f = dht.readTemperature(true);//Se lee la temperatura en Fahrenheit


  // Bluetooth
  // Enviaremos 3 datos. El 0, el 1, el 2 y el 3.
    byte Datos[3]; //Declaramos una variable que puede almacenar varios datos (array)
    serialA=BT1.read(); //Indicamos que lea lo de BT1
    Datos[0]='a';  //El primer dato será un caracter para indicar a la app donde comenzar
    Datos[1]=t;    //El segundo 
    Datos[2]=f;     
    Datos[3]=h;    //Se envía el dato de la humedad

// Envío de datos.
     if (serialA == 49){   //Una condición para ejecutra lo siguiente:
      BT1.write(Datos[0]); //Escribir los datos enviados
      BT1.write(Datos[1]);
      BT1.write(Datos[2]);
      BT1.write(Datos[3]);
      serialA=0;           //Y hacer que A valga cero para que al evitar que
      }                    //se acumulen los datos
  delay(100);              //Esperar 1 segundo y continuar
}
