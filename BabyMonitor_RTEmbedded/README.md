## Summary

A system that provides a solution for monitoring and controlling the baby's room.
The purpose of the system is to identify situations in which parents are required to pay attention to the baby while they are not close to the baby's room.
You can:
1. Recognize when the baby begins to cry.
2. Identify when the baby tries to get out of the coop.
3. Set the intensity of the light in the baby's room.

## Sensors and Protocols

Sensor details:

1. The noise level will be measured by the ADMP401 (MEMS Microphone Module) sensor that operates on the ADC protocol, 
   which converts analog signals to digital and transfers them to the system.
2. The distance measured by the US-100 Ultrasonic Distance Sensor (UART) 
   sensor is a common communication protocol for asynchronous serial communication, in which the data format and transmit speeds are          configurable.
3. The the intensity of the light in the baby's room can be set by Dimmer, 
   which reads the data via ADC protocol and converts the readings using PWM protocol and sets the LED power.
   PWM - A technique used to encode an encoding into a Pulsating Signal, 
   whose main use is to enable the control of the power supplied to electrical devices.
4. GPIO - There are 2 buttons, which are marked on the board in SW2 and SW3.
   The SW2 - P15 button is used by us to turn off the LED light, which turns on when there is some warning from the system.
   The SW3 - P4 button is used by us to switch the system on and off.
   
   ## Activity Diagram 
   ![Activity Diagram](https://github.com/DanielSchafer87/BabyMonitor_RTEmbedded/blob/master/BabyMonitor_RTEmbedded/ActivityDiagram.png)
   
   ## Board Photos Including Sensors
   ![Photo #1](https://github.com/DanielSchafer87/BabyMonitor_RTEmbedded/blob/master/BabyMonitor_RTEmbedded/4207209c-8c4b-40bc-b181-2fb2c344b7f2.jpg)
   
   ![Photo #2](https://github.com/DanielSchafer87/BabyMonitor_RTEmbedded/blob/master/BabyMonitor_RTEmbedded/8978a96c-c45c-4802-bd30-008c1576c38c.jpg)
  
