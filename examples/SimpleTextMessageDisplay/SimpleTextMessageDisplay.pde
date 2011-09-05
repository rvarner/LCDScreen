#include <LCDScreen.h>
/*
  Copyright Richard Reid Varner 2011
  
  Title: SimpleTextMessageDisplay.pdr
  
  Description:
  The purpose of this sketch is to display a simple text message on the LCD screen
  
  
*/

#define rxPin 4  // rxPin is immaterial - not used - just make this an unused Arduino pin number
#define txPin 14 // pin 14 is analog pin 0, on a BBB just use a servo cable :), see Reference pinMode

LCDScreen lcd = LCDScreen(txPin,rxPin);

void setup(){
   lcd.init();
}

boolean printed = false;
char message[] = "?x00?y0FROM: Saul Ramos?x00?y2Let's kill some?nzombies!";

void loop(){
  if(!printed) {
    lcd.print(message);
    delay(300);
    lcd.printRightArrow();
    printed = true;
  }
}
