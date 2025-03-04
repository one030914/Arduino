int led = 13, red = 11, green = 10, blue = 9; // pins
int r = 0, g = 0, b = 0; // color
unsigned char a_r = 0, a_g = 0, a_b = 0;
int count[6] = {0, 0, 0, 0, 0, 0};
int cmd = 0;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Serial control RGB LED.
  while(count[0] != 1 || count[1] != 1 || count[2] != 1 || count[3] != 1 || count[4] != 1 || count[5] != 1){
  // for(int i = 0; i < 6; i++){
    cmd = Serial.read();
    switch(cmd){
      case 'R':
        color(255, 0, 0); // 紅色亮
        delay(1000); // 延時一秒
        Serial.println("Red");
        count[0] = 1;
        break;
      case 'G':
        color(0,255, 0); //綠色亮
        delay(1000); //延時一秒
        Serial.println("Green");
        count[1] = 1;
        break;
      case 'B':
        color(0, 0, 255); // 藍色燈亮  
        delay(1000); //延時一秒
        Serial.println("Blue");
        count[2] = 1;
        break;
      case 'Y':
        color(255,255,0); // 黃色  
        delay(1000); //延時一秒
        Serial.println("Yellow");
        count[3] = 1;
        break;
      case 'P':
        color(128,0,255); // 紫色  
        delay(1000); //延時一秒
        Serial.println("Purple");
        count[4] = 1;
        break;
      case 'W':
        color(255,255,255); // 白色  
        delay(1000); //延時一秒
        Serial.println("White");
        count[5] = 1;
        break;
      case 'I':
        color(0,0,0);
        delay(100);
        Serial.println("OFF");
    }
  }
  color(0,0,0); // t關閉led  
  delay(1000); //延時一秒
  Serial.println("OFF");
}

void color(unsigned char r, unsigned char g, unsigned char b){
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}