/*
 * AlertLed_Control.c
 *
 *      Author: Daniel Shefer & Zohar Korenblum
 */
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include "unistd.h"
#include <ti/sysbios/BIOS.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/ADC.h>
#include "Board.h"
#include <ti/devices/cc32xx/inc/hw_types.h>
#include <ti/devices/cc32xx/inc/hw_memmap.h>
#include <ti/devices/cc32xx/driverlib/timer.h>
#include <xdc/runtime/System.h>
#include <xdc/cfg/global.h>
#include <ti/display/Display.h>
#include "PWM_Helper.h"

static PWM_Handle pwm;
static int OneTime = 0;

//Button SW2 Interrupt follow-up function.
void LedResetHWI(){
    //Release the Button SW2 Interrupt.
    GPIO_clearInt(Board_GPIO_BUTTON0);

    //System_printf("LED Reset HWI!\n");
    //System_flush();

    ////Call the SWI follow-up function (LedReset).
    Swi_post(LedResetSWI);
}

//Button SW2 HWI follow-up function.
void LedReset(){
    //System_printf("LED Reset\n");
    //System_flush();

    //Set the Red LED duty to 0 (turn it off).
    SetRedLEDDuty(0);
}

//Configure the PWM.
void InitializePWM(){

    //PWM Variables.
    PWM_Params params;
    uint16_t pwmPeriod = 3000;

    //Initialize the PWM.
     PWM_init();

     //Set the PWM Parameters.
     PWM_Params_init(&params);
     params.periodUnits = PWM_PERIOD_US;
     params.periodValue = pwmPeriod;
     params.dutyUnits = PWM_DUTY_US;

     //Open the PWM connection.
     pwm = PWM_open(Board_PWM0,&params);
     if(pwm ==NULL)
     {
       System_printf("Error open PWM\n");
       System_flush();
       while(1);
     }

     //Start the PWM.
     PWM_start(pwm);
}

void SetRedLEDDuty(uint16_t pwmDuty){

    //Configure the PWM only once.
    if(OneTime == 0){
        OneTime = 1;
        InitializePWM();
    }

    //Set the PWM duty (red led power).
    PWM_setDuty(pwm,pwmDuty);
}







