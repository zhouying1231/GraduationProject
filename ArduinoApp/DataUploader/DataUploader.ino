#include <Ethernet.h>
#include <SPI.h>
#include "info.cpp"
byte mMacAddress[] = {0xDE,0xAD,0xBE,0xEF,0xFE,0xED};
IPAddress mLocalIP(192,168,1,2);
IPAddress mServerIP(218,244,137,34);
int mServerPort = 5464;

EthernetClient mClient;
void InitPin()
{
    pinMode(A0,INPUT);
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(A3,INPUT);
    pinMode(A4,INPUT);
    pinMode(A5,INPUT); 
}
void setup() 
{
  Serial.begin(9600);
  Serial.println("Serial open Successed!");
  if(Ethernet.begin(mMacAddress) == 0)
  {
    Serial.println("Configure Ethernet using DHCP failed");
    Ethernet.begin(mMacAddress,mLocalIP);
  }
  delay(500);
  if(mClient.connect(mServerIP,mServerPort))
  {
    Serial.println("Connect to Server Succcessed");
    String command = "";
    command += "{\"Tpye\":";
    command += REGISTTYPE;
    command += ",\"ID\":";
    command += APPID;
    command += ",\"name\":\"";
    command += APPNAME;
    command += "\"}";
    mClient.println(command);
  }
}
void UpLoadData(int pin)
{
  int mRawData = analogRead(pin);
  String command = "";
  command += "{\"pin\":";
  command += pin;
  command += ",\"data\":";
  command += mRawData;
  command += "}";
  mClient.println(command);
}
void loop() 
{
  if(mClient.connected())
  {
    UpLoadData(A0);
  }
  else
  {   
    mClient.stop();
  }
  delay(1000);
}
