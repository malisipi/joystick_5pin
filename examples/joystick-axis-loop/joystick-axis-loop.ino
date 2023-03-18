#include "joystick_5pin.h"

#define RX_PIN A0
#define RY_PIN A1
#define BUTTON_PIN 2
#define DEAD_ZONE 127

Joystick joystick = Joystick(RX_PIN, RY_PIN, BUTTON_PIN, DEAD_ZONE);

void setup() {
  Serial.begin(9600);
}

void x_axis(int x_value){
  Serial.print("x:");
  Serial.println(x_value);
}

void y_axis(int y_value){
  Serial.print("y:");
  Serial.println(y_value);
}

void loop() {
  joystick.axis_loop(x_axis, y_axis, false);
  delay(20);
}
