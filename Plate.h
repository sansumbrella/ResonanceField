#pragma once

#include "SensorData.h"
#include "PinUpdater.h"

class Plate{
public:
	void setPin(int id){ mPin.setPin(id); }
	void setSensorID(int id){ mSensor.setID(id); }
	void update();
	void nextTimeSegment();
private:
	PinUpdater mPin;
	int mId, mIndex;
	SensorData mSensor;
};