/* Output-side (LED) Arduino code */
#include "SoftwareSerial.h"
// RX: Arduino pin 2, XBee pin DOUT.  TX:  Arduino pin 3, XBee pin DIN
SoftwareSerial XBee(3, 2);
int BUTTON = 5;
int LED = 4;

void setup()
{
  // Baud rate MUST match XBee settings (as set in XCTU)
  //Serial.begin(9600);
  XBee.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (XBee.available())  
  { 
    char c = XBee.read();
    //Serial.println("test");
    if (c == 'a')
    {
      digitalWrite(LED, HIGH);
      digitalWrite(13, HIGH);
      delay(50);
    }
    else
    {
      digitalWrite(LED, LOW);
      digitalWrite(13, LOW);
    }
  }
  else
  {
    digitalWrite(LED, LOW);
  }
    if (digitalRead(BUTTON) == HIGH)
  {
    XBee.write('a');
    digitalWrite(13, HIGH);
    delay(50);
    
      
  }
  else
  {
    digitalWrite(13, LOW);
  }
  
}
