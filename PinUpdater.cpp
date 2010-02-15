#include "PinUpdater.h"

PinUpdater::PinUpdater(){
	mHoldTime = 5;
}

void PinUpdater::setRate(char hz){
	//change value every half herz cycle (on for half the time, off for half, might need tweaking)
	mUpdateTime = (float)1.0f/hz * 1000.0f;
	Serial.print("Rate set to: ");
	Serial.print(hz);
	Serial.print("hz, millis: ");
	Serial.println(mUpdateTime);
}

void PinUpdater::setUpdateInterval(int millis){
	mUpdateTime = millis;
	Serial.print("Rate set to millis: ");
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

void PinUpdater::setPin(int id){
	mPin = id;
	pinMode(mPin, OUTPUT);
	Serial.print("Pin set to: ");
	Serial.println(id);
}