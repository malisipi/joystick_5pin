#include "joystick_5pin.h"

/*
 * The project licensed by MIT License.
 * Author & Maintainer: malisipi <mehmetalisipi@gmail.com>
 * Source Code: https://github.com/malisipi/joystick_5pin
 */

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
  const bool new_state = get_button_state();
  if(new_state == prev_state) return;

  if(new_state > prev_state) { // if button was pressed
    prev_state = true;
    press();
  } else { // if button was released; the last option (new_state < prev_state)
    prev_state = false;
    release();
  }
}

void Joystick::axis_loop(void (*x_axis)(int), void (*y_axis)(int), bool new_events_only){
  const int new_axis [2] = {get_x_axis(), get_y_axis()};
  if(new_events_only || new_axis[0]!=prev_axis[0]){ // if the axis value was changed or new event handling was enabled
    x_axis(new_axis[0]);
  }
  if(new_events_only || new_axis[1]!=prev_axis[1]){ // if the axis value was changed or new event handling was enabled
    y_axis(new_axis[1]);
  }
  prev_axis[0] = new_axis[0];
  prev_axis[1] = new_axis[1];
}

void Joystick::axis_loop(void (*x_axis)(int), void (*y_axis)(int)){
  axis_loop(x_axis, y_axis, false);
}

void Joystick::directional_loop(void (*up)(void), void (*right)(void), void (*down)(void), void (*left)(void), bool new_events_only){
  const int new_axis [2] = {get_x_axis(), get_y_axis()};
  if(!new_events_only || new_axis[0]!=prev_axis[0]){ // if the axis value was changed or always event handling was enabled
    if(new_axis[0]>823 && (!new_events_only || prev_axis[0]<=823)){ // if the axis value was bigger than 823 and (always event handling was enabled or the axis value was changed)
      up();
    }
    if(new_axis[0]<200 && (!new_events_only || prev_axis[0]>=200)){ // if the axis value was smaller than 200 and (always event handling was enabled or the axis value was changed)
      down();
    }
  }
  if(!new_events_only || new_axis[1]!=prev_axis[1]){ // if the axis value was changed or always event handling was enabled
    if(new_axis[1]>823 && (!new_events_only ||  prev_axis[1]<=823)){ // if the axis value was bigger than 823 and (always event handling was enabled or the axis value was changed)
      right();
    }
    if(new_axis[1]<200 && (!new_events_only || prev_axis[1]>=200)){ // if the axis value was smaller than 200 and (always event handling was enabled or the axis value was changed)
      left();
    }
  }
  prev_axis[0] = new_axis[0];
  prev_axis[1] = new_axis[1];
}

void Joystick::directional_loop(void (*up)(void), void (*right)(void), void (*down)(void), void (*left)(void)){
  directional_loop(up, right, down, left, false);
}

#endif