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

numbers = map(White, 0, 1023, 0, 255);

analogWrite(ledPin,numbers);

Serial.println(White);
Serial.println(numbers);
delay(250);
}
