#include <Arduino.h>


int BAUD_RATE=9600;
int opcao=0;


//definir structs
typedef struct Botao
{
  int periferico;
  int estado;
};

Botao botao_cima;
Botao botao_direita;
Botao botao_baixo;
Botao botao_esquerda;

void Setas(String message)
{
  Serial.println(message);
}

void setup()
{
  // configurar perifericos
  botao_cima.periferico=4;
  botao_direita.periferico=5;
  botao_baixo.periferico=6;
  botao_esquerda.periferico=7;

  pinMode(botao_cima.periferico, INPUT);
  pinMode(botao_direita.periferico, INPUT);
  pinMode(botao_baixo.periferico, INPUT);
  pinMode(botao_esquerda.periferico, INPUT);
  //configurar porta serie
 Serial.begin(BAUD_RATE);
}


void loop()
{
  botao_cima.estado = !digitalRead(botao_cima.periferico);
  botao_direita.estado = !digitalRead(botao_direita.periferico);
  botao_baixo.estado = !digitalRead(botao_baixo.periferico);
  botao_esquerda.estado = !digitalRead(botao_esquerda.periferico);
  
  //quando nenhum botao pressionado nenhuma seta aparece
if (!botao_cima.estado && !botao_direita.estado && !botao_baixo.estado && !botao_esquerda.estado)
{
  opcao=0;
}

  //quando so pressionado o botao 1 "seta para cima"
if(botao_cima.estado && !botao_direita.estado && !botao_baixo.estado && !botao_esquerda.estado)
{
  opcao=1;
}
  //quando pressionado so botap 2 "seta direita"
if(!botao_cima.estado && botao_direita.estado && !botao_baixo.estado && !botao_esquerda.estado)
{
  opcao=2;
}
  //quando pressionado so botao 3 "seta para baixo"
if(!botao_cima.estado && !botao_direita.estado && botao_baixo.estado && !botao_esquerda.estado)
{
  opcao=3;
}
  // quando pressionado so o botao 4 "seta para a esquerda"
if(!botao_cima.estado && !botao_direita.estado && !botao_baixo.estado && botao_esquerda.estado)
{
  opcao=4;
}
  //quando pressionaod o botao 1 e 2 "seta diagonal superior para direita"
if(botao_cima.estado && botao_direita.estado && !botao_baixo.estado && !botao_esquerda.estado)
{
  opcao=5;
}
  //quando pressionado botao 1 e 4 "seta diagonal superior para esquerda"
if(botao_cima.estado && !botao_direita.estado && !botao_baixo.estado && botao_esquerda.estado)
{
  opcao=6;
}
//quando pressionado botao 2 e 3 "seta diagonal inferior para direita"
if(!botao_cima.estado && botao_direita.estado && botao_baixo.estado && !botao_esquerda.estado)
{
  opcao=7;
}
  //quando pressionado botao 3 e 4 "seta diagonal inferior para esquerda"
if(!botao_cima.estado && !botao_direita.estado && botao_baixo.estado && botao_esquerda.estado)
{
  opcao=8;
}

switch(opcao)
{
  case 0:
  Setas("100setas");
  break;

  case 1:
  Setas("↑");
  break;

  case 2:
  Setas("→");
  break;

  case 3:
  Setas("↓");
  break;

  case 4:
  Setas("←");
  break;

  case 5:
  Setas("↗");
  break;

  case 6:
  Setas("↖");
  break;

  case 7:
  Setas("↘");
  break;

  case 8:
  Setas("↙");
  break;

  default:
  Serial.println("ERROR");
  break;

}
  delay(500);
}