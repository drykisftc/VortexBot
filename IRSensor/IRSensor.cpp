 #include <IRSensor.h>

IRSensor::IRSensor(int L_IR, int R_IR, int IR_IN){
    this->leftTransmitterPin = L_IR;
    this->rightTransmitterPin = R_IR;
    this->irReceiverPin = IR_IN;
    this->leftCount = 0;
    this->rightCount = 0;


    pinMode(L_IR,OUTPUT);           //init the left transmitter pin
    pinMode(R_IR,OUTPUT);           //init the right transmitter pin
    pinMode(IR_IN,INPUT);           //init the ir receiver pin 

    pcint0Init();
    sei();                          //enable the interrupt
}

IRSensor::~IRSensor() {

}

void IRSensor::pcint0Init(void){    //init the interrupt
    PCICR |= 1 << PCIE2;
    PCMSK2 |= 1 << PCINT23;
}

void IRSensor::leftSend38KHZ(void){   //left ir transmitter sends 38kHZ pulse
    for(int i=0;i<21;i++){
        digitalWrite(this->leftTransmitterPin,LOW);
        delayMicroseconds(8);
        digitalWrite(this->leftTransmitterPin,HIGH);
        delayMicroseconds(8);
    }
}

void IRSensor::rightSend38KHZ(void){  //right ir transmitter sends 38kHZ pulse
    for(int i=0;i<21;i++){
        digitalWrite(this->rightTransmitterPin,LOW);
        delayMicroseconds(8);
        digitalWrite(this->rightTransmitterPin,HIGH);
        delayMicroseconds(8);
    }
}

