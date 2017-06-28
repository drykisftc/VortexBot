#include <PWMMotor.h>
#include <InterruptEncoder.h>

PWMMotor * leftMotor =0;
PWMMotor * rightMotor = 0;

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

void setup() {
  leftMotor = new PWMMotor(9,5,false);
  leftMotor->setEncoder(leftEncoderPin,&interruptLeftEncoder,forwardLeftEncoderCallBack,backwardLeftEncoderCallBack);
  rightMotor = new PWMMotor(10,6,false);
  rightMotor->setEncoder(rightEncoderPin,&interruptRightEncoder,forwardRightEncoderCallBack,backwardRightEncoderCallBack);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  leftMotor->setPower(-155);
  rightMotor->setPower(155);
  int lPos = leftMotor->getPosition();
  int rPos = rightMotor->getPosition();

  Serial.print("left wheel pos:");
  Serial.println(lPos);
  Serial.print("right wheel pos:");
  Serial.println(rPos);
}

void cleanup() {
  if (leftMotor) delete leftMotor;
  if (rightMotor) delete rightMotor;
}

