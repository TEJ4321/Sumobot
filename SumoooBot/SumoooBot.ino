// Motor control pins
const int IN1 = 2;   // Left Motor
const int IN2 = 3;
const int IN3 = 4;   // Right Motor
const int IN4 = 5;

const int ENA = 9;   // PWM for Left Motor
const int ENB = 10;  // PWM for Right Motor

// Cork motor pin
const int CORK_PIN = 6;

void setup() {
  // Set all motor control pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(CORK_PIN, OUTPUT);

  // Optional: Start Serial for debugging
  Serial.begin(9600);
}

// Movement Functions
void moveForward(int speed = 200) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void moveBackward(int speed = 200) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnLeft(int speed = 200) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnRight(int speed = 200) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void stopMoving() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// Cork mechanism functions
void spinCorkOn() {
  digitalWrite(CORK_PIN, HIGH); // Or analogWrite(CORK_PIN, 255);
}

void spinCorkOff() {
  digitalWrite(CORK_PIN, LOW);  // Or analogWrite(CORK_PIN, 0);
}

void loop() {
  // Example sequence
  moveForward();
  delay(1000);

  stopMoving();
  delay(500);

  turnLeft();
  delay(700);

  stopMoving();
  delay(500);

  spinCorkOn();
  delay(3000);
  spinCorkOff();

  stopMoving();
  delay(1000);
}
