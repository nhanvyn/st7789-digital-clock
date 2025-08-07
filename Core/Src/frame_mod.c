/*
 * frame_mod.c
 *
 *  Created on: Aug 6, 2025
 *      Author: limou
 */
#include "frame_mod.h"

/**
 * @brief Write a char
 * @param  x&y -> cursor of the start point.
 * @param ch -> char to write
 * @param font -> fontstyle of the string
 * @param color -> color of the char
 * @param bgcolor -> background color of the char
 * @return  none
 */
void Buffer_WriteChar(uint16_t x, uint16_t y, char ch,  uint16_t* buffer, FontDef font, uint16_t color, uint16_t bgcolor)
{
	uint32_t i, b, j;


	for (i = 0; i < font.height; i++) {
		b = font.data[(ch - 32) * font.height + i]; // get next row of bits
		for (j = 0; j < font.width; j++) {
			if ((b << j) & 0x8000) {
				buffer[(y + i) * FRAME_WIDTH + (x + j)] = color;
			}
			else {
				buffer[(y + i) * FRAME_WIDTH + (x + j)] = bgcolor;
			}
		}
	}
}

/**
 * @brief Write a string
 * @param  x&y -> cursor of the start point.
 * @param str -> string to write
 * @param font -> fontstyle of the string
 * @param color -> color of the string
 * @param bgcolor -> background color of the string
 * @return  none
 */
void Buffer_WriteString(uint16_t x, uint16_t y, const char *str, uint16_t* buffer , FontDef font, uint16_t color, uint16_t bgcolor)
{
	while (*str) {
		if (x + font.width >= ST7789_WIDTH) {
			x = 0;
			y += font.height;
			if (y + font.height >= ST7789_HEIGHT) {
				break;
			}

			if (*str == ' ') {
				// skip spaces in the beginning of the new line
				str++;
				continue;
			}
		}
		Buffer_WriteChar(x, y, *str, buffer, font, color, bgcolor);
		x += font.width;
		str++;
	}
}


