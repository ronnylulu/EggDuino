#include "config.h"
#include "EBBHardware.h"
#include "Button.h"

EBBHardware ebb(Serial);

// Buttons
#define PRG_BUTTON_PIN A2 // PRG button ("Abort")
#define PEN_TOGGLE_BUTTON_PIN A1 // pen up/down button ("Hold")
#define MOTORS_BUTTON_PIN A0 // motors enable button ("Resume")

void toggleMotors()
{
    ebb.doToggleMotors();
}

void setprgButtonState()
{
    ebb.doPrgButtonState();
}

void togglePen()
{
    ebb.doTogglePen();
}

//create Buttons
#ifdef PRG_BUTTON_PIN
Button prgButtonToggle(PRG_BUTTON_PIN, setprgButtonState);
#endif
#ifdef PEN_TOGGLE_BUTTON_PIN
Button penToggle(PEN_TOGGLE_BUTTON_PIN, togglePen);
#endif
#ifdef MOTORS_BUTTON_PIN
Button motorsToggle(MOTORS_BUTTON_PIN, toggleMotors);
#endif

void setup()
{
    Serial.begin(9600);
    ebb.init();
}

void loop()
{
    ebb.processEvents();

#ifdef PEN_TOGGLE_BUTTON_PIN
    penToggle.check();
#endif

#ifdef MOTORS_BUTTON_PIN
    motorsToggle.check();
#endif

#ifdef PRG_BUTTON_PIN
    prgButtonToggle.check();
#endif
}
