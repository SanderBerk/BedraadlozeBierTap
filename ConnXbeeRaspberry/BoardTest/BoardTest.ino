/* Input-side (button) Arduino code */
#include "SoftwareSerial.h"
// RX: Arduino pin 2, XBee pin DOUT.  TX:  Arduino pin 3, XBee pin DIN
//SoftwareSerial XBee(2, 3);
int BUTTON = 5;
int LED = 4;

void setup()
{
  pinMode(LED, OUTPUT);
  // Baud rate MUST match XBee settings (as set in XCTU)
  pinMode(BUTTON, INPUT);
  //XBee.begin(9600);
}

void loop()
{
  if (digitalRead(BUTTON) == HIGH)
  {
    //XBee.write('a');
    //delay(50);
    digitalWrite(LED, HIGH);
      delay(50);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}
