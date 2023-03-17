#include "joystick_5pin.h"

#define RX_PIN A0
#define RY_PIN A1
#define BUTTON_PIN 2
#define DEAD_ZONE 127

Joystick joystick = Joystick(RX_PIN, RY_PIN, BUTTON_PIN, DEAD_ZONE);

void setup() {
  Serial.begin(9600);
}

void button_press(){
  Serial.println("<<press>>");
}

void button_release(){
  Serial.println("<<release>>");
}

void loop() {
  joystick.button_loop(button_press, button_release);
  Serial.print("y: ");
  Serial.print(joystick.get_y_axis());
  Serial.print(", x: ");
  Serial.print(joystick.get_x_axis());
  Serial.print(", button: "); 
  Serial.println(joystick.get_button_state());
  delay(200);
}
