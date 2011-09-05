/*
  LCDScreen.h
*/

#ifndef LCDScreen_h
#define LCDScreen_h

#include "WProgram.h"
#include "NewSoftSerial.h"

class LCDScreen {
  public:
    LCDScreen(int,NewSoftSerial&);
    void init();
    void cls();
    void newline();
    void home();
    void clsHome();
    void print(char*);
    void print(const String&);
    void printNoDelay(const String&);
    void defineVar(String,int);
    void printRightArrow();
    void printLeftArrow();

  private:
    NewSoftSerial& mySerial;
    int _txPin;
    String blankD;
    String rightArrowTop;
    String rightArrowBottom;
    String leftArrowTop;
    String leftArrowBottom;
};

#endif
