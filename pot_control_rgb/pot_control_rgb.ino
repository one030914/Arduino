int red = 11, green = 10, blue = 9, res = 0;
int res_v = 0.0, value = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  res_v = analogRead(res);
  value = map(res_v, 0, 1023, 1, 4);
  switch(value){
    case 1:
      color(255, 0, 0);
      delay(50);
      Serial.println("Red");
      break;
    case 2:
      color(0, 255, 0);
      delay(50);
      Serial.println("Green");
      break;
    case 3:
      color(0, 0, 255);
      delay(50);
      Serial.println("Blue");
      break;
    case 4:
      color(255, 255, 0);
      delay(50);
      Serial.println("Yellow");
      break;
  }
}

void color(unsigned char r, unsigned char g, unsigned char b){
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}