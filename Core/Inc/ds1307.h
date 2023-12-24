/*
 * ds1307.h
 *
 *  Created on: Dec 23, 2023
 *      Author: Mosazghi
 */

#ifndef CORE_INC_DS1307_H_
#define CORE_INC_DS1307_H_

#include "main.h"
#include "utils.h"

#define DS1307_SLAVE_ADDRESS 0x68 << 1
#define DS1307_SECONDS_ADDRESS 0x00
#define DS1307_INT_MEM_ADDR_SIZE 1

#define DS1307_TIMEOUT 1000

enum WEEKDAY {
  MONDAY = 1,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY,
  SUNDAY
};

// DS1307 time struct 
typedef struct {
  uint8_t seconds; //< 0-59
  uint8_t minutes; //< 0-59
  uint8_t hours;   //< 24 hour format 0-23
  uint8_t day;     //< day of week 1-7
  uint8_t date;    //< day of month 1-31
  uint8_t month;   //< month 1-12
  uint8_t year;    //< year (20)00-99
} RTC_date_t;

void ds1307_init(I2C_HandleTypeDef *hi2c);
void ds1307_set_time(RTC_date_t *time);
void ds1307_get_time(RTC_date_t *time);
#endif /* CORE_INC_DS1307_H_ */
