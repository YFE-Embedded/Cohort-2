#include <Servo.h>

// Define pins
const int trigPin = A0;
const int echoPin = A1;
const int servoPin = 10;

const int enA = 5;
const int in1 = 4;
const int in2 = 3;
const int in3 = 2;
const int in4 = 7;
const int enB = 6;

Servo MicroSky;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Set motor speed (0-255)
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  
  MicroSky.attach(servoPin);
  MicroSky.write(90); // Center position
  Serial.begin(9600);
}

void loop() {
  int distance = readDistance();
  
  if (distance < 20) {
    stopCar();
    backward();
    delay(300);
    stopCar();
    
    int distLeft = lookLeft();
    int distRight = lookRight();
    
    if (distLeft >= distRight) {
      turnLeft();
      delay(400);
    } else {
      turnRight();
      delay(400);
    }
    stopCar();
  } else {
    forward();
  }
}

int readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
  
}

int lookLeft() {
  MicroSky.write(170);
  delay(500);
  int d = readDistance();
  MicroSky.write(90);
  return d;
}

int lookRight() {
  MicroSky.write(10);
  delay(500);
  int d = readDistance();
  MicroSky.write(90);
  return d;
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopCar() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
