#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <Wire.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiWire.h>

#include "door.h"
#include "radio.h"

#define CEPIN 10
#define CSPIN 9

Radio radio(CEPIN, CSPIN);
Door door(radio);

#define OLED_I2C_ADDRESS 0x3C
SSD1306AsciiWire display;


void setup()
{
    Serial.begin(115200);   
    Serial.println(F("Receiver"));
	

  	display.begin(&Adafruit128x32, OLED_I2C_ADDRESS);
  	display.set400kHz();
  	display.setFont(Adafruit5x7);
  	display.clear();
  	display.setCursor(0, 0);
  	display.print(F("Receiver"));

    radio.Setup(Serial);
    door.Setup(Serial);
}

void displayCode(DoorCode code)
{
  display.setCursor(0, 0);
  display.clearToEOL();
  display.setCursor(0, 0);
  switch(code) 
  {
    case DoorCode::Unknown:
      display.print(F("Unknown"));
      break;

    case DoorCode::Close:
      display.print(F("Closed"));
      break;

    case DoorCode::Open:
      display.print(F("Open"));
  }
}

DoorCode prevCode = DoorCode::Unknown;
void loop()
{      
    DoorCode code = door.GetStatus(Serial);
    if (code != prevCode)
    {
      prevCode = code;
      displayCode(code);
    }
    

}
