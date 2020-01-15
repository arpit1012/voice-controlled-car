int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0;

void setup() {
pinMode(sensorPin, INPUT);
pinMode(ledPin, OUTPUT);

Serial.begin(9600);
}

void loop() {
sensorValue = analogRead(sensorPin);

if(sensorValue >= 34)
{
 digitalWrite(13, LOW);
}
else
{
digitalWrite(13, HIGH);  
}
Serial.println(sensorValue);
}
