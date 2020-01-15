#include<SoftwareSerial.h>
String voice; 
#define TxD 10
#define RxD 11

SoftwareSerial bluetoothSerial(TxD, RxD);
int x = 14;
char c;

void setup() {
  bluetoothSerial.begin(9600);
  Serial.begin(9600);
pinMode(x, OUTPUT);

  }

void loop() { 
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
          if(voice == "on") {digitalWrite(x, HIGH);
          Serial.println(voice);}
          
          else if (voice == "of") {digitalWrite(x, LOW);
          
          Serial.println(voice);}

          voice = ""; // REset voice
}}
