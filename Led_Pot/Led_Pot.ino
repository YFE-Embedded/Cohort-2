int ledPin=10;
int White;
int potPin=A5;
int numbers;

void setup() {
pinMode(ledPin,OUTPUT);
pinMode(potPin,INPUT);
Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
White = analogRead(potPin);
Serial.println(White);
numbers = 255*(White/1023);
analogWrite(ledPin,numbers);
Serial.println(numbers);
delay(250);
}
