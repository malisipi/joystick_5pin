class Joystick {
  public:
    Joystick(int rx_pin, int ry_pin, int button_pin);
    Joystick(int rx_pin, int ry_pin, int button_pin, int dead_zone);
    int get_x_axis(void);
    int get_y_axis(void);
    bool get_button_state(void);
    void button_loop(void (*press)(void), void (*release)(void));
    void axis_loop(void (*x_axis)(int), void (*y_axis)(int));
    void axis_loop(void (*x_axis)(int), void (*y_axis)(int), bool new_events_only);
    void directional_loop(void (*up)(void), void (*right)(void), void (*down)(void), void (*left)(void));
    void directional_loop(void (*up)(void), void (*right)(void), void (*down)(void), void (*left)(void), bool new_events_only);
    int rx_pin;
    int ry_pin;
    int button_pin;
    int dead_zone;
  private:
    bool prev_state;
    int prev_axis [2];
};
