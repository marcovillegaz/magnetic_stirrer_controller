#ifndef SYSTEMSTATE_H
#define SYSTEMSTATE_H

#include <stdint.h>

// Enum for display modes
enum DisplayMode
{
    SHOW_RPM,
    SET_RPM
};

// Enum for motor options
enum MotorOption
{
    MOTOR1,
    MOTOR2
};

// Shared system state class
class SystemState
{
public:
    DisplayMode mode;
    MotorOption currentOption;
    int rpm[2]; // RPM values for each motor, is a list

    // Singleton pattern: Get the global state instance
    static SystemState &getInstance();

private:
    // Class constructor
    SystemState();
    // Prevent copying
    SystemState(const SystemState &) = delete;
    SystemState &operator=(const SystemState &) = delete;
};

#endif
