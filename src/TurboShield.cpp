#include"TurboShield.h"
#include"AutomationShield.h"

#define TURBO_getH 0x0c // Sensor Register
#define TURBO_getL 0x0d
#define TURBO_sensorAddr 0x36
#define TURBO_UPIN 5
#define TURBO_RPIN 0
#define TURBO_UVOLT 3.7
void TurboShieldClass::begin(){ //Initial method
   Wire.begin();
}
float TurboShieldClass::sensorRead(){ //Returns angle in percents
    Wire.beginTransmission(TURBO_sensorAddr); //Initialize com with sensor
    Wire.write(TURBO_getL); //Demand angle value
    Wire.endTransmission();
    Wire.requestFrom(TURBO_sensorAddr, 1); //Expecting byte
    while(!Wire.available()); //Waiting for delivery
    uint8_t byteH = Wire.read(); //Remembering the value

    Wire.beginTransmission(TURBO_sensorAddr);//Reading High byte
    Wire.write(TURBO_getH);
    Wire.endTransmission();
    Wire.requestFrom(TURBO_sensorAddr, 1);
    while(!Wire.available());
    uint8_t byteL = Wire.read();
    return AutomationShield.mapFloat((byteH<<8|byteL),0,4095,0,100);
}

void TurboShieldClass::actuatorWrite(float percentValue) {//--duty cycle for the Motor, determining angular velocity  
  analogWrite(TURBO_UPIN, AutomationShield.percToPwm(AutomationShield.constrainFloat(percentValue,0,100)));
}

void TurboShieldClass::actuatorWriteVolt(float voltageValue){ //--Expects Root Mean Square Voltage value as input  
  analogWrite(TURBO_UPIN,sq(voltageValue)*255.0/sq(TURBO_UVOLT)); //--Convert Urms -> PWM duty 8-bit
}

float TurboShieldClass::referenceRead() {//--Reads potentiometers reference value and returns it in percentage
  return AutomationShield.mapFloat((float)analogRead(TURBO_RPIN), 0.0, 1023.0, 0.0, 100.0);
}
TurboShieldClass TurboShield;