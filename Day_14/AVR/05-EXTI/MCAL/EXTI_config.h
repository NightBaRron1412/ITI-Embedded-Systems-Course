/** @file EXTI_config.h
 * 
 * @brief A header file including Sense Control options for the EXTI peripheral.
 *
 * @author Amir Shetaia
 * @version 1.0
 * @date Aug 22, 2021       
 *
 */

#ifndef EXTI_COINFIG_H
#define EXTI_CONFIG_H

#define EXTI_LOW_LEVEL_SC 0    /*LOW LEVEL SENSE CONTROL */
#define EXTI_FALLING_EDGE_SC 1 /*FALLING_EDGE SENSE CONTROL */
#define EXTI_RISING_EDGE_SC 2  /*RISING_EDGE SENSE CONTROL */
#define EXTI_ONCHANGE_SC 3     /*ONCHANGE SENSE CONTROL */

#define EXTI0_SENSE_CONTROL EXTI_ONCHANGE_SC
#define EXTI1_SENSE_CONTROL EXTI_LOW_LEVEL_SC
#define EXTI2_SENSE_CONTROL EXTI_FALLING_EDGE_SC


/**
 * Options:
 * EXTI_LOW_LEVEL_SC
 * EXTI_FALLING_EDGE_SC
 * EXTI_RISING_EDGE_SC
 * EXTI_ONCHANGE_SC
 */

//NOTE: EXTI2 Only supports FALLING_EDGE and RISING_EDGE SC !!

#endif /* EXTI_CONFIG_H */

/*** end of file ***/
