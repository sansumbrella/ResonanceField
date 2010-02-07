#pragma once
#include "RawData.h"
#include "SensorData.h"

struct EQData{
	EQData();
	SensorData mSensors[data::numSensors];
};