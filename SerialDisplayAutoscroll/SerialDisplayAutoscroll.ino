/*
 
 This code will read a text input from the serial monitor, then it will print the text in a 16x2 LCD Display 
 
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

*/

// include LCD library:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String serialRead = "";
int pos = 16;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(9600);
  lcd.display(); //turn on display
}

void loop() {
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // save characters into string
      serialRead = Serial.readString();
    }    
    lcd.setCursor(pos,0);
    lcd.autoscroll(); //turn on autoscroll
    for(int n = 0; n < serialRead.length(); n++){
      lcd.print(serialRead[n]);
      delay(500);
    }
    lcd.noAutoscroll(); //turn off autoscroll
  }
}
