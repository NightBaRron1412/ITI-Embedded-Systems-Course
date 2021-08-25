/** @file ADC_config.h
 * 
 * @brief A header file including some configurations for ADC driver.
 *
 * @author Amir Shetaia
 * @version 1.0
 * @date Aug 25, 2021       
 *
 */

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* Voltage Reference Bits --- Bit6 : REFS0 --- Bit7 : REFS1 */

#define ADC_AREF_INTERNAL_OFF 0    /*AREF, Internal Vref turned off */
#define ADC_AVCC_EXTCAP_AREF 1     /*AVCC with external capacitor at AREF pin */
#define ADC_RESERVED 2             /*Reserved */
#define ADC_INTERNAL_EXTCAP_AREF 3 /*Internal 2.56V Voltage Reference with external capacitor at AREF pin */

#define ADC_REFRENCE_SELECTION ADC_AVCC_EXTCAP_AREF

/**
 * Options:
 * ADC_AREF_INTERNAL_OFF
 * ADC_AVCC_EXTCAP_AREF
 * ADC_RESERVED
 * ADC_INTERNAL_EXTCAP_AREF
 */

/* Left Or Right Adjustment of Data Registers */
#define ADC_LEFT_ADJUST 0
#define ADC_RIGHT_ADJUST 1

#define ADC_REGISTER_ADJUSTMENT ADC_RIGHT_ADJUST

/**
 * Options:
 * ADC_LEFT_ADJUST
 * ADC_RIGHT_ADJUST
 */

/* Bits 2:0 ---- Pre Scalar Bits */

#define ADC_PRESCALER_2 2
#define ADC_PRESCALER_4 4
#define ADC_PRESCALER_8 8
#define ADC_PRESCALER_16 16
#define ADC_PRESCALER_32 32
#define ADC_PRESCALER_64 64
#define ADC_PRESCALER_128 128

#define ADC_PRESCALER ADC_PRESCALER_128

/**
 * Options:
 * ADC_PRESCALER_2 
 * ADC_PRESCALER_4 
 * ADC_PRESCALER_8 
 * ADC_PRESCALER_16
 * ADC_PRESCALER_32
 * ADC_PRESCALER_64
 * ADC_PRESCALER_128
 */

#endif /* ADC_CONFIG_H */

/*** end of file ***/
