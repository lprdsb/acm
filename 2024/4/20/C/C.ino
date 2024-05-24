#define r 9
#define g 10
#define b 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A0);
  Serial.println(val);
  float vol = val * (5.0 / 1023.0);
  int light = vol / 5.0 * 255;
  Serial.println(light);
  analogWrite(r, light);
  delay(100);

  
  // analogWrite(r, light);
  // analogWrite(g, 255 - light);
  // analogWrite(b, 114);
  // delay(100);
}
