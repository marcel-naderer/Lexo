#include <Lexo.h>

Lexo lexo;

void setup() {
    Serial.begin(115200);
    lexo.begin();  // Initialize library with default pin settings
}

void loop() {
    float batt = lexo.readBatteryVoltage();
    float current = lexo.readMotorCurrent();
    int angle = lexo.readMotorAngle(); // from AS5600

    Serial.print("Battery: "); Serial.print(batt); Serial.print(" V, ");
    Serial.print("Motor Current: "); Serial.print(current); Serial.print(" mA, ");
    Serial.print("Angle: "); Serial.println(angle);

    delay(1000);
}
