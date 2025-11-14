#include <OneWire.h>
#include <Arduino.h>

// Código do sensor de temperatura OneWire (DS18B20)
// Nota: Mudei o pino do OneWire de 2 para 12 para evitar conflito com o botão CIMA_B (que usa pino 2).
#define ONE_WIRE_BUS 13
OneWire ds(ONE_WIRE_BUS);

// Pino do buzzer
#define BUZZER_PIN 7

// Função para obter temperatura
float getTemp() 
{
    byte data[9], addr[8];

    if (!ds.search(addr)) 
    {
        ds.reset_search();
        return -1000;
    }

    if (OneWire::crc8(addr, 7) != addr[7]) return -1000;
    if (addr[0] != 0x28) return -1000;

    ds.reset();
    ds.select(addr);
    ds.write(0x44, 1);
    delay(750);
    ds.reset();
    ds.select(addr);
    ds.write(0xBE);

    for (int i = 0; i < 9; i++) data[i] = ds.read();
    ds.reset_search();

    int16_t raw = (data[1] << 8) | data[0];
    return (float)raw / 16.0;
}

// Código dos LEDs e botões
int opcao = 0;
int estado = 0;

typedef enum eLed
{
  CIMA_L = 0,
  DIREITA_L,
  BAIXO_L,
  ESQUERDA_L,
  TOTAL_L
};

typedef enum eBotao
{
  CIMA_B = 0,
  DIREITA_B,
  BAIXO_B,
  ESQUERDA_B,
  TOTAL_B
};

int index = 0;

typedef struct Led
{
  int estado;
  int periferico;
};
Led leds[TOTAL_L];

typedef struct Botao
{
  int estado;
  int periferico;
};
Botao botoes[TOTAL_B];

typedef enum OPCAO
{
  FAZER_NADA = 0,
  CIMA = 1,
  DIREITA = 2,
  BAIXO = 4,
  ESQUERDA = 8,
  TODOS = 16,
};
OPCAO opcoes = FAZER_NADA;

void ledsi(int cima, int direita, int baixo, int esquerda)
{
  digitalWrite(leds[0].periferico, cima);
  digitalWrite(leds[1].periferico, direita);
  digitalWrite(leds[2].periferico, baixo);
  digitalWrite(leds[3].periferico, esquerda);
}

void setup()
{
  Serial.begin(9600);

  // Configuração dos LEDs
  leds[CIMA_L].periferico = 8;
  leds[DIREITA_L].periferico = 9;
  leds[BAIXO_L].periferico = 10;
  leds[ESQUERDA_L].periferico = 11;

  // Configuração dos botões
  botoes[CIMA_B].periferico = 2;
  botoes[DIREITA_B].periferico = 3;
  botoes[BAIXO_B].periferico = 4;
  botoes[ESQUERDA_B].periferico = 5;

  // Configuração do buzzer
  pinMode(BUZZER_PIN, OUTPUT);

  index = 0;
  while (index < TOTAL_B)
  {
    botoes[index].estado == LOW; 
    leds[index].estado == LOW;    
    pinMode(botoes[index].periferico, INPUT);
    pinMode(leds[index].periferico, OUTPUT);
    index++;
  }
}

void loop() 
{
  // Lógica do sensor de temperatura
  float t = getTemp();
  Serial.print("Temperatura: ");
  Serial.println(t);

  // Lógica do buzzer: ativa se temperatura > 23°C
  if (t > 23.0) {
    tone(BUZZER_PIN, 2000);  // Toca um tom de 1000 Hz
  } else {
    noTone(BUZZER_PIN);  // Para o som
  }

  // Lógica dos LEDs e botões
  index = 0;
  opcao = 0; 
  // Ler botões
  while (index < TOTAL_B) 
  {
    botoes[index].estado = !digitalRead(botoes[index].periferico);
    index++;
  }
  Serial.println();  // Nova linha após imprimir estados dos botões

  if (botoes[CIMA_B].estado)          
  {
    opcao = opcao + 1;
  }

  if (botoes[DIREITA_B].estado)
  {
    opcao = opcao + 2;
  }

  if (botoes[BAIXO_B].estado)
  {
    opcao = opcao + 4;
  }

  if (botoes[ESQUERDA_B].estado)
  {
    opcao = opcao + 8;
  }

  switch (opcao)
  {
    case FAZER_NADA:
      ledsi(LOW, LOW, LOW, LOW);
      Serial.println("nenhum led ligado");
      break;
    
    case CIMA:
      ledsi(HIGH, LOW, LOW, LOW);
      Serial.println("LIGA CIMA");
      break;

    case DIREITA:
      ledsi(LOW, HIGH, LOW, LOW);
      Serial.println("LIGA DIREITA");
      break;

    case BAIXO:
      ledsi(LOW, LOW, HIGH, LOW);
      Serial.println("LIGA BAIXO");
      break;

    case ESQUERDA:
      ledsi(LOW, LOW, LOW, HIGH);
      Serial.println("LIGA ESQUERDA");
      break;

    case CIMA + DIREITA:
      ledsi(HIGH, HIGH, LOW, LOW);
      Serial.println("LIGA CIMA_DIREITA");
      break;

    case CIMA + BAIXO:
      ledsi(HIGH, LOW, HIGH, LOW);
      Serial.println("LIGA CIMA_BAIXO");
      break;

    case CIMA + ESQUERDA:
      ledsi(HIGH, LOW, LOW, HIGH);
      Serial.println("LIGA CIMA_ESQUERDA");
      break;

    case BAIXO + DIREITA:
      ledsi(LOW, HIGH, HIGH, LOW);
      Serial.println("LIGA BAIXO_DIREITA");
      break;

    case BAIXO + ESQUERDA:
      ledsi(LOW, LOW, HIGH, HIGH);
      Serial.println("LIGA BAIXO_ESQUERDA");
      break;

    case DIREITA + ESQUERDA:
      ledsi(LOW, HIGH, LOW, HIGH);
      Serial.println("LIGA DIREITA_ESQUERDA");
      break;

    case CIMA + DIREITA + BAIXO:
      ledsi(HIGH, HIGH, HIGH, LOW);
      Serial.println("LIGA CIMA_DIREITA_BAIXO");
      break;

    case CIMA + DIREITA + ESQUERDA:
      ledsi(HIGH, HIGH, LOW, HIGH);
      Serial.println("LIGA CIMA_DIREITA_ESQUERDA");
      break;
      
    case CIMA + BAIXO + ESQUERDA:
      ledsi(HIGH, LOW, HIGH, HIGH);
      Serial.println("LIGA CIMA_BAIXO_ESQUERDA");
      break;

    case BAIXO + DIREITA + ESQUERDA:
      ledsi(LOW, HIGH, HIGH, HIGH);
      Serial.println("LIGA BAIXO_DIREITA_ESQUERDA");
      break;

    case TODOS:
      ledsi(HIGH, HIGH, HIGH, HIGH);
      Serial.println("TODOS LIGADOS");
      break;

    default:
      Serial.println("erro");
      break;
  }

  // Delay combinado: usei 500ms para equilibrar entre a leitura de temp (750ms interno) e botões (100ms original)
  delay(500);
}
