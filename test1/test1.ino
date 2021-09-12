#include "dht.h"
#include <SoftwareSerial.h>

#define sen1 A0
#define sen2 A1
#define sen3 A2
#define sen4 A3
#define smoke1 A4;
#define smoke2 A5;

dht DHT1;
dht DHT2;
dht DHT3;
dht DHT4;

void setup() {
  Serial.begin(9600);

  pinMode(smoke1, INPUT);
  pinMode(smoke2, INPUT);

  
}

void loop() {
  
  DHT1.read11(sen1);
  DHT2.read11(sen2);
  DHT3.read11(sen3);
  DHT4.read11(sen4);
  int s1 = analogRead(smoke1);
  int s2 = analogRead(smoke2);

  if(s1 > 400 || s2 > 400){
    Serial.println("Warning : Smoke Present");
  }
  else{
    Serial.println("No Smoke Present");
  }
  
  if(DHT1.temperature > 28.0 || DHT1.humidity < 20.0 ) Serial.println("Might be Fire in the grid One");
  else
  {
      Serial.print("Temperature1 in Celsius");
      Serial.print(DHT1.temperature);
      Serial.print("\tHumidity1 = ");
      Serial.print(DHT1.humidity);
      Serial.println("%");  
  }
  delay(500);
 
  
  if(DHT2.temperature > 28.0 || DHT2.humidity < 20.0 ) Serial.println("Might be Fire in the grid two");
  else
  {
      Serial.print("Temperature2 in Celsius");
      Serial.print(DHT2.temperature);
      Serial.print("\tHumidity2 = ");
      Serial.print(DHT2.humidity);
      Serial.println("%");  
  }
  
  delay(500);
  
  if(DHT3.temperature > 28.0 || DHT3.humidity < 20.0 ) Serial.println("Might be Fire in the grid three");
  else
  {
      Serial.print("Temperature3 in Celsius");
      Serial.print(DHT3.temperature);
      Serial.print("\tHumidity3 = ");
      Serial.print(DHT3.humidity);
      Serial.println("%");  
  }
  
  delay(500);
  
  if(DHT4.temperature > 28.0 || DHT4.humidity < 20.0 ) Serial.println("Might be Fire in the grid four");
  else
  {
      Serial.print("Temperature4 in Celsius");
      Serial.print(DHT4.temperature);
      Serial.print("\tHumidity4 = ");
      Serial.print(DHT4.humidity);
      Serial.println("%");  
  }
  
  delay(500);
  
  Serial.println();
  delay(1000);
   
}
 
