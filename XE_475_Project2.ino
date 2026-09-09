Fuck you
#include <Servo.h>

Servo steering;
Servo throttle;



// Vehicle outputs
const byte STEERING_PIN = 5;
const byte THROTTLE_PIN = 6;

// Ultrasonic sensor
const byte TRIGGER_PIN = 10;
const byte ECHO_PIN = 11;

// Laser object-detection sensor
const byte LASER_PIN = 7;

// Start/stop pushbutton
const byte BUTTON_PIN = 2;

const byte LED = 4;

const int FULL_LEFT = 1000;
const int HALF_LEFT = 1250;
const int STRAIGHT = 1500;
const int FULL_RIGHT = 2000;
const int HALF_RIGHT = 1750;
const int FULL_REVERSE = 1000;
const int STOP = 1500;
const int HALF_REVERSE = 1250;
const int FULL_FORWARD = 2000;
const int HALF_FORWARD = 1750;
const int SLOW_FORWARD = 1580;
const int CONST_CRAWL = 1600;
const float K = 0.5; // Correction Factor is subject to change
const int DESIRED_WALL_DIST = 36;
const int ACTUAL_WALL_DIST = 0;//SUBJECT TO CHANGE
const float distanceErrorCM = 0.0;



enum State {
  STANDBY, 
  SURVIVAL,
  EVASION,
  RESISTANCE,
  ESCAPE
};

State currentState = STANDBY;

unsigned long echoduration = 0;
float ultrasonicDistanceCM = 0.0;
//Max time to wait for the echo signal
const unsigned long ECHO_TIMEOUT = 30000;
unsigned long tLoopLast = 0, tLoopSample = 500;
bool LaserReading = LOW;
bool ObjectDetected = FALSE;
bool WallDetected = FALSE;
int steeringCorection = 0;
int steeringCommand = STRAIGHT;
int throttleCommand = STOP;

bool buttonReading = HIGH;
bool buttonState = HIGH;
bool lastButtonReading = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long DEBOUNCE_TIME_MS = 20;
unsigned long currentTime = 0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
