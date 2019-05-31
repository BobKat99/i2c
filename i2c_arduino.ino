//Libraries
#include <Wire.h>
#include <DHT.h>

//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz
 
#define SLAVE_ADDRESS 0x68

//Variables
float temp; //Stores temperature value

void setup(){
  Serial.begin(9600); // start serial for output
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(sendData);
  Serial.println("I2C Ready!");
}

void sendData(){
   char buff[3];
   dtostrf(temp, 2, 1, buff);
   Wire.write('temp');
} 

void loop(){
  temp= dht.readTemperature();
   Serial.print("Temp: ");
   Serial.print(temp);
   Serial.println(" Celsius");
  delay(2000);
}
