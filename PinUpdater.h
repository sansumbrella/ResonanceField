#pragma once
#include <WProgram.h>

class PinUpdater{
public:
	PinUpdater();
	void setPin(int id=13){mPin = id;}
	void setRate(unsigned long herz);
	void update();
	void changeValue();
private:
	int mPin;
	bool mOn;
	unsigned long mLastUpdate, mUpdateTime, mHoldTime;
};