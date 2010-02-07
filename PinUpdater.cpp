#include "PinUpdater.h"


void PinUpdater::setRate(unsigned long hz){
	//change value every half herz cycle (on for half the time, off for half, might need tweaking)
	mUpdateTime = (float)1.0f/hz * 1000.0f;
	Serial.print("Rate set to: ");
	Serial.print(hz);
	Serial.print("hz, millis: ");
	Serial.println(mUpdateTime);
}

void PinUpdater::update(){
	if(mOn || (millis() - mLastUpdate > mUpdateTime) ){
		changeValue();
	}
}

void PinUpdater::changeValue(){
	mOn = !mOn;
	mLastUpdate = millis();
	
	if(mOn){
		digitalWrite(mPin, HIGH);
		Serial.println("Switchin pin on");
	} else {
		digitalWrite(mPin, LOW);
	}
}