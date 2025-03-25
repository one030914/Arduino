int pot = 0, potv = 0, left = 13, mid = 12, right = 11, value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(left, OUTPUT);
  pinMode(mid, OUTPUT);
  pinMode(right, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potv = analogRead(pot);
  value = map(potv, 0, 990, 0, 8);
  Serial.print("origin value: ");
  Serial.println(potv);
  Serial.print("after value: ");
  Serial.println(value);
  switch (value){
    case 1:
      digitalWrite(left, LOW);
      digitalWrite(mid, LOW);
      digitalWrite(right, HIGH);
      break;
    case 2:
      digitalWrite(left, LOW);
      digitalWrite(mid, HIGH);
      digitalWrite(right, LOW);
      break;
    case 4:
      digitalWrite(left, HIGH);
      digitalWrite(mid, LOW);
      digitalWrite(right, LOW);
      break;
    case 5:
      digitalWrite(left, HIGH);
      digitalWrite(mid, LOW);
      digitalWrite(right, HIGH);
      break;
    case 7:
      digitalWrite(left, HIGH);
      digitalWrite(mid, HIGH);
      digitalWrite(right, HIGH);
      break;
    default:
      digitalWrite(left, LOW);
      digitalWrite(mid, LOW);
      digitalWrite(right, LOW);
      break;
  }
  delay(500);
}
