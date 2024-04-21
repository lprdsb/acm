
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    if(Serial.available() > 0) {
      char c;
      String S;
      while(c = Serial.read()){
        if(c == '\n') break;
        S += c;
      }
      Serial.println(S);
      return;
    }
    delay(1000);
}
