#include <Arduino.h>
void setup()
{
  Serial.begin(115200);
}
void loop()
{
  Serial.println("Trabalho bem feito pelo formando");
  delay(2000);
  Serial.println("Quer dizer 10 flexões do formador");
  delay(2000);
}