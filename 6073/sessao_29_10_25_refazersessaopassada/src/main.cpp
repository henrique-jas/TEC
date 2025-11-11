#include <Arduino.h>

int index=0;
int opcao=0;

typedef enum eBotoes
{
  cima_b=0,
  direita_b,
  baixo_b,
  esquerda_b,
  total_b,

};

typedef struct Botao
{
  int estado;
  int periferico;
};
Botao botoes[total_b];

typedef enum eLeds
{
  cima_l=0,
  direita_l,
  baixo_l,
  esquerda_l,
  total_l,
};

typedef struct Led
{
  int estado;
  int periferico;
};

Led leds[total_l];

typedef enum Opcao
{
  CIMA=1,
  DIREITA=2,
  BAIXO=4,
  ESQUERDA=8,
  
  
  //nao fazer nada
      // fazer_nada=0,
   
  //funções unicas
      // liga_cima,
      // liga_direita,
      // liga_baixo,
      // liga_esquerda,
  //funções duplas
      // liga_cima_direita,
      // liga_direita_baixo,
      // liga_baixo_esquerda,
      // liga_esquerda_cima,
      // liga_cima_baixo,
      // liga_esquerda_direita,
  //funções triplas
      // liga_cima_direita_baixo,
      // liga_direita_baixo_esquerda,
      // liga_baixo_esquerda_cima,
      // liga_esquerda_cima_direita,
  //ligatodos
      // liga_todos,
};

void luz(int cima, int direita, int baixo, int esquerda)
{
  digitalWrite(leds[cima_l].periferico, cima);
  digitalWrite(leds[direita_l].periferico, direita);
  digitalWrite(leds[baixo_l].periferico, baixo);
  digitalWrite(leds[esquerda_l].periferico, esquerda);
}



void setup()
{
  Serial.begin(9600);

  botoes[cima_b].periferico=2;
  botoes[direita_b].periferico=3;
  botoes[baixo_b].periferico=4;
  botoes[esquerda_b].periferico=5;

  leds[cima_l].periferico=8;
  leds[direita_l].periferico=9;
  leds[baixo_l].periferico=10;
  leds[esquerda_l].periferico=11;
  
  while(index<total_b)
  {
    botoes[index].estado==LOW;
    pinMode(botoes[index].periferico,INPUT); 
    index++;
  }

  while(index<total_l)
  {
    leds[index].estado==LOW;
    pinMode(leds[index].periferico, OUTPUT);
    index++;
  }
}

void loop()
{
  opcao=0; // inicializar em fazer nada
  
  index = 0;
  while(index<total_b)
  {
    //ler botoes 
    botoes[index].estado = !digitalRead(botoes[index].periferico);
    Serial.print(botoes[index].estado);
    index++;
  }
  Serial.println();
  
  if(botoes[cima_b].estado)           //neste caso a opcao=opcao+1 porque estando o botao
  {                                   //cima na posicao 0 o numero binario seria 2 elevado
    opcao = opcao + CIMA;             //a 0 que é 1 e assim será consecutivamente.   
    Serial.println("botao de cima pressionado");
  }

  if(botoes[direita_b].estado)        //neste caso a opcao=opcao+1 porque estando o botao
  {                                   //cima na posicao 0 o numero binario seria 2 elevado
    opcao = opcao + DIREITA;          //a 1 que é 2 e assim será consecutivamente.   
    Serial.println("botao de direita pressionado");
  }

  if(botoes[baixo_b].estado)          //neste caso a opcao=opcao+1 porque estando o botao
  {                                   //cima na posicao 0 o numero binario seria 2 elevado
    opcao = opcao + BAIXO;            //a 2 que é 4 e assim será consecutivamente.  
    Serial.println("botao de baixo pressionado");
  }

  if(botoes[esquerda_b].estado)       //neste caso a opcao=opcao+1 porque estando o botao
  {                                   //cima na posicao 0 o numero binario seria 2 elevado
    opcao = opcao + ESQUERDA;         //a 3 que é 8.  
    Serial.println("botao de esquerda pressionado");
  }

  // testar botoes estao pressionados                      
  // if (!botoes[cima_b].estado &&
  //     !botoes[direita_b].estado &&
  //     !botoes[baixo_b].estado &&
  //     !botoes[esquerda_b].estado )
  // {
  //   opcao= fazer_nada;
  // }

  //  if (botoes[cima_b].estado &&
  //     !botoes[direita_b].estado &&
  //     !botoes[baixo_b].estado &&
  //     !botoes[esquerda_b].estado )
  // {
  //   opcao= liga_cima;
  // }
   
  //  if (!botoes[cima_b].estado &&
  //     botoes[direita_b].estado &&
  //     !botoes[baixo_b].estado &&
  //     !botoes[esquerda_b].estado )
  // {
  //   opcao= liga_direita;
  // }

  //  if (!botoes[cima_b].estado &&
  //     !botoes[direita_b].estado &&
  //     botoes[baixo_b].estado &&
  //     !botoes[esquerda_b].estado )
  // {
  //   opcao= liga_baixo;
  // }

  //  if (!botoes[cima_b].estado &&
  //     !botoes[direita_b].estado &&
  //     !botoes[baixo_b].estado &&
  //     botoes[esquerda_b].estado )
  // {
  //   opcao= liga_esquerda;
  // }
  
  //  if (botoes[cima_b].estado &&
  //     botoes[direita_b].estado &&
  //     !botoes[baixo_b].estado &&
  //     !botoes[esquerda_b].estado )
  // {
  //   opcao= liga_cima_direita;
  // }

  //  if (!botoes[cima_b].estado &&
  //    botoes[direita_b].estado &&
  //     botoes[baixo_b].estado &&
  //     !botoes[esquerda_b].estado )
  // {
  //   opcao= liga_direita_baixo;
  // }

  //  if (botoes[cima_b].estado &&
  //     !botoes[direita_b].estado &&
  //     botoes[baixo_b].estado &&
  //     botoes[esquerda_b].estado )
  // {
  //   opcao= liga_baixo_esquerda;
  // }

  //  if (botoes[cima_b].estado &&
  //     !botoes[direita_b].estado &&
  //     !botoes[baixo_b].estado &&
  //     botoes[esquerda_b].estado )
  // {
  //   opcao= liga_esquerda_cima;
  // }

  //  if (botoes[cima_b].estado &&
  //     !botoes[direita_b].estado &&
  //     botoes[baixo_b].estado &&
  //     !botoes[esquerda_b].estado )
  // {
  //   opcao= liga_cima_baixo;
  // }

  //  if (!botoes[cima_b].estado &&
  //     botoes[direita_b].estado &&
  //     !botoes[baixo_b].estado &&
  //     botoes[esquerda_b].estado )
  // {
  //   opcao= liga_esquerda_direita;
  // }
  
  // if (botoes[cima_b].estado &&
  //     botoes[direita_b].estado &&
  //     botoes[baixo_b].estado &&
  //     !botoes[esquerda_b].estado )
  // {
  //   opcao= liga_cima_direita_baixo;
  // }
  
  // if (!botoes[cima_b].estado &&
  //     botoes[direita_b].estado &&
  //     botoes[baixo_b].estado &&
  //     botoes[esquerda_b].estado )
  // {
  //   opcao= liga_direita_baixo_esquerda;
  // }

  // if (botoes[cima_b].estado &&
  //     !botoes[direita_b].estado &&
  //     botoes[baixo_b].estado &&
  //     botoes[esquerda_b].estado )
  // {
  //   opcao= liga_baixo_esquerda_cima;
  // }

  // if (botoes[cima_b].estado &&
  //     botoes[direita_b].estado &&
  //     !botoes[baixo_b].estado &&
  //     botoes[esquerda_b].estado )
  // {
  //   opcao= liga_esquerda_cima_direita;
  // }

  // if (botoes[cima_b].estado &&
  //     botoes[direita_b].estado &&
  //     botoes[baixo_b].estado &&
  //     botoes[esquerda_b].estado )
  // {
  //   opcao= liga_todos;
  // }
  
  //selecionar opcao
  switch (opcao)
  {
    case 0:
    luz(LOW,LOW,LOW,LOW);
    break;

    case CIMA:
    luz(HIGH,LOW,LOW,LOW);
    break;

    case DIREITA:
    luz(LOW,HIGH,LOW,LOW);
    break;

    case BAIXO:
    luz(LOW,LOW,HIGH,LOW);
    break;

    case ESQUERDA:
    luz(LOW,LOW,LOW,HIGH);
    break;
  
    case CIMA + DIREITA:
    luz(HIGH,HIGH,LOW,LOW);
    break;

    case DIREITA + BAIXO:
    luz(LOW,HIGH,HIGH,LOW);
    break;

    case BAIXO + ESQUERDA:
    luz(LOW,LOW,HIGH,HIGH);
    break;

    case ESQUERDA + CIMA:
    luz(HIGH,LOW,LOW,HIGH);
    break;

    case CIMA + BAIXO:
    luz(HIGH,LOW,HIGH,LOW);
    break;

    case ESQUERDA + DIREITA:
    luz(LOW,HIGH,LOW,HIGH);
    break;

    case CIMA + DIREITA + BAIXO:
    luz(HIGH,HIGH,HIGH,LOW);
    break;

    case DIREITA + BAIXO + ESQUERDA:
    luz(LOW,HIGH,HIGH,HIGH);
    break;

    case BAIXO + ESQUERDA + CIMA:
    luz(HIGH,LOW,HIGH,HIGH);
    break;

    case ESQUERDA + CIMA + DIREITA:
    luz(HIGH,HIGH,LOW,HIGH);
    break;

    case CIMA + DIREITA + BAIXO + ESQUERDA:
    luz(HIGH,HIGH,HIGH,HIGH);
    break;
    
    default:
    Serial.println("ERROR");
    break;
  }
  delay(100);
}