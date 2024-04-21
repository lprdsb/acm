
void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    // digitalWrite(LED_BUILTIN, HIGH);
    if(Serial.available() > 0) {
      int x = Serial.read() - '0';
      Serial.println('0' + x);
      for(int i = 1; i <= x; ++i){
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
      }
    }
    delay(1000);
}
