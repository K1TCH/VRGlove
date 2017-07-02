#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS0.h>
#include <Adafruit_Sensor.h>  // not used in this demo but required!

/*********************************************/
/*********************************************/
#define TCAADDR 0x70

//establish Contact with Processing application
void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("A");   // send a capital A
    delay(300);
  }
}

/***multiplexer**/
void tcaselect(uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

/*********************************************/
/*********************************************/


// i2c
Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();

// You can also use software SPI
//Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0(13, 12, 11, 10, 9);
// Or hardware SPI! In this case, only CS pins are passed in
//Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0(10, 9);

void setupSensor()
{
  // 1.) Set the accelerometer range
  //  lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_4G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_6G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_8G);
  lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_16G);

  // 2.) Set the magnetometer sensitivity
  lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_4GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_8GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_12GAUSS);

  // 3.) Setup the gyroscope
  lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_500DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_2000DPS);
}

void setup()
{
#ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif
  Serial.begin(9600);
  Serial.println("LSM raw read demo");

  establishContact();  // send a byte to establish contact until receiver responds
  Wire.begin();
  Serial.print("\t Sensor 0: \t");
  Serial.println("Accelerometer Test"); Serial.println("");
  tcaselect(5);

  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM9DS0. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS0 9DOF");
  Serial.println("");
  Serial.println("");

    tcaselect(6);

  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM9DS0. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS0 9DOF");
  Serial.println("");
  Serial.println("");

    tcaselect(7);

  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM9DS0. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS0 9DOF");
  Serial.println("");
  Serial.println("");
}

void loop()
{
  int i;
  for(i=0; i<5; i++){
    tcaselect(5);
    if(i==0) {
      Serial.println("Selecting 5");
    }
    if (Serial.available() > 0) {
      lsm.read();
      float constant = 1600;
      //    Serial.print("Accel X: "); Serial.print((int)lsm.accelData.x); Serial.print(" ");
      //    Serial.print("Y: "); Serial.print((int)lsm.accelData.y);       Serial.print(" ");
      //    Serial.print("Z: "); Serial.println((int)lsm.accelData.z);     Serial.print(" ");
      //    Serial.print("Mag X: "); Serial.print((int)lsm.magData.x);     Serial.print(" ");
      //    Serial.print("Y: "); Serial.print((int)lsm.magData.y);         Serial.print(" ");
      //    Serial.print("Z: "); Serial.println((int)lsm.magData.z);       Serial.print(" ");
      //    Serial.print("Gyro X: "); Serial.print((int)lsm.gyroData.x);   Serial.print(" ");
      //    Serial.print("Y: "); Serial.print((int)lsm.gyroData.y);        Serial.print(" ");
      //    Serial.print("Z: "); Serial.println((int)lsm.gyroData.z);      Serial.println(" ");
      //    Serial.print("Temp: "); Serial.print((int)lsm.temperature);    Serial.println(" ");
      Serial.print((lsm.accelData.x / constant)); Serial.print(",");
      Serial.print((lsm.accelData.y / constant)); Serial.print(",");
      Serial.print((lsm.accelData.z / constant)); Serial.println(" ");
          delay(1000);
    }
  }

  for(i=0; i<5; i++){
    tcaselect(6);
    if(i == 0){
      Serial.println("Selecting 6");
    }
    if (Serial.available() > 0) {
      lsm.read();
      float constant = 1600;
      //    Serial.print("Accel X: "); Serial.print((int)lsm.accelData.x); Serial.print(" ");
      //    Serial.print("Y: "); Serial.print((int)lsm.accelData.y);       Serial.print(" ");
      //    Serial.print("Z: "); Serial.println((int)lsm.accelData.z);     Serial.print(" ");
      //    Serial.print("Mag X: "); Serial.print((int)lsm.magData.x);     Serial.print(" ");
      //    Serial.print("Y: "); Serial.print((int)lsm.magData.y);         Serial.print(" ");
      //    Serial.print("Z: "); Serial.println((int)lsm.magData.z);       Serial.print(" ");
      //    Serial.print("Gyro X: "); Serial.print((int)lsm.gyroData.x);   Serial.print(" ");
      //    Serial.print("Y: "); Serial.print((int)lsm.gyroData.y);        Serial.print(" ");
      //    Serial.print("Z: "); Serial.println((int)lsm.gyroData.z);      Serial.println(" ");
      //    Serial.print("Temp: "); Serial.print((int)lsm.temperature);    Serial.println(" ");
      Serial.print((lsm.accelData.x / constant)); Serial.print(",");
      Serial.print((lsm.accelData.y / constant)); Serial.print(",");
      Serial.print((lsm.accelData.z / constant)); Serial.println(" ");
          delay(1000);
    }
  }

  for(i=0; i<5; i++){
    tcaselect(7);
    if(i==0){
      Serial.println("Selecting 7");
    }
    if (Serial.available() > 0) {
      lsm.read();
      float constant = 1600;
      //    Serial.print("Accel X: "); Serial.print((int)lsm.accelData.x); Serial.print(" ");
      //    Serial.print("Y: "); Serial.print((int)lsm.accelData.y);       Serial.print(" ");
      //    Serial.print("Z: "); Serial.println((int)lsm.accelData.z);     Serial.print(" ");
      //    Serial.print("Mag X: "); Serial.print((int)lsm.magData.x);     Serial.print(" ");
      //    Serial.print("Y: "); Serial.print((int)lsm.magData.y);         Serial.print(" ");
      //    Serial.print("Z: "); Serial.println((int)lsm.magData.z);       Serial.print(" ");
      //    Serial.print("Gyro X: "); Serial.print((int)lsm.gyroData.x);   Serial.print(" ");
      //    Serial.print("Y: "); Serial.print((int)lsm.gyroData.y);        Serial.print(" ");
      //    Serial.print("Z: "); Serial.println((int)lsm.gyroData.z);      Serial.println(" ");
      //    Serial.print("Temp: "); Serial.print((int)lsm.temperature);    Serial.println(" ");
      Serial.print((lsm.accelData.x / constant)); Serial.print(",");
      Serial.print((lsm.accelData.y / constant)); Serial.print(",");
      Serial.print((lsm.accelData.z / constant)); Serial.println(" ");
          delay(1000);
    }
  }
}
