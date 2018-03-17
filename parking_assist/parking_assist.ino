int proximityPin = 0; //analog pin 0
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

//uncomment this line if using a Common Anode LED
#define COMMON_ANODE

void setup(){
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}

void loop() {
  int distance = average_value(100); //loop 100 times and get its average
  
  if (distance > 50) {
    setColor(255, 255, 0);  // yellow
    Serial.print("case 1");
  } else if (distance < 85 && distance > 75) {
    setColor(0, 255, 0);  // green
    Serial.print("case 2");
  } else if (distance > 85) {
    setColor(255, 0, 0);  // red
    Serial.print("case 2");
  } else {
    setColor(0, 0, 0);  // off
    Serial.print("case 3");
  }

  Serial.print(" ");
  Serial.println(distance); //print the sensor value
  
  delay(500); //delay 500ms (0.5 second)
}

int average_value(int average_count) {
  int sum = 0;
  for (int i=0; i<average_count; i++) {
    int sensor_value = analogRead(proximityPin);  //read the sensor value
    int distance_cm = pow(3027.4/sensor_value, 1.2134); //convert readings to distance(cm)
    sum = sum + distance_cm;
  }
  return(sum/average_count);  
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

