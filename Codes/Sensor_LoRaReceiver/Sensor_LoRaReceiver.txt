#include <SPI.h>
#include <LoRa.h>
 
#define SS PA4
#define RST PB0
#define DI0 PA1
 
#define TX_P 17
#define BAND 433E6
#define ENCRYPT 0x78
 
  String counter;
  String pressure;
 
void setup() 
{
  Serial.begin(115200);
  while (!Serial);
 
  Serial.println("LoRa Receiver");
  LoRa.setTxPower(TX_P);
  LoRa.setSyncWord(ENCRYPT);
  
  LoRa.setPins(SS, RST, DI0);
  if (!LoRa.begin(BAND)) 
  {
    Serial.println("Starting LoRa failed!");
    //while (1);
  }
}
 
void loop() {
  //parse packet
  int pos1,pos2,pos3,pos4;
  
  int packetSize = LoRa.parsePacket();
  if (packetSize) 
  {
    // received a packet
    Serial.print("Received packet:  ");
    String LoRaData = LoRa.readString();
    Serial.print(LoRaData); 
    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    // print RSSI(Recieved signal strength indicator) of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
 
    pos1 = LoRaData.indexOf('/');
    pos2 = LoRaData.indexOf('&');
    pos3 = LoRaData.indexOf('#');
    pos4 = LoRaData.indexOf('@');
 
    counter = LoRaData.substring(0, pos1);
    pressure = LoRaData.substring(pos2+1,pos3);
 
    
    Serial.print(F("Packet No. = "));
    Serial.println(counter);
  
    Serial.print(F("Pressure = "));
    Serial.print(pressure);
    Serial.println(F("hPa"));
  }
}
