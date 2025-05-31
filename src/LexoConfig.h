#ifndef LEXO_CONFIG_H
#define LEXO_CONFIG_H

struct LexoConfig {
    // Buttons
    int buttonPins[3] = {21, 19, 35};

    // Force & EMG
    int forcePins[2] = {32, 33};
    int emgPin = 34;

    // Vibration motors
    int vibPins[3] = {4, 16, 17};

    // RGB LED
    int ledR = 14;
    int ledG = 12;
    int ledB = 13;

    // Buzzer
    int buzzerPin = 25;

    // Motor control
    int motorPWMPin = 26;
    int motorDirPin = 27;

    // I2C bus
    int sda = 21;
    int scl = 22;
};

#endif
