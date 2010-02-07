#pragma once

#include "RawData.h"

/**
A simple iterator to step through sensor data.
Wraps back to zero from end
*/

struct SensorData{
public:
	SensorData();
	void setID(int id){ mId = id; };
	float nextReading();
private:
	int mId;
	int mIndex;
};