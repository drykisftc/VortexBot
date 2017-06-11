#include <PWMMotor.h>

PWMMotor::PWMMotor (int dP, int pP, bool bR) {
    pinDirection = dP;
    pinPWM = pP;
    bReversed = bR;
    pEncoder = 0;
    pForwardCallBack = 0;
    pBackwardCallBack = 0; 
    nLastPower = 0;   
    pinMode(pinDirection, OUTPUT);  
}

PWMMotor::~PWMMotor () {
    if (pEncoder) delete pEncoder;
}

void PWMMotor::setPower (int power) {
    if (bReversed) {
        power *= -1;
    }
    if ( power > 0 ) {
        digitalWrite(pinDirection,HIGH);
        if (pForwardCallBack && nLastPower<=0) {
            pEncoder->start(pForwardCallBack);
        }
    } else {
        digitalWrite(pinDirection,LOW);
        if (pBackwardCallBack && nLastPower>=0) {
            pEncoder->start(pBackwardCallBack);
        }
    }   
    nLastPower = power;
    analogWrite(pinPWM, abs(power));
}

void PWMMotor::setEncoder( int encoderPin, 
                           long * encoderInterrupt,
                           void (*forwardCallBack)(),
                           void (*backwardCallBack)() ) {
    if (pEncoder) { delete pEncoder ; }
    pEncoder = new InterruptEncoder(encoderPin, encoderInterrupt);
    pEncoder->reset();
    pForwardCallBack = forwardCallBack;
    pBackwardCallBack = backwardCallBack;
}

long PWMMotor::getPosition () {
    if (pEncoder) {
        return pEncoder->getPosition();
    } else {
        return 0;
    }
}

void PWMMotor::resetEncoder() {
    if (pEncoder) pEncoder->reset();
}
