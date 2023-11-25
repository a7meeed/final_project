/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
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

typedef struct Student{
	uint32_t Student_ID;
	uint32_t Student_Grade;
}Student_t;

BaseType_t xReturned_vTaskCodeOne;
BaseType_t xReturned_vTaskCodeTwo;
TaskHandle_t xHandle_vTaskCodeOne = NULL;
TaskHandle_t xHandle_vTaskCodeTwo = NULL;

void vTaskCodeOne( void * pvParameters );
void vTaskCodeTwo( void * pvParameters );

uint32_t pvParameters_vTaskCodeOne = 0x11223344;
Student_t Ahmed = {
	.Student_ID = 88,
	.Student_Grade = 99
};


/* USER CODE END Variables */
/* Definitions for Task_1 */
osThreadId_t Task_1Handle;
const osThreadAttr_t Task_1_attributes = {
  .name = "Task_1",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for Task_2 */
osThreadId_t Task_2Handle;
const osThreadAttr_t Task_2_attributes = {
  .name = "Task_2",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal,
};
/* Definitions for Task_3 */
osThreadId_t Task_3Handle;
const osThreadAttr_t Task_3_attributes = {
  .name = "Task_3",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Task_4 */
osThreadId_t Task_4Handle;
const osThreadAttr_t Task_4_attributes = {
  .name = "Task_4",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityAboveNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Task_One(void *argument);
void Task_Two(void *argument);
void Task_Three(void *argument);
void Task_Four(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationIdleHook(void);

/* USER CODE BEGIN 2 */
void vApplicationIdleHook( void )
{
   /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
   to 1 in FreeRTOSConfig.h. It will be called on each iteration of the idle
   task. It is essential that code added to this hook function never attempts
   to block in any way (for example, call xQueueReceive() with a block time
   specified, or call vTaskDelay()). If the application makes use of the
   vTaskDelete() API function (as this demo application does) then it is also
   important that vApplicationIdleHook() is permitted to return to its calling
   function, because it is the responsibility of the idle task to clean up
   memory allocated by the kernel to any task that has since been deleted. */
}
/* USER CODE END 2 */

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
  /* creation of Task_1 */
  //Task_1Handle = osThreadNew(Task_One, NULL, &Task_1_attributes);

  /* creation of Task_2 */
  //Task_2Handle = osThreadNew(Task_Two, NULL, &Task_2_attributes);

  /* creation of Task_3 */
  //Task_3Handle = osThreadNew(Task_Three, NULL, &Task_3_attributes);

  /* creation of Task_4 */
  //Task_4Handle = osThreadNew(Task_Four, NULL, &Task_4_attributes);

  /* USER CODE BEGIN RTOS_THREADS */

  xReturned_vTaskCodeOne = xTaskCreate(vTaskCodeOne,
		  	  	  	  	  	  	  	  "This is vTaskCodeOne Task",
									  128,
									  (void *) &pvParameters_vTaskCodeOne,
									  45,
									  &xHandle_vTaskCodeOne);
  xReturned_vTaskCodeTwo = xTaskCreate(vTaskCodeTwo,
  		  	  	  	  	  	  	  	  "This is vTaskCodeTwo Task",
  									  128,
  									  (void *) &Ahmed,
  									  46,
  									  &xHandle_vTaskCodeTwo);

  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_Task_One */
/**
  * @brief  Function implementing the Task_1 thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Task_One */
void Task_One(void *argument)
{
  /* USER CODE BEGIN Task_One */
  uint32_t Counter_Task = 0;
  /* Infinite loop */
  for(;;)
  {
	  HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_0);
	Counter_Task++;
    printf("Task_One Counter_Task = %i \n", Counter_Task);
    osDelay(500);
  }
  /* USER CODE END Task_One */
}

/* USER CODE BEGIN Header_Task_Two */
/**
* @brief Function implementing the Task_2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Two */
void Task_Two(void *argument)
{
	  HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_2);
  /* USER CODE BEGIN Task_Two */
  uint32_t Counter_Task = 0;
  /* Infinite loop */
  for(;;)
  {
	Counter_Task++;
	printf("Task_Two Counter_Task = %i \n", Counter_Task);
    osDelay(1000);
  }
  /* USER CODE END Task_Two */
}

/* USER CODE BEGIN Header_Task_Three */
/**
* @brief Function implementing the Task_3 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Three */
void Task_Three(void *argument)
{
  /* USER CODE BEGIN Task_Three */
  uint32_t Counter_Task = 0;
  /* Infinite loop */
  for(;;)
  {
	Counter_Task++;
	printf("Task_Three Counter_Task = %i \n", Counter_Task);
    osDelay(1500);
  }
  /* USER CODE END Task_Three */
}

/* USER CODE BEGIN Header_Task_Four */
/**
* @brief Function implementing the Task_4 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_Four */
void Task_Four(void *argument)
{
  /* USER CODE BEGIN Task_Four */
  uint32_t Counter_Task = 0;
  /* Infinite loop */
  for(;;)
  {
	Counter_Task++;
	printf("Task_Four Counter_Task = %i \n", Counter_Task);
    osDelay(2000);
  }
  /* USER CODE END Task_Four */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

void vTaskCodeOne(void *pvParameters)
{
	uint32_t Local_pvParameters = *((uint32_t *)pvParameters);
    for( ;; )
    {
    	printf("vTaskCodeOne 0x%X => \n", Local_pvParameters);
    	printf("vTaskCodeOne 0x%X -> \n", *((uint32_t *)pvParameters));
    	vTaskDelay(250);
    }
}

void vTaskCodeTwo(void *pvParameters)
{
    for( ;; )
    {
    	printf("Student ID    : %i \n", ((Student_t *)pvParameters)->Student_ID);
    	printf("Student Grade : %i \n", ((Student_t *)pvParameters)->Student_Grade);
    	vTaskDelay(500);
    }
}

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
