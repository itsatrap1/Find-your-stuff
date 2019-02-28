#define BUZZER_PIN 8
char state;
bool x;

void buzzer(void) {
  tone(8, 400);
  delay(1000);
  noTone(8);
  delay(1000);
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  tone(8, 600);
  if (Serial.available() > 0) {
    state = Serial.read();
    delay(2);
    
    if (state == 'a')
      x = true;
    delay(5);
    
    while (x) {
      buzzer();
      state = Serial.read();
      
      if (state == 'b') {
        noTone(8);
        x = false;
      }
    }
  }
}
