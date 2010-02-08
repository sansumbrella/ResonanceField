#pragma once

#include <WProgram.h>
#include "SensorData.h"
#include "PinUpdater.h"
#include "Plate.h"

class ResonanceApplication{
public:
	ResonanceApplication();
	void setup();
	void update();
	void usePin(int pin);
private:
	void changeTimeSegment();
	int pinsUsed;
	unsigned long mLastUpdate, mUpdateTime;
	
	Plate mPlates[data::numSensors];
};