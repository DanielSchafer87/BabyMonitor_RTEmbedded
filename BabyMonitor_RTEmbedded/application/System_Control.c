/*
 * System_Control.c
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
#include "PWM_Helper.h"

bool SystemOn = false;

//SystemTimer Interrupt follow-up function.
void TimerHWI(){
    //Post the Microphone semaphore.
    Semaphore_post(MicrophoneSem);
    //Post the Distance Sensor semaphore.
    Semaphore_post(UART_DistanceSem);
    //Clear the timer intterupt.
    TimerIntClear(TIMERA2_BASE, TIMER_TIMA_TIMEOUT);
}

//Button SW3 Interrupt follow-up function.
void GreenLedHWI(){
    //Release the Button SW3 Interrupt.
    GPIO_clearInt(Board_GPIO_BUTTON1);
    //Call the SWI follow-up function (GreenLedSWI).
    Swi_post(SystemSWI);
}

//Button SW3 HWI follow-up function.
void GreenLedSWI(){
    //System_printf("Green LED!\n");
    //System_flush();

    //Turn the LED on or OFF.
    GPIO_toggle(Board_GPIO_LED0);
    //If the System if OFF
    if(SystemOn == false){
        System_printf("The System Is ON\n");
        System_flush();
        //Set the system as ON.
        SystemOn = true;
        //Start the system timer.
        Timer_start(SystemTimer);
    }
    else{
        System_printf("The System Is OFF\n");
        System_flush();
        //Set the system as OFF
        SystemOn = false;
        //Set the Red LED duty to 0 (turn it off).
        SetRedLEDDuty(0);
        //Stop the system timer.
        Timer_stop(SystemTimer);
    }
}









