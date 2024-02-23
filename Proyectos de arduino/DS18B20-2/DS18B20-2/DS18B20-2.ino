#include <OneWire.h>
#include <DallasTemperature.h>

// Pin donde se conecta el bus 1-Wire
const int pinDatosDQ = 9;

// Instancia a las clases OneWire y DallasTemperature
OneWire oneWireObjeto(pinDatosDQ);
DallasTemperature sensorDS18B20(&oneWireObjeto);
 
void setup() {
    // Iniciamos la comunicación serie
    Serial.begin(115200);
    // Iniciamos el bus 1-Wire
    while (!Serial);
    sensorDS18B20.begin(); 
}
 
void loop() {
    // Mandamos comandos para toma de temperatura a los sensores
    Serial.println("Mandando comandos a los sensores");
    sensorDS18B20.requestTemperatures();
 
    // Leemos y mostramos los datos de los sensores DS18B20
    Serial.print("Temperatura sensor 1: ");
    Serial.print(sensorDS18B20.getTempCByIndex(1));
    Serial.println(" C");
    
    delay(2000); 
}
