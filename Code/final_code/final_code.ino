#include <Servo.h>

// PIN DEFINITIONS
const int LDR_TL = A0; // Top-Left
const int LDR_TR = A1; // Top-Right 
const int LDR_BL = A2; // Bottom-Left 
const int LDR_BR = A3; // Bottom-Right 
const int SERVO_H = 9; // Servo azimut (Horizontal)
const int SERVO_V = 10; // Servo elevation (Vertical)

// PARAMETERS
const int TOLERANCE = 50; // ADC counts dead-zone
const int STEP_DEG = 1; // Degrees per iteration
const int NIGHT_THR = 100; // Night-mode threshold
const int DELAY_MS = 500; // Loop delay (ms)

Servo servoH, servoV;
int posH = 90, posV = 90; // Initial positions (centre)

void setup() {
  servoH.attach(SERVO_H);
  servoV.attach(SERVO_V);
  servoH.write(posH);
  servoV.write(posV);
  Serial.begin(9600);
  Serial.println("Solar Tracker - ENSA Agadir - Initialized");
  delay(1000);
}

void loop() {
  //Read ADC value
  int v1 = analogRead(LDR_TL); // Top-Left
  int v2 = analogRead(LDR_TR); // Top-Right
  int v3 = analogRead(LDR_BL); // Bottom-Left
  int v4 = analogRead(LDR_BR); // Bottom-Right

  //Night mode check
  if (max(max(v1, v2), max(v3, v4)) < NIGHT_THR) {
    servoH.write(90);
    servoV.write(90); // Reset to East
    Serial.println("Night mode - sleeping");
    delay(DELAY_MS * 10);
    return;
  }

  //Compute differential errors
  int dH = (v1 + v3) - (v2 + v4); // Horizontal error
  int dV = (v1 + v2) - (v3 + v4); // Vertical error

  //Horizontal axis control
  if (abs(dH) > TOLERANCE) {
    posH += (dH > 0) ? STEP_DEG : -STEP_DEG;
    posH = constrain(posH, 0, 180);
    servoH.write(posH);
  }

  //Vertical axis control
  if (abs(dV) > TOLERANCE) {
    posV += (dV > 0) ? STEP_DEG : -STEP_DEG;
    posV = constrain(posV, 30, 150); // Limit elevation range
    servoV.write(posV);
  }

  //Serial monitoring
  Serial.print("LDRs: ");
  Serial.print(v1); Serial.print(" ");
  Serial.print(v2); Serial.print(" ");
  Serial.print(v3); Serial.print(" ");
  Serial.print(v4);
  Serial.print(" | Pos H: "); Serial.print(posH);
  Serial.print(" V: "); Serial.println(posV);

  delay(DELAY_MS);
}