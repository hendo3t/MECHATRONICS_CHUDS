#include <Servo.h>
Servo steering;
Servo throttle;

const byte triggerPin = 5;
const byte echoPin = 6;
const int steeringPin = 5;
const int throttlePin = 6;
unsigned long duration = 0;
float distance_cm = 0;
float ACTUAL_WALL_DIST = 0;
float DESIRED_WALL_DIST = 36;
const int STRAIGHT = 1500;
float STEERING_CORRECTION = 0;
const float K = 0.5;

float cmConvert = 1/55.0;
float inConvert = 1/150.0;

unsigned long tk = 0;

unsigned long tLoopLast = 0, tLoopSample = 500;

void setup() {
  Serial.begin(9600);

  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  steering.attach(steeringPin);
  throttle.attach(throttlePin);

    // Start stopped and straight
  steering.writeMicroseconds(1500);
  throttle.writeMicroseconds(1500);

}

void loop() {

  tk = millis();

  if (tk - tLoopLast >= tLoopSample) {
    tLoopLast = tk;

    // Trigger the Ultrasonic
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    // Read the pulse length from ECHO
    duration = pulseIn(echoPin, HIGH, 15000);

    // Convert pulse to distance
    ACTUAL_WALL_DIST = duration*inConvert;

    STEERING_CORRECTION = (1500 - (K*(DESIRED_WALL_DIST - ACTUAL_WALL_DIST)));

    steering.writeMicroseconds(STEERING_CORRECTION);
    throttle.writeMicroseconds(1750);
    Serial.print("Distance in: ");
    Serial.print(ACTUAL_WALL_DIST);
    Serial.print("\n\r");
  }
}




