#include <Arduino.h>
int BAUD_RATE = 9600;
int led = 2;
int botao = 4;
unsigned long int tempo_atual = 0;
unsigned long int tempo_anterior = 0;
void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);  
  pinMode(botao, INPUT); 
 
}
void loop() 
{
  int estado_botao = !digitalRead(botao);  
  // Se botão pressionado, acende e inicia a contar
  if (estado_botao && digitalRead(led) == LOW) {
    digitalWrite(led, HIGH);
    tempo_anterior = millis();  
    Serial.println("Botao pressionado! LED aceso por 30s.");
  }
  // Se LED aceso
  if (digitalRead(led) == HIGH) {
    tempo_atual = millis();
    if (tempo_atual - tempo_anterior > 30000) {  // 30 segundos
      digitalWrite(led, LOW);
      Serial.println("30s acabaram! LED apagado.");
    }
  }
}
  

  



  
  

