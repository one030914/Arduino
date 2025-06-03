#include <Timer.h>
const int r = 11, g = 10, b = 9, vr = A0;
int vrValue = 0, value = 0, yr_counter = 0, table[6] = {-1, -1, -1, -1, -1, -1}, index = 0, rgb_index = 0, counter = 5;
int vr_show, rgb_show, last_rgb, clock;
Timer t;

void setup() {
  Serial.begin(9600);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(vr, INPUT);

  Serial.println("VR Start Reading...");
  clock = t.every(1000, Clock);
  vr_show = t.every(500, vrShow);
  rgb_show = t.every(500, rgbShow);
  t.after(3000, stop);
  t.after(10000, end);
}

void loop() {
  t.update();
}

void Clock(){
  Serial.print("Timer: ");
  Serial.print(millis() / 1000);
  Serial.println("s");
}

void vrShow(){
  vrValue = analogRead(vr);
  value = map(vrValue, 0, 1023, 1, 4);
  Serial.print("VR: ");
  Serial.print(vrValue);
  Serial.print(", After map: ");
  Serial.println(value);
  index = ++index % 6;
  table[index - 1] = value;
}

void rgbShow(){
  switch (value) {
    case 1:
      color(0, 255, 0);
      Serial.println("green");
      break;
    case 2:
      color(0, 0, 255);
      Serial.println("blue");
      break;
    case 3:
      color(255, 0, 255);
      Serial.println("purple");
      break;
    case 4:
      color(255, 0, 0);
      Serial.println("red");
      break;
    default:
      color(0, 0, 0);
      break;
  }
}

void stop(){
  Serial.println("VR Stop Reading...");
  t.stop(vr_show);
  t.stop(rgb_show);
  last_rgb = t.every(1000, lastRGB);
}

void lastRGB(){
  counter--;
  int index = table[counter];
  switch (index) {
    case 1:
      color(0, 255, 0);
      Serial.println("green");
      break;
    case 2:
      color(0, 0, 255);
      Serial.println("blue");
      break;
    case 3:
      color(255, 0, 255);
      Serial.println("purple");
      break;
    case 4:
      color(255, 0, 0);
      Serial.println("red");
      break;
    default:
      color(0, 0, 0);
      break;
  }
}

void end(){
  t.stop(last_rgb);
  t.stop(clock);
}

void color(unsigned char red, unsigned char green, unsigned char blue){
  analogWrite(r, red);
  analogWrite(g, green);
  analogWrite(b, blue);
}