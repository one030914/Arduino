const int seg[7] = {6, 7, 8, 9, 10, 11, 12}, pot = 0;
int ms = 1000, pot_v = 0, v = 0;
bool mode = true; // Cathode is false, Anode is true.

void setup() {
  for(int i = 0; i < sizeof(seg); i++){
    pinMode(seg[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // sequence
  // for(int i = 0; i < sizeof(seg); i++){
  //   digitalWrite(seg[i], !mode);
  //   delay(100);
  // }
  // for(int i = 0; i < sizeof(seg); i++){
  //   digitalWrite(seg[i], mode);
  //   delay(100);
  // }

  // pot control
  pot_v = analogRead(pot);
  v = map(pot_v, 0, 1010, 0, 9);
  switch(v){
    case 3:
      digital3(mode);
      delay(100);
      break;
    case 5:
      digital5(mode);
      delay(100);
      break;
    case 7:
      digital7(mode);
      delay(100);
      break;
    case 9:
      digital9(mode);
      delay(100);
      break;
    default:
      off(mode);
      delay(100);
      break;
  }
}

void off(bool mode){
  for(int i = 0; i < sizeof(seg); i++){
    digitalWrite(seg[i], mode);
  }
}

void digital0(bool mode){
  for(int i = 0; i < 6; i++){
    digitalWrite(seg[i], !mode);
  }
  digitalWrite(seg[6], mode);
}

void digital1(bool mode){
  digitalWrite(seg[0], mode);
  for(int i = 1; i < 3; i++){
    digitalWrite(seg[i], !mode);
  }
  for(int i = 3; i < sizeof(seg); i++){
    digitalWrite(seg[i], mode);
  }
}

void digital2(bool mode){
  digitalWrite(seg[0], !mode);
  digitalWrite(seg[1], !mode);
  digitalWrite(seg[2], mode);
  digitalWrite(seg[3], !mode);
  digitalWrite(seg[4], !mode);
  digitalWrite(seg[5], mode);
  digitalWrite(seg[6], !mode);
}

void digital3(bool mode){
  for(int i = 0; i < 4; i++){
    digitalWrite(seg[i], !mode);
  }
  for(int i = 4; i < 6; i++){
    digitalWrite(seg[i], mode);
  }
  digitalWrite(seg[6], !mode);
}

void digital4(bool mode){
  digitalWrite(seg[0], mode);
  digitalWrite(seg[1], !mode);
  digitalWrite(seg[2], !mode);
  digitalWrite(seg[3], mode);
  digitalWrite(seg[4], mode);
  digitalWrite(seg[5], !mode);
  digitalWrite(seg[6], !mode);
}

void digital5(bool mode){
  digitalWrite(seg[0], !mode);
  digitalWrite(seg[1], mode);
  digitalWrite(seg[2], !mode);
  digitalWrite(seg[3], !mode);
  digitalWrite(seg[4], mode);
  digitalWrite(seg[5], !mode);
  digitalWrite(seg[6], !mode);
}

void digital6(bool mode){
  digitalWrite(seg[0], !mode);
  digitalWrite(seg[1], mode);
  for(int i = 2; i < sizeof(seg); i++){
    digitalWrite(seg[i], !mode);
  }
}

void digital7(bool mode){
  for(int i = 0; i < 3; i++){
    digitalWrite(seg[i], !mode);
  }
  for(int i = 3; i < sizeof(seg); i++){
    digitalWrite(seg[i], mode);
  }
}

void digital8(bool mode){
  for(int i = 0; i < sizeof(seg); i++){
    digitalWrite(seg[i], !mode);
  }
}

void digital9(bool mode){
  for(int i = 0; i < 4; i++){
    digitalWrite(seg[i], !mode);
  }
  digitalWrite(seg[4], mode);
  digitalWrite(seg[5], !mode);
  digitalWrite(seg[6], !mode);
}