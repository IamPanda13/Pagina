#include<Servo.h>
Servo servo3;
Servo servo5;
const int pin3=3; // Un servo se conecta al pin 3
const int pin5=5; 
char val;
String grados;
int angulo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin3,OUTPUT);
  pinMode(pin5,OUTPUT);
  servo3.attach(pin3);
  servo5.attach(pin5);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    val=Serial.read();
    if(isDigit(val)){
      grados+=(char)val;
      }
    if(val=='\n'){
      angulo=grados.toInt();
      Serial.println(angulo);
      if(angulo==0){
        servo3.write(angulo);
      }
       if(angulo==90){
        servo3.write(angulo);
      }
       if(angulo==180){
        servo3.write(angulo);
      }
       if(angulo==1){
        servo5.write(angulo);
      }
       if(angulo==91){
        servo5.write(angulo);
      }
       if(angulo==181){
        servo5.write(angulo);
      }
      grados="";
     }
   }  
 }
