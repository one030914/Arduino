int red = 10, green = 11, blue = 12, btn = 7;
int state = 0, count = 0;
int r = 0, g = 0, b = 0;

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(btn, INPUT);
  Serial.begin(9600);
}

void loop() {
  state = digitalRead(btn);
  if(state == HIGH){
    delay(200);
    count = count++ % 5 + 1;
    switch (count) {
      case 1:
        color(255, 0, 0); // 紅色亮
        break;
      case 2:
        color(0, 0, 255); // 藍色燈亮
        break;
      case 3:
        color(255,255,0); // 黃色
        break;
      case 4:
        color(255,255,255); // 白色
        break;
      case 5:
        color(128,0,255); // 紫色  
        break;
      default:
        color(0,0,0);
        break;
    }
  }
}

void color(unsigned char r, unsigned char g, unsigned char b){
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}