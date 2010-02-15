#include "Plate.h"

void Plate::nextTimeSegment(){
	// mPin.setRate(mSensor.nextReading());
	mPin.setUpdateInterval(mSensor.nextReading());
}

void Plate::update(){
	mPin.update();
}