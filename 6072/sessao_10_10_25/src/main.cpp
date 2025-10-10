#include <Arduino.h>
//configurar variaveis
int BAUD_RATE=9600;
typedef struct sensor_temperatura
{
int valor;
int periferico;
unsigned long int tempo_anterior;
unsigned long int intervalo;
};
sensor_temperatura sensor1;
sensor_temperatura sensor2;
sensor_temperatura sensor3;
sensor_temperatura sensor4;


void setup()
{
//definir perifericos e series
Serial.begin(BAUD_RATE);

sensor1.intervalo = 4000;
sensor2.intervalo = 4200;
sensor3.intervalo = 4400;
sensor4.intervalo = 4600;

//leitura millis
sensor1.tempo_anterior = millis();
sensor2.tempo_anterior = millis();
sensor3.tempo_anterior = millis();
sensor4.tempo_anterior = millis();
}
void loop()
{
  if(millis()-sensor1.tempo_anterior >sensor1.intervalo)
  {
    Serial.println("ola, eu sou o Henrique");
    sensor1.tempo_anterior=millis();
  }

  if(millis()-sensor2.tempo_anterior > sensor2.intervalo)
  {
    Serial.println("ola, eu sou o Gonçalo");
    sensor2.tempo_anterior=millis();
  }
  if(millis()-sensor3.tempo_anterior > sensor3.intervalo)
  {
    Serial.println("Ola, eu sou o Gaspar");
    sensor3.tempo_anterior=millis();
  }
  if(millis()-sensor4.tempo_anterior > sensor4.intervalo)
  {
    Serial.println("e somos AMIGAS 4EVER");
    sensor4.tempo_anterior=millis();
  }
}