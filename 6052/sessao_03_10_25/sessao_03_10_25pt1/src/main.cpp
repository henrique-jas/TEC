#include <Arduino.h>

const int BAUD_RATE=9600;
int botao1=10;
int botao2=12;
int led1=3;
int led2=4;
int estado_do_botao1=0;
int estado_do_botao2=0;
int opcao=0;



// void leds_desligam()
// {
//   Serial.println("leds desligados");
//   digitalWrite(led1,LOW);
//   digitalWrite(led2,LOW);
// }
// void led1_liga()
// {
//   Serial.println("led da esquerda liga");
//   digitalWrite(led1,HIGH);
//   digitalWrite(led2,LOW);
// }
// void led2_liga()
// {
//   Serial.println("led da direita liga");
//   digitalWrite(led1,LOW);
//   digitalWrite(led2,HIGH);
// }
// void leds_ligam()
// {
//   Serial.println("leds ligados");
//   digitalWrite(led1,HIGH);
//   digitalWrite(led2,HIGH);
// }
int estado_led1=0;
int estado_led2=0;

void leds(int estado_led1, int estado_led2, String message)
{
  Serial.println(message);
  digitalWrite(led1, estado_led1);
  digitalWrite(led2, estado_led2);
}
void setup()
{
  Serial.begin(BAUD_RATE);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(botao1,INPUT);
  pinMode(botao2,INPUT);
}

void loop()
{
  estado_do_botao1= digitalRead(botao1)==LOW;
  estado_do_botao2= digitalRead(botao2)==LOW;
  if (!estado_do_botao1&&!estado_do_botao2)
  {
    opcao=0;
  }
  
  if (estado_do_botao1&&!estado_do_botao2)
  {
    opcao=1;
  }
  
  if (!estado_do_botao1&&estado_do_botao2)
  {
    opcao=2;
  }

  if (estado_do_botao1&&estado_do_botao2)
  {
    opcao=3;
  }
  
  switch (opcao)
  {
  case 0:
    leds(LOW,LOW,"desligados");
    break;
  
    case 1:
    leds(HIGH,LOW, "led esquerda ligado");
    break;

    case 2:
    leds(LOW,HIGH,"led direita ligado");
    break;

    case 3:
    leds(HIGH,HIGH,"ligados");
    break;

  default:
  Serial.println("error");
    break;
  }
  // switch(opcao)
  // {
  // case 0:
  //   leds_desligam();
  //   break;
  // case 1:
  //   led1_liga();
  //   break;
  // case 2:
  //   led2_liga();
  //   break;
  // case 3:
  //   leds_ligam();
  //   break;  

  // default:
  // Serial.println("erro");
  //   break;
  // }
  delay(500);

}