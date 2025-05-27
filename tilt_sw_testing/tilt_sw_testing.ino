const int sw = 1;

void setup() {
  pinMode(sw, INPUT);
  Serial.begin(9600);
}

void loop() {
  int i;
  while(1){
    i = analogRead(sw);
    Serial.println(i);
  }
}
