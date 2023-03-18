
#include "joystick_5pin.h"

#define RX_PIN A0
#define RY_PIN A1
#define BUTTON_PIN 2
#define DEAD_ZONE 127

Joystick joystick = Joystick(RX_PIN, RY_PIN, BUTTON_PIN, DEAD_ZONE);

void setup() {
  Serial.begin(9600);
}

void up(){
  Serial.println("<<up>>");
}

void down(){
  Serial.println("<<down>>");
}

void left(){
  Serial.println("<<left>>");
}

void right(){
  Serial.println("<<right>>");
}

void loop() {
  joystick.directional_loop(up, right, down, left, true);
  delay(20);
}
