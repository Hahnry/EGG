#include <Servo.h>

#define ENABLE_Wagen 9
#define MotorWagenA 11  //H-Bridge
#define MotorWagenB 10
//Motor Zahnstange
#define ENABLE_Zahnstange 6
#define MotorZahnstangeA 5
#define MotorZahnstangeB 4

//sensors
#define SensorWagenLinks A1
#define SensorWagenRechts A2
#define SensorGreiferOben A3
#define SensorGreiferUnten A4

#define StartButton A0
#define ResetButton A5

Servo servoGreifer;


enum State {
  RESET,
  READY,
  MOVE_DOWN,
  GRAB,
  MOVE_UP,
  MOVE_RIGHT,
  MOVE_DOWN_2,
  DROP
};

State state = RESET;


void stopAll() {
  digitalWrite(MotorWagenA, LOW);
  digitalWrite(MotorWagenB, LOW);
  digitalWrite(MotorZahnstangeA, LOW);
  digitalWrite(MotorZahnstangeB, LOW);
}

void stopVertical() {
  digitalWrite(MotorZahnstangeA, LOW);
  digitalWrite(MotorZahnstangeB, LOW);
}

void stopHorizontal() {
  digitalWrite(MotorWagenA, LOW);
  digitalWrite(MotorWagenB, LOW);
}

void moveUp() {
  digitalWrite(MotorZahnstangeA, LOW);
  digitalWrite(MotorZahnstangeB, HIGH);
  analogWrite(ENABLE_Zahnstange, 255);
}

void moveDown() {
  digitalWrite(MotorZahnstangeA, HIGH);
  digitalWrite(MotorZahnstangeB, LOW);
}

void moveLeft() {
  digitalWrite(MotorWagenA, LOW);
  digitalWrite(MotorWagenB, HIGH);
}

void moveRight() {
  digitalWrite(MotorWagenA, HIGH);
  digitalWrite(MotorWagenB, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(ENABLE_Wagen, OUTPUT);
  pinMode(MotorWagenA, OUTPUT);
  pinMode(MotorWagenB, OUTPUT);

  pinMode(ENABLE_Zahnstange, OUTPUT);
  pinMode(MotorZahnstangeA, OUTPUT);
  pinMode(MotorZahnstangeB, OUTPUT);

  pinMode(SensorWagenLinks, INPUT_PULLUP);
  pinMode(SensorWagenRechts, INPUT_PULLUP);
  pinMode(SensorGreiferOben, INPUT_PULLUP);
  pinMode(SensorGreiferUnten, INPUT_PULLUP);

  pinMode(StartButton, INPUT_PULLUP);
  pinMode(ResetButton, INPUT_PULLUP);
  servoGreifer.attach(3);
  servoGreifer.write(90);  // closed
}


void loop() {
  analogWrite(ENABLE_Wagen, 255);
  analogWrite(ENABLE_Zahnstange, 255);
//Reset Button
  if (digitalRead(ResetButton) == LOW) {
    stopAll();
    state = RESET;
    Serial.println("Reset");
  }

//Start Button
  static bool lastStart = HIGH;
  bool currentStart = digitalRead(StartButton);

  if (lastStart == HIGH && currentStart == LOW && state == READY) {
    state = MOVE_DOWN;
    Serial.println("Starts");
  }
  lastStart = currentStart;


  switch (state) {

    case RESET:
      if (digitalRead(SensorGreiferOben) == HIGH) {
        moveUp();
        Serial.print("MOvingUp ");
      } else if (digitalRead(SensorWagenLinks) == HIGH) {
        stopVertical();
        moveLeft();
        Serial.print("MovingLEft ");
      } else {
        stopAll();
        Serial.print("Stopping ");

        state = READY;
      }
      break;

    case READY:
      stopAll();
      break;

    case MOVE_DOWN:
      if (digitalRead(SensorGreiferUnten) == HIGH) {
        servoGreifer.write(70);
        moveDown();
      } else {
        stopAll();
        state = GRAB;
      }
      break;

    case GRAB:
      servoGreifer.write(100);  // close
      delay(100);
      state = MOVE_UP;
      break;

    case MOVE_UP:
      if (digitalRead(SensorGreiferOben) == HIGH) {
        moveUp();
      } else {
        stopAll();
        state = MOVE_RIGHT;
      }
      break;

    case MOVE_RIGHT:
      if (digitalRead(SensorWagenRechts) == HIGH) {
        moveRight();
      } else {
        stopAll();
        state = MOVE_DOWN_2;
      }
      break;

    case MOVE_DOWN_2:
      if (digitalRead(SensorGreiferUnten) == HIGH) {
        moveDown();
      } else {
        stopAll();
        state = DROP;
      }
      break;

    case DROP:
      servoGreifer.write(70);  // open
      delay(500);
      //state = RESET;
      break;
  }


  Serial.println(state);

  delay(200);  // loop pacing
}
