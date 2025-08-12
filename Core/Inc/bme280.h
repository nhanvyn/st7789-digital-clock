/*
 * bme280.h
 *
 *  Created on: Aug 11, 2025
 *      Author: limou
 */

#ifndef INC_BME280_H_
#define INC_BME280_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "main.h"
#define BME280_ADDR 0x76
#define CTRL_MEAS_REG 0xF4


/* Oversampling settings: How much samples the BME280
 * take into consideration before calculate the avg the temperature / pressure */

#define OSRS_0    	0x00
#define OSRS_1     0x01
#define OSRS_2     0x02

#define MODE_SLEEP      0x00
#define MODE_FORCED     0x01
#define MODE_NORMAL     0x03

#define BME280_TIMEOUT 100

#define TEMP_MSB_REG 0xFA
#define ID_REG 0xD0

#define CHIP_ID 0x60

#define TRIM_REG 0x88

typedef uint8_t bool_t;
#define TRUE  1
#define FALSE 0


int BME280_Config(I2C_HandleTypeDef* hi2c);
void Calib_Data_Read(I2C_HandleTypeDef* hi2c);
int32_t BME280_ReadTemp(I2C_HandleTypeDef* hi2c);
int32_t BME280_compensate_T_int32(int32_t adc_T);

#endif /* INC_BME280_H_ */



