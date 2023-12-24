/*
 * utils.c
 *
 *  Created on: Dec 23, 2023
 *      Author: Mosazghi
 */

#include "utils.h"

uint8_t DecToBCD(uint8_t val) { return ((val / 10 * 16) + (val % 10)); }

uint8_t BCDToDec(uint8_t val) { return ((val / 16 * 10) + (val % 16)); }
