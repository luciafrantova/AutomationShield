#ifndef TURBOSHIELD_H_
#define TURBOSHIELD_H_
#include<Arduino.h>
#include<Wire.h>

class TurboShieldClass(){
public:
	void begin();
	float sensorRead();
	void actuatorWrite(float percentValue);
	void actuatorWriteVolt(float voltageValue);
};
extern TurboShieldClass TurboShield;
#endif