#include "Lib/Std_Types.h"
#include "MCAL/TMR_interface.h"
#include "MCAL/GIE_interface.h"
#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"

TaskControlBlock_t TaskBlocksArr[RTOS_TASK_NUM] = {{NULL}};

void RTOS_VidStart()
{
    TMR_VidInit();

    TMR_VidSetDutyCycle(0, 50); /* Set OCR0 = 127 */

    TMR_VidSetCallBack(0, VidAlgorithm);

    GIE_VidEnable();
}

void RTOS_VidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void (*func)(void))
{
    if (Copy_u8Priority < RTOS_TASK_NUM)
    {
        TaskBlocksArr[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
        TaskBlocksArr[Copy_u8Priority].TaskFunc = func;
        TaskBlocksArr[Copy_u8Priority].RunMe = 0;
        TaskBlocksArr[Copy_u8Priority].TaskCounter = 0;
    }
}

void RTOS_VidDispatcher()
{

    /* Check on all tasks and excute any task with RunMe flag raised */
    for (u8 i = 0; i < RTOS_TASK_NUM; i++)
    {
        /* Check if task exists */
        if (TaskBlocksArr[i].TaskFunc != NULL)
        {
            /* Check if flag is raised */
            if (TaskBlocksArr[i].RunMe == 1)
            {
                /* Downing Flag */
                TaskBlocksArr[i].RunMe = 0;

                /*Run Task */
                TaskBlocksArr[i].TaskFunc();
            }
        }
    }
}

static void VidAlgorithm()
{
    /* Iterating through all the tasks */
    for (u8 i = 0; i < RTOS_TASK_NUM; i++)
    {
        /* Checking if task exists */
        if (TaskBlocksArr[i].TaskFunc != NULL)
        {
            /* Check if counter equals 0 */
            if (TaskBlocksArr[i].TaskCounter == 0)
            {
                /* Set flag */
                TaskBlocksArr[i].RunMe = 1;
                /* Update counter periodicity */
                TaskBlocksArr[i].TaskCounter = TaskBlocksArr[i].Periodicity;
            }

            /* if task is not ready */
            else
            {
                /* Counter Decrement */
                TaskBlocksArr[i].TaskCounter--;
            }
        }
    }
}
