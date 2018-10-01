/*
 * Microphone_Control.c
 *
 *      Author: Daniel Shefer & Zohar Korenblum
 */
#include <stdint.h>
#include <stddef.h>
#include "unistd.h"
#include<ti/sysbios/bios.h>
#include <ti/drivers/GPIO.h>
#include<ti/sysbios/knl/Semaphore.h>
#include <xdc/runtime/System.h>
#include <xdc/cfg/global.h>
#include "stdio.h"
#include "Board.h"

void Microphone_func()
{
   //ADC Variables.
   ADC_Params params;
   ADC_Handle adc;
   uint16_t adcValue;
   uint32_t adcMicrovoltValue;
   uint32_t adcMilivoltValue;

   int result;

   //Initialize the ADC.
   ADC_init();
   //Set ADC Parameters.
   ADC_Params_init(&params);
   adc = ADC_open(Board_ADC0,&params);

   while(1){
       //Wait for post from the timer interrupt.
       Semaphore_pend(MicrophoneSem,BIOS_WAIT_FOREVER);
       //Get the ADC value from the Microphone.
       result = ADC_convert(adc , &adcValue);
       //If the convert was successful
       if(result == ADC_STATUS_SUCCESS)
       {
           //Convert the value to MicroVolts.
           adcMicrovoltValue = ADC_convertRawToMicroVolts(adc,adcValue);
           //Convert from MicroVolts to Milivolts
           adcMilivoltValue = adcMicrovoltValue/423;

           //If the Milivolts level is high (as a baby cry)
           //get the dimmer value and turn on the Alert Led.
           if(adcMilivoltValue < 1350){
           Semaphore_post(DimmerSem);
           System_printf("Baby Cry Alert!\n");
           }
       }
       else
       {
           //System_printf("fail %d\n\n",adcValue);
       }

       System_flush();
   }

   ADC_close(adc);
}



