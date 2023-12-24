/*
 * ds1307.c
 *
 *  Created on: Dec 23, 2023
 *      Author: Mosazghi
 */
#include "ds1307.h"

// I2C handle for DS1307
static I2C_HandleTypeDef *hi2c_ds1307;

/**
 * @brief Initialize DS1307
 * @param hi2c I2C handle
 */
void ds1307_init(I2C_HandleTypeDef *hi2c) { hi2c_ds1307 = hi2c; }

/**
 * @brief Set time to DS1307
 * @param time pointer to RTC_date_t struct
 */
void ds1307_set_time(RTC_date_t *time) {
  uint8_t data[7];
  data[0] = DecToBCD(time->seconds);
  data[1] = DecToBCD(time->minutes);
  data[2] = DecToBCD(time->hours);
  data[3] = DecToBCD(time->day);
  data[4] = DecToBCD(time->date);
  data[5] = DecToBCD(time->month);
  data[6] = DecToBCD(time->year);

  // Write given time struct to DS1307
  HAL_I2C_Mem_Write(hi2c_ds1307, DS1307_SLAVE_ADDRESS, DS1307_SECONDS_ADDRESS,
                    DS1307_INT_MEM_ADDR_SIZE, data, 7, DS1307_TIMEOUT);
}

/**
 * @brief Get time from DS1307
 * @param time pointer to RTC_date_t struct
 */
void ds1307_get_time(RTC_date_t *time) {
  uint8_t data[7];

  // Retrieve current time from DS1307
  HAL_I2C_Mem_Read(hi2c_ds1307, DS1307_SLAVE_ADDRESS, DS1307_SECONDS_ADDRESS,
                   DS1307_INT_MEM_ADDR_SIZE, data, 7, DS1307_TIMEOUT);

  time->seconds = BCDToDec(data[0]); // 0x7F to remove CH bit
  time->minutes = BCDToDec(data[1]);
  time->hours = BCDToDec(data[2]);
  time->day = BCDToDec(data[3]);
  time->date = BCDToDec(data[4]);
  time->month = BCDToDec(data[5]);
  time->year = BCDToDec(data[6]);
}
