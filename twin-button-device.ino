#include "Keyboard.h"
#include <debounce.h>
const int leftPin = 9;   // input pin for pushbutton
const int rightPin = 12;  // input pin for pushbutton

static void buttonHandler(uint8_t btnId, uint8_t btnState) {
  if (btnState == BTN_PRESSED) {
    Keyboard.print(String(btnId));
  }
}
static Button leftButton(1, buttonHandler);
static Button rightButton(2, buttonHandler);

void setup() {
  // make the pushButton pin an input:
  pinMode(leftPin, INPUT_PULLUP);
  pinMode(rightPin, INPUT_PULLUP);
  // initialize control over the keyboard:
  Keyboard.begin();
}


static void pollButtons() {
  // update() will call buttonHandler() if PIN transitions to a new state and stays there
  // for multiple reads over 25+ ms.
  leftButton.update(digitalRead(leftPin));
  rightButton.update(digitalRead(rightPin));
}

void loop() {
  pollButtons();  // Poll your buttons every loop.
  //delay(10); // Loop iterations should run fairly quickly, 10's of ms, not 100's.
}
