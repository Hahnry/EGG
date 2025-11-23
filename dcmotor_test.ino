#define ENABLE_1 9
#define MOTOR_1_A 11
#define MOTOR_1_B 10

void setup() {
  pinMode(ENABLE_1, OUTPUT);
  pinMode(MOTOR_1_A, OUTPUT);
  pinMode(MOTOR_1_B, OUTPUT);
}

void loop() {
  // Full forward:
  digitalWrite(MOTOR_1_A, HIGH);
  digitalWrite(MOTOR_1_B, LOW);

  // Speed control:
  analogWrite(ENABLE_1, 255
  );  // speed = 100/255
}
