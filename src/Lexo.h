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
    int readMotorAngle(); // AS5600

    // Actuator control
    void setMotor(int speed); // speed: -255 to 255
    void setBuzzer(bool on);
    void setRGB(uint8_t r, uint8_t g, uint8_t b);
    void setVibration(uint8_t index, bool on);

private:
    LexoConfig pins;
    Adafruit_INA219 inaMotor, inaBattery;
    int readAS5600();
};

#endif
