#include "joystick_5pin.h"

#ifndef joystick_5pin
#define joystick_5pin

#include <Arduino.h>

Joystick::Joystick(int _rx_pin, int _ry_pin, int _button_pin){
  Joystick(_rx_pin, _ry_pin, _button_pin, 31);
}

Joystick::Joystick(int _rx_pin, int _ry_pin, int _button_pin, int _dead_zone){
  pinMode(_rx_pin, INPUT);
  pinMode(_ry_pin, INPUT);
  pinMode(_button_pin, INPUT);
  rx_pin = _rx_pin;
  ry_pin = _ry_pin;
  button_pin = _button_pin;
  dead_zone = _dead_zone;
}

int Joystick::get_x_axis(void){
  int x_value = analogRead(rx_pin);
  if( abs(x_value - 511) > dead_zone ){ // if x axis value is larger than dead zone value
    return x_value;
  } else {
    return 511;
  }
}

int Joystick::get_y_axis(void){
  int y_value = analogRead(ry_pin);
  if( abs(y_value - 511) > dead_zone ){ // if y axis value is larger than dead zone value
    return y_value;
  } else {
    return 511;
  }
}

bool Joystick::get_button_state(void){
  return digitalRead(button_pin) == 0; // was pressed
}

void Joystick::button_loop(void (*press)(void), void (*release)(void)){
  bool new_state = get_button_state();
  if(new_state == prev_state) return;

  if(new_state > prev_state) { // if button was pressed
    prev_state = true;
    press();
  } else { // if button was released; the last option (new_state < prev_state)
    prev_state = false;
    release();
  }
}

#endif