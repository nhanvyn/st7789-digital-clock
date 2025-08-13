/*
 * time_convert.c
 *
 *  Created on: Aug 12, 2025
 *      Author: limou
 */
#include "time_convert.h"


const char* get_AM_or_PM(uint8_t hours) {
    return (hours < 12) ? "AM" : "PM";
}

uint8_t weekday_from_ymd(int year, int month, int day) {
    static const uint8_t t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (month < 3) year -= 1;
    uint8_t w = (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
    return (w == 0) ? 7 : w; // 1=Mon, 7=Sun (STM32 HAL convention)
}

const char* weekday_to_str(uint8_t weekday) {
    // 1 = Monday, 7 = Sunday
    static const char *names[] = {
        "???", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"
    };
    if (weekday >= 1 && weekday <= 7) {
        return names[weekday];
    }
    return "???";
}

const char* month_to_str(uint8_t month) {
    // month: 1 = Jan, 12 = Dec
    static const char *names = "JanFebMarAprMayJunJulAugSepOctNovDec";
    if (month >= 1 && month <= 12) {
        return names + (month - 1) * 3;
    }
    return "???";
}

uint8_t month_from_str(const char *date) {
	// date points to "__DATE__", e.g. "Aug  8 2025"
    static const char *names = "JanFebMarAprMayJunJulAugSepOctNovDec";
    for (uint8_t i = 0; i < 12; i++){
    	if (strncmp(date, names + 3*i, 3) == 0){
    		return i+1;
    	}
    }
    return 1;
}
