#include "Lexo.h"

Lexo::Lexo() {}

void Lexo::begin(LexoConfig config) {
    pins = config;

    Wire.begin(pins.sda, pins.scl);

    inaMotor = Adafruit_INA219(0x40);
    inaBattery = Adafruit_INA219(0x41);
    inaMotor.begin();
    inaBattery.begin();

    for (int i = 0; i < 3; i++) {
        pinMode(pins.buttonPins[i], INPUT_PULLUP);
        pinMode(pins.vibPins[i], OUTPUT);
    }

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

void Lexo::readIMU(float &x, float &y, float &z) {
    // Placeholder for IMU code
    x = y = z = 0;
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
    analogWrite(pins.ledR, r);
    analogWrite(pins.ledG, g);
    analogWrite(pins.ledB, b);
}

void Lexo::setVibration(uint8_t index, bool on) {
    if (index >= 3) return;
    digitalWrite(pins.vibPins[index], on);
}

int Lexo::readMotorAngle() {
    Wire.beginTransmission(0x36); // AS5600 default address
    Wire.write(0x0E); // Angle register MSB
    Wire.endTransmission();
    Wire.requestFrom(0x36, 2);
    if (Wire.available() == 2) {
        int high = Wire.read();
        int low = Wire.read();
        return ((high & 0x0F) << 8) | low; // 12-bit angle
    }
    return -1;
}
