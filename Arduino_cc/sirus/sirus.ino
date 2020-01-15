# include <SoftwareSerial.h>
String voice;
int enA=10;
int enB=5;
int in1=9;
int in2=6;
int in3=7;
int in4=8;


#define TxD 3
#define RxD 2

SoftwareSerial bluetoothSerial(TxD, RxD);

void setup()
{

bluetoothSerial.begin(9600);
Serial.begin(9600); //start serial communication
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,INPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

}

void loop() 
{
  voice="";
  while (bluetoothSerial.available()){
    //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable 
    char c = bluetoothSerial.read(); 
     Serial.println(c);
    //Conduct a serial read
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    voice += c; //Shorthand for voice = voice + c
  }
  if (voice.length() > 0){
          Serial.println(voice);

    if(voice == "forward"){
      Serial.println("forwardfgdgjhjfh");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,200);
      analogWrite(in2,0 );
      analogWrite(in3,0 );
      analogWrite(in4,255);
      delay(1000);
      }
    else if(voice == "backward"){
      Serial.println("back");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,0);
      analogWrite(in2,215 );
      analogWrite(in3,255 );
      analogWrite(in4,0 );
      }
    else if(voice == "left") {
      Serial.println("left");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,0 );
      analogWrite(in2,196);
      analogWrite(in3,0 );
      analogWrite(in4,255); /*left*/
            delay(1500);
      analogWrite(in1,196);
      analogWrite(in2,0 );
      analogWrite(in3,0 );
      analogWrite(in4,255 );
    }
    else if(voice == "right") {
      Serial.println("right");
      analogWrite(enA,255);
      analogWrite(enB,255);
      analogWrite(in1,196 );
      analogWrite(in2,0);
      analogWrite(in3,255 );
      analogWrite(in4,0);  /*right*/
            delay(1900);
      analogWrite(in1,196);
      analogWrite(in2,0 );
      analogWrite(in3,0 );
      analogWrite(in4,255 );
    }
    
    else if(voice == "stop") {
      Serial.println("stop");
      analogWrite(enA,0);
      analogWrite(enB,0); 
      analogWrite(in1,0 );
      analogWrite(in2,0);
      analogWrite(in3,0 );
      analogWrite(in4,0);
    }
    
  voice=""; //Reset the variable after initiating
  }
}
