#include <Ethernet.h>
#include <SPI.h>
#include "info.cpp"
byte mMacAddress[] = {0xDE,0xAD,0xBE,0xEF,0xFE,0xED};
IPAddress mLocalIP(192,168,1,2);
IPAddress mServerIP(218,244,137,34);
int mServerPort = 5464;
int mPin = 2;
EthernetClient mClient;
void InitPin()
{
  for(int i = 2;i<9;i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
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
int ParseSerial()
{
  char* command;
  while(mClient.available())
  {
    command += mClient.read();
  }
  Serial.print("Receive:");
  Serial.println(command);
  //5,0;5,1;A,0;A,1
  if(command[0] == 'A' || command[0] == 'a')
  {
    return (command[2]==1)?OPENALL:CLOSEALL;
  }
  else
  {
    mPin = (int)command[0];
    return (command[2]==1)?OPEN:CLOSE;
  }
}
void ActionALL(bool mode)
{
  for(int i = 2;i<9;i++)
    digitalWrite(i,mode);
}
void loop() 
{
  if(mClient.connected())
  {
    if(mClient.available())
      switch(ParseSerial())
      {
        case OPEN:
          digitalWrite(mPin,HIGH);
          break;
        case CLOSE:
          digitalWrite(mPin,LOW);
          break;
        case OPENALL:
          ActionALL(HIGH);
          break;
        case CLOSEALL:
          ActionALL(LOW);
          break;
      }
      String command = "";
      command += "{\"Tpye\":";
      command += CONFIRMTYPE;
      command += ",\"Context\":";
      command += "OK";
      command += "\"}";
      mClient.println(command);
  }
  else
  {   
    mClient.stop();
    ActionALL(LOW);
  }
}
