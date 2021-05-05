/*
	API for TurboShield hardware.
	Initial version.
	Incomplete API in development phase.
	
	 This code is part of the AutomationShield hardware and software
  	ecosystem. Visit http://www.automationshield.com for more
  	details. This code is licensed under a Creative Commons
  	Attribution-NonCommercial 4.0 International License.
*/
#ifndef TURBOSHIELD_H_
#define TURBOSHIELD_H_
#include"Arduino.h"
#include"Wire.h"
#include"AutomationShield.h"

class TurboShieldClass{
public:
	void begin();
	float sensorRead();
	void actuatorWrite(float percentValue);
	void actuatorWriteVolt(float voltageValue);
	float referenceRead();
};
extern TurboShieldClass TurboShield;
#endif
