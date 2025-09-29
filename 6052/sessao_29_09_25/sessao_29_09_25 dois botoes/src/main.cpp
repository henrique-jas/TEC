#include <Arduino.h>

const int BAUD_RATE=9600;
int botao1= 10;
int botao2= 12;
int led1= 2;
int led2= 4;

void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}
void loop()
{
  //enquanto pressionar no botao1
while (digitalRead(botao1)==LOW)
{
digitalWrite(led1,HIGH);
  //fim de curso linha esquerda
Serial.println("fim de curso linha da esquerda");
delay(500);
digitalWrite(led1,LOW);
}
  //enquanto pressionar no botao2
while (digitalRead(botao2)==LOW)
{
  digitalWrite(led2,HIGH);
  //fim de curso linha direita
  Serial.println("fim de curso linha da direita");
  delay(500);
  digitalWrite(led2,LOW);
}
}