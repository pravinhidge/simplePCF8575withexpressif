# simplePCF8575withexpressif
code for io expander pcf8575 in esp32 expressif platform

This code is for ESP32 using EXPRESSIF platform 
PCF8575 I2C adress is 0x21
Port o is configured as output---- P04 and P05 connected to LED and continuosly blinking.
Port 1 is configured as input port
Both port status are checking continuosly on serial.
Also provided I2C scan function to scan I2C devices connected to ESP
