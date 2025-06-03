#include <Timer.h>

Timer t;
const int r = 11, g = 10, b = 9, abtn = 6, bbtn = 5;
int a_state = 0, b_state = 0, counter = 0, len = 0, table[6] = {-1, -1, -1, -1, -1, -1}, value = 0;
int clock = 0, show = 0, input = 0;

void setup() {
  Serial.begin(9600);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(abtn, INPUT);
  pinMode(bbtn, INPUT);

  input = t.every(1, Input);
  // clock = t.after(3000, Clock);
}

void loop() {
  t.update();
}

void Input(){
  a_state = digitalRead(abtn);
  b_state = digitalRead(bbtn);
  if (a_state == HIGH) {
    delay(200);
    color(255,255,255);
    value = 1;
    counter++;
    len++;
    // t.stop(clock);
  }else if (b_state == HIGH) {
    delay(200);
    color(255,255,0);
    value = 2;
    counter++;
    len++;
    // t.stop(clock);
  }
  // else{
  //   clock = t.after(3000, Clock);
  // }
  // Serial.println(counter);
  table[counter] = value;
  if(counter == 6){
    Pulse();
  }
}

// void Clock(){
//   Serial.println("time over");
//   show = t.every(1000, Show);
// }

void Pulse(){
  t.stop(input);
  show = t.every(1000, Show);
}

void Show(){
  counter = counter % len + 1;
  value = table[counter];
  switch (value) {
    case 1:
      color(255,255,255);
      Serial.println("white");
      break;
    case 2:
      color(255,255,0);
      Serial.println("yellow");
      break;
    default:
      color(0, 0, 0);
      break;
  }
}

void color(unsigned char red, unsigned char green, unsigned char blue){
  analogWrite(r, red);
  analogWrite(g, green);
  analogWrite(b, blue);
}