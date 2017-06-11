#ifndef _interrupt_encoder_
#define _interrupt_encoder_

#include <arduino.h>

class InterruptEncoder {
    public:
        InterruptEncoder (int pin, long * interrupt);
        unsigned long getPosition ();
        void start (void (pulseCallBack)());
        void reset ();
    protected:
        int pinInterrupt;
        long * pPulse;
};

#endif

