int r = 10, g = 11, b = 12, btn = 7;
int state = 0, l_count = 0, count = 0;
bool reverse = false;

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(btn, INPUT);
  Serial.begin(9600);
}

void loop() {
  state = digitalRead(btn);
  if(state == HIGH){
    delay(200);
    l_count = l_count++ % 3 + 1;
    switch (l_count) {
      case 1:
        digitalWrite(r, HIGH);
        digitalWrite(g, LOW);
        digitalWrite(b, LOW);
        Serial.println("R");
        break;
      case 2:
        digitalWrite(r, LOW);
        digitalWrite(g, HIGH);
        digitalWrite(b, LOW);
        Serial.println("G");
        break;
      case 3:
        digitalWrite(r, LOW);
        digitalWrite(g, LOW);
        digitalWrite(b, HIGH);
        Serial.println("B");
        break;
      default:
        digitalWrite(r, LOW);
        digitalWrite(g, LOW);
        digitalWrite(b, LOW);
        Serial.println("OFF");
        break;
    }
    if(l_count == 3){
      count = count++ % 2 + 1;
      Serial.println(count);
    }
    if(count == 2){
      reverse = !reverse;
    }
    if(!reverse){
      r = 10;
      b = 12;
      Serial.println("RGB");
    }else{
      r = 12;
      b = 10;
      Serial.println("BGR");
    }
  }
}
