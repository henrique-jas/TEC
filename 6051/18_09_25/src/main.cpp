#include <Arduino.h>
int periferico = 11;

void setup()
{
  pinMode (periferico, OUTPUT); // Configurar os Leds
  pinMode (12, OUTPUT); 
  pinMode (13, OUTPUT); 
}
 
void loop() // ciclo
{
  digitalWrite(periferico, HIGH);
  digitalWrite(13, HIGH); // Ligar led 11
  digitalWrite(12, LOW); // desligar led 7

  delay(1000); // esperar 1s

  digitalWrite(periferico, LOW);
  digitalWrite(13, LOW); 
  digitalWrite(12, HIGH);

  delay(1000);
}