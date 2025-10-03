#include <Arduino.h>
// definir perifericos
int BAUD_RATE=9600;
//leds
int led_esquerda=3;
int led_direita=4;
//botoes
int botao_esquerda=10;
int botao_direita=12;
//switch case
int opcao=0;
//estado dos leds
int estadoled_esquerda=0;
int estadoled_direita=0;
//estado dos botoes
int estadobotao_esquerda=0;
int estadobotao_direita=0;

//criar uma função para os leds
void leds (int estadoled_esquerda, int estadoled_direita, String message)
{
Serial.println(message);
digitalWrite(led_esquerda, estadoled_esquerda);
digitalWrite(led_direita, estadoled_direita);
}
void setup()
{
// confirgurar perifericos e porta serie
Serial.begin(BAUD_RATE);
pinMode(botao_esquerda, INPUT);
pinMode(botao_direita, INPUT);
pinMode(led_esquerda, OUTPUT);
pinMode(led_direita, OUTPUT);
}


void loop()
{
estadobotao_esquerda = digitalRead(botao_esquerda)==LOW;
estadobotao_direita = digitalRead(botao_direita)==LOW;

// quando os dois botoes nao estiverem pressionados leds desligados
if (!estadobotao_esquerda&&!estadobotao_direita)
{
  opcao=0;
}

// quando o botao da esquerda tiver pressionado e o da direita nao liga o led da esquerda e delsiga o da direita
if(estadobotao_esquerda&&!estadobotao_direita)
{
  opcao=1;
}
//quando o botao da direita tiver pressionado e o da esquerda nao delsiga o led da esquerda e liga o da direita
if (!estadobotao_esquerda&&estadobotao_direita)
{
  opcao=2;
}

// quando ambos os botoes tiverem pressionado ambos o leds ligam
if(estadobotao_esquerda&&estadobotao_direita)
{
  opcao=3;
}

switch(opcao)
{
case 0:
leds(LOW,LOW,"leds desligados");
break;

case 1:
leds(HIGH,LOW, "led da esquerda ligado e o da direita desligado");
break;

case 2:
leds(LOW,HIGH, "led da esquerda desligado e o da direita ligado");
break;

case 3:
leds(HIGH,HIGH, "leds ligados");
break;

default:
Serial.print("error");
break;
}
delay(500);
}