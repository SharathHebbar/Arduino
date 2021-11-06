
#include <SoftwareSerial.h>  

#define B_RX    4                // Define software serial RX pin for bluetooth
#define B_TX    3                // Define software serial TX pin for bluetooth

SoftwareSerial BTSerial(B_RX, B_TX);    // Configure BluetoothSerial library

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);          //setting serial baudrate to 9600
 BTSerial.begin(9600);       // setting Bluetooth baudrate to 9600 
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.println("hello in serial monitor");
    BTSerial.println("hello  in bt");
}
