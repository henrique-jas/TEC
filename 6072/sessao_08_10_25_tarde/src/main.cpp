#include <Arduino.h>

int BAUD_RATE =9600;
unsigned long int tempo_atual=0;
unsigned long int tempo_anterior=0;
int led1=2;
int led2=4;
unsigned long int tempo_atual2=0;
unsigned long int tempo_anterior2=0;


void setup()
{
    Serial.begin(BAUD_RATE);
    pinMode(led1, OUTPUT);
    pinMode(led2,OUTPUT);
}

void loop()
{
tempo_atual=millis();
if (tempo_atual - tempo_anterior > 1000)
{
    Serial.print("tempo atual -");
    Serial.println(tempo_atual);

    Serial.print("tempo anterior -");
    Serial.println(tempo_anterior);

    if(digitalRead(led1)==LOW)
    {
        digitalWrite(led1, HIGH);
    }
    else
    {
        digitalWrite(led1,LOW);
    }
    
    tempo_anterior=millis();
}


tempo_atual2=millis();

    if (tempo_atual2 - tempo_anterior2 > 2000)
    {
        if (digitalRead(led2)==LOW)
        {
            digitalWrite(led2,HIGH);
        }
        else
        {
            digitalWrite(led2,LOW);
        }
        tempo_anterior2=millis();
    }
}

