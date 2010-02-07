#include "ResonanceApplication.h"

ResonanceApplication::ResonanceApplication(){
	mUpdateTime = 2001;
	
	for(int i=0; i!=data::numSensors; i++){
		mSensors[i].init(i);
		mPins[i].setPin(13);
	}
}

void ResonanceApplication::setup(){	
	Serial.begin(9600);
	Serial.println("Starting ResonanceApplication");
	
	for(int i=0; i!=data::numSensors; i++){
		mPins[i].setRate(mSensors[i].nextReading());
	}
}

void ResonanceApplication::update(){
	for(int i=0; i!=data::numSensors; i++){
		mPins[i].update();
	}
	
	if(millis()-mLastUpdate > mUpdateTime){
		changeTimeSegment();
	}
}

void ResonanceApplication::changeTimeSegment(){
	mLastUpdate = millis();
	
	Serial.println("=====================");
	Serial.println("Changing Time Segment");
	Serial.println("=====================");
	
	for(int i=0; i!=data::numSensors; i++){
		mPins[i].setRate(mSensors[i].nextReading());
	}
}