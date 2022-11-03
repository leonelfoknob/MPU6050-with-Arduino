/****************************makinafleo**********************/
/*
youtube : makinafleo
instagram : @makin_afleo
website : makinafleo.wordpress.com
*/

#include <Adafruit_MPU6050.h> //don't forget to download this library
#include <Adafruit_Sensor.h> //don't forget to download this library
#include <Wire.h>
Adafruit_MPU6050 mpu;
void setup() {
  Serial.begin(19200);
  }

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  delay(100);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  float Acc_x = a.acceleration.x;
  float Acc_y = a.acceleration.y;
  float Acc_z = a.acceleration.z;
  float Gy_x = g.gyro.x;
  float Gy_y = g.gyro.y;
  float Gy_z = g.gyro.z;
  Serial.print("Acc_x: ");
  Serial.print(Acc_x);
  Serial.print(" | ");
  Serial.print("Acc_y: ");
  Serial.print(Acc_y);
  Serial.print(" | ");
  Serial.print("Acc_z ");
  Serial.print(Acc_z);
  Serial.print(" m/s^2");
  Serial.print(" | ");
  Serial.print("Gy_x: ");
  Serial.print(Gy_x);
  Serial.print(" | ");
  Serial.print("Gy_y");
  Serial.print(Gy_y);
  Serial.print(" | ");
  Serial.print("Gy_z: ");
  Serial.print(Gy_z);
  Serial.println(" rad/s");
  delay(500);
  
}
