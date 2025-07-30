// Motor control pins
const int IN1 = 3;   // Left Motor
const int IN2 = 4;
const int IN3 = 5;   // Right Motor
const int IN4 = 6;

const int ENA = 2;   // PWM for Left Motor
const int ENB = 10;  // PWM for Right Motor

// Cork motor pin
const int CORK_PIN = 6; // Assuming it's a simple DC motor

void setup() {
  // Set motor control pins as output
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(CORK_PIN, OUTPUT); // Assuming it's connected to PWM pin like D6

  Serial.begin(9600);
  Serial.println("Starting SumoBot...");

  // Startup delay for match readiness (5 seconds)
  delay(5000);
  Serial.println("GO!");
}

void moveForward(int speed = 200) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  // analogWrite(ENB, speed);
}

void moveBackward(int speed = 200) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  // analogWrite(ENB, speed);
}

void stopMoving(int speed = 200) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  // analogWrite(ENB, 0);
}

void rotate(int speed = 200) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  // analogWrite(ENB, speed);
}



void loop() {
  //moveForward();
  rotate();
  delay(10);

 
}
