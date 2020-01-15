# include <SoftwareSerial.h>
# include "VoiceRecognitionV3.h"
VR myVR(1,0); // (rxD,txD) on arduino 

uint8_t records[7];
uint8_t buf[64];
String voice;
int f=0;
int enA=10;
int enB=5;
int in1=9;
int in2=6;
int in3=7;
int in4=8;
int trigfwd = 11;
int echofwd = 12;
int trigbk = 13;
int echobk = 4;
long duration,duration1;
float distance,distance1;


#define TxD 3
#define RxD 2
#define forward (0)
#define backward (1)
#define left (2)
#define right (3)
#define Stop (4)


/**
  @brief   Print signature, if the character is invisible, 
           print hexible value instead.
  @param   buf     --> command length
           len     --> number of parameters
*/
void printSignature(uint8_t *buf, int len)
{
  int i;
  for(i=0; i<len; i++){
    if(buf[i]>0x19 && buf[i]<0x7F){
      Serial.write(buf[i]);
    }
    else{
      Serial.print("[");
      Serial.print(buf[i], HEX);
      Serial.print("]");
    }
  }
}

/**
  @brief   Print signature, if the character is invisible, 
           print hexible value instead.
  @param   buf  -->  VR module return value when voice is recognized.
             buf[0]  -->  Group mode(FF: None Group, 0x8n: User, 0x0n:System
             buf[1]  -->  number of record which is recognized. 
             buf[2]  -->  Recognizer index(position) value of the recognized record.
             buf[3]  -->  Signature length
             buf[4]~buf[n] --> Signature
*/
void printVR(uint8_t *buf)
{
  Serial.println("VR Index\tGroup\tRecordNum\tSignature");

  Serial.print(buf[2], DEC);
  Serial.print("\t\t");

  if(buf[0] == 0xFF){
    Serial.print("NONE");
  }
  else if(buf[0]&0x80){
    Serial.print("UG ");
    Serial.print(buf[0]&(~0x80), DEC);
  }
  else{
    Serial.print("SG ");
    Serial.print(buf[0], DEC);
  }
  Serial.print("\t");

  Serial.print(buf[1], DEC);
  Serial.print("\t\t");
  if(buf[3]>0){
    printSignature(buf+4, buf[3]);
  }
  else{
    Serial.print("NONE");
  }
  Serial.println("\r\n");
}


SoftwareSerial bluetoothSerial(TxD, RxD);

void setup()

{
  /** initialize */
  myVR.begin(9600);
  
  Serial.begin(115200);
  Serial.println("Elechouse Voice Recognition V3 Module\r\nControl LED sample");
   
    
  if(myVR.clear() == 0){
    Serial.println("Recognizer cleared.");
  }else{
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while(1);
  }
  
  if(myVR.load((uint8_t)forward) >= 0){
    Serial.println("forward loaded");
  }
  
  if(myVR.load((uint8_t)backward) >= 0){
    Serial.println("backward loaded");
  }
  
  if(myVR.load((uint8_t)left) >= 0){
    Serial.println("left loaded");
  }
  
  if(myVR.load((uint8_t)right) >= 0){
    Serial.println("right loaded");
  }
  
  if(myVR.load((uint8_t)Stop) >= 0){
    Serial.println("Stop loaded");
  }



  voice="";

bluetoothSerial.begin(9600);
Serial.begin(9600); //start serial communication
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(2,OUTPUT);//RxD
pinMode(3,INPUT);//TxD
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

pinMode(trigfwd, OUTPUT);
pinMode(echofwd, INPUT);
pinMode(trigbk, OUTPUT);
pinMode(echobk, INPUT);


}

void loop() 
{    
  int ret;
  ret =  myVR.recognize(buf, 50);
  
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
  
  if (voice.length() > 0 || ret>0){
    f=1;
          Serial.println(voice);

    if(voice == "forward" || buf[1] == forward){
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
      digitalWrite(in4,LOW);\
      }
      
 //   delay(1000);
      //voice="";
      
      }
      
      
        
      
    if(voice == "backward" || buf[1] == backward){
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
      digitalWrite(in4,LOW);\
      }
      }
      
    else if(voice == "right" || buf[1] == right) {
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
      digitalWrite(in4,LOW);\
      }
      if (bluetoothSerial.available())
      {break;}
  }
        
    }
    
    else if(voice == "left" || buf[1] == left) {
     
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
      digitalWrite(in4,LOW);\
      }
       if (bluetoothSerial.available())
      {break;}
      }
    
    }
    
    else if(voice == "stop" || buf[1] == Stop) {
      Serial.println("stop");
      analogWrite(enA,0);
      analogWrite(enB,0);
      digitalWrite(in1,LOW );
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW );
      digitalWrite(in4,LOW);  
    }
    else{ Serial.println("Record function not defined");}
  //Reset the variable after initiating
  }
    
     }
