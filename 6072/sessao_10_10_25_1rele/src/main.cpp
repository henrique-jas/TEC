#include <Arduino.h>

int BAUD_RATE=9600;

typedef struct Temporizador
{
  unsigned long int tempo_anterior;
  unsigned long int intervalo;
};

typedef struct rele
{
  int estado;
  int periferico; 
  Temporizador temporizador;
};

rele rele1;

void setup()
{
  //definir perifericos 
  Serial.begin(BAUD_RATE);

  rele1.temporizador.tempo_anterior=millis();

  rele1.temporizador.intervalo=5000;

  rele1.periferico=7; 

  pinMode(rele1.periferico,OUTPUT);

}

void loop()
{
  //temporizador
  if(millis() - rele1.temporizador.tempo_anterior > rele1.temporizador.intervalo)
  {
    // ligar e desligar
    if(!digitalRead(rele1.periferico))
    {
      // liga 
      digitalWrite(rele1.periferico, HIGH);
      Serial.println("liga o rele1");
    }
    else
    {
      //desligar rele
      digitalWrite(rele1.periferico,LOW);
      Serial.println("passaram 5s, desliga rele1");
    }

    // atualizar
    rele1.temporizador.tempo_anterior=millis();
  }
}