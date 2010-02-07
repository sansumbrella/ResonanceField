#pragma once

#include <WProgram.h>
#include "SensorData.h"

class ResonanceApplication{
public:
	ResonanceApplication();
	void setup();
	void update();
private:
	int ledPin;
	SensorData mSensors[data::numSensors];
};