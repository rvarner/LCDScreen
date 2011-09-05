#include "LCDScreen.h"

LCDScreen::LCDScreen(int txPin,NewSoftSerial& serialRef):mySerial(serialRef) {
  _txPin = txPin;
  blankD = "1F1F1F1F1F1F1F1F";
  rightArrowTop = "1018181C1C1E1E1F";
  rightArrowBottom = "1F1E1E1C1C181810";
  leftArrowTop = "01030307070F0F1F";
  leftArrowBottom = "1F0F0F0707030301";
}

void LCDScreen::cls() {
  mySerial.print("?f");
  delay(300);
}

void LCDScreen::newline() {
  mySerial.print("?n");
  delay(300);
}

void LCDScreen::home() {
  mySerial.print("?x00?y0");
  delay(100);
}

void LCDScreen::clsHome() {
  cls();
  home();
}

void LCDScreen::print(char* str) {
  mySerial.print(str);
  delay(200);
}

void LCDScreen::print(const String& str) {
  mySerial.print(str);
  delay(200);
}

void LCDScreen::printNoDelay(const String& str) {
  mySerial.print(str);
}

void LCDScreen::defineVar(String special,int num) {
  String str = "?D" + String(num) + special;
  char buf[] = "                   ";
  str.toCharArray(buf,20);
  mySerial.print(buf);
  delay(300);
}

void LCDScreen::printRightArrow() {
  mySerial.print("?x18?y0?1?x17?y1?0?0?1?x17?y2?0?0?2?x18?y3?2");
  delay(400);
}

void LCDScreen::printLeftArrow() {
  mySerial.print("?x18?y0?3?x17?y1?3?0?0?x17?y2?4?0?0?x18?y3?4");
  delay(400);
}

void LCDScreen::init() {

  pinMode(_txPin, OUTPUT);
  mySerial.begin(9600);      // 9600 baud is chip comm speed
  
  mySerial.print("?G420");   // set display geometry,  2 x 16 characters in this case
  delay(500);                // pause to allow LCD EEPROM to program
  
  mySerial.print("?Bff");    // set backlight to ff hex, maximum brightness
  delay(1000);                // pause to allow LCD EEPROM to program
  
  mySerial.print("?s6");     // set tabs to six spaces
  delay(1000);               // pause to allow LCD EEPROM to program
  
  mySerial.print("?f");                   // clear the LCD
  delay(10);
  
  this->print("?x03?y0Booting LCD...");
  
  defineVar(blankD,0);
  defineVar(rightArrowTop,1);
  defineVar(rightArrowBottom,2);
  defineVar(leftArrowTop,3);
  defineVar(leftArrowBottom,4);
  
  mySerial.print("?c0");                  // turn cursor off
  delay(300);

  cls();
  delay(100);
}
