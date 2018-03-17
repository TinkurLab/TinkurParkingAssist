//The following tutorials, code, and libraries are used in this project:
// tutorial, code https://www.thingiverse.com/thing:2808403
// library https://github.com/RobTillaart/Arduino/tree/master/libraries/RunningMedian
// tutorial https://github.com/arduino/Arduino/issues/4936 (how to include Arduino library in project folder

#include "src/RunningMedian/RunningMedian.h"

int redPin = 11; 
int greenPin = 10;
int bluePin = 9;
int trigPin = 5; // Sensor Trip pin connected to Arduino pin D5
int echoPin = 6; // Sensor Echo pin connected to Arduino pin D6
long TempDistance = 0; // A variable to store the temporary distance
int counter = 0; // Counter value to check if the object has stopped moving

RunningMedian samples = RunningMedian(3);

//uncomment this line if using a Common Anode LED
#define COMMON_ANODE

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop() {
  long duration, Distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  Distance = (duration/2) / 74; // Distance in Inches

  samples.add(Distance);

  int medianDistance = samples.getMedian();

  if(counter < 20){ // Do the rest if the car is still moving
    if (medianDistance < 68 && medianDistance > 38) {
      setColor(255, 255, 0);  // yellow
      Serial.println("case 1");
    } else if (medianDistance <= 38 && medianDistance >= 30) {
      setColor(0, 255, 0);  // green
      Serial.println("case 2");
    } else if (medianDistance < 30) {
      setColor(255, 0, 0);  // red
      Serial.println("case 3");
    } else {
      setColor(0, 0, 0);  // off
      Serial.println("case 4");
    }
  }

  if ((Distance == TempDistance) || ((Distance+1) == TempDistance) || ((Distance-1) == TempDistance)){
    if(counter >= 20){ // Turn off the lights if the object hasn't moved for 20 cycles (no change in distance)
      Serial.println("no movement detected, turning off the lights");
      setColor(0, 0, 0);  // off
    } else {
      counter++;
    }
  } else {
    counter = 0; // Reset counter if there is a movement
  }
  TempDistance = Distance;

  Serial.print("distance inches: ");
  Serial.println(medianDistance); //print the median sensor value
    Serial.print("counter count: ");
  Serial.println(counter); //print the median sensor value
  
  delay(500); //delay 500ms (0.5 second)
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

