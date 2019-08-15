/*
 * This code will read a text input from the serial monitor, then it will print the text in a 16x2 LCD Display 
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
