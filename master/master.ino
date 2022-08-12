// CREATED BY GAURESH WADEKAR 
#include <Wire.h>

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(9600);
}

byte x = 0;

void loop()
{
  if(Serial.available()>0)
  {
    Wire.beginTransmission(4);
    byte string = Serial.read();
    Serial.print((char)string);  
    Wire.write((char)string);
    Wire.endTransmission();    // stop transmitting
}
  delay(500);
}
