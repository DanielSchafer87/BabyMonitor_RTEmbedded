/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-D28
 */

#include <xdc/std.h>

#include <ti/sysbios/heaps/HeapMem.h>
extern const ti_sysbios_heaps_HeapMem_Handle heap0;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle LedResetSWI;

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle AlertLedInt;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle UART_Distance;

#include <ti/sysbios/knl/Semaphore.h>
extern const ti_sysbios_knl_Semaphore_Handle UART_DistanceSem;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle DimmerTask;

#include <ti/sysbios/knl/Semaphore.h>
extern const ti_sysbios_knl_Semaphore_Handle DimmerSem;

#include <ti/sysbios/knl/Task.h>
extern const ti_sysbios_knl_Task_Handle MicrophoneTask;

#include <ti/sysbios/knl/Semaphore.h>
extern const ti_sysbios_knl_Semaphore_Handle MicrophoneSem;

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle SystemInt;

#include <ti/sysbios/knl/Swi.h>
extern const ti_sysbios_knl_Swi_Handle SystemSWI;

#include <ti/sysbios/hal/Hwi.h>
extern const ti_sysbios_hal_Hwi_Handle TimerInt;

#include <ti/sysbios/hal/Timer.h>
extern const ti_sysbios_hal_Timer_Handle SystemTimer;

extern int xdc_runtime_Startup__EXECFXN__C;

extern int xdc_runtime_Startup__RESETFXN__C;

