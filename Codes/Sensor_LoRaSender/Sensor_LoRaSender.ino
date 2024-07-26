#include <Wire.h> // device communication
#include <SPI.h> // Serial peripheral Interface
#include <LoRa.h> 

#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
 
#define NSS PA4
#define RST PB0
#define DI0 PA1
 
#define TX_P 17 // MINIMUM POWER FOR TRANSMISSION OF DATA - 17DBM
#define BAND 433E6 //frequency 433 * 10(6)
#define ENCRYPT 0x78 //In 256 bit encryption there are 78 bits combination
 
int counter = 0;
String LoRaMessage = "";
 
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BMP280 bmp;
 
void setup() 
{
  Serial.begin(115200); // set baud rate (bits/sec)
  while (!Serial); // wait for serial port to connect. Needed for native USB port only
 
  Serial.println(F("LoRa Sender"));
 
  LoRa.setTxPower(TX_P);
  LoRa.setSyncWord(ENCRYPT); // To isolate LoRa network
  
  LoRa.setPins(NSS, RST, DI0);
  if (!LoRa.begin(BAND)) 
  {
    Serial.println(F("Starting LoRa failed!"));
    //while (1);
  }
  if (!bmp.begin(0x76)) 
  {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
}
 
void loop() 
{
  float pressure = bmp.readPressure() / 100.0F; //to convert from Pa to hPa
  
  Serial.print(F("Sending packet: ")); //Serial is used to send information from your Arduino to your computer
  //You can pass flash-memory based strings to Serial.print() by wrapping them with F().
  Serial.println(counter);
 
  Serial.print(F("Pressure = "));
  Serial.print(pressure);
  Serial.println(F("hPa"));
 
  Serial.println();
 
  LoRaMessage = String(counter) + "/" + String(pressure);
 
  // send packet
  //LoRa.beginPacket();
  //LoRa.print(LoRaMessage);
  //LoRa.endPacket();
 
  counter++;
 
  delay(3000);
}
