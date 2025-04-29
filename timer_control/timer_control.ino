#include "Timer.h"

Timer t;
const int pin = 13, r = 9, g = 10, b = 11;
int count = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  t.oscillate(pin, 100, LOW);
  t.every(3000, takeReading);
  t.every(1000, led_sequence);
}

void loop()
{
  t.update();
}

void takeReading()
{
  Serial.println(count++);
}

void led_sequence(){
  digitalWrite(r, HIGH);
  delay(200);
  digitalWrite(r, LOW);
  digitalWrite(g, HIGH);
  delay(200);
  digitalWrite(g, LOW);
  digitalWrite(b, HIGH);
  delay(200);
  digitalWrite(b, LOW);
}
