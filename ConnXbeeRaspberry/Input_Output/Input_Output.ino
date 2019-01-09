/* Output-side (LED) Arduino code */
#include "SoftwareSerial.h"
// RX: Arduino pin 2, XBee pin DOUT.  TX:  Arduino pin 3, XBee pin DIN
SoftwareSerial XBee(3, 2);
int BUTTON = 5;
int LED = 4;
int LEDON = 0;

void setup()
{
  // Baud rate MUST match XBee settings (as set in XCTU)
  Serial.begin(9600);
  XBee.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (XBee.available())
  {
    char c = XBee.read();
    //Serial.println(c, BIN);
    if (c == 'b' && LEDON  == 0)
    {
      LEDON = 1;
    } else if (c == 'b' && LEDON == 1) {
      LEDON = 0;
    }

    if (LEDON == 1) {

      digitalWrite(LED, HIGH);
      digitalWrite(13, HIGH);
      delay(50);
    } else if (LEDON == 0) {
      digitalWrite(LED, LOW);
      digitalWrite(13, LOW);
    }
  }
 
  if (Serial.available())
  {
    char c = Serial.read();
    Serial.println("1");
    delay(500);
  }

  // The led van de andere Xbee aanzetten
  if (digitalRead(BUTTON) == HIGH)
  {
    while (digitalRead(BUTTON) == HIGH) {

    }
    XBee.write('c');
    digitalWrite(13, HIGH);
    delay(50);


  }
  else
  {
    digitalWrite(13, LOW);
  }

}
