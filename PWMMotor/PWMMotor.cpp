#include <PWMMotor.h>

PWMMotor::PWMMotor (int dP, int pP, bool bR) {
    pinDirection = dP;
    pinPower = pP;
    bReversed = pR;
    pinMode(pinDirection, OUTPUT);  
}

void PWMMotor::setPower (int power) {
    if (bReversed) {
        power *= -1;
    }
    if ( power > 0 ) {
        digitalWrite(pinDirection,HIGH);
    } else {
        digitalWrite(pinDirection,LOW);
    }   
    analogWrite(pinPower, abs(value));
}

