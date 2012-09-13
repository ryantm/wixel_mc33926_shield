#include "DualMC33926MotorShield.h"
DualMC33926MotorShield md;
unsigned char oneGoing = 0;
unsigned char twoGoing = 0;
int incomingByte;

void setup()
{
  delay(10);
  Serial.begin(115200);
  delay(10);
  Serial.println("Dual MC33926 Motor Shield");
  Serial.println("Send '1' for motor 1 and '2' for motor 2.");
  md.init();
}

void loop()
{
  // see if there's incoming serial data:
  if (Serial.available() > 0) 
  {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    if (incomingByte == '1') 
    {
      oneGoing = !oneGoing;
      if (oneGoing)
        md.setM1Speed(200);
      else
        md.setM1Speed(0);
    } 
    if (incomingByte == '2') 
    {
      twoGoing = !twoGoing;
      if (twoGoing)
        md.setM2Speed(200);
      else
        md.setM2Speed(0);
    }
  }
}
