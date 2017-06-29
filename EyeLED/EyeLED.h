#ifndef _eye_led_
#define _eye_led_

#include "Arduino.h"
#include <Wire.h>

#define I2C_LED_ADDRESS  0b1100000
#define I2C_WRITE   	 0x00



class EyeLED
{
public:
	enum EyeColor
	{
		BLUE = 0x01,
		GREEN = 0x02,
		AZURE = 0x03,
		RED = 0x04,
		PURPLE = 0x05,
		YELLOW = 0x06,
		WHITE = 0x07

	};

	enum Emotion: uint8_t
	{
		//the value can be from 0 to 35
		STANDARD = 32,
		CUTE = 28,
		SERIOURS = 16,
		SLEEPY = 14,
		SMILE = 11
		//...
	};

	EyeLED();
	setEmotion(EyeColor eyecolor, Emotion emotion);
	~EyeLED();

	
};
#endif