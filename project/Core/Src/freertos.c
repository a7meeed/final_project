/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "gpio.h"
#include "stm32f4xx_hal_gpio.h"
#include <stdio.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId myTask02Handle;
osThreadId myTask03Handle;
osThreadId myTask04Handle;
osThreadId myTask05Handle;
osThreadId myTask06Handle;
osThreadId myTask07Handle;
osThreadId myTask08Handle;
osThreadId myTask09Handle;
osThreadId myTask10Handle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void StartTask02(void const * argument);
void StartTask03(void const * argument);
void StartTask04(void const * argument);
void StartTask05(void const * argument);
void StartTask06(void const * argument);
void StartTask07(void const * argument);
void StartTask08(void const * argument);
void StartTask09(void const * argument);
void StartTask10(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of myTask02 */
  osThreadDef(myTask02, StartTask02, osPriorityIdle, 0, 128);
  myTask02Handle = osThreadCreate(osThread(myTask02), NULL);

  /* definition and creation of myTask03 */
  osThreadDef(myTask03, StartTask03, osPriorityIdle, 0, 128);
  myTask03Handle = osThreadCreate(osThread(myTask03), NULL);

  /* definition and creation of myTask04 */
  osThreadDef(myTask04, StartTask04, osPriorityIdle, 0, 128);
  myTask04Handle = osThreadCreate(osThread(myTask04), NULL);

  /* definition and creation of myTask05 */
  osThreadDef(myTask05, StartTask05, osPriorityIdle, 0, 128);
  myTask05Handle = osThreadCreate(osThread(myTask05), NULL);

  /* definition and creation of myTask06 */
  osThreadDef(myTask06, StartTask06, osPriorityIdle, 0, 128);
  myTask06Handle = osThreadCreate(osThread(myTask06), NULL);

  /* definition and creation of myTask07 */
  osThreadDef(myTask07, StartTask07, osPriorityIdle, 0, 128);
  myTask07Handle = osThreadCreate(osThread(myTask07), NULL);

  /* definition and creation of myTask08 */
  osThreadDef(myTask08, StartTask08, osPriorityIdle, 0, 128);
  myTask08Handle = osThreadCreate(osThread(myTask08), NULL);

  /* definition and creation of myTask09 */
  osThreadDef(myTask09, StartTask09, osPriorityIdle, 0, 128);
  myTask09Handle = osThreadCreate(osThread(myTask09), NULL);

  /* definition and creation of myTask10 */
  osThreadDef(myTask10, StartTask10, osPriorityIdle, 0, 128);
  myTask10Handle = osThreadCreate(osThread(myTask10), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {    osDelay(1);

    }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void const * argument)
{  uint32_t Counter_Task = 0;

  /* USER CODE BEGIN StartTask02 */
  for(;;){
   Counter_Task++;
  printf("Task_One Counter_Task = %i \n", Counter_Task);
  HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_0);
  osDelay(500);
  }
  /* USER CODE END StartTask02 */
}

/* USER CODE BEGIN Header_StartTask03 */
/**
* @brief Function implementing the myTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask03 */
void StartTask03(void const * argument)
{uint32_t Counter_Task = 0;
  /* USER CODE BEGIN StartTask03 */
  /* Infinite loop */
  for(;;)
  {
//HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0, GPIO_PIN_SET);
	  Counter_Task++;
	  printf("Task_One Counter_Task = %i \n", Counter_Task);
	  HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_1);
	  osDelay(1000);
  }
  /* USER CODE END StartTask03 */
}

/* USER CODE BEGIN Header_StartTask04 */
/**
* @brief Function implementing the myTask04 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask04 */
void StartTask04(void const * argument)
{uint32_t Counter_Task = 0;
  /* USER CODE BEGIN StartTask04 */
  /* Infinite loop */
  for(;;)
  {
	  Counter_Task++;
	  printf("Task_One Counter_Task = %i \n", Counter_Task);
	  HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_2);
	  osDelay(1500);
  }
  /* USER CODE END StartTask04 */
}

/* USER CODE BEGIN Header_StartTask05 */
/**
* @brief Function implementing the myTask05 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask05 */
void StartTask05(void const * argument)
{uint32_t Counter_Task = 0;
  /* USER CODE BEGIN StartTask05 */
  /* Infinite loop */
  for(;;)
  {
	  Counter_Task++;
	  printf("Task_One Counter_Task = %i \n", Counter_Task);
	  HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_3);
	  osDelay(2000);
  }
  /* USER CODE END StartTask05 */
}

/* USER CODE BEGIN Header_StartTask06 */
/**
* @brief Function implementing the myTask06 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask06 */
void StartTask06(void const * argument)
{uint32_t Counter_Task = 0;
  /* USER CODE BEGIN StartTask06 */
  /* Infinite loop */
  for(;;)
  {
	  Counter_Task++;
	  printf("Task_One Counter_Task = %i \n", Counter_Task);
	  HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_4);
	  osDelay(2500);
  }
  /* USER CODE END StartTask06 */
}

/* USER CODE BEGIN Header_StartTask07 */
/**
* @brief Function implementing the myTask07 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask07 */
void StartTask07(void const * argument)
{uint32_t Counter_Task = 0;
  /* USER CODE BEGIN StartTask07 */
  /* Infinite loop */
  for(;;)
  {
	  Counter_Task++;
	  printf("Task_One Counter_Task = %i \n", Counter_Task);
	  HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
	  osDelay(3000);
  }
  /* USER CODE END StartTask07 */
}

/* USER CODE BEGIN Header_StartTask08 */
/**
* @brief Function implementing the myTask08 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask08 */
void StartTask08(void const * argument)
{uint32_t Counter_Task = 0;
  /* USER CODE BEGIN StartTask08 */
  /* Infinite loop */
  for(;;)
  {
	  Counter_Task++;
	  printf("Task_One Counter_Task = %i \n", Counter_Task);
	  HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_6);
	  osDelay(3500);
  }
  /* USER CODE END StartTask08 */
}

/* USER CODE BEGIN Header_StartTask09 */
/**
* @brief Function implementing the myTask09 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask09 */
void StartTask09(void const * argument)
{uint32_t Counter_Task = 0;
  /* USER CODE BEGIN StartTask09 */
  /* Infinite loop */
  for(;;)
  {
	  Counter_Task++;
	  printf("Task_One Counter_Task = %i \n", Counter_Task);
	  HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_7);
	  osDelay(4000);
  }
  /* USER CODE END StartTask09 */
}

/* USER CODE BEGIN Header_StartTask10 */
/**
* @brief Function implementing the myTask10 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask10 */
void StartTask10(void const * argument)
{uint32_t Counter_Task = 0;
  /* USER CODE BEGIN StartTask10 */
  /* Infinite loop */
  for(;;)
  {
	  Counter_Task++;
	  printf("Task_One Counter_Task = %i \n", Counter_Task);
	  HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_8);
	  osDelay(4500);
  }
  /* USER CODE END StartTask10 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
