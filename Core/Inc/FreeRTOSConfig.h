#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include "stm32g0xx.h"

/* ---------------------------------------------------------------
 * 基础配置
 * --------------------------------------------------------------- */
#define configUSE_PREEMPTION                    1
#define configUSE_TIME_SLICING                  1
#define configCPU_CLOCK_HZ                      64000000UL
#define configTICK_RATE_HZ                      1000        /* 1ms tick */
#define configMAX_PRIORITIES                    8
#define configMINIMAL_STACK_SIZE                128         /* 单位：字，即512字节 */
#define configMAX_TASK_NAME_LEN                 16
#define configUSE_16_BIT_TICKS                  0
#define configENABLE_MPU                        0

/* ---------------------------------------------------------------
 * 内存
 * --------------------------------------------------------------- */
#define configTOTAL_HEAP_SIZE                   (8 * 1024)  /* RAM:8KB */
#define configSUPPORT_DYNAMIC_ALLOCATION        1
#define configSUPPORT_STATIC_ALLOCATION         0

/* ---------------------------------------------------------------
 * 功能开关
 * --------------------------------------------------------------- */
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     1           /* freertos 接管*/
#define configUSE_MALLOC_FAILED_HOOK            1           /* 堆用完时触发 */
#define configCHECK_FOR_STACK_OVERFLOW          2           /* 栈溢出检测*/
#define configUSE_MUTEXES                       1
#define configUSE_RECURSIVE_MUTEXES             0
#define configUSE_COUNTING_SEMAPHORES           1
#define configUSE_QUEUE_SETS                    0
#define configUSE_TIMERS                        1
#define configTIMER_TASK_PRIORITY               2
#define configTIMER_QUEUE_LENGTH                8
#define configTIMER_TASK_STACK_DEPTH            128

/* ---------------------------------------------------------------
 * 中断优先级 —— CM0没有BASEPRI寄存器
 * --------------------------------------------------------------- */
#define configKERNEL_INTERRUPT_PRIORITY         3           /* SysTick/PendSV优先级 */

/* ---------------------------------------------------------------
 * 调试
 * --------------------------------------------------------------- */
#define configUSE_TRACE_FACILITY                0
#define configUSE_STATS_FORMATTING_FUNCTIONS    0
#define configGENERATE_RUN_TIME_STATS           0

/* ---------------------------------------------------------------
 * API别名，按需开启
 * --------------------------------------------------------------- */
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_uxTaskGetStackHighWaterMark     1           /* 配合栈溢出检测用 */
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_xTaskGetCurrentTaskHandle       1

#endif /* FREERTOS_CONFIG_H */