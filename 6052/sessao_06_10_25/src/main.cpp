#include <Arduino.h>
int opcao= 0;

typedef struct Botao
{
  int periferico;
  int estado;
};

Botao botao_esquerda;
Botao botao_direita;

typedef struct Leds
{
  int periferico;
};

Leds led_esquerda;
Leds led_direita;

int estadoled_esquerdo=0;
int estadoled_direito=0;
void leds (int left_pin, int right_pin, String message)
{
  Serial.println(message);
  digitalWrite(led_esquerda.periferico, estadoled_esquerdo);  // Usa o pino global e o estado passado
  digitalWrite(led_direita.periferico, estadoled_direito); 
}


void setup()
{
  botao_esquerda.periferico=10;
  botao_direita.periferico=12;
  led_esquerda.periferico=2;
  led_direita.periferico=3;

  pinMode(botao_esquerda.periferico, INPUT);
  pinMode(botao_direita.periferico, INPUT);
  pinMode(led_esquerda.periferico,OUTPUT);
  pinMode(led_direita.periferico, OUTPUT);

}

void loop()
{
botao_direita.estado=digitalRead(botao_direita.periferico);
botao_esquerda.estado=digitalRead(botao_esquerda.periferico);

if(!botao_esquerda.estado && !botao_direita.estado)
{
  opcao=0;
}

if(botao_esquerda.estado && !botao_direita.estado)
{
  opcao=1;
}

if(!botao_esquerda.estado && botao_direita.estado)
{
  opcao=2;
}

if (botao_esquerda.estado && botao_direita.estado)
{
  opcao=3;
}

switch (opcao)
{
case 0:
leds(LOW,LOW, "leds desligados");
break;

case 1:
leds(HIGH,LOW,"led da esquerda ligado");
break;

case 2:
leds(LOW,HIGH, "led da direita ligado");
break;

case 3:
leds(HIGH,HIGH, "leds ligados");
break;

default:
Serial.println("ERROR");
break;
}

}
