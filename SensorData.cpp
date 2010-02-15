#include "SensorData.h"

SensorData::SensorData(){
	mIndex = 0;
}

/**
Return the sensor value at this station and point to the next one
*/
prog_uint SensorData::nextReading(){
	if( mIndex >= data::numValues ){
		mIndex = 0;
	}
	prog_uint16_t val = pgm_read_word_near( data::raw[mId][mIndex] );
	mIndex++;
	Serial.print("Getting reading of: ");
	Serial.print(val);
	return val;
}