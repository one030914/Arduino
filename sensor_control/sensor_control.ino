const int trig = 3, echo = 2, led = 10;
float dis = 0.0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  dis = pulseIn(echo, HIGH) / 58.0;
  dis = (int(dis * 100)) / 100.0;
  Serial.print(dis);
  Serial.println("cm");
  if(int(dis) == 51){
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
  }
  delay(200);
}
