/*
 * frame_mod.h
 *
 *  Created on: Aug 6, 2025
 *      Author: limou
 */
#include "frames.h"
#include "fonts.h"
#include "st7789.h"

#ifndef INC_FRAME_MOD_H_
#define INC_FRAME_MOD_H_

void Buffer_WriteChar(uint16_t x, uint16_t y, char ch,  uint16_t* buffer, FontDef font, uint16_t color, uint16_t bgcolor);
void Buffer_WriteString(uint16_t x, uint16_t y, const char *str, uint16_t* buffer , FontDef font, uint16_t color, uint16_t bgcolor);



#endif /* INC_FRAME_MOD_H_ */
