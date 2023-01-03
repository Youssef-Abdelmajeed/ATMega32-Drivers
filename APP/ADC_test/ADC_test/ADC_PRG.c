/**
 * @file ADC_PRG.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  Analog to Digital Converter Implementation file 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "LIB\BIT_MATH.h"
#include "LIB\STD_TYPES.h"
#include "ADC_INT.h"
#include "ADC_REG.h"

inline void ADC_Start (void) 
{
    setBit(ADCSRA,ADCSRA_ADEN) ; 
}

inline void ADC_Stop(void)
{
    clearBit(ADCSRA,ADCSRA_ADEN) ;
} 

inline void ADC_SelectRefMode(EN_ADC_Ref_t refmode) 
{
    /* clear reference selection bits 6, 7  */
    ADMUX &=  0X3F ; 
    /* set ADC reference mode */
    ADMUX |= (refmode<<6) ;
}

inline void ADC_SelectPrescaller(uint8_t prescaller)
{
    /* limit selection to  8 (0 - 7) */
    prescaller &= 0x07 ;

    /* clear prescaller selection bits */
    ADCSRA &= 0XF8 ;

    /* set prescaller value */
    ADCSRA |= prescaller ;
    
    
}

inline void  ADC_SelectChannel(uint8_t channel)
{
    /* limit selection to  8 (0 - 7) */
    channel &= 0x07 ; 

    /* clear channel selection bits 0 - 3 */
    ADMUX &=  0XF0 ; 

    /* select a channel */
    ADMUX |= channel ;
}

uint8_t ADC_Init(EN_ADC_Ref_t refmode, uint8_t prescaller)
{
    /* Start ADC */
    ADC_Start() ;

    /* Select ADC Voltage reference mode */
    ADC_SelectRefMode(refmode) ; 

    /* Select ADC Clock prescaller */
    ADC_SelectPrescaller(prescaller) ; 

    return ADC_OK ;
}

/* Synchronous mode functions */
uint8_t ADC_Read(uint8_t channel,uint16_t *adcReading)
{
    /* initialing counter to add timeout option to ADC polling */
    uint32_t counter = 0 ; 
    /* set the result register to be in right adjust mode */
    clearBit(ADMUX,ADMUX_ADLAR) ; 

    /* select the channel to read from */
    ADC_SelectChannel(channel) ;
   
    /* Start conversion */
    setBit(ADCSRA,ADCSRA_ADSC) ; 
   
    /* polling on ADC Interrupt flag or ADC timeout */
    while ((getBit(ADCSRA,ADCSRA_ADIF)!= 1 )&&(counter!=ADC_TIMEOUT)) 
    {
        counter++;
    }
    if(counter==ADC_TIMEOUT)
    {
        /* return exceeded timeout flag */
        return ADC_TIMEOUT_EXCEEDED ;
    }
    else
    {
        /* clear ADC Interrupt flag */
        setBit(ADCSRA,ADCSRA_ADIF) ;
    
        /* update ADC reading */ 
        *adcReading = ADC_Result ; 
    }
    /* everything is working ok flag */
    return ADC_OK ;

}
uint8_t ADC_Read8Bit(uint8_t channel,uint8_t *adcReading)
{
    /* initialing counter to add timeout option to ADC polling */
    uint32_t counter = 0 ; 
    
    /* set the result register to be in left adjust mode */
    setBit(ADMUX,ADMUX_ADLAR) ; 
    
    /* select the channel to read from */
    ADC_SelectChannel(channel) ;
   
    /* Start conversion */
    setBit(ADCSRA,ADCSRA_ADSC) ; 
   
    /* polling on ADC Interrupt flag or ADC timeout */
    while ((getBit(ADCSRA,ADCSRA_ADIF)!= 1 )&&(counter!=ADC_TIMEOUT)) 
    {
        counter++;
    }
    if(counter==ADC_TIMEOUT)
    {
        /* return exceeded timeout flag */
        return ADC_TIMEOUT_EXCEEDED ;
    }
    else
    {
        /* clear ADC Interrupt flag */
        setBit(ADCSRA,ADCSRA_ADIF) ;
    
        /* update ADC reading */ 
        *adcReading = ADCL ; 
    }
    /* everything is working ok flag */
    return ADC_OK ;
}
/* Synchronous mode functions End*/

