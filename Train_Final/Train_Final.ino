#include <Servo.h>
Servo servo1;
Servo servo2;
const int servo1Pin = 6;
const int servo2Pin = 7;
const int servo1P1 = 90;
const int servo1P2 = 41;
const int servo2P1 = 98;
const int servo2P2 = 45;
const int relayPin = 5;
// const int resetPin = 4;
const int irPin1=22;
const int irPin2=24;
int count=0;
boolean state = true;

void setup() {
  Serial.begin(9600);
  pinMode(irPin1, INPUT);
  pinMode(irPin2, INPUT);
  pinMode(relayPin, OUTPUT);
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo1.write(servo1P1);
  servo2.write(servo2P1);
  digitalWrite(relayPin,HIGH);
}

void loop() 
{
    
  if (!digitalRead(irPin1) && state && count<=2)
  {
      count++;
      state = false;
      Serial.print("Count: ");
      Serial.println(count);
      delay(100);
  }
  
  if(count==1)
  {
    servo1.write(servo1P2);
    servo2.write(servo2P2);
  }
  if(count==3)
  {
    servo1.write(servo1P1);
    servo2.write(servo2P1);
    // count=0;
  }
  if(count==3 && !digitalRead(irPin2))
  {
    Serial.println("Train Arrived On Platform 1");
    count=0; 
    digitalWrite(relayPin, LOW);
    delay(60000);
    delay(60000);
    delay(30000);
    digitalWrite(relayPin, HIGH);
  }
  if (digitalRead(irPin1))
  {
     state = true;
     delay(100);
  }

}