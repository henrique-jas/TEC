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
rele rele2;
rele rele3;

void setup()
{
  //definir perifericos 
  Serial.begin(BAUD_RATE);

  rele1.temporizador.tempo_anterior=millis();

  rele1.temporizador.intervalo=5000;

  rele1.periferico=7; 
  
  rele2.temporizador.tempo_anterior=millis();

  rele2.temporizador.intervalo=10000;

  rele2.periferico=8; 

  rele3.temporizador.tempo_anterior=millis();

  rele3.temporizador.intervalo=15000;

  rele3.periferico=9; 

  pinMode(rele1.periferico,OUTPUT);

  pinMode(rele2.periferico, OUTPUT);

  pinMode(rele3.periferico,OUTPUT);


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

  //temporizador
  if(millis() - rele2.temporizador.tempo_anterior > rele2.temporizador.intervalo)
  {
    // ligar e desligar
    if(!digitalRead(rele2.periferico))
    {
      // liga 
      digitalWrite(rele2.periferico, HIGH);
      Serial.println("liga o rele2");
    }
    else
    {
      //desligar rele
      digitalWrite(rele2.periferico,LOW);
      Serial.println("passaram 10s, desliga rele2");
    }

    // atualizar
    rele2.temporizador.tempo_anterior=millis();
  }

  //temporizador
  if(millis() - rele3.temporizador.tempo_anterior > rele3.temporizador.intervalo)
  {
    // ligar e desligar
    if(!digitalRead(rele3.periferico))
    {
      // liga 
      digitalWrite(rele3.periferico, HIGH);
      Serial.println("liga o rele3");
    }
    else
    {
      //desligar rele
      digitalWrite(rele3.periferico,LOW);
      Serial.println("passaram 15s, desliga rele3");
    }

    // atualizar
    rele3.temporizador.tempo_anterior=millis();
  }
}