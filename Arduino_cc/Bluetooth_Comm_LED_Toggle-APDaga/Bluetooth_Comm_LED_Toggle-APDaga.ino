 /*******************************************************************
 * Board: Arduino Mega (ATMega2560)
 * Developed by: Akshay P Daga       Email: apdaga@gmail.com
 * 
 * PROBLEM STATEMENT:
 * This code is Turn ON and OFF the LED using Serial Communication 
 * using BLUETOOTH MODULE HC-05 (Bluetooth 2.0).
 * 
 * PROGRAM OUTCOME:
 * If pressed "a" on computer keyboard -> LED will be ON
 * If presses "b" on computer keyboard -> LED will be OFF
********************************************************************/

/****************************************************************
 * STEPS:
 * 1. Install Bluetooth Terminal app (By Juan Sebastian Ochoa Zambrano) on Android mobile from Play Store.
 * 2. Make Physical Connections of the BLuetooth Module (HC-05) as given above.
 * 3. On Android mobile, Search for Bluetooth and Connect to HC-05 and pair it using password "0000" or "1234". 
 * 4. Open Bluetooth Terminal App on the Mobile and connect to paired HC-05 module. 
 ***************************************************************/

/****************************************************************** 
 * PHYSICAL CONNECTIONS: 
 * Arduino Mega  ->  Bluetooth Module 
 * Pin 18 (Tx1)  ->  Rx
 * Pin 19 (Rx1)  ->  Tx
 * Gnd           ->  GND
 * Vcc           ->  VCC (+5V)
 * 
 * Pin 13 -> LED+  
 * Gnd    -> LED-
 * Serial Communication through USB cable (Tx0 and Rx0)
 * Arduino Terminal (Desktop) is used just to cross verify.
 *****************************************************************/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Tx0 and Rx0  //Set Baud Rate to 9600 for Serial Communication Tx0 and Rx0
  Serial1.begin(9600);  //Tx1 and Rx1  //Connected to Bluetooth Module HC-05 (Bluetooth 2.0)
  //Serial2;  //Tx2 and Rx2
  //Serial3;  //Tx3 and Rx3

  pinMode(13, OUTPUT);  //Set Pin 13 as Output (Connected to LED)

  Serial.println("press \"a\" or \"A\" to switch ON the LED");  //To Desktop
  Serial.println("press \"b\" or \"B\" to switch OFF the LED");
  Serial1.println("press \"a\" or \"A\" to switch ON the LED"); //To mobile
  Serial1.println("press \"b\" or \"B\" to switch OFF the LED");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial1.available ()>0)
  {
    int buffer_value = Serial1.read();
    if(buffer_value == 'a' || buffer_value == 'A')
    {
      digitalWrite(13, HIGH);    //Turn ON LED
      Serial.println("LED ON");  //Arduino Terminal of Desktop 
      Serial1.println("LED ON"); //Bluetooth Terminal on Mobile
    }
    else if(buffer_value == 'b' || buffer_value == 'B')
    {
      digitalWrite(13, LOW);      //Turn OFF LED
      Serial.println("LED OFF");  //Arduino Terminal on Desktop
      Serial1.println("LED OFF"); //Bluetooth Terminal on Mobile 
    }
  }
}
