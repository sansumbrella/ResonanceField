#include "EQData.h"

EQData::EQData(){
	for(int i=0; i!=data::numSensors; i++){
		mSensors[i].init(i);
	}
}