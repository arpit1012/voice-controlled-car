# include <SoftwareSerial.h>
#include <Servo.h>. 
String voice;
int f=0;
int enA=10;
int enB=5;
int in1=9;
int in2=6;
int in3=7;
int in4=8;
int trigfwd = 11; 
int echofwd = 14;  
int trigbk = 15;   
int echobk = 4;
long duration,duration1;
float distance,distance1;
//const int trigPin_rad = 19;
//const int echoPin_rad = 18;

// Variables for the duration and the distance
long duration_rad;
int distance_rad;
int i;
Servo myServo; // Creates a servo object for controlling the servo motor
#define TxD 12
#define RxD 13

SoftwareSerial bluetoothSerial(TxD, RxD);
//SoftwareSerial BTserial(TxD, RxD);
void setup()
{
  voice="";

bluetoothSerial.begin(9600);

Serial.begin(9600);//start serial communication

  //BTserial.begin(9600);
  //myServo.attach(8); // Defines on which pin is the servo motor attached
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(RxD,OUTPUT);
pinMode(TxD,INPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
  //pinMode(trigPin_rad, OUTPUT); // Sets the trigPin as an Output
  //pinMode(echoPin_rad, INPUT); // Sets the echoPin as an Input
pinMode(37, OUTPUT);
pinMode(33, OUTPUT);
pinMode(trigfwd, OUTPUT);
pinMode(echofwd, INPUT);
pinMode(trigbk, OUTPUT);
pinMode(echobk, INPUT);


}//For Radar
/*int calculateDistance(){ 
  
  digitalWrite(trigPin_rad, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin_rad, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin_rad, LOW);
  duration_rad = pulseIn(echoPin_rad, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance_rad= duration_rad*0.034/2;
  return distance_rad;
}*/

void loop() 
{  
  digitalWrite(30,HIGH);
  digitalWrite(37,HIGH);
    

 /*// rotates the servo motor from 15 to 165 degrees
  for(i=0;i<=180;i++){  
  myServo.write(i);
  delay(25);
  distance_rad = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree

  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance_rad); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing


          // Clears the trigPin
digitalWrite(trigfwd, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigfwd, HIGH);
delayMicroseconds(10);
digitalWrite(trigfwd, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echofwd, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor

Serial.print("Distance: ");
Serial.println(distance);


digitalWrite(trigbk, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigbk, HIGH);
delayMicroseconds(10);
digitalWrite(trigbk, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echobk, HIGH);
// Calculating the distance
distance1= duration1*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance1: ");
Serial.println(distance1);
  
  BTserial.print(i); // Sends the current degree into the Serial Port
  BTserial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  BTserial.print(distance_rad); // Sends the distance value into the Serial Port
  BTserial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for(i=180;i>0;i--){  
  myServo.write(i);
  delay(25);
  distance_rad = calculateDistance();
  
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance_rad); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing


          // Clears the trigPin
digitalWrite(trigfwd, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigfwd, HIGH);
delayMicroseconds(10);
digitalWrite(trigfwd, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echofwd, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor

Serial.print("Distance: ");
Serial.println(distance);


digitalWrite(trigbk, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigbk, HIGH);
delayMicroseconds(10);
digitalWrite(trigbk, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echobk, HIGH);
// Calculating the distance
distance1= duration1*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance1: ");
Serial.println(distance1);
  
  BTserial.print(i); // Sends the current degree into the Serial Port
  BTserial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  BTserial.print(distance_rad); // Sends the distance value into the Serial Port
  BTserial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
*/
// Function for calculating the distance measured by the Ultrasonic sensor


 
  while (bluetoothSerial.available()){
     if(f==1)
       {
        voice="";
        f=0;
       }
    //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable 
    char c = bluetoothSerial.read(); 
     Serial.println(c);
    //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
   voice += c; //Shorthand for voice = voice + c

  }
          // Clears the trigPin
digitalWrite(trigfwd, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigfwd, HIGH);
delayMicroseconds(10);
digitalWrite(trigfwd, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echofwd, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor

Serial.print("Distance: ");
Serial.println(distance);


digitalWrite(trigbk, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigbk, HIGH);
delayMicroseconds(10);
digitalWrite(trigbk, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echobk, HIGH);
// Calculating the distance
distance1= duration1*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance1: ");
Serial.println(distance1);

  
  if (voice.length() > 0){
    f=1;
          Serial.println(voice);

    if(voice == "forward"){
     if(distance>80){
      Serial.println("forward");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,200);
      analogWrite(in2,0 );
      analogWrite(in3,0 );
      analogWrite(in4,255 );
     }
      if(distance<=80)
     {Serial.println("stop");
      analogWrite(enA,0);
      analogWrite(enB,0);
      digitalWrite(in1,LOW );
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW );
      digitalWrite(in4,LOW);

        Serial.println("right");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,255 );
      analogWrite(in2,0);
      analogWrite(in3,255 );
      analogWrite(in4,0);/*right*/
      delay(610);

      Serial.println("forward");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,200);
      analogWrite(in2,0 );
      analogWrite(in3,0 );
      analogWrite(in4,255 );
      delay(1000);

      Serial.println("left");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,0 );
      analogWrite(in2,255);
      analogWrite(in3,0 );
      analogWrite(in4,255);  /*left*/
      delay(530);

      Serial.println("forward");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,200);
      analogWrite(in2,0 );
      analogWrite(in3,0 );
      analogWrite(in4,255 );
      
      }
      
      
 //   delay(1000);
      //voice="";
      
      }
      
      
        
      
    if(voice == "backward"){
         if(distance1>80){
      Serial.println("back");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,0);
      analogWrite(in2,215 );
      analogWrite(in3,255 );
      analogWrite(in4,0 );
         }
      if(distance1<=80)
       {Serial.println("stop");
      analogWrite(enA,0);
      analogWrite(enB,0);
      digitalWrite(in1,LOW );
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW );
      digitalWrite(in4,LOW);
      }
      }
      
    else if(voice == "right") {
      Serial.println("right");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,255 );
      analogWrite(in2,0);
      analogWrite(in3,255 );
      analogWrite(in4,0);/*right*/
      delay(450);
      
      while(voice=="right"){
      
                // Clears the trigPin
digitalWrite(trigfwd, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigfwd, HIGH);
delayMicroseconds(10);
digitalWrite(trigfwd, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echofwd, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

digitalWrite(trigbk, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigbk, HIGH);
delayMicroseconds(10);
digitalWrite(trigbk, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echobk, HIGH);
// Calculating the distance
distance1= duration1*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance1: ");
Serial.println(distance1);
      
      if(distance>80){
      Serial.println("forward");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,200);
      analogWrite(in2,0 );
      analogWrite(in3,0 );
      analogWrite(in4,255 );
     }
      if(distance<=80)
       {Serial.println("stop");
      analogWrite(enA,0);
      analogWrite(enB,0);
      digitalWrite(in1,LOW );
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW );
      digitalWrite(in4,LOW);
      delay(500);

        Serial.println("right");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,255 );
      analogWrite(in2,0);
      analogWrite(in3,255 );
      analogWrite(in4,0);/*right*/
      delay(610);

      Serial.println("forward");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,200);
      analogWrite(in2,0 );
      analogWrite(in3,0 );
      analogWrite(in4,255 );
      delay(1000);

      Serial.println("left");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,0 );
      analogWrite(in2,255);
      analogWrite(in3,0 );
      analogWrite(in4,255);  /*left*/
      delay(580);


      Serial.println("forward");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,200);
      analogWrite(in2,0 );
      analogWrite(in3,0 );
      analogWrite(in4,255 );
      
      
      }
      if (bluetoothSerial.available())
      {break;}
  }
        
    }
    
    else if(voice == "left") {
     
      Serial.println("left");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,0 );
      analogWrite(in2,255);
      analogWrite(in3,0 );
      analogWrite(in4,255);  /*left*/
      delay(510);
     while(voice = "left"){
                // Clears the trigPin
digitalWrite(trigfwd, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigfwd, HIGH);
delayMicroseconds(10);
digitalWrite(trigfwd, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echofwd, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

digitalWrite(trigbk, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigbk, HIGH);
delayMicroseconds(10);
digitalWrite(trigbk, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echobk, HIGH);
// Calculating the distance
distance1= duration1*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance1: ");
Serial.println(distance1);
      if(distance>80){
      Serial.println("forward");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,200);
      analogWrite(in2,0 );
      analogWrite(in3,0 );
      analogWrite(in4,255 );
     }
      if(distance<=80)
       {Serial.println("stop");
      analogWrite(enA,0);
      analogWrite(enB,0);
      digitalWrite(in1,LOW );
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW );
      digitalWrite(in4,LOW);

              Serial.println("right");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,255 );
      analogWrite(in2,0);
      analogWrite(in3,255 );
      analogWrite(in4,0);/*right*/
      delay(610);

      Serial.println("forward");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,200);
      analogWrite(in2,0 );
      analogWrite(in3,0 );
      analogWrite(in4,255 );
      delay(1000);

      Serial.println("left");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,0 );
      analogWrite(in2,255);
      analogWrite(in3,0 );
      analogWrite(in4,255);  /*left*/
      delay(580);


      Serial.println("forward");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,200);
      analogWrite(in2,0 );
      analogWrite(in3,0 );
      analogWrite(in4,255 );
      }
       if (bluetoothSerial.available())
      {break;}
      }
    
    }
    
     else if(voice == "stop") {
      Serial.println("stop");
      analogWrite(enA,0);
      analogWrite(enB,0);
      digitalWrite(in1,LOW );
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW );
      digitalWrite(in4,LOW);
    }
    
  //Reset the variable after initiating
  }
}
