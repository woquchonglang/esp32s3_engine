#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "unity.h"
#include "driver/i2c.h"
#include "driver/spi_master.h"
#include "esp_heap_caps.h"
#include "driver/gpio.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_io_interface.h"
#include "esp_lcd_panel_ops.h"
#include "mpu6050_drv.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nv3030b_sof_drv.h"




#define I2C_MASTER_SCL_IO 9      /*!< gpio number for I2C master clock */
#define I2C_MASTER_SDA_IO 10      /*!< gpio number for I2C master data  */
#define I2C_MASTER_NUM I2C_NUM_0  /*!< I2C port number for master dev */
#define I2C_MASTER_FREQ_HZ 400000 /*!< I2C master clock frequency */

static const char *TAG = "mpu6050 test";
static mpu6050_handle_t mpu6050 = NULL; 
mpu6050_acce_value_t acce;
mpu6050_gyro_value_t gyro;
mpu6050_temp_value_t temp;
complimentary_angle_t angle;

/**
 * @brief i2c master initialization
 */
static void i2c_bus_init(void)
{
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = (gpio_num_t)I2C_MASTER_SDA_IO;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_io_num = (gpio_num_t)I2C_MASTER_SCL_IO;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = I2C_MASTER_FREQ_HZ;
    conf.clk_flags = I2C_SCLK_SRC_FLAG_FOR_NOMAL;

    esp_err_t ret = i2c_param_config(I2C_MASTER_NUM, &conf);
    TEST_ASSERT_EQUAL_MESSAGE(ESP_OK, ret, "I2C config returned error");

    ret = i2c_driver_install(I2C_MASTER_NUM, conf.mode, 0, 0, 0);
    TEST_ASSERT_EQUAL_MESSAGE(ESP_OK, ret, "I2C install returned error");
}

/**
 * @brief i2c master initialization
 */
static void i2c_sensor_mpu6050_init(void)
{
    esp_err_t ret;

    i2c_bus_init();
    mpu6050 = mpu6050_create(I2C_MASTER_NUM, MPU6050_I2C_ADDRESS);
    TEST_ASSERT_NOT_NULL_MESSAGE(mpu6050, "MPU6050 create returned NULL");

    ret = mpu6050_config(mpu6050, ACCE_FS_2G, GYRO_FS_2000DPS);
    TEST_ASSERT_EQUAL(ESP_OK, ret);

    ret = mpu6050_wake_up(mpu6050);
    TEST_ASSERT_EQUAL(ESP_OK, ret);
}


void read_acce_func(void)
{
    while(1)
    {
        mpu6050_get_acce(mpu6050, &acce);
        ESP_LOGI(TAG, "acce_x:%.2f, acce_y:%.2f, acce_z:%.2f\n", acce.acce_x, acce.acce_y, acce.acce_z);
        vTaskDelay(100 / portTICK_PERIOD_MS); 
    }
}

void read_gyro_func()
{
    while(1)
    {
        mpu6050_get_gyro(mpu6050, &gyro);
        ESP_LOGI(TAG, "gyro_x:%.2f, gyro_y:%.2f, gyro_z:%.2f\n", gyro.gyro_x, gyro.gyro_y, gyro.gyro_z);
        vTaskDelay(100 / portTICK_PERIOD_MS); 
    }
    
}
void read_temp_func()
{
    while(1)
    {
        mpu6050_get_temp(mpu6050, &temp);
        ESP_LOGI(TAG, "t:%.2f \n", temp.temp);
        vTaskDelay(100/ portTICK_PERIOD_MS); 
    }
    
}

void mpu6050_complimentory_filter_func()
{
    while(1)
    {
        mpu6050_get_acce(mpu6050, &acce);
        mpu6050_get_gyro(mpu6050, &gyro);
        mpu6050_complimentory_filter(mpu6050,&acce,&gyro,&angle);
        ESP_LOGI(TAG, "pitch_roll:%.2f,%.2f \n", angle.pitch,angle.roll);
        vTaskDelay(100/ portTICK_PERIOD_MS); 
    }
    
}

void LCD_fill_tset()
{
    ESP_LOGI(TAG, "LCD_fill_tset");

    while(1)
    {
        LCD_Fill(0,0,LCD_W,LCD_H,BLUE);

        vTaskDelay(1000/ portTICK_PERIOD_MS); 

        // LCD_Fill(0,0,LCD_W,LCD_H,GBLUE);

        // vTaskDelay(1000/ portTICK_PERIOD_MS); 
    }
    
}

void app_main(void)
{
    
    uint8_t mpu6050_deviceid;
    
    i2c_sensor_mpu6050_init();

    mpu6050_get_deviceid(mpu6050, &mpu6050_deviceid);
     
    LCD_Init();

    // mpu6050_delete(mpu6050);
    // i2c_driver_delete(I2C_MASTER_NUM);


    //xTaskCreate(mpu6050_complimentory_filter_func,"mpu6050_complimentory_filter_func",2048,NULL,1,NULL);

    xTaskCreate(LCD_fill_tset,"LCD_fill_tset",2048,NULL,1,NULL);
}
