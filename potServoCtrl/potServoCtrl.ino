#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int potPin = A0; // analog pin used to connect the potentiometer
int val,var;    // variable to read the value from the analog pin

void setup() {
  Serial.begin(9600);  // initialize serial communication at 9600 bits per second
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // var = analogRead(potPin);            // read the value from the potentiometer
  // val = map(var, 0, 1023, 0, 180);    // map the potentiometer value from 0-1023 to 0-180
  myservo.write(51);
  delay(3000);
  myservo.write(98);
  delay(3000);                 // set the servo position based on the mapped value
  
  // Serial.print("Potentiometer Value: ");
  // Serial.print(analogRead(potPin));
  Serial.print(" Servo Position: ");
  Serial.println(val);              // print the potentiometer value and the servo position to the serial monitor

  delay(15);                          // wait for the servo to move to the desired position
}
