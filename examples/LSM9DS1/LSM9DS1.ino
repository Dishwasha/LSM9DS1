#include<LSM9DS1.h>

LSM9DS1* lsm9ds1;

// Pin definitions
int intPin = 15;  // These can be changed, 2 and 3 are the Arduinos ext int pins
int myLed  = 13;

void setup()
{
  lsm9ds1 = new LSM9DS1(I2C_PINS_16_17, I2C_PULLUP_INT, I2C_RATE_400);
  delay(10000);
  
  // Set up the interrupt pin, its set as active high, push-pull
  pinMode(intPin, INPUT);
  pinMode(myLed, OUTPUT);
  digitalWrite(myLed, HIGH);
  lsm9ds1->init();
}

void loop()
{  
  lsm9ds1->capture();
}
