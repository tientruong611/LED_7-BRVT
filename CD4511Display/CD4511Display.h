#ifndef CD4511DISPLAY_H
#define CD4511DISPLAY_H

#include <Arduino.h>

class CD4511Display {
  private:
    int pinD, pinC, pinB, pinA,pinE;
  public:
    CD4511Display(int dPin, int cPin, int bPin, int aPin,int ePin);
    void begin();
    void display(int number);
    void update();
};

#endif
