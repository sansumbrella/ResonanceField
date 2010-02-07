#include "PinUpdater.h"


void PinUpdater::setRate(float hz){
	//change value every half herz cycle (on for half the time, off for half, might need tweaking)
	mUpdateTime = hz * 60.0f/1000.0f/2.0f;
}

void PinUpdater::update(){
	if(millis() - mLastUpdate > mUpdateTime){
		changeValue();
	}
}

void PinUpdater::changeValue(){
	mOn = !mOn;
	
	if(mOn){
		digitalWrite(mPin, HIGH);
	} else {
		digitalWrite(mPin, LOW);
	}
}