#include "ResonanceApplication.h"

ResonanceApplication::ResonanceApplication(){
	mUpdateTime = 2001;
	
	pinsUsed = 0;
	
	for(int i=0; i!=data::numSensors; i++){
		mPlates[i].setSensorID(i);
	}
}

void ResonanceApplication::setup(){	
	Serial.begin(9600);
	Serial.println("Starting ResonanceApplication");
	
	for(int i=0; i!=data::numSensors; i++){
		mPlates[i].nextTimeSegment();
	}
}

void ResonanceApplication::update(){
	for(int i=0; i!=data::numSensors; i++){
		mPlates[i].update();
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
		mPlates[i].nextTimeSegment();
	}
}

//use the specified pin for output
//more pins than sensors will roll back to the first sensor
void ResonanceApplication::usePin(int pin){
	mPlates[pinsUsed++].setPin(pin);
}