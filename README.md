# A joystick library for Arduino Uno

This is a joystick library to get values of axis and button.

## Documentation

```cpp
// Create Joystick Object with
Joystick(int rx_pin, int ry_pin, int button_pin);
// or
Joystick(int rx_pin, int ry_pin, int button_pin, int dead_zone);

// Get axis values
int Joystick::get_x_axis(void); // of x
int Joystick::get_y_axis(void); // of y

// Get button state
bool Joystick::get_button_state(void);

// Handle button events
void Joystick::button_loop(void (*press)(void), void (*release)(void));

// Handle axis events
void Joystick::axis_loop(void (*x_axis)(int), void (*y_axis)(int)); // new_events_only=false
// or
void Joystick::axis_loop(void (*x_axis)(int), void (*y_axis)(int), bool new_events_only);

// Handle directional events
void Joystick::directional_loop(void (*up)(void), void (*right)(void), void (*down)(void), void (*left)(void)); // new_events_only=false
// or
void Joystick::directional_loop(void (*up)(void), void (*right)(void), void (*down)(void), void (*left)(void), bool new_events_only);
```

## Wiring Diagram

<center>

![Wiring Diagram](./assets/wiring-diagram.svg "Wiring Diagram")

</center>

## License

> This library licensed by MIT-License.

* `assets/cover.png` licensed by CC BY-SA 4.0. Authors: malisipi & craiyon.com
