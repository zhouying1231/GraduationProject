#include <Ethernet.h>
#include <SPI.h>

const byte mMacAddress[] = {0xDE,0xAD,0xBE,0xEF,0xFE,0xED};
const IPAddress mLocalIP(192,168,1,2);

IPAddress mServerIP(218,244,137,34);
int mServerPort = 5464;

EthernetClient mClient;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Serial open Successed!");
  if(Ethernet.begin(mMacAddress)==0)
    if(Ethernet.begin(mMacAddress,mLocalIP) == 0)
      Serial.println("Configure MacAddress Failed");
  delay(500);
  mClient.connect(mServerIP,mServerPort);
}

void loop() {
  // put your main code here, to run repeatedly:

}
