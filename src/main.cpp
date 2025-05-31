#include <Lexo.h>


Lexo lexo;

void setup() {
    Serial.begin(115200);
    lexo.begin(); // Use defaults
}

void loop() {
    int angle = lexo.readMotorAngle();
    Serial.print("Angle: ");
    Serial.println(angle);

    float current = lexo.readMotorCurrent();
    Serial.print("Motor Current: ");
    Serial.println(current);

    lexo.setVibration(0, true);
    delay(100);
    lexo.setVibration(0, false);
    delay(900);
}
