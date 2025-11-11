#include <Arduino.h>
int BAUD_RATE=9600;
int index = 0;

//Definir Enum
typedef enum eBotoes
{
  nenhum_b = 0,
  cima_b,
  direita_b,
  esquerda_b,
  baixo_b,
  TOTAL_b
};


typedef enum leds
{
  nenhum_l = 0,
  cima_l,
  direita_l,
  esquerda_l,
  baixo_l,
  TOTAL_l
};

typedef enum Opcao
{
  fazer_nada = 0,
  LED_cima_liga,
  LED_direita_liga,
  LED_esquerda_liga,
  LED_baixo_liga,
  LED_cima_baixo_liga,
  LED_direita_esquerda_liga,
  LED_cima_direita_liga,
  LED_cima_esquerda_liga,
  LED_baixo_direita_liga,
  LED_baixo_esquerda_liga,
  LED_cima_direita_esquerda_liga,
  LED_baixo_direita_esquerda_liga,
  LED_cima_direita_baixo_liga,
  LED_cima_esquerda_baixo_liga,
  LED_todos_ligados

  
};

Opcao opcao=fazer_nada;

//Definir Struct
typedef struct Botoes
{
  int estado;
  int periferico;
};
Botoes Botao  [TOTAL_b];


typedef struct LEDs
{
  int estado;
  int periferico;
};
LEDs led [TOTAL_l];

//Função para acender os LEDs
void leds(int cima, int direita, int esquerda, int baixo)
{
  digitalWrite(led [0].periferico, cima);
  digitalWrite(led [1].periferico, direita);
  digitalWrite(led [2].periferico, esquerda);
  digitalWrite(led [3].periferico, baixo);

}

void setup() 
{
  Serial.begin(BAUD_RATE);
  //enquanto indice for menor que 4
  while(index < 4)
  {
    
    Botao [index].estado = LOW;
    pinMode(index, INPUT); 
    pinMode(index, OUTPUT); 
    index++;
  }


//Definir Portas
Botao [0].periferico = 7; //Botao Cima
Botao [1].periferico = 8; //Botao Direita
Botao [2].periferico = 9; //Botao Esquerda
Botao [3].periferico = 10; //Botao Baixo




led [0].periferico = 3; //LED Cima
led [1].periferico = 4; //LED Direita
led [2].periferico = 5; //LED Esquerda
led [3].periferico = 6; //LED Baixo

}

void loop() 
{
  //leitura dos Botoes
  //enquanto indice for menor que 4
  index = 0;
  while(index < 4)
  {
    Botao[index].estado = !digitalRead(Botao [index].periferico); //Leitura Botao Cima
    index++;
  }

if 
(
  !Botao[cima_b].estado &&
  !Botao[direita_b].estado &&
  !Botao[esquerda_b].estado &&
  !Botao[baixo_b].estado
) 

{
 opcao= fazer_nada;
}

if 
(
   Botao[cima_b].estado &&
  !Botao[direita_b].estado &&
  !Botao[esquerda_b].estado &&
  !Botao[baixo_b].estado
) 
{
  opcao=LED_cima_liga; 
}

if 
(
  !Botao[cima_b].estado &&
   Botao[direita_b].estado &&
  !Botao[esquerda_b].estado &&
  !Botao[baixo_b].estado
) 
{
  opcao=LED_direita_liga;
}

if 
(
  !Botao[cima_b].estado &&
  !Botao[direita_b].estado &&
   Botao[esquerda_b].estado &&
  !Botao[baixo_b].estado
) 
{
  opcao=LED_esquerda_liga;
}

if 
(
  !Botao[cima_b].estado &&
  !Botao[direita_b].estado &&
  !Botao[esquerda_b].estado &&
   Botao[baixo_b].estado
) 
{
  opcao=LED_baixo_liga;
}

if 
(
   Botao[cima_b].estado &&
  !Botao[direita_b].estado &&
  !Botao[esquerda_b].estado &&
   Botao[baixo_b].estado
) 
{
  opcao= LED_cima_baixo_liga; 
}

if 
(
  !Botao[cima_b].estado &&
   Botao[direita_b].estado &&
   Botao[esquerda_b].estado &&
  !Botao[baixo_b].estado
) 
{
  opcao=LED_direita_esquerda_liga;
}

if 
(
   Botao[cima_b].estado &&
   Botao[direita_b].estado &&
  !Botao[esquerda_b].estado &&
  !Botao[baixo_b].estado
) 
{
  opcao=LED_cima_direita_liga;
}

if 
(
   Botao[cima_b].estado &&
  !Botao[direita_b].estado &&
   Botao[esquerda_b].estado &&
  !Botao[baixo_b].estado
) 
{
  opcao=LED_cima_esquerda_liga;
}

if 
(
  !Botao[cima_b].estado &&
   Botao[direita_b].estado &&
  !Botao[esquerda_b].estado &&
   Botao[baixo_b].estado
) 
{
  opcao=LED_baixo_direita_liga;
}

if
(
  !Botao[cima_b].estado &&
  !Botao[direita_b].estado &&
   Botao[esquerda_b].estado &&
   Botao[baixo_b].estado
) 
{
  opcao=LED_baixo_esquerda_liga;
}

if
(
   Botao[cima_b].estado &&
   Botao[direita_b].estado &&
   Botao[esquerda_b].estado &&
  !Botao[baixo_b].estado
) 
{
  opcao=LED_cima_direita_esquerda_liga;
}

if (
  !Botao[cima_b].estado &&
   Botao[direita_b].estado &&
   Botao[esquerda_b].estado &&
   Botao[baixo_b].estado
) 
{
  opcao=LED_baixo_direita_esquerda_liga;
}

if (
   Botao[cima_b].estado &&
   Botao[direita_b].estado &&
  !Botao[esquerda_b].estado &&
   Botao[baixo_b].estado
) 
{
  opcao=LED_cima_direita_baixo_liga;
}

if (
   Botao[cima_b].estado &&
  !Botao[direita_b].estado &&
   Botao[esquerda_b].estado &&
   Botao[baixo_b].estado
) 
{
  opcao=LED_cima_esquerda_baixo_liga;
}

if (
  Botao[cima_b].estado &&
  Botao[direita_b].estado &&
  Botao[esquerda_b].estado &&
  Botao[baixo_b].estado
) 
{ 
  opcao=LED_todos_ligados;
}

  //Definir Opcao
  opcao= fazer_nada;


  //Definir Switchs e seus casos
  switch (opcao)
  {
  
    case fazer_nada:
    leds(LOW, LOW, LOW, LOW);
    Serial.println("Nenhum LED ligado");
    break;
  
    case LED_cima_liga:
    leds(HIGH, LOW, LOW, LOW);
    Serial.println("LED Cima ligado");
    break;

    case LED_direita_liga:
    leds(LOW, HIGH, LOW, LOW);
    Serial.println("LED Direita ligado");
    break;

    case LED_esquerda_liga:
    leds(LOW, LOW, HIGH, LOW);
    Serial.println("LED Esquerda ligado");
    break;

    case LED_baixo_liga:
    leds(LOW, LOW, LOW, HIGH);
    Serial.println("LED Baixo ligado");
    break;

    case LED_cima_baixo_liga:
    leds(HIGH, LOW, LOW, HIGH);
    Serial.println("LED Cima e Baixo ligados");
    break;

    case LED_direita_esquerda_liga:
    leds(LOW, HIGH, HIGH, LOW);
    Serial.println("LED Direita e Esquerda ligados");
    break;

    case LED_cima_direita_liga:
    leds(HIGH, HIGH, LOW, LOW);
    Serial.println("LED Cima e Direita ligados");
    break;

    case LED_cima_esquerda_liga:
    leds(HIGH, LOW, HIGH, LOW);
    Serial.println("LED Cima e Esquerda ligados");
    break;

    case LED_baixo_direita_liga:
    leds(LOW, HIGH, LOW, HIGH);
    Serial.println("LED Baixo e Direita ligados");
    break;

    case LED_baixo_esquerda_liga:
    leds(LOW, LOW, HIGH, HIGH);
    Serial.println("LED Baixo e Esquerda ligados");
    break;

    case LED_cima_direita_esquerda_liga:
    leds(HIGH, HIGH, HIGH, LOW);
    Serial.println("LED Cima, Direita e Esquerda ligados");
    break;

    case LED_baixo_direita_esquerda_liga:
    leds(LOW, HIGH, HIGH, HIGH);
    Serial.println("LED Baixo, Direita e Esquerda ligados");
    break;

    case LED_cima_direita_baixo_liga:
    leds(HIGH, HIGH, LOW, HIGH);
    Serial.println("LED Cima, Direita e Baixo ligados");
    break;

    case LED_cima_esquerda_baixo_liga:
    leds(HIGH, LOW, HIGH, HIGH);
    Serial.println("LED Cima, Esquerda e Baixo ligados");
    break;

    case LED_todos_ligados:
    leds(HIGH, HIGH, HIGH, HIGH);
    Serial.println("Todos os LEDs ligados");
    break;
  }
  delay(500);

}
