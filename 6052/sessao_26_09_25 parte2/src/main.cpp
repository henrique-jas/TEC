#include <Arduino.h>
const int pinBotao=12;
const int led=2;
const int BAUD_RATE= 9600;
void setup ()
{
  pinMode(pinBotao, INPUT);
pinMode(led, OUTPUT);
Serial.begin (BAUD_RATE);
}
void loop()
{
  Serial.println(digitalRead(pinBotao));
  //quando carregar no botao
  //ler botao
  if(digitalRead(pinBotao) == LOW)
  {
    digitalWrite(led, HIGH);
    Serial.println("Led ligou!");
  }
  else// quando nao pressionado o botao o led desliga
  {
    digitalWrite(led, LOW);
    Serial.println("Led desligou");
  }
  delay(1000);
}
