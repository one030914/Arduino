#include <Timer.h>

Timer t;
const int LDR = 0, sw = 1, buz = 8;
int music;
char i;

void setup() {
  pinMode(LDR, INPUT);
  pinMode(sw, INPUT);
  pinMode(buz, OUTPUT);
  Serial.begin(9600);

  t.every(1000, timer);
  music = t.every(1, play);
  t.after(5000, stop);
}

void loop() {
  t.update();
}

void timer(){
  Serial.print(millis() / 1000);
  Serial.println(" seconds.");
}

void play(){
  for(i = 0; i < 80; i++){
    digitalWrite(buz, HIGH);
    delay(1);
    digitalWrite(buz, LOW);
    delay(1);
  }
  for(i = 0; i < 100; i++){
    digitalWrite(buz, HIGH);
    delay(2);
    digitalWrite(buz, LOW);
    delay(2);
  }
}

void stop(){
  t.every(200, sensor);
}

void sensor(){
  int sw_v, ldr_v;
  sw_v = analogRead(sw);
  ldr_v = analogRead(LDR);
  // Serial.println(sw_v);
  // Serial.println(ldr_v);

  if(sw_v < 512){
    t.stop(music);
  }
  if(ldr_v < 512 && sw_v > 512){
    music = t.every(1, play);
  }
}