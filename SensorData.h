#pragma once

#include <WProgram.h>
#include "RawData.h"

/**
A simple iterator to step through sensor data.
Wraps back to zero from end
*/

struct SensorData{
public:
	SensorData();
	void setID(int id){ mId = id; };
	prog_uint16_t nextReading();
	prog_uint16_t readingAt(int index);
private:
	int mId;
	int mIndex;
};