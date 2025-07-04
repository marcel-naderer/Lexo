#include "Lexo.h"

Lexo::Lexo() {}

void Lexo::begin(LexoConfig config) {
    pins = config;

    Wire.begin(pins.sda, pins.scl);

    inaMotor = Adafruit_INA219(0x40);
    inaBattery = Adafruit_INA219(0x41);
    inaMotor.begin();
    inaBattery.begin();


    pinMode(pins.buttonPins[1], INPUT_PULLUP);
    pinMode(pins.vibPins[1], OUTPUT);	
    pinMode(pins.buttonPins[2], INPUT_PULLUP);
    pinMode(pins.vibPins[2], OUTPUT);	
    pinMode(pins.buttonPins[3], INPUT_PULLUP);
    pinMode(pins.emgPin, INPUT);	
    pinMode(pins.ledR, OUTPUT);
    pinMode(pins.ledG, OUTPUT);
    pinMode(pins.ledB, OUTPUT);
    pinMode(pins.buzzerPin, OUTPUT);
    pinMode(pins.motorPWMPin, OUTPUT);
    pinMode(pins.motorDirPin, OUTPUT);
}

float Lexo::readBatteryVoltage() {
    return inaBattery.getBusVoltage_V();
}

float Lexo::readMotorCurrent() {
    return inaMotor.getCurrent_mA();
}



int Lexo::readForceSensor(uint8_t index) {
    if (index >= 2) return -1;
    return analogRead(pins.forcePins[index]);
}

int Lexo::readEMG() {
    return analogRead(pins.emgPin);
}

bool Lexo::readButton(uint8_t index) {
    if (index >= 3) return false;
    return digitalRead(pins.buttonPins[index]) == LOW;
}

void Lexo::setMotor(int speed) {
    bool dir = speed >= 0;
    digitalWrite(pins.motorDirPin, dir);
    analogWrite(pins.motorPWMPin, abs(speed));
}

void Lexo::setBuzzer(bool on) {
    digitalWrite(pins.buzzerPin, on);
}

void Lexo::setRGB(uint8_t r, uint8_t g, uint8_t b) {
    analogWrite(pins.ledR, !r);
    analogWrite(pins.ledG, !g);
    analogWrite(pins.ledB, !b);
}

void Lexo::setVibration(uint8_t index, bool on) {
    if (index >= 2) return;
    digitalWrite(pins.vibPins[index], on);
}
void Lexo::setupPID(float kp, float ki, float kd, float uMin, float uMax) {
    _kp = kp;
    _ki = ki;
    _kd = kd;
    _pid_integral = 0;
    _pid_prev_error = 0;
    _pid_uMin = uMin;
    _pid_uMax = uMax;
}

void Lexo::resetPID() {
    _pid_integral = 0;
    _pid_prev_error = 0;
}

float Lexo::positionControlPID(float target, float actVal) {
    float error = target - actVal;
    float derivative = error - _pid_prev_error;
    

    // Anti-windup: only integrate when within limits
    if (output < _pid_uMax && output > _pid_uMin) {
        _pid_integral += error;
    }

    float output = _kp * error + _ki * _pid_integral + _kd * derivative;

    // Saturate output
    if (output > _pid_uMax) output = _pid_uMax;
    if (output < _pid_uMin) output = _pid_uMin;

    _pid_prev_error = error;
    return output;
}


    return -1;
}
