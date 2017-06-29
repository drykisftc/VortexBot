#ifndef _ir_sensor_
#define _ir_sensor_

#include "Arduino.h"

class IRSensor
{
	public:

		int leftCount;
		int rightCount;
		
		IRSensor(int leftTransmitterPin, int rightTransmitterPin, int irReceiverPin);
		virtual ~IRSensor();
		void pcint0Init();
		void leftSend38KHZ();
		void rightSend38KHZ();


	protected:
		int leftTransmitterPin;
		int rightTransmitterPin;
		int irReceiverPin;
		
	
};

#endif

