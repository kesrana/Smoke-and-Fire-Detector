// Project main file

#include "common.h"
#include "sensor.h"
#include "output.h"
#include "user.h"

int main(void)
{
    system("config-pin P9_17 i2c");
    system("config-pin P9_18 i2c");

    struct thread_data thread_data;
    thread_data.end_all_threads = false;

    // Start threads
    pthread_create(&thread_data.id_user, NULL, exitProgram, &thread_data);
    pthread_create(&thread_data.id_temp, NULL, readTemperature, &thread_data);
    pthread_create(&thread_data.id_IR, NULL, readIR, &thread_data);
    pthread_create(&thread_data.id_air, NULL, readAirSensors, &thread_data);
    

    sleepForMs(1000);
    pthread_create(&thread_data.id_status, NULL, calculateStatus, &thread_data);
    pthread_create(&thread_data.id_alarm, NULL, calcAlarm, &thread_data);
    pthread_create(&thread_data.id_output, NULL, displayOutput, &thread_data);
    
    while(1) {
        // Check for USER button
        pthread_mutex_lock(&thread_data.mutexControl);
        {
            if(thread_data.end_all_threads == true) {
                // Make sure to unlock mutex before waiting
                pthread_mutex_unlock(&thread_data.mutexControl);
                pthread_join(thread_data.id_user, NULL);
                break;
            }
        }
        pthread_mutex_unlock(&thread_data.mutexControl);  
 
        sleepForMs(1000);
    }

    printf("Exiting Program!\n");

    return 0;
}
