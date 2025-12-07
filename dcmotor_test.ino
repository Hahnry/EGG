#define ENABLE_1 9
#define MOTOR_1_A 11
#define MOTOR_1_B 10

#define ENABLE_2 6
#define MOTOR_2_A 5
#define MOTOR_2_B 4

#define WAGEN_A A1
#define WAGEN_B A2
#define GREIFER_POS A3

void setup() {
  Serial.begin(9600);
  pinMode(ENABLE_1, OUTPUT);
  pinMode(MOTOR_1_A, OUTPUT);
  pinMode(MOTOR_1_B, OUTPUT);

  pinMode(ENABLE_2, OUTPUT);
  pinMode(MOTOR_2_A, OUTPUT);
  pinMode(MOTOR_2_B, OUTPUT);

  pinMode(WAGEN_A, INPUT_PULLUP);
  pinMode(WAGEN_B, INPUT_PULLUP);
  pinMode(GREIFER_POS, INPUT_PULLUP);
}

void loop() {
  // Full forward:


  analogWrite(ENABLE_2, 250);
  analogWrite(ENABLE_1, 250);
  // Speed control:

  if (!digitalRead(WAGEN_B)) {

    digitalWrite(MOTOR_1_A, HIGH);
    digitalWrite(MOTOR_1_B, LOW);
  } else {
    digitalWrite(MOTOR_1_A, LOW);
    digitalWrite(MOTOR_1_B, LOW);
  }


  if (!digitalRead(WAGEN_A)) {
    digitalWrite(MOTOR_2_A, HIGH);
    digitalWrite(MOTOR_2_B, LOW);
  }   else {
      digitalWrite(MOTOR_2_A, LOW);
    digitalWrite(MOTOR_2_B, LOW);
  }




  // if (digitalRead(GREIFER_POS)) {
  //   Serial.print(digitalRead(GREIFER_POS));
  //   Serial.print(' ');
  // }
  // if (!digitalRead(WAGEN_A)) {
  //   Serial.println(digitalRead(WAGEN_A));
  // }

  delay(100);
}
