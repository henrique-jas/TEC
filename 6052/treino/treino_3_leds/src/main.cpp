#include <Arduino.h>

//definir perifericos
int BAUD_RATE=9600;
int botao_esquerda= 10;
int botao_direita= 12;
int led_esquerda=2;
int led_direita=4;
int led_meio=3;
int opcao=0;
int estadobotao_esquerda=0;
int estadobotao_direita=0;



int estadoled_esquerda=0;
int estadoled_direita=0;
int estadoled_meio=0;

void leds(int estadoled_esquerda, int estadoled_direita, int estadoled_meio, String message)
{
  Serial.println(message);
  digitalWrite(led_esquerda, estadoled_esquerda);
  digitalWrite(led_direita, estadoled_direita);
  digitalWrite(led_meio, estadoled_meio);
}

void setup()
{
//confirgurar perifericos e porta serie
Serial.begin(BAUD_RATE);
pinMode(botao_esquerda, INPUT);
pinMode(botao_direita, INPUT);
pinMode(led_direita, OUTPUT);
pinMode(led_esquerda,OUTPUT);
pinMode(led_meio, OUTPUT);
}

void loop()
{
 estadobotao_esquerda=digitalRead(botao_esquerda)==LOW;
 estadobotao_direita=digitalRead(botao_direita)==LOW;
  //quando nao se carrega nos dois botoes nao se liga os leds
if (!estadobotao_esquerda&&!estadobotao_direita)
{
  opcao=0;
}
//quando se carrega no botao da esquerda liga o led da esquerda
if (estadobotao_esquerda&&!estadobotao_direita)
{
  opcao=1;
}
//quando se carrega no led da direita liga o led da direita
if (!estadobotao_esquerda&&estadobotao_direita)
{
  opcao=2;
}
//quando se carrega nos dois botoes liga o led do meio
if (estadobotao_esquerda&&estadobotao_direita)
{
  opcao=3;
}

switch(opcao)
{
case 0:
leds(LOW,LOW,LOW,"leds desligados");
break;

case 1:
leds(HIGH,LOW,LOW, "led da esquerda ligado");
break;

case 2:
leds(LOW,LOW,HIGH, "led da diretia ligado");
break;

case 3:
leds(LOW,HIGH,LOW,"led do meio ligado");
break;

default:
Serial.println("error");
break;
}
delay(500);
}
