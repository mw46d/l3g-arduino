#include <Wire.h>
#include <L3G.h>

L3G gyro;

void setup() {
  SerialUSB.begin();
  Wire.begin(14, 15);

  if (!gyro.init()) {
    SerialUSB.println("Failed to autodetect gyro type!");
    while (1);
  }

  gyro.enableDefault();
}

void loop() {
  gyro.read();

  SerialUSB.print("G ");
  SerialUSB.print("X: ");
  SerialUSB.print((int)gyro.g.x);
  SerialUSB.print(" Y: ");
  SerialUSB.print((int)gyro.g.y);
  SerialUSB.print(" Z: ");
  SerialUSB.println((int)gyro.g.z);

  delay(100);
}
