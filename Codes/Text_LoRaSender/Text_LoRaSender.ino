#include <SPI.h> // device communication
#include <LoRa.h> // Serial peripheral Interface
 
#define SS PA4
#define RST PB0
#define DI0 PA1
 
#define TX_P 17 // MINIMUM POWER FOR TRANSMISSION OF DATA - 17DBM
#define BAND 433E6 //frequency 433 * 10(6)
#define ENCRYPT 0x78 //In 256 bit encryption there are 78 bits combination
 
int counter = 0;
 
void setup() 
{
  Serial.begin(115200); // set baud rate (bits/sec)
  while (!Serial); // wait for serial port to connect. Needed for native USB port only
 
  Serial.println("LoRa Sender");
 
  LoRa.setTxPower(TX_P);
  LoRa.setSyncWord(ENCRYPT);  // To isolate LoRa network
  
  LoRa.setPins(SS, RST, DI0);
  if (!LoRa.begin(BAND)) 
  {
    Serial.println("Starting LoRa failed!");
    //while (1);
  }
}
 
void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);
 
  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();
 
  counter++;
 
  delay(5000);
}
