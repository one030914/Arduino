int led1 = 10, led2 = 11, pot = 0, potval = 0, val = 0, input = 0;
bool left = false, right = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  potval = analogRead(pot);
  val = map(potval, 0, 1023, 1, 15);
  switch (val){
    case 1:
    case 8:
    case 9:
      left = false;
      right = false;
      break;
    case 2:
    case 3:
    case 10:
    case 11:
      left = false;
      right = true;
      break;
    case 4:
    case 5:
    case 12:
    case 13:
      left = true;
      right = false;
      break;
    case 6:
    case 7:
    case 14:
    case 15:
      left = true;
      right = true;
      break;
    default:
      left = false;
      right = false;
      break;
  }
  input = Serial.read();
  if(input == 'x'){
    Serial.print("value: ");
    Serial.println(val);
    delay(100);
  }else if(input == 'y'){
    Serial.println(right);
    digitalWrite(led2, right);
    delay(100);
  }else if(input == 'z'){
    Serial.println(left);
    digitalWrite(led1, left);
    delay(100);
  }
}
