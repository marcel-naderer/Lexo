#ifndef LEXO_H
#define LEXO_H

#include <Wire.h>
#include <Adafruit_INA219.h>
#include "LexoConfig.h"

class Lexo {
public:
    Lexo();
    void begin(LexoConfig config = LexoConfig());

    // Sensor reads
    float readBatteryVoltage();
    float readMotorCurrent();
    void readIMU(float &x, float &y, float &z); // Placeholder
    int readForceSensor(uint8_t index);
    int readEMG();
    bool readButton(uint8_t index);



    // Actuator control
    void setMotor(int speed); // speed: -255 to 255
    void setBuzzer(bool on);
    void setRGB(uint8_t r, uint8_t g, uint8_t b);
    void setVibration(uint8_t index, bool on);

    // Motor Controller 
    void setupPID(float kp, float ki, float kd, float uMin = -255, float uMax = 255);
    void resetPID();
    float LexoPID(float target, float current);

private:
    LexoConfig pins;
    Adafruit_INA219 inaMotor, inaBattery;
    float _kp, _ki, _kd;
    float _pid_integral;
    float _pid_prev_error;
    float _pid_uMin, _pid_uMax;

};

#endif
