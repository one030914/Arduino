int seg[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // 7 segment pins.
int d1 = 10, d2 = 11, d3 = 12, d4 = 13; // Digit pins.
bool mode = true; // Cathode is false, Anode is true.

void setup() {
  for(int i = 0; i < sizeof(seg); i++){
    pinMode(seg[i], OUTPUT);
  }
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Display(1, 0);
  Display(2, 6);
  Display(3, 7);
  Display(4, 9);
}

void Display(unsigned char x, unsigned char Number) // 顯示x為座標，Number為數字
{
  Select(x);
  pickNumber(Number);
  delay(1);
  off(mode);
}

void Select(unsigned char n)//
{
  switch(n){
	  case 1: 
      digitalWrite(d1, LOW);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, HIGH);   
      break;
    case 2: 
      digitalWrite(d1, HIGH);
      digitalWrite(d2, LOW);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, HIGH); 
      break;
    case 3: 
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, LOW);
      digitalWrite(d4, HIGH); 
      break;
    case 4: 
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, LOW); 
      break;
    default :
      digitalWrite(d1, HIGH);
      digitalWrite(d2, HIGH);
      digitalWrite(d3, HIGH);
      digitalWrite(d4, HIGH);
      break;
	}
}

void pickNumber(unsigned char n){
  switch(n){
    case 0:
      digital0(mode);
      break;
    case 1:
      digital1(mode);
      break;
    case 2:
      digital2(mode);
      break;
    case 3:
      digital3(mode);
      break;
    case 4:
      digital4(mode);
      break;
    case 5:
      digital5(mode);
      break;
    case 6:
      digital6(mode);
      break;
    case 7:
      digital7(mode);
      break;
    case 8:
      digital8(mode);
      break;
    case 9:
      digital9(mode);
      break;
    default:
      off(mode);
      break; 
  }
}

void off(bool mode){
  for(int i = 0; i < sizeof(seg); i++){
    digitalWrite(seg[i], !mode);
  }
}

void digital0(bool mode){
  for(int i = 0; i < 6; i++){
    digitalWrite(seg[i], mode);
  }
  digitalWrite(seg[6], !mode);
  digitalWrite(seg[7], !mode);
}

void digital1(bool mode){
  digitalWrite(seg[0], !mode);
  for(int i = 1; i < 3; i++){
    digitalWrite(seg[i], mode);
  }
  for(int i = 3; i < sizeof(seg); i++){
    digitalWrite(seg[i], !mode);
  }
}

void digital2(bool mode){
  digitalWrite(seg[0], mode);
  digitalWrite(seg[1], mode);
  digitalWrite(seg[2], !mode);
  digitalWrite(seg[3], mode);
  digitalWrite(seg[4], mode);
  digitalWrite(seg[5], !mode);
  digitalWrite(seg[6], mode);
  digitalWrite(seg[7], !mode);
}

void digital3(bool mode){
  for(int i = 0; i < 4; i++){
    digitalWrite(seg[i], mode);
  }
  for(int i = 4; i < 6; i++){
    digitalWrite(seg[i], !mode);
  }
  digitalWrite(seg[6], mode);
  digitalWrite(seg[7], !mode);
}

void digital4(bool mode){
  digitalWrite(seg[0], !mode);
  digitalWrite(seg[1], mode);
  digitalWrite(seg[2], mode);
  digitalWrite(seg[3], !mode);
  digitalWrite(seg[4], !mode);
  digitalWrite(seg[5], mode);
  digitalWrite(seg[6], mode);
  digitalWrite(seg[7], !mode);
}

void digital5(bool mode){
  digitalWrite(seg[0], mode);
  digitalWrite(seg[1], !mode);
  digitalWrite(seg[2], mode);
  digitalWrite(seg[3], mode);
  digitalWrite(seg[4], !mode);
  digitalWrite(seg[5], mode);
  digitalWrite(seg[6], mode);
  digitalWrite(seg[7], !mode);
}

void digital6(bool mode){
  digitalWrite(seg[0], mode);
  digitalWrite(seg[1], !mode);
  for(int i = 2; i < sizeof(seg); i++){
    digitalWrite(seg[i], mode);
  }
}

void digital7(bool mode){
  for(int i = 0; i < 3; i++){
    digitalWrite(seg[i], mode);
  }
  for(int i = 3; i < sizeof(seg); i++){
    digitalWrite(seg[i], !mode);
  }
}

void digital8(bool mode){
  for(int i = 0; i < 7; i++){
    digitalWrite(seg[i], mode);
  }
  digitalWrite(seg[7], !mode);
}

void digital9(bool mode){
  for(int i = 0; i < 4; i++){
    digitalWrite(seg[i], mode);
  }
  digitalWrite(seg[4], !mode);
  digitalWrite(seg[5], mode);
  digitalWrite(seg[6], mode);
  digitalWrite(seg[7], !mode);
}