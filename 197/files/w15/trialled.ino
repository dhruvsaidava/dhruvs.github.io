#include<SoftwareSerial.h>
int rxPin = 1;
int txPin = 0;

SoftwareSerial myserial(rxPin, txPin);

void setup() {
  myserial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  char chr = myserial.read();

  if (chr == '0') {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    delay(10);
  }
  else if (chr == '1') {
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH);
    delay(10);
  }

  else if (chr == '2') {
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    delay(10);
  }

  else {
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
  }
}

