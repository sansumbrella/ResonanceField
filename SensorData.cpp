#include "SensorData.h"

SensorData::SensorData(){
	mIndex = 0;
}

/**
Return the next sensor value at this station
*/
float SensorData::nextReading(){
	mIndex++;
	if(mIndex >= data::numValues){
		mIndex = 0;
	}
	return data::raw[mId][mIndex];
}