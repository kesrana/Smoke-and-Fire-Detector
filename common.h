// Header file common functions/libraries between modules

#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <math.h>
#include <fcntl.h>
#include <string.h>

#define IRPOINT 1.75
#define TEMPPOINT 27.0
#define COPOINT 0.9
#define CO2POINT 0.9
#define SMOKEPOINT 0.65

#define BUFFER_SIZE 10

struct thread_data
{
    pthread_mutex_t mutexControl, mutexTemp, mutexIR, mutexAir, mutexAlarm;
    pthread_t id_user, id_temp, id_air, id_IR, id_status, id_output, id_alarm;

    // Uses mutexControl
    bool end_all_threads;

    double temp_value, smoke_value, CO_value, CO2_value, IR_value; 
    bool alarm_temp, alarm_smoke, alarm_CO, alarm_CO2, alarm_IR;
    bool warning_alarm, general_alarm, obstructed_alarm;

    double IR_buffer[BUFFER_SIZE];
};

// Sleep in ms
void sleepForMs(long long delayInMs);

#endif
