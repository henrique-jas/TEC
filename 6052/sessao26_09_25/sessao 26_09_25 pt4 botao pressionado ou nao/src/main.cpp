#include <Arduino.h>
const int Baud_Rate = 9600;
const int botao = 10;
const int led = 2;

void setup()
{
  Serial.begin(Baud_Rate);
  pinMode(led, OUTPUT);
  pinMode(botao,INPUT);
}

void loop ()
{
  if(digitalRead(botao)==LOW)
  {
    digitalWrite(led, HIGH);
    Serial.println( "botao pressionado");
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.println("botao nao pressionado");
  }
  delay(500);

}
