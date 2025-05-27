const int LDR = 0;
int val = 0;

void setup() {
  pinMode(LDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(LDR);
  Serial.println(val);
}
