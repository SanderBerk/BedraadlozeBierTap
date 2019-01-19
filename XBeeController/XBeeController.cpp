/**
 * @file Main.h
 * @date January, 2019
 * @brief
 * ! \mainpage Arduino Nano Led/Button Controller (XBee)
 *
 * This program will use the broadcasted messages received from the XBee to turn on a LED.
 * Also when the connected button is pressed it will send a message to the other nodes using the attached XBee.
 * 
 *
 *
 *
 * This project was made by second year students from Avans Hogeschool Den Bosch Technische Informatica.
 *
 * 
 *
 */

/* Output-side (LED) Arduino code */
#include "SoftwareSerial.h"

// RX: Arduino pin 2, XBee pin DOUT.  TX:  Arduino pin 3, XBee pin DIN
SoftwareSerial XBee(3, 2);

#define BUTTON 5
#define LED 4

int LEDON = 0;

void setup()
{
  // Baud rate MUST match XBee settings (as set in XCTU)
  Serial.begin(9600);
  XBee.begin(9600);
  pinMode(LED, OUTPUT);
}

void XBeeReceive() {
  if (XBee.available())
  {
    char c = XBee.read();
    if (c == 'c' && LEDON  == 0)
    {
      LEDON = 1;
    } else if (c == 'c' && LEDON == 1) {
      LEDON = 0;
    }

    if (LEDON == 1) {

      digitalWrite(LED, HIGH);
      delay(50);
    } else if (LEDON == 0) {
      digitalWrite(LED, LOW);
    }
  }
}

void XBeeSend() {
  // The led van de andere Xbee aanzetten
  if (digitalRead(BUTTON) == HIGH)
  {
    // beter maken
    while (digitalRead(BUTTON) == HIGH) { }
    XBee.write('a');
    digitalWrite(13, HIGH);
    delay(50);

  }
  else
  {
    digitalWrite(13, LOW);
  }
}

void SerialReceive() {
  if (Serial.available())
  {
    byte c = Serial.read();
    if (int(c) == 255) {
      XBee.write("c");
    }
    if (int(c) == 254) {
      XBee.write("b");
    }
    if (int(c) == 253) {
      XBee.write("a");
    }
  }
}


void loop()
{
  XBeeReceive();
  XBeeSend();
  SerialReceive();
}
