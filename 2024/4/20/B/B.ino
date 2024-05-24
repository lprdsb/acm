
#define led_r 9
#define led_g 10
#define led_b 11
#define key0 7
#define key1 8
#define key2 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_b, OUTPUT);
  pinMode(key0, INPUT);
  pinMode(key1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int key = 20;
  if(digitalRead(key0) == HIGH) key = 0;
  if(digitalRead(key1) == HIGH) key = 1;
  Serial.println(key);
  // key = 20;
  if(key == 0){
    for(int i = 255; i > 0; --i){
      analogWrite(led_r, i);
      analogWrite(led_g, 114);
      analogWrite(led_b, 255);
      delay(10);
      // if(digitalRead(key2) == 1) break;
    }
    for(int i = 0; i < 255; ++i){
      analogWrite(led_r, i);
      analogWrite(led_g, 114);
      analogWrite(led_b, 255 - i);
      delay(10);
      // if(digitalRead(key2) == 1) break;
    }
  }
  else if(key == 1){
      analogWrite(led_r, 0);
      analogWrite(led_g, 0);
      analogWrite(led_b, 255);
      delay(500);
      analogWrite(led_r, 255);
      analogWrite(led_g, 0);
      analogWrite(led_b, 0);
      delay(500);
      analogWrite(led_r, 0);
      analogWrite(led_g, 255);
      analogWrite(led_b, 0);
      delay(500);
  }
}
