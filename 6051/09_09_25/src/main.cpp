#include <Arduino.h>
void setup()
{
pinMode(13, OUTPUT); // configurar o pin 13 como saída
pinMode(12, OUTPUT);
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(4, OUTPUT);
}


void loop()
{
digitalWrite(13, HIGH); // ligar o pin 13, no caso o led
digitalWrite(12, HIGH);
digitalWrite(8,HIGH);
digitalWrite(7, HIGH);
digitalWrite(4, HIGH);
delay(1000);
digitalWrite(13, LOW); // desligar o pin 13, no caso o led
digitalWrite(12,LOW);
digitalWrite(8,LOW);
digitalWrite(7,LOW);
digitalWrite(4,LOW);
delay(1000);
}