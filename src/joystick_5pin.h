class Joystick
{
  public:
    Joystick(int rx_pin, int ry_pin, int button_pin);
    Joystick(int rx_pin, int ry_pin, int button_pin, int dead_zone);
    int get_x_axis(void);
    int get_y_axis(void);
    bool get_button_state(void);
    void button_loop(void (*press)(void), void (*release)(void));
    int rx_pin;
    int ry_pin;
    int button_pin;
    int dead_zone;
  private:
    bool prev_state;
};
