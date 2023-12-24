/*
 * utils.h
 *
 *  Created on: Dec 23, 2023
 *      Author: Mosazghi
 */

#ifndef CORE_INC_UTILS_H_
#define CORE_INC_UTILS_H_
#include "main.h"
// // Convert normal decimal numbers to binary coded decimal
// uint8_t decToBcd(int val);
// // Convert binary coded decimal to normal decimal numbers
// int bcdToDec(uint8_t val);

uint8_t DecToBCD(uint8_t val);
uint8_t BCDToDec(uint8_t val);
#endif /* CORE_INC_UTILS_H_ */
