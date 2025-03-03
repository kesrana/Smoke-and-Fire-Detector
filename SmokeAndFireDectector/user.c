#include "user.h"

int UserButtonValue() {
    // Open file to read value
    FILE *pFile = fopen(USERBUTTON, "r");

    // Error checking
    if (pFile == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    // Value for pressed button is 0
    int value;
    fscanf(pFile, "%d", &value);
    fclose(pFile);

    return value;
}

void *exitProgram(void *arg) 
{
    struct thread_data *data = arg;

    while(1) {
        int button_value = UserButtonValue();

        // On the board, 0 is the value for button pressed
        if(button_value == 0) {
            
            printf("USER button pressed! Closing all threads...\n");

            // Close all threads
            pthread_mutex_lock(&data->mutexControl); 
            {
                data->end_all_threads = true; 
            }
            pthread_mutex_unlock(&data->mutexControl);
            
            pthread_join(data->id_output, NULL);
            pthread_join(data->id_temp, NULL);
            pthread_join(data->id_IR, NULL);
            pthread_join(data->id_air, NULL);
            pthread_join(data->id_status, NULL);
            pthread_join(data->id_alarm, NULL);

            break; // Breaks the loop in main()
        }

        // Check every 100 ms
        sleepForMs(100);
    }

    return NULL;
}
