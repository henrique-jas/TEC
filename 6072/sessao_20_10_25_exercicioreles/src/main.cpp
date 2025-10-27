#include <Arduino.h>

#define NUMERO_DE_COMPONENTES 3

#define CONTACTOR_LEITURA 4
int BAUD_RATE=9600;
//criar struct de reles
typedef struct Rele
{
  int periferico;
  int valor;
};

Rele reles[NUMERO_DE_COMPONENTES];
//criar struct de botoes
typedef struct Botao
{
  int periferico;
  int estado;
};

Botao botoes[NUMERO_DE_COMPONENTES];

int contar=0;

void setup()
{
   pinMode(CONTACTOR_LEITURA, INPUT);
  //configurar porta serie
  Serial.begin(BAUD_RATE);
 
  // configurar botoes
  botoes[0].periferico = 2;
  //botoes[1].periferico = 3;
  //botoes[2].periferico = 4;

  //configurar reles
  reles[0].periferico = 5;
  //reles[1].periferico = 6;
  //reles[2].periferico = 7;


  // inicializar index
  contar=0;
  // enquanto houver botoes e reles, inicializar o periferico como entrada
  while(contar<NUMERO_DE_COMPONENTES)
  {
    //definir valor do estado dos botoes
    botoes[contar].estado=0;
    //definir valor dos reles
    reles[contar].valor=0;
    
    // configurar entrada botoes
    pinMode(botoes[contar].periferico, INPUT);
    
    //configurar entrada reles 
    pinMode(reles[contar].periferico, OUTPUT);

    //incrementar index
    contar++;
  }
  
}
void loop()
{
  contar=0;
  while(contar<NUMERO_DE_COMPONENTES)
  {
    botoes[contar].estado = !digitalRead(botoes[contar].periferico);
    
    if(botoes[contar].estado)
    {
      Serial.println("botao pressionado");
      reles[contar].valor=HIGH;
      digitalWrite(reles[contar].periferico,reles[contar].valor);
      Serial.println("reles ativados");
    }
    else
    {
      Serial.println("botao nao pressionado");
      reles[contar].valor=LOW;
      digitalWrite(reles[contar].periferico,reles[contar].valor);
      Serial.println("reles desativados");
    }

    contar++;
  }
  Serial.println(CONTACTOR_LEITURA);
  delay(500);
}