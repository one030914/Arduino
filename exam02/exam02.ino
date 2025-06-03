#include <Timer.h>
const int r = 11, g = 10, b = 9, vr = A0;
int vrValue = 0, value = 0, yr_counter = 0, table[6] = {-1, -1, -1, -1, -1, -1}, index = 0, rgb_index = 0, counter = 0;
int vr_show, yr, vr_read, rgb_show, last_rgb;
Timer t;

void setup() {
  Serial.begin(9600);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(vr, INPUT);

  vr_show = t.every(1000, vrShow);
  yr = t.every(500, YR);
  t.after(5000, vrStop);
  t.after(10000, rgbStop);
  t.after(16000, stop);
}

void loop() {
  t.update();
}

void YR(){
  yr_counter = yr_counter++ % 2 + 1;
  switch (yr_counter) {
    case 1:
      color(255, 255, 0);
      break;
    case 2:
      color(255, 0, 0);
      break;
    default:
      color(0, 0, 0);
      break;
  }
}

void vrShow(){
  vrValue = analogRead(vr);
  value = map(vrValue, 0, 1023, 1, 4);
  Serial.print("Timer: ");
  Serial.print(millis() / 1000);
  Serial.print(" s=> VR: ");
  Serial.print(vrValue);
  Serial.print(", After map: ");
  Serial.println(value);
}

void vrStop(){
  Serial.println("VR Start Reading...");
  t.stop(vr_show);
  t.stop(yr);
  vr_read = t.every(1000, vrRead);
  rgb_show = t.every(1000, rgbShow);
}

void vrRead(){
  vrShow();
  index = ++index % 6;
  table[index - 1] = value;
}

void rgbShow(){
  rgb_index = ++rgb_index % 6;
  int index = table[rgb_index - 1];
  switch (index) {
    case 0:
      color(128, 0, 255);
      break;
    case 1:
      color(255, 255, 0);
      break;
    case 2:
      color(255, 255, 255);
      break;
    case 3:
      color(0, 0, 255);
      break;
    case 4:
      color(0, 255, 0);
      break;
    default:
      color(0, 0, 0);
      break;
  }
}

void rgbStop(){
  Serial.println("VR Stop Reading...");
  t.stop(vr_read);
  t.stop(rgb_show);
  last_rgb = t.every(2000, lastRGB);
}

void lastRGB(){
  counter = counter % 3 + 1;
  int index = table[counter + 2];
  switch (index) {
    case 0:
      color(128, 0, 255);
      break;
    case 1:
      color(255, 255, 0);
      break;
    case 2:
      color(255, 255, 255);
      break;
    case 3:
      color(0, 0, 255);
      break;
    case 4:
      color(0, 255, 0);
      break;
    default:
      color(0, 0, 0);
      break;
  }
}

void stop(){
  t.stop(last_rgb);
}

void color(unsigned char red, unsigned char green, unsigned char blue){
  analogWrite(r, red);
  analogWrite(g, green);
  analogWrite(b, blue);
}