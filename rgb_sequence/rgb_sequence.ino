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
  // RGB LED sequence.
  if(++r > 255){
    r--;
  }else if(--r < 0){
    r++;
  }
  a_r = 256 % ++r;
  if(a_r / 256 > 0.5){
    a_g = 256 % ++g;
  }
  if(a_g / 256 > 0.5){
    a_b = 256 % ++b;
  }
  color(a_r, a_g, a_b);
  delay(100);
}

void color(unsigned char r, unsigned char g, unsigned char b){
  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);
}