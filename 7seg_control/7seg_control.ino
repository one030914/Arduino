int seg[7] = {6, 7, 8, 9, 10, 11, 12}, pot = 0, ms = 1000, pot_v = 0, v = 0;

void setup() {
  for(int i = 0; i < sizeof(seg); i++){
    pinMode(seg[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // sequence
  // for(int i = 0; i < sizeof(seg); i++){
  //   digitalWrite(seg[i], LOW);
  //   delay(100);
  // }
  // for(int i = 0; i < sizeof(seg); i++){
  //   digitalWrite(seg[i], HIGH);
  //   delay(100);
  // }

  // pot control
  pot_v = analogRead(pot);
  v = map(pot_v, 0, 1010, 0, 9);
  switch(v){
    case 3:
      digital3();
      delay(100);
      break;
    case 5:
      digital5();
      delay(100);
      break;
    case 7:
      digital7();
      delay(100);
      break;
    case 9:
      digital9();
      delay(100);
      break;
    default:
      off();
      delay(100);
      break;
  }
}

void off(void){
  for(int i = 0; i < sizeof(seg); i++){
    digitalWrite(seg[i], HIGH);
  }
}

void digital0(void){
  for(int i = 0; i < 6; i++){
    digitalWrite(seg[i], LOW);
  }
  digitalWrite(seg[6], HIGH);
}

void digital1(void){
  digitalWrite(seg[0], HIGH);
  for(int i = 1; i < 3; i++){
    digitalWrite(seg[i], LOW);
  }
  for(int i = 3; i < sizeof(seg); i++){
    digitalWrite(seg[i], HIGH);
  }
}

void digital2(void){
  digitalWrite(seg[0], LOW);
  digitalWrite(seg[1], LOW);
  digitalWrite(seg[2], HIGH);
  digitalWrite(seg[3], LOW);
  digitalWrite(seg[4], LOW);
  digitalWrite(seg[5], HIGH);
  digitalWrite(seg[6], LOW);
}

void digital3(void){
  for(int i = 0; i < 4; i++){
    digitalWrite(seg[i], LOW);
  }
  for(int i = 4; i < 6; i++){
    digitalWrite(seg[i], HIGH);
  }
  digitalWrite(seg[6], LOW);
}

void digital4(void){
  digitalWrite(seg[0], HIGH);
  digitalWrite(seg[1], LOW);
  digitalWrite(seg[2], LOW);
  digitalWrite(seg[3], HIGH);
  digitalWrite(seg[4], HIGH);
  digitalWrite(seg[5], LOW);
  digitalWrite(seg[6], LOW);
}

void digital5(void){
  digitalWrite(seg[0], LOW);
  digitalWrite(seg[1], HIGH);
  digitalWrite(seg[2], LOW);
  digitalWrite(seg[3], LOW);
  digitalWrite(seg[4], HIGH);
  digitalWrite(seg[5], LOW);
  digitalWrite(seg[6], LOW);
}

void digital6(void){
  digitalWrite(seg[0], LOW);
  digitalWrite(seg[1], HIGH);
  for(int i = 2; i < sizeof(seg); i++){
    digitalWrite(seg[i], LOW);
  }
}

void digital7(void){
  for(int i = 0; i < 3; i++){
    digitalWrite(seg[i], LOW);
  }
  for(int i = 3; i < sizeof(seg); i++){
    digitalWrite(seg[i], HIGH);
  }
}

void digital8(void){
  for(int i = 0; i < sizeof(seg); i++){
    digitalWrite(seg[i], LOW);
  }
}

void digital9(void){
  for(int i = 0; i < 4; i++){
    digitalWrite(seg[i], LOW);
  }
  digitalWrite(seg[4], HIGH);
  digitalWrite(seg[5], LOW);
  digitalWrite(seg[6], LOW);
}