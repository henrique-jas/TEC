#include <Arduino.h>

//definir perifericos
int BAUD_RATE=9600;
int botao_esquerda= 10;
int botao_direita= 12;
int led_1= 2;

int estado_led=0;

int estadobotao_esquerda=0;
int estadobotao_direita=0;

int opcao=0;
void led (int estado_led, String message)
{
  Serial.println(message);
  digitalWrite(led_1, estado_led);
}

void setup()
{
  //confirgurar perifericos e porta serie
  Serial.begin(BAUD_RATE);
  pinMode(botao_esquerda, INPUT);
  pinMode(botao_direita, INPUT);
  pinMode(led_1,OUTPUT);

}
void loop()
{
  estadobotao_esquerda=digitalRead(botao_esquerda)==LOW;
  estadobotao_direita=digitalRead(botao_direita)==LOW;
  // quando os dois botoes nao estiverem pressionados o led nao liga
if(!estadobotao_esquerda&&!estadobotao_direita)
{
  opcao=0;
}
  // quando o botao esquerdo estiver pressionado liga o led 
if(estadobotao_esquerda&&!estadobotao_direita)
{
  opcao=1;
}  

  // quando o botao da direita estiver pressionado o led direita pisca
if (!estadobotao_esquerda&&estadobotao_direita)
{
  opcao=2;
}

switch (opcao)
{
  case 0:
  led(LOW, "led desligado");
  break;

  case 1:
  led(HIGH,"led liga");
  break;

  case 2:
    if(estado_led)
    {
      led(LOW, "led pisca");
      estado_led=LOW;
    }
    else
    {
      led(HIGH, "led pisca");
      estado_led=HIGH;
    }
    
  break;

  default:
  Serial.println("error");
  break;
}

  delay(500);
}

