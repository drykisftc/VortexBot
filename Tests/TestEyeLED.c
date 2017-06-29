#include <EyeLED.h>

EyeLED * eyes = 0;

void setup(){
    eyes = new EyeLED();
}
 
void loop(){
    eyes->setEmotion(EyeLED::EyeColor::RED, EyeLED::Emotion::SMILE);
}