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

#define ADC_REFRENCE_SELECTION ADC_AVCC_EXTCAP_AREF

/**
 * Options:
 * ADC_AREF_INTERNAL_OFF            AREF, Internal Vref turned off
 * ADC_AVCC_EXTCAP_AREF             AVCC with external capacitor at AREF pin
 * ADC_INTERNAL_EXTCAP_AREF         Internal 2.56V Voltage Reference with external capacitor at AREF pin
*/

/* Left Or Right Adjustment of Data Registers for reading resolutions*/

#define ADC_READING_RESOLUTION ADC_8_BIT

/**
 * Options:
 * ADC_10_BIT
 * ADC_8_BIT
 */

/* Bits 2:0 ---- Pre Scalar Bits */

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
