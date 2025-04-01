const int trig = 3, echo = 2;
float dis = 0.0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  // pulse out
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  dis = pulseIn(echo, HIGH) / 58.0;
  dis = (int(dis * 100)) / 100;
  Serial.print(dis);
  Serial.println("cm");
  delay(200);
}
