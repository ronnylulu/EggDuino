#pragma once

// no homing sequence, switch-on position of pen will be taken as reference point.
// No collision-detection!!
// Supported Servos: I do not know, I use Arduino Servo Lib with TG9e- standard servo.
// Note: Maximum-Speed in Inkscape is 1000 Steps/s. You could enter more, but then Pythonscript
// sends nonsense.
// EBB-Coordinates are coming in for 16th-Microstepmode. The number of steps per revolution
// can be adjusted in eggbot_conf.py from the inkscape plugin.

#include "config.h"
#include "EBBParser.h"
#include "Button.h"

#include <AccelStepper.h>
#include <VarSpeedServo.h>

class EBBHardware : public EBBParser {
public:
    EBBHardware(Stream& stream);

    void init();

    virtual void processEvents();

protected:
    virtual void enableMotor(int axis, bool state);
    virtual void stepperMove(int duration, int numPenSteps, int numRotSteps);

    virtual void setPenState(bool up);
    virtual bool getPenState();
    virtual void setPenUpPos(int pos);
    virtual void setPenDownPos(int pos);

    virtual void setServoRateUp(int rate);
    virtual void setServoRateDown(int rate);

    virtual bool getPrgButtonState();

    virtual void setPinOutput(char port, int pin, int value);

    virtual void setEngraverState(bool state, int power);

private:
    bool moveOneStep();
    void moveToDestination();

    AccelStepper rotMotor;
    AccelStepper penMotor;
    VarSpeedServo penServo;

    bool penState;
    short penUpPos; // eeprom!
    short penDownPos; // eeprom!

    short servoRateUp; // eeprom
    short servoRateDown; // eeprom

    bool motorEnabled;

    bool prgButtonState;

// create Buttons
#ifdef PRG_BUTTON_PIN
    Button prgButtonToggle;
#endif
#ifdef PEN_TOGGLE_BUTTON_PIN
    Button penToggle;
#endif
#ifdef MOTORS_BUTTON_PIN
    Button motorsToggle;
#endif
};
