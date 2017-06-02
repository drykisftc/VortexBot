#ifndef _pwm_motor_
#define _pwm_motor_

#include "Arduino.h"

class PWMMotor {

    public:
        PWMMotor (int directionPin, int pwmPin, bool bReverse);
        void setPower (int power);
    protected:
        int pinDirection, pinPWM;
        bool bReversed;
};
#endif
