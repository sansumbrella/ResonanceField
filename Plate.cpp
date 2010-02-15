#include "Plate.h"

void Plate::nextTimeSegment(){
	// mPin.setRate(mSensor.nextReading());
	mPin.setUpdateInterval(mSensor.nextReading());
}

void Plate::update(){
	mPin.update();
}

void Plate::printValues(){
	Serial.print("Sensor values: [");
	for(int i=0; i!=10; i++){
		Serial.print( mSensor.readingAt(i) );
		Serial.print(",");
	}
	Serial.println("]");
}