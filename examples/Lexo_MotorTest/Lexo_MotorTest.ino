#include <Lexo.h>

Lexo lexo;

void setup() {
    lexo.begin();
    Serial.begin(115200);
}

void loop() {
    Serial.println("Running motor forward...");
    lexo.setMotor(200);  // Speed from 0 to 255
    lexo.setVibration(0, true);
    lexo.setRGB(255, 0, 0);  // Red

    delay(2000);

    Serial.println("Running motor reverse...");
    lexo.setMotor(-200);
    lexo.setVibration(0, false);
    lexo.setRGB(0, 0, 255);  // Blue

    delay(2000);

    lexo.setMotor(0);
    lexo.setRGB(0, 255, 0);  // Green
    delay(1000);
}
