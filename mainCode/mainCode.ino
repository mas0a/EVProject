/*
SCIOLY ELECTRIC VEHICLE CONTROLLER - ADAPTED
Based on Unphayzed Electric Champion Kit
Adapted for L298N motor driver and JGB37-520 encoder
Auto-start, no LCD or buttons
Simplified for straight-line movement
*/

#include <Arduino.h>
#include <math.h>

// ========================
// COMPETITION SETTINGS
// ========================
double TargetDistance = 6.000;   // meters
double TargetTime = 20.00;        // seconds

// ========================
// MOTOR DRIVER PINS (L298N)
// ========================
#define ENA 11
#define IN1 9
#define IN2 10

// ========================
// ENCODER PINS
// ========================
#define ENCA 2
#define ENCB 3

// ========================
// PHYSICAL PARAMETERS
// ========================
double wheelDiameter = 7.3025;     // cm
double motorPPR = 70;              // JGB37-520 motor shaft
double gearRatio = 16.0 / 20.0;    // motor to wheel

// ========================
// ENCODER VARIABLES
// ========================
volatile long counter = 0;

// ========================
// STATE VARIABLES
// ========================
bool SBpressed = false;
bool moved = false;
bool slowed = false;
bool snail = false;
bool reachedTargetDistance = false;

// ========================
// DISTANCE VARIABLES
// ========================
double TargetDistanceCM;
double slowDownDistance;

double targetEncoderValue;
double slowDownEncoderValue;
double maxEncoderValue;

double encoderChange;
double finalDist;

// ========================
// TIMER VARIABLES
// ========================
long startTime;
long currentTime;
long endTime;

double timeDiff;
double milisTime;
double runTime;

// ========================
// SETUP
// ========================
void setup() {
  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENCA, INPUT_PULLUP);
  pinMode(ENCB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENCA), ai0, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCB), ai1, RISING);

  TargetDistanceCM = TargetDistance * 100.0;
  slowDownDistance = TargetDistanceCM * 0.8;

  targetEncoderValue = getEncoderValue(TargetDistanceCM, wheelDiameter);
  slowDownEncoderValue = getEncoderValue(slowDownDistance, wheelDiameter);
  maxEncoderValue = getEncoderValue(TargetDistanceCM * 2.0, wheelDiameter);

  Serial.println("=== ENCODER CALCULATIONS ===");
  Serial.print("Target Distance: ");
  Serial.print(TargetDistanceCM);
  Serial.println(" cm");
  Serial.print("Target Encoder Value: ");
  Serial.println(targetEncoderValue);
  Serial.print("Slow Down Encoder Value: ");
  Serial.println(slowDownEncoderValue);
  Serial.print("Max Encoder Value: ");
  Serial.println(maxEncoderValue);
  Serial.println();

  delay(3000);
  counter = 0;
  startTime = millis();
  SBpressed = true;
  Serial.println("=== READY TO START ===\n");
}

// ========================
// MAIN LOOP
// ========================
void loop() {
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 250) {
    lastPrint = millis();
    Serial.print("ENC = ");
    Serial.println(counter);
  }

  if (SBpressed) {
    motorForward(255);
    moved = true;
    SBpressed = false;
    Serial.println("Motor started at full power");
  }

  if (moved) {
    if (counter >= slowDownEncoderValue && counter < maxEncoderValue) {
      motorStop();
      delay(500);

      currentTime = millis();
      runTime = (currentTime - startTime) / 1000.0;
      timeDiff = TargetTime - runTime;

      Serial.print("Reached slowdown point. Counter: ");
      Serial.print(counter);
      Serial.print(", Time remaining: ");
      Serial.println(timeDiff);

      slowed = true;
      moved = false;
    }
  }

  if (slowed) {
    encoderChange = 0;

    for (int i = 0; i < 5; i++) {
      long startEnc = counter;
      motorForward(150);
      delay(200);
      motorStop();
      delay(200);
      encoderChange += (counter - startEnc);
    }

    encoderChange /= 5.0;

    currentTime = millis();
    runTime = (currentTime - startTime) / 1000.0;
    timeDiff = TargetTime - runTime;

    snail = true;
    slowed = false;
  }

  if (snail) {
    double remaining = targetEncoderValue - counter;
    double pulses = remaining / encoderChange;

    double pulseTime = pulses * 0.2;
    double nonPulseTime = timeDiff - pulseTime;
    if (nonPulseTime < 0) nonPulseTime = 0;

    double pulseDelay = 1000.0 * (nonPulseTime / (pulses - 1));

    for (int i = 0; i < pulses; i++) {
      motorForward(150);
      delay(200);
      motorStop();
      delay(pulseDelay);
    }

    endTime = millis();
    runTime = (endTime - startTime) / 1000.0;

    snail = false;
    reachedTargetDistance = true;
  }

  if (reachedTargetDistance) {
    finalDist = TargetDistance * (counter / targetEncoderValue);

    while (true) {
      delay(100);
    }
  }
}

// ========================
// MOTOR FUNCTIONS
// ========================
void motorForward(int pwm) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, pwm);
}

void motorStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}

// ========================
// ENCODER ISRs
// ========================
void ai0() {
  if (digitalRead(ENCB) == LOW) counter++;
  else counter--;
}

void ai1() {
  if (digitalRead(ENCA) == LOW) counter--;
  else counter++;
}

// ========================
// CALCULATIONS
// ========================
double getEncoderValue(double distCM, double wheelDiaCM) {
  double wheelCirc = 3.14159 * wheelDiaCM;
  double effectivePPR = motorPPR / gearRatio;
  return (distCM / wheelCirc) * effectivePPR;
}
