#include <Arduino.h>
int BAUD_RATE=9600;
int botao_arranque_1= 1;
int botao_arranque_2= 0;
int sobrecarga=0;
int temperatura_max= 20;
int temperatura_lida= 21;
void setup()
{
  Serial.begin(BAUD_RATE);
}

void loop()
{
  if(botao_arranque_1 && botao_arranque_2)
  {
    Serial.println("ligar maquina");
  }
  else
  {
    Serial.println("desligar maquina");
  }
  if((temperatura_lida>temperatura_max) || sobrecarga)
  {
    Serial.println("desligar maquina");
  }
  else
  {
    Serial.println("lugar maquina");
  }
  delay(1000);

}
