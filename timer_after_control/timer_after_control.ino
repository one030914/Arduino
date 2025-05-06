#include <Event.h>
#include <Timer.h>

Timer t;
const int r = 11, g = 10, b = 9;
int counter = 0, ypg;

void setup() {
  Serial.begin(9600);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);

  t.every(1000, Timer);
  ypg = t.every(500, YPG);
  t.after(10000, After);
}

void loop() {
  t.update();
}

void Timer(){
  Serial.print("Timer: ");
  Serial.print(millis() / 1000);
  Serial.println("s");
}

void YPG(){
  counter = counter++ % 3 + 1;
  switch (counter) {
    case 1:
      color(255, 255, 0);
      break;
    case 2:
      color(128, 0, 255);
      break;
    case 3:
      color(0, 255, 0);
      break;
    default:
      color(0, 0, 0);
      break;
  }
}

void BRW(){
  counter = counter++ % 3 + 1;
  switch (counter) {
    case 1:
      color(0, 0, 255);
      break;
    case 2:
      color(255, 0, 0);
      break;
    case 3:
      color(255, 255, 255);
      break;
    default:
      color(0, 0, 0);
      break;
  }
}

void After(){
  Serial.println("Changing Color...");
  t.stop(ypg);
  t.every(2000, BRW);
}

void color(unsigned char red, unsigned char green, unsigned char blue){
  analogWrite(r, red);
  analogWrite(g, green);
  analogWrite(b, blue);
}