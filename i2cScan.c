#include "i2cScan.h"

void i2c_Scan(void)
{
    // i2c init & scan
    
    if (i2c_master_init() != ESP_OK){
        ESP_LOGE(TAG, "i2c init failed\n");
    }
    printf("i2c scan: \n");
    for (uint8_t i = 1; i < 127; i++)
    {
        int ret;
        i2c_cmd_handle_t cmd = i2c_cmd_link_create();
        i2c_master_start(cmd);
        i2c_master_write_byte(cmd, (i << 1) | I2C_MASTER_WRITE, 1);
        i2c_master_stop(cmd);
        ret = i2c_master_cmd_begin(I2C_NUM_0, cmd, 100 / portTICK_RATE_MS);
        i2c_cmd_link_delete(cmd);

        if (ret == ESP_OK)
        {
            printf("Found device at: 0x%2x\n", i);
        }
    }
}

int i2c_Send(unsigned char *data1)
{
    // i2c_master_init();
    // if (i2c_master_init() != ESP_OK)
    //     ESP_LOGE(TAG, "i2c init failed\n");

    printf("i2c sending data : \n");
    int ret;
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (Expander_pcf8575_ADDR << 1) | I2C_MASTER_WRITE, 1);
   
    i2c_master_write_byte(cmd, data1[0], 0);
    // printf("0x0F \n");
    i2c_master_write_byte(cmd, data1[1], true);
    // i2c_master_write(cmd, data1, sizeof(data1), 1);
    // printf("0x00 \n");
    i2c_master_stop(cmd);

    ret = i2c_master_cmd_begin(I2C_NUM_0, cmd,I2C_MASTER_TIMEOUT_MS);// 100 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);
    if (ret == ESP_OK)
        {
            printf("Data send Successfully \n");
        }

    return 0;
}

// int i2cSend(void)
// {
//     // i2c_master_init();
//     // if (i2c_master_init() != ESP_OK)
//     //     ESP_LOGE(TAG, "i2c init failed\n");

//     printf("i2c sending data : \n");
//     int ret;
//     i2c_cmd_handle_t cmd = i2c_cmd_link_create();
//     i2c_master_start(cmd);
//     i2c_master_write_byte(cmd, (Expander_pcf8575_ADDR << 1) | I2C_MASTER_WRITE, 1);
   
//     i2c_master_write_byte(cmd, 0x4F, 0);
//     // printf("0x0F \n");
//     i2c_master_write_byte(cmd, 0xFF, true);
//     // i2c_master_write(cmd, data1, sizeof(data1), 1);
//     // printf("0x00 \n");
//     i2c_master_stop(cmd);

//     ret = i2c_master_cmd_begin(I2C_NUM_0, cmd,I2C_MASTER_TIMEOUT_MS);// 100 / portTICK_RATE_MS);
//     i2c_cmd_link_delete(cmd);
//     if (ret == ESP_OK)
//         {
//             printf("Data send Successfully \n");
//         }

//     return 0;
// }

void i2cReceive(void){
    uint8_t data[2];
    printf("i2c Reading data : \n");
    int ret;
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (Expander_pcf8575_ADDR << 1) | I2C_MASTER_READ, 1);
   
    i2c_master_read(cmd, data, 2, 0);
    // printf("0x0F \n");
    // i2c_master_read_byte(cmd, data[1], true);
    // i2c_master_write(cmd, data1, sizeof(data1), 1);
    // printf("0x00 \n");
    i2c_master_stop(cmd);

    ret = i2c_master_cmd_begin(I2C_NUM_0, cmd,I2C_MASTER_TIMEOUT_MS);// 100 / portTICK_RATE_MS);
    i2c_cmd_link_delete(cmd);
    printf(" first byte %X \n", data[0]);
    printf(" second byte  %X \n", data[1]);
    if (ret == ESP_OK)
        {
            printf("Data received Successfully \n");
    }
     
}