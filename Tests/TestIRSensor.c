#include <IRSensor.h>
#include <PWMMotor.h>
#include <InterruptEncoder.h>


IRSensor * irsensor = 0;

PWMMotor * leftMotor =0;
PWMMotor * rightMotor = 0;

int count = 0;
int state = 0;

long interruptLeftEncoder = 0;
int leftEncoderPin = 0;
long interruptRightEncoder = 0;
int rightEncoderPin = 1;

void forwardLeftEncoderCallBack() {
  interruptLeftEncoder++;
}

void forwardRightEncoderCallBack() {
  interruptRightEncoder++;
}

void backwardLeftEncoderCallBack() {
  interruptLeftEncoder--;
}

void backwardRightEncoderCallBack() {
  interruptRightEncoder--;
}


ISR(PCINT2_vect){           //motor encoder interrupt
    count++;
}


void chaseBall () {
    switch (state) {
        case 0: {
            count = 0;
            state = 1; 
            irsensor->leftCount = 0; 
            irsensor->rightCount = 0; 
            break;
        }
        case 1: {
            // send one left pulse
            int timeElapse = 0;
            for(int i=0;i<20;i++){  //left transmitter sends 20 pulses
                irsensor->leftSend38KHZ();
                delayMicroseconds(600);
            }
            state = 2;
            break;
        }
        case 2: {
            // read count
            irsensor->leftCount = count;
            if (irsensor->leftCount > 10)
            {
              leftMotor->setPower(-155);
              delay(500);
              leftMotor->setPower(155);
            }
            else{
              leftMotor->setPower(155);
              rightMotor->setPower(155);
            }
            state = 3;
            break;
        }
        case 3: {
            // send on right pulse
            for(int i=0;i<20;i++){  //left transmitter sends 20 pulses
                irsensor->rightSend38KHZ();
                delayMicroseconds(600);
            }
            //if time elapse > 0.05 second go to next state
            state = 4;
            break;
        }
        case 4: {
            // read count
            irsensor->rightCount = count;
            if (irsensor->rightCount > 10)
            {
                rightMotor->setPower(-155);
                //Serial.println("##########RIGHT#########");
                delay(500);
                rightMotor->setPower(155);

            }
            else{
                leftMotor->setPower(155);
                rightMotor->setPower(155);
            }
            state = 5;
            //lastTime = millsec();
            
            break;
        } 
        case 5: {
            // action turn left/right based on left count or right count;
            if (irsensor->leftCount >0 && irsensor->rightCount > 0) {
                leftMotor->setPower(-155);
                rightMotor->setPower(-155);
                delay(300);
                leftMotor->setPower(155);
                rightMotor->setPower(155);
            }
            state = 0;
            break;
        }
    }
}

void setup(){
    //setup IR sensor
    irsensor = new IRSensor(8, 12, 7);

    //setup motor
    leftMotor = new PWMMotor(9,5,false);
    leftMotor->setEncoder(leftEncoderPin,&interruptLeftEncoder,forwardLeftEncoderCallBack,backwardLeftEncoderCallBack);
    rightMotor = new PWMMotor(10,6,false);
    rightMotor->setEncoder(rightEncoderPin,&interruptRightEncoder,forwardRightEncoderCallBack,backwardRightEncoderCallBack);

    leftMotor->setPower(155);
    rightMotor->setPower(155);

    Serial.begin(9600); 
}

void loop(void){
    chaseBall();

}

void cleanup() {
    if (irsensor) delete irsensor;
    if (leftMotor) delete leftMotor;
    if (rightMotor) delete rightMotor;
}
