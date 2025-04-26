#include "CD4511Display.h"
#include <Arduino.h>
CD4511Display led1(2, 3, 4, 5,32); // D, C, B, A
CD4511Display led2 (10, 11, 12, 13,34); // D, C, B, A
CD4511Display led3 (20, 21, 22, 23,36); // D, C, B, A
CD4511Display led4 (24, 25, 26, 27,38); // D, C, B, A
CD4511Display led5 (28, 29, 30, 31,40); // D, C, B, A

int final_led = 42;

//pine vao 32 34 36 38 40
CD4511Display leds[] = {led1, led2, led3, led4, led5};
String stringb;
String stringc;
String stringd;
int inChar;
unsigned long a;
int digit1, digit2, digit3, digit4, digit5, digit6;

void calculate(unsigned long number) {
  String numStr = String(number); // Chuyển số thành chuỗi
  int length = numStr.length(); // Độ dài chuỗi
  // Chuyển số thành chuỗi 98765 
  // nhung thang nao khong co no tu nhan gia tri 0
  int value_led6 = (number / 100000) % 10;
  int value_led5 = (number / 10000) % 10; 
  int value_led4 = (number / 1000 ) % 10; 
  int value_led3 = (number / 100) % 10; 
  int value_led2 = (number / 10) % 10; 
  int value_led1 = number % 10; 
  
  ////////////////     0         1          2            3          4           5
  char digit[] = {value_led6,value_led5, value_led4, value_led3, value_led2,value_led1};
  switch (length) {
    case 1:
      leds[0].display(value_led1);
      leds[1].display(10);
      leds[2].display(10);
      leds[3].display(10);
      leds[4].display(10);
      digitalWrite(final_led, LOW);

      break;
        case 2:
      leds[0].display(value_led1);
      leds[1].display(value_led2);
      leds[2].display(10);
      leds[3].display(10);
      leds[4].display(10);
      digitalWrite(final_led, LOW);

      break;
    case 3:
      leds[0].display(value_led1);
      leds[1].display(value_led2);
      leds[2].display(value_led3);
      leds[3].display(10);
      leds[4].display(10);
      digitalWrite(final_led, LOW);
      break;
    case 4:
      leds[0].display(value_led1);
      leds[1].display(value_led2);
      leds[2].display(value_led3);
      leds[3].display(value_led4);
      leds[4].display(10);
      digitalWrite(final_led, LOW);
      break;
    case 5:
      leds[0].display(value_led1);
      leds[1].display(value_led2);
      leds[2].display(value_led3);
      leds[3].display(value_led4);
      leds[4].display(value_led5);
      digitalWrite(final_led, LOW);
      break;
    case 6:
      leds[0].display(value_led1);
      leds[1].display(value_led2);
      leds[2].display(value_led3);
      leds[3].display(value_led4);
      leds[4].display(value_led5);
      digitalWrite(final_led, HIGH);
      break;
  }
}
void setup() {
  pinMode(final_led, OUTPUT);
  
  Serial.begin(9600); 
  Serial1.begin(9600); 

  for(int i=0; i<5; i++){
    leds[i].begin();
  }
}

void loop() {

  if (Serial1.available() > 0) {
    int inChar = Serial1.read();
    if (isDigit(inChar)) {
        stringb += (char)inChar;
    }
      if (inChar == '\r' || inChar == 3) {
        stringc = stringb.substring(0, 6);
        a= stringc.toInt();
        calculate(a);    
          stringb = "";
      }
    }
  
  }
  


