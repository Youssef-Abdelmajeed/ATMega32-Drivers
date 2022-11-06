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

void ADC_Init(EN_ADC_Ref_t refmode, uint8_t prescaller)
{
    /* Start ADC */
    ADC_Start() ;

    /* Select ADC Voltage reference mode */
    ADC_SelectRefMode(refmode) ; 

    /* Select ADC Clock prescaller */
    ADC_SelectPrescaller(prescaller) ; 

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

uint16_t ADC_Read(uint8_t channel)
{
    /* set the result register to be in right adjust mode   */
    clearBit(ADMUX,ADMUX_ADLAR) ; 

    /* select the channel to read from */
     ADC_SelectChannel(channel) ;
   
    /* Start conversion */
    setBit(ADCSRA,ADCSRA_ADSC) ; 
   
    /* polling on ADC Interrupt flag */
    while (getBit(ADCSRA,ADCSRA_ADIF)!= 1 ) ; 
    
    /* clear ADC Interrupt flag */
    setBit(ADCSRA,ADCSRA_ADIF) ; 

    return ADC_Result ;

}
uint8_t ADC_Read8Bit(uint8_t channel)
{
    /* set the result register to be in left adjust mode   */
    setBit(ADMUX,ADMUX_ADLAR) ; 

    /* select the channel to read from */
    ADC_SelectChannel(channel) ;
   
    /* Start conversion */
    setBit(ADCSRA,ADCSRA_ADSC) ; 
   
    /* polling on ADC Interrupt flag */
    while (getBit(ADCSRA,ADCSRA_ADIF)!= 1 ) ; 
    
    /* clear ADC Interrupt flag */
    setBit(ADCSRA,ADCSRA_ADIF) ; 

    return ADCL ;
}

