#include "CD4511Display.h"

CD4511Display::CD4511Display(int dPin, int cPin, int bPin, int aPin, int ePin) {
  pinD = dPin;
  pinC = cPin;
  pinB = bPin;
  pinA = aPin; 
  pinE = ePin;
}

void CD4511Display::begin() {
  pinMode(pinD, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinA, OUTPUT);
}

void CD4511Display::display(int number) {
  if (number < 0 || number > 9) {
    digitalWrite(pinD, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinA, LOW);
    return; // Exit early for invalid input
  }
  if (number == 0) {
    digitalWrite(pinD, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinA, LOW);
  } else if (number == 1) {
    digitalWrite(pinD, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinA, HIGH);
  } else if (number == 2) {
    digitalWrite(pinD, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinA, LOW);
  } else if (number == 3) {
    digitalWrite(pinD, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinA, HIGH);
  } else if (number == 4) {
    digitalWrite(pinD, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinA, LOW);
  } else if (number == 5) {
    digitalWrite(pinD, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinA, HIGH);
  } else if (number == 6) {
    digitalWrite(pinD, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinA, LOW);
  } else if (number == 7) {
    digitalWrite(pinD, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinA, HIGH);
  } else if (number == 8) {
    digitalWrite(pinD, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinA, LOW);
  } else if (number == 9) {
    digitalWrite(pinD, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinA, HIGH);
  }
}


void CD4511Display::update() {
  digitalWrite(pinE, LOW); // Enable the display
}

