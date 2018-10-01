/*
 * Main.c
 *
 *      Author: Daniel Shefer & Zohar Korenblum
 */
#include <stdint.h>
#include "unistd.h"
#include "stdio.h"
#include <stddef.h>
#include <ti/drivers/GPIO.h>
#include <pthread.h>
#include <ti/sysbios/BIOS.h>
#include <ti/devices/cc32xx/inc/hw_types.h>
#include <ti/devices/cc32xx/inc/hw_memmap.h>
#include <ti/devices/cc32xx/driverlib/timer.h>
#include <xdc/cfg/global.h>
#include "Board.h"

/*
 *  ======== main ========
 */
int main()
{
    /* Call driver init functions */
    Board_initGeneral();
    //Initialize the GPIO.
    GPIO_init();
    //Enable GPIO buttons interrupt.
    GPIO_enableInt(Board_GPIO_BUTTON0);
    GPIO_enableInt(Board_GPIO_BUTTON1);

    //Enable timer interrupt.
    TimerIntEnable(TIMERA2_BASE, TIMER_TIMA_TIMEOUT);

    /*
     *  enable interrupts
     *  and start the scheduler and kick BIOS into gear
     */
    BIOS_start();
    return(0);
}
