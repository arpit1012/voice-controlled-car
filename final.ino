# include <SoftwareSerial.h>

String voice;
int f=0;
int enA=10;
int enB=5;
int in1=9;
int in2=6;
int in3=7;
int in4=8;
int led_red1=32;
int led_green1=33;
int led_blue1=34;
int led_red2=35;
int led_green2=37;
int led_blue2=39;
int trigfwd = 11; 
int echofwd = 14;  //14 
int trigbk = 15;   //15
int echobk = 4;
long duration,duration1;
float distance,distance1;

#define TxD 12
#define RxD 13

SoftwareSerial bluetoothSerial(TxD, RxD);
void setup()
{
  voice="";

bluetoothSerial.begin(9600);

Serial.begin(9600);//start serial communication
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(RxD,OUTPUT);
pinMode(TxD,INPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);



pinMode(trigfwd, OUTPUT);
pinMode(echofwd, INPUT);
pinMode(trigbk, OUTPUT);
pinMode(echobk, INPUT);


}

void loop() 
{    
  /*digitalWrite(led_red1, HIGH);
  digitalWrite(led_red2, HIGH);
  delay(1000);
  digitalWrite(led_red1, LOW);
  digitalWrite(led_red2, LOW);

  digitalWrite(led_green1, HIGH);
  digitalWrite(led_green2, HIGH);
  delay(1000);
   digitalWrite(led_green1, LOW);
  digitalWrite(led_green2, LOW);

  digitalWrite(led_blue1, HIGH);
  digitalWrite(led_blue2, HIGH);
  delay(1000);
  digitalWrite(led_blue1, LOW);
  digitalWrite(led_blue2, LOW);
  */
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
      delay(530);


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
      delay(530);


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
