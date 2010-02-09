#include "SensorData.h"

SensorData::SensorData(){
	mIndex = 0;
}

/**
Return the sensor value at this station and point to the next one
*/
float SensorData::nextReading(){
	if(mIndex >= data::numValues){
		mIndex = 0;
	}
	return pgm_read_byte_near(data::raw[mId] + (mIndex++));
}