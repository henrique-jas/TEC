#include <Arduino.h>

int comecar_contagem=0;
unsigned long int tempo_anterior=0;
int BAUD_RATE=9600;
int botao = 4;
int led= 2;


void setup()
{
  //definir perifercos
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);

  digitalWrite(led,LOW);
  //definir porta série
  Serial.begin(BAUD_RATE);
}

void loop()
{
  

  //pressionar o botao
  if(digitalRead(botao)==LOW)
  {
    comecar_contagem=1;
    tempo_anterior=millis();
    Serial.println("pressiona botao");
  }

  if(comecar_contagem)
  {
    if(millis()-tempo_anterior>2000)
    {
      digitalWrite(led,HIGH);
      Serial.println("led liga");
      tempo_anterior=millis();
    }
  }
  
}