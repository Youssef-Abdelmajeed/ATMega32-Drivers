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

/* define NULL */
#define NULL ((void*) 0)

/* ADC Asynchronous mode global variables */
static uint8_t ISR_SOURCE ; 
static void(*globalNotificationFunc)(void) = NULL ; 
static uint16_t *globalADCResult =  NULL ;  
static uint8_t globalADCStatus = ADC_IDLE ;
/*ADC Asynchronous Chain mode global variables */
static uint8_t  globalADC_ChainLenght =  0 ; 
static uint8_t	globalChainIndex = 0 ;
static uint8_t	*globalChannelsArr = NULL; 
static uint16_t	*globalADC_ChainResultArr = NULL ; 

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
	/* Check if the ADC is busy */
	if(globalADCStatus==ADC_BUSY) return ADC_BUSY ;
	
    /* check the given ADC reading pointer */
    if(adcReading==NULL) return ADC_NULL ;

	/*set ADC status to be busy */
	globalADCStatus = ADC_BUSY ;
	
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
	
	/* Set ADC status to free again */
	globalADCStatus = ADC_IDLE ;
	
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
    /* everything is working OK flag */
    return ADC_OK ;

}
uint8_t ADC_Read8Bit(uint8_t channel,uint8_t *adcReading)
{
	/* Check if the ADC is busy */
	if(globalADCStatus==ADC_BUSY) return ADC_BUSY ;
	
    /* check the given ADC reading pointer */
    if(adcReading==NULL) return ADC_NULL ;
    
	/*set ADC status to be busy */
    globalADCStatus = ADC_BUSY ;
    
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
	
	/* Set ADC status to free again */
	globalADCStatus = ADC_IDLE ;
    
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
    /* everything is working OK flag */
    return ADC_OK ;
}
/* Synchronous mode functions End*/

/* ASynchronous mode functions */
uint8_t ADC_ReadAsync(uint8_t channel,uint16_t *adcReading,void(*notification)(void))
{
	/* Check if the ADC is busy */
	if(globalADCStatus==ADC_BUSY) return ADC_BUSY ;
	
    /* check the given ADC reading pointer and notification callback function */
    if(adcReading==NULL||notification==NULL) return ADC_NULL ;
    
    /* set callback notification function */
    globalNotificationFunc = notification ; 
    
    /* set ADC reading */
    globalADCResult = adcReading ;

    /* set the result register to be in right adjust mode */
    clearBit(ADMUX,ADMUX_ADLAR) ; 
    
    /* select the channel to read from */
    ADC_SelectChannel(channel) ;

    /* Start conversion */
    setBit(ADCSRA,ADCSRA_ADSC) ; 
    
    /*Set ADC Interrupt Enable */
    setBit(ADCSRA,ADCSRA_ADIE) ;
	
    /* set the ADC status to be busy */
    globalADCStatus = ADC_BUSY ;
    
    /*Set the ISR Source to be Single channel conversion */
    ISR_SOURCE = ISR_SINGLE_CHANNEL ;
	
	return ADC_OK ;

}

uint8_t ADC_ReadChainAsync(ST_ADC_Chain_t *chain)
{
	/* Check if the ADC is busy */
	if(globalADCStatus==ADC_BUSY) return ADC_BUSY ;

     /* check the given ADC reading pointer and notification callback function */
    if(chain->results==NULL||chain->notifcation==NULL) return ADC_NULL ;
    
    /* set callback notification function */
    globalNotificationFunc = chain->notifcation ; 
    
    /* set ADC readings */
    globalADC_ChainResultArr = chain->results ; 
    
	/*set ADC Channels */
	globalChannelsArr = chain->channelsArr ; 
	
	/*set How many ADC Channels to read */
	globalADC_ChainLenght = chain->length ; 
	
     /* set the result register to be in right adjust mode */
    clearBit(ADMUX,ADMUX_ADLAR) ;
   
    /* initialize chain Index */
	globalChainIndex = 0 ; 
	
	/*select the first channel */
    ADC_SelectChannel(globalChannelsArr[globalChainIndex]) ;

    /* Start conversion */
    setBit(ADCSRA,ADCSRA_ADSC) ; 
    
    /*Set ADC Interrupt Enable */
    setBit(ADCSRA,ADCSRA_ADIE) ;
	
    /* set the ADC status to be busy */
	globalADCStatus = ADC_BUSY ;
	
	/*Set the ISR Source to be Chain conversion */
	ISR_SOURCE = ISR_CHAIN ; 
	
	return ADC_OK ;

}

void __vector_16(void) __attribute__((signal)) ;
void __vector_16(void)
{
    switch (ISR_SOURCE)
    {
    case ISR_SINGLE_CHANNEL:
        /* store ADC result */
        *globalADCResult = ADC_Result ; 

        /*set ADC Status to be free */
        globalADCStatus = ADC_IDLE ;
        
        /* invoke notification function*/
        globalNotificationFunc(); 
        
        /* disable ADC Interrupt Enable */
        clearBit(ADCSRA,ADCSRA_ADIE) ; 
        break;
    case ISR_CHAIN: 
        /* store the ADC reading at the appropriate index */
        globalADC_ChainResultArr[globalChainIndex] = ADC_Result ; 
		
		/*increment chain reading index*/
		globalChainIndex++ ; 
		
        if(globalChainIndex==globalADC_ChainLenght)		/* Chain is complete */
        {
			/*set ADC Status to be free */
			globalADCStatus = ADC_IDLE ;
			  
			/* invoke notification function*/
			globalNotificationFunc();
			  
			/* disable ADC Interrupt Enable */
			clearBit(ADCSRA,ADCSRA_ADIE) ;
        }
        else /* Chain isn't complete */
        {
			/* select the next channel to read */
			ADC_SelectChannel(globalChannelsArr[globalChainIndex]) ;
			/* start the next conversion */
			setBit(ADCSRA,ADCSRA_ADSC) ;
        }
        break;
    }
 
}

/* ASynchronous mode functions End*/
