#include <PWMMotor.h>
#include <InterruptEncoder.h>

PWMMotor * leftMotor =0;
PWMMotor * rightMotor = 0;
InterruptEncoder * leftEncoder = 0;
InterruptEncoder * rightEncoder = 0;

long interruptLeftEncoder = 0;
int leftEncoderPin = 0;
long interruptRightEncoder = 0;
int rightEncoderPin = 1;

void interruptLeftEncoderCallBack() {
      interruptLeftEncoder++;
}

void interruptRightEncoderCallBack() {
      interruptRightEncoder++;
}

void setup() {
      leftMotor = new PWMMotor(9,5,false);
        rightMotor = new PWMMotor(10,6,false);
          leftEncoder = new InterruptEncoder(leftEncoderPin, &interruptLeftEncoder);
            rightEncoder = new InterruptEncoder(rightEncoderPin, &interruptRightEncoder);
              leftEncoder->reset();
                rightEncoder->reset();
                  rightEncoder->start(interruptRightEncoderCallBack);
                    leftEncoder->start(interruptLeftEncoderCallBack);
                      Serial.begin(9600);
}

void loop() {
      // put your main code here, to run repeatedly:
      //   leftMotor->setPower(255);
      //     rightMotor->setPower(255);
      //       int lPos = leftEncoder->getPosition();
      //         int rPos = rightEncoder->getPosition();
      //
      //           Serial.print("left wheel pos:");
      //             Serial.println(lPos);
      //               Serial.print("right wheel pos:");
      //                 Serial.println(rPos);
      //                  
      //                  }
      //
      //                  void cleanup() {
      //                     if (leftMotor) delete leftMotor;
      //                        if (rightMotor) delete rightMotor;
      //                           if (leftEncoder) delete leftEncoder;
      //                              if (rightEncoder) delete rightEncoder;
      //                              }
      //
