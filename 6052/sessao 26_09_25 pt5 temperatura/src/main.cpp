#include <Arduino.h>

int BAUD_RATE=9600;
int temperatura_max=22;
int temperatura_lida= 8;
int temperatura_min=12;
int botao= 2;
int led= 10;
void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(botao,INPUT);
  pinMode(led,OUTPUT);
}
void loop()
{
  if (digitalRead(botao)==LOW)
  {
    digitalWrite(led,HIGH);
    Serial.println("led ligado");
    Serial.println("botao pressionado");
  }
  else
  {
    digitalWrite(led,LOW);
    Serial.println("led desligado");
    Serial.println("botao não pressionado");
  }
  if(temperatura_lida>=temperatura_max)
  {
  Serial.println("ligar ventoinha");
  }
  else
  {
  Serial.println("desligar ventoinha");
  }
  if (temperatura_lida<=temperatura_min)
  {
    Serial.println("ligar ac");
  }
  else
  {
    Serial.println("desligar ac");
  }

delay(3000);
}