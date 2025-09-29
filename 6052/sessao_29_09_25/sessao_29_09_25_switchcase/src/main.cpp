#include <Arduino.h>


const int BAUD_RATE=9600;
int botao1= 10;
int botao2=12;
int opcao= 4;
int led1= 3;
int led2=4;

void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(botao1, INPUT);
  pinMode (botao2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop()
{
  if (digitalRead(botao1)==LOW)
  {
    opcao= 1;
  }

  

  if (digitalRead(botao2)==LOW)
  {
    opcao=3;
  }

  if (digitalRead(botao2)==LOW && digitalRead(botao1)==LOW)
  {
    opcao=2;
  }

  if (digitalRead(botao2)==HIGH && digitalRead(botao1)==HIGH)
  {
    opcao=4;
  }

  switch(opcao)
  {
  case 1: 
  Serial.println("led da esquerda liga");
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);

  break;

  case 2:
  Serial.println("os dois leds ligam");
  
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
  break;
  
  case 3:
  Serial.println("led da direita liga");
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);

  break;

    case 4:
    Serial.println("nenhum liga");
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);

    break;

  default:
  Serial.println("esta opção não existe");
  break;

}
delay(500);

}