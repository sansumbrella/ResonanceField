#include "PinUpdater.h"

PinUpdater::PinUpdater(){
	mHoldTime = 10;
}

void PinUpdater::setRate(unsigned long hz){
	//change value every half herz cycle (on for half the time, off for half, might need tweaking)
	hz = min(100, hz)
	mUpdateTime = (float)1.0f/hz * 1000.0f;
	Serial.print("Rate set to: ");
	Serial.print(hz);
	Serial.print("hz, millis: ");
	Serial.println(mUpdateTime);
}

void PinUpdater::update(){
	if(mOn && (millis() - mLastUpdate > mHoldTime) ){
		//switch off after min hold time elapsed
		changeValue();
	}
	
	if( millis() - mLastUpdate > mUpdateTime ){
		//switch on
		changeValue();
	}
}

void PinUpdater::changeValue(){
	mOn = !mOn;
	mLastUpdate = millis();
	
	if(mOn){
		digitalWrite(mPin, HIGH);
	} else {
		digitalWrite(mPin, LOW);
	}
}