#include <EyeLED.h>

EyeLED::EyeLED() {
	Wire.begin(); // join i2c bus (address optional for master)
	setEmotion(EyeColor::WHITE, Emotion::STANDARD);
}

EyeLED::~EyeLED() {}

EyeLED::setEmotion(EyeColor eyecolor, Emotion emotion) {
	Wire.beginTransmission(I2C_LED_ADDRESS << 1 | I2C_WRITE); // transmit to device #4
	Wire.write(eyecolor);       
	Wire.write(emotion);      
	Wire.endTransmission(); 
}