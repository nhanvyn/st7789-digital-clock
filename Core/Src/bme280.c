/*
 * bme280.c
 *
 *  Created on: Aug 11, 2025
 *      Author: limou
 */
#include "bme280.h"
#include <stdint.h>


uint16_t dig_T1;
int16_t  dig_T2, dig_T3;



int BME280_Config(I2C_HandleTypeDef* hi2c)
{
	uint8_t writedata = (OSRS_2 << 5) | (OSRS_2 << 2) | MODE_NORMAL;
	uint8_t readdata = 0;
	HAL_I2C_Mem_Write(hi2c, BME280_ADDR << 1, CTRL_MEAS_REG, 1, &writedata, 1, BME280_TIMEOUT);

	HAL_I2C_Mem_Read(hi2c, BME280_ADDR << 1, CTRL_MEAS_REG, 1, &readdata, 1, BME280_TIMEOUT);

	if (readdata != writedata)
	{
		return -1;
	}

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	return 0;

}

void Calib_Data_Read(I2C_HandleTypeDef* hi2c)
{
	uint8_t calibData[6];
	HAL_I2C_Mem_Read(hi2c, BME280_ADDR << 1, TRIM_REG, 1, calibData, 6, BME280_TIMEOUT);

	dig_T1 = (uint16_t)((calibData[1] << 8) | calibData[0]);
	dig_T2 = (int16_t)((calibData[3] << 8) | calibData[2]);
	dig_T3 = (int16_t)((calibData[5] << 8) | calibData[4]);
}

int32_t BME280_ReadTemp(I2C_HandleTypeDef* hi2c)
{
	uint8_t chipID;
	uint8_t rawData[3];
	HAL_I2C_Mem_Read(hi2c, BME280_ADDR << 1, ID_REG, 1, &chipID, 1, BME280_TIMEOUT);
	if (chipID == CHIP_ID)
	{
		HAL_I2C_Mem_Read(hi2c, BME280_ADDR << 1, TEMP_MSB_REG, 1, rawData, 3, BME280_TIMEOUT);
		return (rawData[0] << 12) | (rawData[1] << 4) | (rawData[2] >> 4);
	}
	return 0;
}

// Returns temperature in DegC, resolution is 0.01 DegC. Output value of “5123” equals 51.23 DegC.
// t_fine carries fine temperature as global value
int32_t BME280_compensate_T_int32(int32_t adc_T)
{
	int32_t var1, var2, T;
	var1 = ((((adc_T>>3) - ((int32_t)dig_T1<<1))) * ((int32_t)dig_T2)) >> 11;
	var2 = (((((adc_T>>4) - ((int32_t)dig_T1)) * ((adc_T>>4) - ((int32_t)dig_T1))) >> 12) * ((int32_t)dig_T3)) >> 14;
	int32_t t_fine = var1 + var2;
	T = (t_fine * 5 + 128) >> 8;
	return T;
}
