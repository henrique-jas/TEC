#include <Arduino.h>

int BAUD_RATE= 9600;
int led= 2;
int botao= 10;
void setup()
{ 
  Serial.begin(BAUD_RATE);
  pinMode(led,OUTPUT);
  pinMode(botao, INPUT);
}
void loop()
{
while (digitalRead(botao)==LOW)//pressionar o botao
{
  digitalWrite(led,HIGH); //ligar o led
  Serial.println("led ligado");
  delay(500);
}
digitalWrite(led, LOW);
Serial.println("led desligado");
delay(500);
}
