void setup() {
  // put your setup code here, to run once:
pinMode(1,OUTPUT);
pinMode(0,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while (Serial.available()){ //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable 
    char c = Serial.read(); //Conduct a serial read
     Serial.print(c);
  }

}
