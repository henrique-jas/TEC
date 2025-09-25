#include <Arduino.h>
int rele = 7;
int rele_2 = 8;
int tempo = 2000;
int botao = 2;
int estado_1 = HIGH;
int estado_2 = LOW;


void setup()
{
  pinMode(rele, OUTPUT);
  pinMode(rele_2, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}
void loop()
{
  if(digitalRead(botao)==estado_1)
  {
    tempo = 500;
  }
  else
  {
    tempo=2000;
  }

  digitalWrite(rele, estado_1);
  digitalWrite(rele_2, estado_1);
  
  delay(tempo);

  digitalWrite(rele, estado_2);
  digitalWrite(rele_2, estado_2);

  delay(tempo);
  
}
