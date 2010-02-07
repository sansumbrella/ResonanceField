#pragma once

#include <WProgram.h>
#include "EQData.h"

class ResonanceApplication{
public:
	ResonanceApplication();
	void setup();
	void update();
private:
	int ledPin;
	EQData data;
};