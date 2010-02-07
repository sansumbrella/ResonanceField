#include "ResonanceApplication.h"

ResonanceApplication::ResonanceApplication(){
	for(int i=0; i!=data::numSensors; i++){
		mSensors[i].init(i);
	}
}

void ResonanceApplication::setup(){
	ledPin = 13;
	digitalWrite(ledPin, HIGH);
}

void ResonanceApplication::update(){
}