#include <InterruptEncoder.h>

InterruptEncoder::InterruptEncoder( int pin, long * pInterrupt) {
    pinInterrupt = pin;
    pPulse = pInterrupt;
}

void InterruptEncoder::start(void (pulseCallBack)()) {
    attachInterrupt(pinInterrupt,pulseCallBack,CHANGE);
    sei();
}

unsigned long InterruptEncoder::getPosition() {
    return *pPulse;
}

void InterruptEncoder::reset () {
    *pPulse = 0;
}



