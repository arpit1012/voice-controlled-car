//analog 10,11
int in1=6;
int in2=5;
int in3=11;
int in4=10;
int trigfwd=9;
int echofwd=7;
int trigrt=3;
int echort=2;
int triglt=4;
int echolt=8;
//int ena =10;
//int enb =11;
float distancef;
float durationf;
float durationl;
float durationr;
float distancer;
float distancel;

void setup() {
Serial.begin(9600);

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3, OUTPUT); 
pinMode(in4, OUTPUT);
//pinMode(ena, OUTPUT);
//pinMode(enb, OUTPUT);
pinMode(trigfwd, OUTPUT);
pinMode(echofwd, INPUT);
pinMode(trigrt, OUTPUT);
pinMode(echort, INPUT);
pinMode(triglt, OUTPUT);
pinMode(echolt, INPUT);

 
}


void loop() {
  ultrafwd();
  ultrart();
  ultralt();
//1
  if(distancef>20 && distancer<18 && distancel<18){
    if(distancer<7.75 && distancel<7.75){
      forward();
      }
     else if(distancer>7.75){
      right();
      }
     else if(distancel>7.75){
      left();
      } 
    }
    //2
  else if(distancef<16 && distancer>18 && distancel<18){
    Stop();
      delay(1000);
      sharp_right();
    delay(510);}

    //3
  else if(distancef<16 && distancer<18 && distancel>18){
      Stop();
      delay(1000);
      sharp_left();
      delay(510);
    }
    //4
  else if(distancef>16 && distancer>18 && distancel>18){
      Stop();
      delay(1000);
      sharp_left();
      delay(510);
    }
   //5
  else if(distancef>16 && distancer>18 && distancel<18){
      forward();
    }
    //6
  else if(distancef<16 && distancer<18 && distancel>18){
      Stop();
      delay(1000);
      sharp_left();
      delay(510);
    }
    //7
  else if(distancef<16 && distancer>18 && distancel>18){
      Stop();
      delay(1000);
      sharp_left();
      delay(510);
    }
   //8 u trun
  else if(distancef<15 && distancer<18 && distancel<18){
    Stop();
    delay(500);
      u_turn();
      delay(580);
    }
}
void ultrafwd(){
          // Clears the trigPin
digitalWrite(trigfwd, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigfwd, HIGH);
delayMicroseconds(10);
digitalWrite(trigfwd, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationf = pulseIn(echofwd, HIGH);
// Calculating the distance
distancef= durationf*0.034/2;
// Prints the distance on the Serial Monitor

Serial.print("Distance_fwd: ");
Serial.println(distancef);

}

void ultralt(){
          // Clears the trigPin
digitalWrite(triglt, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(triglt, HIGH);
delayMicroseconds(10);
digitalWrite(triglt, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationl = pulseIn(echolt, HIGH);
// Calculating the distance
distancel= durationl*0.034/2;
// Prints the distance on the Serial Monitor

Serial.print("Distance_lt: ");
Serial.println(distancel);

}

void ultrart(){
          // Clears the trigPin
digitalWrite(trigrt, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigrt, HIGH);
delayMicroseconds(10);
digitalWrite(trigrt, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationr = pulseIn(echort, HIGH);
// Calculating the distance
distancer= durationr*0.034/2;
// Prints the distance on the Serial Monitor

Serial.print("Distance_rt: ");
Serial.println(distancer);


}
void forward(){
   Serial.println("Forward");
  analogWrite(in1,80);
  analogWrite(in2,0 );
  analogWrite(in3,80);
  analogWrite(in4,0); 
}

void right(){
  Serial.println("Right");
  analogWrite(in1,0);
  analogWrite(in2,0 );
 analogWrite(in3,80);
  analogWrite(in4,0);
}

void left(){
  Serial.println("Left");
  analogWrite(in1,80);
  analogWrite(in2,0 );
  analogWrite(in3,0);
  analogWrite(in4,0); 
 }
void Stop(){
  Serial.println("Stop");
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW );
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW); 
 }

void u_turn(){
  Serial.println("U-Turn");
  analogWrite(in1,125);
  analogWrite(in2,LOW );
  analogWrite(in3,LOW);
  analogWrite(in4,120); 
 }

void sharp_right(){
    Serial.println("Sharp_Right");
  analogWrite(in1,0);
  analogWrite(in2,0 );
 analogWrite(in3,120);
  analogWrite(in4,0);
}

void sharp_left(){
  Serial.println("Sharp_Left");
  analogWrite(in1,120);
  analogWrite(in2,0 );
  analogWrite(in3,0);
  analogWrite(in4,0);
}
