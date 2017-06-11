#ifndef _pwm_motor_
#define _pwm_motor_

#include "Arduino.h"
#include <InterruptEncoder.h>

class PWMMotor {

    public:
        PWMMotor (int directionPin, int pwmPin, bool bReverse);
        virtual ~PWMMotor ();
        void setPower (int power);
        void setEncoder( int encoderPin,
                         long * encoderInterrupt,
                         void (*forwardCallBack)(),
                         void (*backwardCallBack)());
        long getPosition();
        void resetEncoder();
    protected:
        int pinDirection, pinPWM;
        bool bReversed;
        InterruptEncoder * pEncoder;
        void (*pForwardCallBack)();
        void (*pBackwardCallBack)();
        int nLastPower;
};
#endif
