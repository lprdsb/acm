
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    if(Serial.available() > 0) {
      char c;
      while(c = Serial.read()){
        if(c == '\n') break;
        if(c >= '0' && c <= '9') Serial.print(c);
      }
      return;
    }
    delay(1000);
}
