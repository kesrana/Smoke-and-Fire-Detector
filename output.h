// Header file for output/logic functions

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "common.h"

// #include <sys/ioctl.h>
// #include <linux/i2c.h>
// #include <linux/i2c-dev.h>

#define I2CDRV_LINUX_BUS1 "/dev/i2c-1"
#define I2C_DEVICE_ADDRESS 0x70
#define REG_DIRA 0x21
#define REG_DIRB 0x81

void *calculateStatus(void *arg);

void *calcAlarm(void *arg);

void *displayOutput(void *arg);

#endif