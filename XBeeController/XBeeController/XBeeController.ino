/**
 * @file Main.h
 * @date January, 2019
 * @brief
 * ! \mainpage Arduino/Xbee Serial connector
 *
 * QT Gui for connecting to an Arduino/Xbee mesh network through Serial and controlling LED's.
 *
 *
 *
 * This project was made by second year students from Avans Hogeschool Den Bosch Technische Informatica.
 *
 * \note https://wiki.qt.io/Main
 *
 */

/* Output-side (LED) Arduino code */
#include "SoftwareSerial.h"

#define module 2
#define sendmodule 3

// RX: Arduino pin 2, XBee pin DOUT.  TX:  Arduino pin 3, XBee pin DIN
SoftwareSerial XBee(3, 2);

#define BUTTON 5
#define LED 4

int LEDON = 0;

int tableLength = 3;
int table[][2] = {
  {1, 255},
  {2, 254},
  {3, 253}
};

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
    if (c == module)
    {
      toggleLed();
    } 
  }
}

void toggleLed(){
  if (LEDON  == 0){
    LEDON = 1;
    digitalWrite(LED, HIGH);
    delay(50);
  } else if (LEDON == 1) {
    LEDON = 0;
    digitalWrite(LED, LOW);
    delay(50);
  }
}

void XBeeSend() {
  // The led van de andere Xbee aanzetten
  if (digitalRead(BUTTON) == HIGH)
  {
    // beter maken
    while (digitalRead(BUTTON) == HIGH) { }
    XBee.write(sendmodule);
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
    for(int x = 0; x < tableLength; x++){
      if(table[x][1] == int(c)){
        if(table[x][0] == module){
          toggleLed();
        }else{
          XBee.write(table[x][0]);
        }
      }
    }
  }
}


void loop()
{
  XBeeReceive();
  XBeeSend();
  SerialReceive();
}
