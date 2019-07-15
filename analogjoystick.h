#ifndef ANALOGJOYSTICK_H
#define ANALOGJOYSTICK_H
#include <stdint.h>
struct JoystickState
{
    uint8_t FilterKoef[3];
    int64_t raw[3];
    uint16_t center[3];
    uint16_t deadZone[3];

    int Out[3];
    uint16_t volume[3];
    uint8_t rev[3];

    uint8_t offset[3];
};

class AnalogJoystick3Axis
{
public:
    AnalogJoystick3Axis();
    ~AnalogJoystick3Axis();
    JoystickState State;
    void Init();
    void Process(void);
    void CalibrateZeros();
    int8_t Rail;
    int8_t F1;
    int8_t F2;

private:
    void ReadRaw();
    void ApplyValueAndOffset();
};

#endif // ANALOGJOYSTICK_H
