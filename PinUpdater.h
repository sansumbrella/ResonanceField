#pragma once
#include <WProgram.h>

class PinUpdater{
public:
	void setPin(int id=13){mPin = id;}
	void setRate(float herz);
	void update();
	void changeValue();
private:
	int mPin;
	float mUpdateTime;
	bool mOn;
	unsigned long mLastUpdate;
	
};