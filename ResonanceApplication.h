#pragma once

#include <WProgram.h>
#include "SensorData.h"
#include "PinUpdater.h"

class ResonanceApplication{
public:
	ResonanceApplication();
	void setup();
	void update();
private:
	void changeTimeSegment();
	int ledPin;
	unsigned long mLastUpdate, mUpdateTime;
	
	PinUpdater mPins[data::numSensors];
	SensorData mSensors[data::numSensors];
};