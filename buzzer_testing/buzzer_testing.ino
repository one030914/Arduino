const int buz = 6;

void setup() {
  pinMode(buz, OUTPUT);
}

void loop() {
  while(1){
    char i, j;
    for(i = 0; i < 80; i++){
      digitalWrite(buz, HIGH);
      delay(1);
      digitalWrite(buz, LOW);
      delay(1);
    }
    for(j = 0; j < 100; j++){
      digitalWrite(buz, HIGH);
      delay(2);
      digitalWrite(buz, LOW);
      delay(2);
    }
  }
}
