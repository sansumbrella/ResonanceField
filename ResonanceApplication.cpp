#include "ResonanceApplication.h"

ResonanceApplication::ResonanceApplication(){
	mUpdateTime = 2001;
	
	pinsUsed = 0;
	mPlates[0].setDataset(data::data1);
	mPlates[1].setDataset(data::data2);
	// mPlates[2].setDataset(data::data3);
	// mPlates[3].setDataset(data::data4);
	// mPlates[4].setDataset(data::data5);
	// mPlates[5].setDataset(data::data6);
	// mPlates[6].setDataset(data::data7);
	// mPlates[7].setDataset(data::data8);
	// mPlates[8].setDataset(data::data9);
	for(int i=0; i != data::numSensors; ++i){
		usePin(i);
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