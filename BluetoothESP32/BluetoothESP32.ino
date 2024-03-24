#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Esp32-BT");
}

void loop() {
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
    SerialBT.print("Data received!!!");
    delay(20);
  }
  delay(20);  
}