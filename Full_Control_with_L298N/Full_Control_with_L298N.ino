#include <IBusBM.h>

IBusBM ibus;

// L298N Pins
const int IN1 = 27;
const int IN2 = 26;
const int IN3 = 31;
const int IN4 = 30;

void setup()
{
  Serial.begin(115200);

  // FS-iA10B iBUS connected to Mega RX1 (Pin 19)
  Serial1.begin(115200);
  ibus.begin(Serial1);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop()
{
  int steering = ibus.readChannel(0); // CH1
  int throttle = ibus.readChannel(1); // CH2

  Serial.print("CH1: ");
  Serial.print(steering);

  Serial.print("  CH2: ");
  Serial.println(throttle);

  if (throttle > 1600){
    forward();
  }

  else if (throttle < 1400){
    reverse();
  }

  else if (steering > 1600){
    right();
  }

  else if (steering < 1400){
    left();
  }

  else{
    stopMotors();
  }

  delay(100);
}

void stopMotors()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void reverse()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}