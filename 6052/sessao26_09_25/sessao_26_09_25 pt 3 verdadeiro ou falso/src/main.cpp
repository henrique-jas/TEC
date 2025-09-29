#include <Arduino.h>
const int teste = 01;
void setup()
{
  pinMode(teste,OUTPUT);
  Serial.begin(9600);
}
void loop ()
{
  
if (teste)
{
Serial.println("verdadeiro");
}
else
{
Serial.println("falso");
}
delay(1000);
}