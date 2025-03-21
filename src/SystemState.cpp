#include "SystemState.h"

// Define the Singleton instance retrieval function
SystemState &SystemState::getInstance()
{
    static SystemState instance;
    return instance;
}

// Constructor implementation (default values)
SystemState::SystemState() : mode(SHOW_RPM), currentOption(MOTOR1)
{
    rpm[MOTOR1] = 0;
    rpm[MOTOR2] = 0;
}
