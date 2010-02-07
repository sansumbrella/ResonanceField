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
private:
	void changeTimeSegment();
	int ledPin;
	unsigned long mLastUpdate, mUpdateTime;
	
	Plate mPlates[data::numSensors];
};