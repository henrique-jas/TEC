#include <Arduino.h>

int BAUD_RATE=9600;

typedef struct Temporizador
{
  unsigned long int tempo_anterior;
  unsigned long int intervalo;
};

typedef struct Rele
{
  int estado;
  int periferico; 
  Temporizador temporizador;
};

Rele reles[3];

void setup()
{
  //definir perifericos 
  Serial.begin(BAUD_RATE);

  reles[0].temporizador.tempo_anterior=millis();

  reles[0].temporizador.intervalo=5000;

  reles[0].periferico=7; 
  
  reles[1].temporizador.tempo_anterior=millis();

  reles[1].temporizador.intervalo=10000;

  reles[1].periferico=8; 

  reles[2].temporizador.tempo_anterior=millis();

  reles[2].temporizador.intervalo=15000;

  reles[2].periferico=9; 

  pinMode(reles[0].periferico,OUTPUT);

  pinMode(reles[1].periferico, OUTPUT);

  pinMode(reles[2].periferico,OUTPUT);


}

void loop()
{
  //temporizador
  if(millis() - reles[0].temporizador.tempo_anterior > reles[0].temporizador.intervalo)
  {
    // ligar e desligar
    if(!digitalRead(reles[0].periferico))
    {
      // liga 
      digitalWrite(reles[0].periferico, HIGH);
      Serial.println("liga o rele1");
    }
    else
    {
      //desligar rele
      digitalWrite(reles[0].periferico,LOW);
      Serial.println("passaram 5s, desliga rele1");
    }

    // atualizar
    reles[0].temporizador.tempo_anterior=millis();
  }

  //temporizador
  if(millis() - reles[1].temporizador.tempo_anterior > reles[1].temporizador.intervalo)
  {
    // ligar e desligar
    if(!digitalRead(reles[1].periferico))
    {
      // liga 
      digitalWrite(reles[1].periferico, HIGH);
      Serial.println("liga o rele2");
    }
    else
    {
      //desligar rele
      digitalWrite(reles[1].periferico,LOW);
      Serial.println("passaram 10s, desliga rele2");
    }

    // atualizar
    reles[1].temporizador.tempo_anterior=millis();
  }

  //temporizador
  if(millis() - reles[2].temporizador.tempo_anterior > reles[2].temporizador.intervalo)
  {
    // ligar e desligar
    if(!digitalRead(reles[2].periferico))
    {
      // liga 
      digitalWrite(reles[2].periferico, HIGH);
      Serial.println("liga o rele3");
    }
    else
    {
      //desligar rele
      digitalWrite(reles[2].periferico,LOW);
      Serial.println("passaram 15s, desliga rele3");
    }

    // atualizar
    reles[2].temporizador.tempo_anterior=millis();
  }
}