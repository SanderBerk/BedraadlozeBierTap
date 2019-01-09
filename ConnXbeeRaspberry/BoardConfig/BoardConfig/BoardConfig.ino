#include "SoftwareSerial.h"
// RX: Arduino pin 2, XBee pin DOUT.  TX:  Arduino pin 3, XBee pin DIN
SoftwareSerial XBee(2, 3);
int LED = 4;
int BUTTON = 5;

void setup() {
  // put your setup code here, to run once:
 XBee.begin(9600);
 pinMode(LED, OUTPUT);
 pinMode(BUTTON, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BUTTON) == HIGH)
  {
    XBee.write('b');
    delay(50);
  }else{ 
    char c = XBee.read();
    if (c == 'a')
    {
      digitalWrite(LED, HIGH);
      delay(50);
    }
    else
    {
      digitalWrite(LED, LOW);
    }
  }
}
