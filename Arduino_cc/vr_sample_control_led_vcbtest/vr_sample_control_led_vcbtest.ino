/**
  ******************************************************************************
  * @file    vr_sample_control_led.ino
  * @author  JiapengLi
  * @brief   This file provides a demostration on 
              how to control led by using VoiceRecognitionModule
  ******************************************************************************
  * @note:
        voice control led
  ******************************************************************************
  * @section  HISTORY
    
    2013/06/13    Initial version.
  */
  
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"

/**        
  Connection
  Arduino    VoiceRecognitionModule
   2   ------->     TX
   3   ------->     RX
*/
VR myVR(0,1);    // 2:RX 3:TX, you can choose your favourite pins.(TX,RX)

uint8_t records[7]; // save record
uint8_t buf[64];

int enA=10;
int enB=5;
int in1=9;
int in2=6;
int in3=7;
int in4=8;
int trigfwd = 11; 
int echofwd = 12;  //14 
int trigbk = 13;   //15
int echobk = 4;
long duration,duration1;
float distance,distance1;

#define forward    (0)
#define backward   (1) 
#define left   (2) 
#define right   (3) 
#define Stop   (4) 


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

void setup()
{
  /** initialize */
  myVR.begin(9600);
  
  Serial.begin(115200);
  Serial.println("Elechouse Voice Recognition V3 Module\r\nControl LED sample");
  

  pinMode(0 , INPUT);
  pinMode(1, OUTPUT);
    
  if(myVR.clear() == 0){
    Serial.println("Recognizer cleared.");
  }else{
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while(1);
  }
  
  if(myVR.load((uint8_t)forward) >= 0){
    Serial.println("onRecord loaded");
  }
  
  if(myVR.load((uint8_t)backward) >= 0){
    Serial.println("offRecord loaded");
  }


pinMode(trigfwd, OUTPUT);
pinMode(echofwd, INPUT);
pinMode(trigbk, OUTPUT);
pinMode(echobk, INPUT);
}
void loop(){


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



  int ret;
  ret = myVR.recognize(buf, 50);
  if(ret>0){
    switch(buf[1]){
      case forward:
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
        Serial.print("Forward - HIGH");
        break;
      case backward:         
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
        Serial.print("Backward - LOW");
        break;
        case right:
          Serial.println("right");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,255 );
      analogWrite(in2,0);
      analogWrite(in3,255 );
      analogWrite(in4,0);/*right*/
      delay(450);

     
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
break;
//code 
  case left:

  
      Serial.println("left");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,0 );
      analogWrite(in2,255);
      analogWrite(in3,0 );
      analogWrite(in4,255);  /*left*/
      delay(510);
      
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
       break;
       case Stop:
   Serial.println("stop");
      analogWrite(enA,0);
      analogWrite(enB,0);
      digitalWrite(in1,LOW );
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW );
      digitalWrite(in4,LOW);
        
      default:
        Serial.println("Record function undefined");
        break;
    }
    /** voice recognized */
    printVR(buf);
  }
