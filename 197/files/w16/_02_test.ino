#include<SoftwareSerial.h>

int trigPin = 3;
int echoPin = 2;
int rxPin = 1;
int txPin = 0;
int duration, cm , inches ;
SoftwareSerial myserial(rxPin, txPin);

void setup() {
  pinMode(trigPin, OUTPUT) ;
  pinMode(echoPin, INPUT) ;
  myserial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration / 2) / 29.1;
  inches = (duration / 2) / 74;

 myserial.println(cm);

  delay(250);

}
