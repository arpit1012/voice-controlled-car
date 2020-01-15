#include <Servo.h>
Servo myservo;
int potpin = A0;
int val;

void setup() {
 myservo.attach(9);
Serial.begin(9600);
}

void loop() {
val = analogRead(potpin);
myservo.write(val);
delay(20);
Serial.println(val);
}
