/*
 * Dimmer_control.c
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
#include "PWM_Helper.h"
#include "Board.h"

void Dimmer_func()
{
   //ADC variables.
   ADC_Params params;
   ADC_Handle adc;
   uint16_t adcValue;
   uint32_t adcMicrovoltValue;
   uint32_t adcMilivoltValue;

   //Calculation rsult.
   int result;

   //Initialize the ADC
   ADC_init();

   //Set ADC Parameters.
   ADC_Params_init(&params);
   adc = ADC_open(Board_ADC1,&params);

   while(1){
       //Wait for post from Microphone or the Distance Sensor.
       Semaphore_pend(DimmerSem,BIOS_WAIT_FOREVER);
       //Get the ADC value from the dimmer.
       result = ADC_convert(adc , &adcValue);
       //If the convert was successful
       if(result == ADC_STATUS_SUCCESS)
       {
           //Convert the value to MicroVolts.
           adcMicrovoltValue = ADC_convertRawToMicroVolts(adc,adcValue);
           //Convert from MicroVolts to Milivolts
           adcMilivoltValue = adcMicrovoltValue/423;

           //System_printf("Dimmer - MiliVolts: %d\n",adcMilivoltValue);
           //System_flush();

           //Send the milivolts value to the red led.
           SetRedLEDDuty(adcMilivoltValue);
       }
       else
       {
           //System_printf("Dimmer Fail %d\n",adcValue);
           //System_flush();
       }
   }
   ADC_close(adc);
}









