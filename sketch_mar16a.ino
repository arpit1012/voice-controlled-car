void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()) {

    char inchar = (char)Serial.read();

    switch(inchar) {
      case '1':
        digitalWrite(13, HIGH);
        break;

        case '2':
          digitalWrite(13,LOW);
          break;
      }
    Serial.println(inchar);
    }
}
