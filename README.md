# **Multipurpose Smoke and Fire Detector**

Advanced Smoke Detector is a multi-purpose fire and gas detector designed to mitigate false alarms commonly triggered by modern detectors. Inspired by personal experiences of inconvenience caused by false fire alarms, the system integrates multiple sensors, including TMP36 for temperature, MQ-2 for flammable gas and smoke, MQ-7 for carbon monoxide (CO), MQ-135 for other harmful gases, and TCRT5000 infrared (IR) light sensor. These sensors are connected to a BeagleBone board, where multi-threaded functions written in C continuously sample, calculate, and display readings. By analyzing sensor data, the system determines whether to issue warnings or full alarms, ensuring accurate detection of hazards. Additionally, an IR sensor monitors obstructions and alerts users accordingly. Alarms and warnings are displayed through the terminal and LED matrix, enhancing user awareness and safety.

![image](https://github.com/user-attachments/assets/4deaa3af-ff9f-4018-a03c-a7f679dbc4ca)

![image](https://github.com/user-attachments/assets/c43ff50d-a0be-49ca-961a-55a0d81022e5)

**BeagleBone Usage**

The project provided invaluable insights into the practical application of BeagleBone in embedded real-time software development. By leveraging BeagleBone's capabilities as a versatile development platform, it was possible to interface with multiple sensors, process sensor data in real-time, and execute complex multi-threaded functions efficiently.

**Embedded Real-Time Software**

Working with BeagleBone taught the intricacies of developing embedded real-time software systems. I gained hands-on experience in writing C code optimized for real-time processing, ensuring timely data acquisition, analysis, and response to sensor inputs (I2C communication protocol).

**Multi-Threading**

The implementation of multi-threaded functions on BeagleBone enabled concurrent execution of tasks, enhancing system performance and responsiveness. Through careful synchronization and resource management, we effectively utilized BeagleBone's multi-core architecture to handle sensor data processing efficiently.

**Working with Different Sensors**

Integrating various sensors into the project broadened my understanding of sensor technologies and their applications in real-world scenarios. By working with sensors such as TMP36, MQ-2, MQ-7, MQ-135, and TCRT5000, I gained practical insights into sensor selection, calibration, and data interpretation, enriching my knowledge of sensor-based systems.


