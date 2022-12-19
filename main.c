#include <stdio.h>
#include "esp_log.h"
#include "i2cScan.h"  

void app_main()
{
    unsigned char data2[2] = {0x4F, 0xFF}, data3[2] = {0x7F, 0xFF};
    i2c_master_init();
    i2c_Scan();
    
    // i2cSend(data1);
    
    while(1){
    i2c_Send(data2);
    i2cReceive();
    esp_rom_delay_us(2000000);
    i2cReceive();
    esp_rom_delay_us(2000000);
    i2cReceive();
    esp_rom_delay_us(2000000);
    i2cReceive();
    i2c_Send(data3);
    esp_rom_delay_us(2000000);
    i2cReceive();
    esp_rom_delay_us(2000000);
    i2cReceive();
    esp_rom_delay_us(2000000);
    i2cReceive();
    esp_rom_delay_us(2000000);


    

    }
}