/*
 * time_convert.h
 *
 *  Created on: Aug 12, 2025
 *      Author: limou
 */

#ifndef INC_TIME_CONVERT_H_
#define INC_TIME_CONVERT_H_
#include <stdint.h>
#include <string.h>

uint8_t month_from_str(const char *m);
const char* month_to_str(uint8_t month);
const char* weekday_to_str(uint8_t weekday);
uint8_t weekday_from_ymd(int year, int month, int day) ;
const char* get_AM_or_PM(uint8_t hours);

#endif /* INC_TIME_CONVERT_H_ */
