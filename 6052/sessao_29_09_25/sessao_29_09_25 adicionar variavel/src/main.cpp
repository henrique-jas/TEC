#include <Arduino.h>
const int BAUD_RATE=9600;
int botao= 10;
int tempo_pressionado=0;

void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(botao, INPUT);
}
void loop()
{
while (digitalRead(botao)==LOW)
{
 Serial.println("adicionar +1");
 delay(500);
}

}