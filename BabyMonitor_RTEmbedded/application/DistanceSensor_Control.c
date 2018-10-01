/*
 * DistanceSensor_Control.c
 *
 *      Author: Daniel Shefer & Zohar Korenblum
 */
#include <stdint.h>
#include <stddef.h>
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ti/sysbios/bios.h>
#include <ti/drivers/GPIO.h>
#include <xdc/cfg/global.h>
#include <ti/devices/cc32xx/inc/hw_types.h>
#include <ti/devices/cc32xx/inc/hw_memmap.h>
#include <ti/devices/cc32xx/driverlib/timer.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/knl/Semaphore.h>
#include "Board.h"

//The UART Distance Sensor function.
void UART_task_func(){

    int distance;
    unsigned char MSByte=0x00;
    unsigned char LSByte=0x00;
    unsigned char trigger = 0x55;
    UART_Handle uart;
    UART_Params uart_params;

    //Inititalize the UART.
    UART_init();

    //Set UART Parameters.
    UART_Params_init(&uart_params);
    uart_params.readDataMode = UART_DATA_TEXT;
    uart_params.writeDataMode = UART_DATA_TEXT;
    uart_params.readEcho = UART_ECHO_OFF;
    uart_params.readReturnMode = UART_RETURN_FULL;
    uart_params.baudRate = 9600;

    //Open the UART connection.
    uart = UART_open(Board_UART1, &uart_params);
    if(uart == NULL){
        System_printf("UART Open Fail!");
        System_flush();
        while(1);
    }

    while(1){
          //Wait for post from the timer interrupt.
          Semaphore_pend(UART_DistanceSem,BIOS_WAIT_FOREVER);
          //Write the trigger sequence to the sensor
          //In order to wake the sensor up.
          UART_write(uart, &trigger, sizeof(trigger));
          //The answer from the sensor has 2 bytes.
          //First we read the first byte.
          UART_read(uart, &MSByte,sizeof(MSByte));
          //And after that read the second byte.
          UART_read(uart, &LSByte,sizeof(LSByte));
          //Convert the distance to Centimeters.
          //(MSByte*256 + LSByte) -> gives us millimeters.
          //and by multiplication of 0.1 we get Centimeters.
          distance = (MSByte*256 + LSByte) * 0.1;
          //If the distance is lower than 95cm
          //post the dimmer semaphore to get the dimmer current value.
          //and then turn on the Red Led (Alert Led).
          if(distance < 95){
              System_printf("Distance Sensor Alert! (%d)\n",distance);
              System_flush();
              Semaphore_post(DimmerSem);
            }
        }
}



