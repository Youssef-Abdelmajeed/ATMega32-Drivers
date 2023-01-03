/**
 * @file ADC_INT.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  Analog to Digital Converter Interface file 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ADC_INT_H_ 
#define ADC_INT_H_ 

/******************* ADC_CONFIG *******************/
#define ADC_TIMEOUT 50000 
/* ADC Error states */
#define ADC_OK      1
#define ADC_TIMEOUT_EXCEEDED  2 
/***************************************************/

/* ADC channels */
#define ADC0            0 
#define ADC1            1 
#define ADC2            2 
#define ADC3            3
#define ADC4            4 
#define ADC5            5
#define ADC6            6 
#define ADC7            7

/* ADC clock prescaller */
#define prescaller2     1  
#define prescaller4     2 
#define prescaller8     3 
#define prescaller16    4
#define prescaller32    5 
#define prescaller64    6
#define prescaller128   7 

/* ADC Voltage References */
typedef enum EN_ADC_Ref 
{
    AREF, AVCC, Internal=3
} EN_ADC_Ref_t;

/**
 * @brief Enable ADC 
 * 
 */
void ADC_Start (void)  ;

/**
 * @brief Stop ADC if conversion is in progress, will terminate this conversion
 * 
 */
void ADC_Stop  (void)  ; 

/**
 *  select ADC Voltage Reference : 
 *  - AREF, Internal Vref turned off
 *  - AVCC with external capacitor at AREF pin
 *  - Internal 2.56V Voltage Reference with external capacitor at AREF pin
 * 
 * @param refmode [ AREF, AVCC, Internal ] 
 */
 void ADC_SelectRefMode(EN_ADC_Ref_t refmode)  ;

/**
 * @brief set ADC clock prescaller which control the speed of the conversion (reading) lower is the faster 
 * 
 * @param prescaller  
 */
void ADC_SelectPrescaller(uint8_t prescaller) ; 

/**
 * @brief Select a channel to read from (0 - 7)
 * 
 * @param channel 
 */
void  ADC_SelectChannel(uint8_t channel) ; 

/**
 * @brief Initialize ADC 
 * 
 * @param refmode [ AREF, AVCC, Internal ] 
 * @param prescaller [ 2, 8, 16, 32, 64, 128 ]
 * @return uint8_t ADC_Error state 
 */
uint8_t ADC_Init(EN_ADC_Ref_t refmode, uint8_t prescaller) ; 

/**
 * @brief read ADC single channel 10 bit mode  
 * 
 * @param channel 
 * @param adcReading 
 * @return uint8_t ADC_Error state  
 */
uint8_t ADC_Read(uint8_t channel,uint16_t * adcReading) ; 

/**
 * @brief read ADC single channel 8 bit mode  
 * 
 * @param channel 
 * @param adcReading 
 * @return uint8_t ADC_Error state  
 */
uint8_t ADC_Read8Bit(uint8_t channel,uint16_t * adcReading) ; 

#endif /* ADC_INT_H_ */