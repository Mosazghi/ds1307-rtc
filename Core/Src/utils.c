/*
 * utils.c
 *
 *  Created on: Dec 23, 2023
 *      Author: Mosazghi
 */

#include "utils.h"

// // Convert normal decimal numbers to binary coded decimal
// uint8_t decToBcd(int val) { return (uint8_t)((val / 10 * 16) + (val % 10)); }
// // Convert binary coded decimal to normal decimal numbers
// int bcdToDec(uint8_t val) { return (int)((val / 16 * 10) + (val % 16)); }

uint8_t DecToBCD(uint8_t val) { return ((val / 10 * 16) + (val % 10)); }

uint8_t BCDToDec(uint8_t val) { return ((val / 16 * 10) + (val % 16)); }
