# Bluetooth Send Text C++(Linux) or Python

## Installation 
```bash
#C++ language:
sudo apt-get update
sudo apt-get install bluez
sudo apt-get install libbluetooth-dev

#Python language: No installation required
```

## HOW TO
1. Change MAC address(Bluetooth).

2. Compile and Run the program:
```bash
#C++ language:
g++ -o bluetooth_send bluetooth_send.cpp -lbluetooth
./bluetooth_send

#Python language:
py .\bluetooth_send.py
#or
python .\bluetooth_send.py
#or
py3 .\bluetooth_send.py
#or
python3 .\bluetooth_send.py
```

3. Test on connected device, can use ESP32 as an example.

### Good Luck
