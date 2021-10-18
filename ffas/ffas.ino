#include <TinyGPS++.h>            // Include TinyGPS++ library
#include <SoftwareSerial.h>       // Include software serial library
#include "dht.h"                  // Include DHT library


TinyGPSPlus gps;                  // gps module object

#define sen1 A0                   // setting dht sensor 1 to A0
#define sen2 A1                   // setting dht sensor 2 to A1
#define sen3 A2                   // setting dht sensor 3 to A2
#define sen4 A3                   // setting dht sensor 4 to A3
#define smoke1 A4                // setting smoke sensor 1 to A4
#define smoke2 A5                // setting smoke sensor 1 to A5

#define B_RX    4                // Define software serial RX pin for bluetooth
#define B_TX    3                // Define software serial TX pin for bluetooth

#define G_RX    6                // Define software serial RX pin for gps
#define G_TX    5                // Define software serial TX pin for gps

dht DHT1;                        //DHT module object1
dht DHT2;                        //DHT module object2
dht DHT3;                        //DHT module object3
dht DHT4;                        //DHT module object4

SoftwareSerial GPSSerial(G_RX, G_TX);    // Configure GPSSerial library
SoftwareSerial BTSerial(B_RX, B_TX);    // Configure BluetoothSerial library

void setup(void) {
  
  Serial.begin(9600);          //setting serial baudrate to 9600
 
  GPSSerial.begin(9600);      // setting GPS baudrate to 9600
  BTSerial.begin(9600);       // setting Bluetooth baudrate to 9600 

  pinMode(smoke1, INPUT);
  pinMode(smoke2, INPUT);
}
void loop()
{
  DHT1.read11(sen1);
  DHT2.read11(sen2);
  DHT3.read11(sen3);
  DHT4.read11(sen4);
  
  int s1 = analogRead(smoke1);
  int s2 = analogRead(smoke2);

  
  if(s1 > 400 || s2 > 400){
    Serial.println("Warning : Smoke Present");
    BTSerial.println("Warning : Smoke Present");
  }
  else{
    Serial.println("No Smoke Present");
    BTSerial.println("No Smoke Present");
  }
  
  if(DHT1.temperature > 28.0 ) { 
    
    Serial.println("Might be Fire in the grid One");
    BTSerial.println("Might be Fire in the grid One");
    alert();
  }
  else
  {
      Serial.print("Temperature1 in Celsius = ");
      Serial.print(DHT1.temperature);
      Serial.print("\tHumidity1 = ");
      Serial.print(DHT1.humidity);
      Serial.println("%");  

      BTSerial.print("Temperature1 in Celsius = ");
      BTSerial.print(DHT1.temperature);
      BTSerial.print("\tHumidity1 = ");
      BTSerial.print(DHT1.humidity);
      BTSerial.println("%");  
  }
  delay(500);
 
  
  if(DHT2.temperature > 28.0 ) 
  {
    Serial.println("Might be Fire in the grid two");
    BTSerial.println("Might be Fire in the grid two");
    alert();
  }
  else
  {
      Serial.print("Temperature2 in Celsius = ");
      Serial.print(DHT2.temperature);
      Serial.print("\tHumidity2 = ");
      Serial.print(DHT2.humidity);
      Serial.println("%");

       
      BTSerial.print("Temperature2 in Celsius = ");
      BTSerial.print(DHT2.temperature);
      BTSerial.print("\tHumidity2 = ");
      BTSerial.print(DHT2.humidity);
      BTSerial.println("%");
  }
  
  delay(500);
  
  if(DHT3.temperature > 28.0 ) {
  Serial.println("Might be Fire in the grid three");
  BTSerial.println("Might be Fire in the grid three");
  alert();
  }
  else
  {
      Serial.print("Temperature3 in Celsius = ");
      Serial.print(DHT3.temperature);
      Serial.print("\tHumidity3 = ");
      Serial.print(DHT3.humidity);
      Serial.println("%");  

      BTSerial.print("Temperature3 in Celsius = ");
      BTSerial.print(DHT3.temperature);
      BTSerial.print("\tHumidity3 = ");
      BTSerial.print(DHT3.humidity);
      BTSerial.println("%");  
  }
  
  delay(500);
  
  if(DHT4.temperature > 28.0){
    Serial.println("Might be Fire in the grid four");
    BTSerial.println("Might be Fire in the grid four");
    alert();
  }
  else
  {
      Serial.print("Temperature4 in Celsius = ");
      Serial.print(DHT4.temperature);
      Serial.print("\tHumidity4 = ");
      Serial.print(DHT4.humidity);
      Serial.println("%");  

      
      BTSerial.print("Temperature4 in Celsius = ");
      BTSerial.print(DHT4.temperature);
      BTSerial.print("\tHumidity4 = ");
      BTSerial.print(DHT4.humidity);
      BTSerial.println("%");  
  }
  
  delay(500);
  
  Serial.println();
  BTSerial.println();
  delay(1000);
   

  
}

void alert() {
 
  if (GPSSerial.available() > 0 and BTSerial.available() > 0) {
 
    if (gps.encode(GPSSerial.read())) {
 
      if (gps.location.isValid()) {
        Serial.print("Latitude   = ");
        Serial.println(gps.location.lat(), 6);
        Serial.print("Longitude  = ");
        Serial.println(gps.location.lng(), 6);

        BTSerial.print("Latitude   = ");
        BTSerial.println(gps.location.lat(), 6);
        BTSerial.print("Longitude  = ");
        BTSerial.println(gps.location.lng(), 6);
      }
      else{
        Serial.println("Location Invalid");
      BTSerial.println("Location Invalid");
      }

 delay(500);
 
      if (gps.time.isValid()) {
        Serial.print("Time (GMT) : ");
        
        BTSerial.print("Time (GMT) : ");
        
        if(gps.time.hour() > 20){
          Serial.print("0");
          BTSerial.print("0");
        }
        Serial.print(gps.time.hour()+5);
        Serial.print(":");
        
        BTSerial.print(gps.time.hour()+5);
        BTSerial.print(":");
        
        if(gps.time.minute() > 30){
          Serial.print("0");
          BTSerial.print("0");
        }
        Serial.print(gps.time.minute()+30);
        Serial.print(":");
        
        BTSerial.print(gps.time.minute()+30);
        BTSerial.print(":");
        
        if(gps.time.second() < 10){
          Serial.print("0");
          BTSerial.print("0");
        }
        Serial.println(gps.time.second());
        BTSerial.println(gps.time.second());
      }
      else{
        Serial.println("Time Invalid");
        BTSerial.println("Time Invalid");
      }

delay(500);
 
      if (gps.date.isValid()) {
        Serial.print("Date       : ");
        BTSerial.print("Date       : ");
        if(gps.date.day() < 10){
          Serial.print("0");
          BTSerial.print("0");
        }
        Serial.print(gps.date.day());
        Serial.print("/");
        
        BTSerial.print(gps.date.day());
        BTSerial.print("/");
        
        if(gps.date.month() < 10){
          Serial.print("0");
          BTSerial.print("0");
        }
        Serial.print(gps.date.month());
        Serial.print("/");
        Serial.println(gps.date.year());

        BTSerial.print(gps.date.month());
        BTSerial.print("/");
        BTSerial.println(gps.date.year());
      }
      else{
        Serial.println("Date Invalid");
        BTSerial.println("Date Invalid");
      }
        

delay(1000);
    }
 
  }
 
}
