#include<Servo.h>
Servo servo3;
Servo servo5;
const int pwmPin3=3; // Un servo se conecta al pin 3
const int pwmPin5=5; 
char val;
String palabra;
String angulo_1;
String angulo_2;
int k1;
int k2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pwmPin3,OUTPUT);
  pinMode(pwmPin5,OUTPUT);
  servo3.attach(pwmPin3);
  servo5.attach(pwmPin5);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    val=Serial.read();
    palabra=palabra+val;
    if(val=='*'){
      Serial.println(palabra);
      k1=palabra.indexOf(',');
      angulo_1=palabra.substring(0,k1);
      k2=palabra.indexOf(',',k1+1);
      angulo_2=palabra.substring(k1+1,k2);
      servo3.write(angulo_1.toInt());
      servo5.write(angulo_2.toInt());
      palabra="";
    }
  }
}
