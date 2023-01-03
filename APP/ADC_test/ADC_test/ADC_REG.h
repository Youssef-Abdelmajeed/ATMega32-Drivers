/**
 * @file ADC_REG.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief  Analog to Digital Converter Register file 
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ADC_REG_H_ 
#define ADC_REG_H_ 

/* ADC Multiplexer Selection Register */
#define ADMUX           (*(volatile uint8_t *) 0x27) 
/*ADC result left adjust bit*/
#define ADMUX_ADLAR     5

/*ADC Control and Status Register A */
#define ADCSRA          (*(volatile uint8_t *) 0x26) 
/* ADC Interrupt Enable */
#define ADCSRA_ADIE     3
/* ADC Interrupt flag */
#define ADCSRA_ADIF     4
/* ADC Auto Trigger Enable */
#define ADCSRA_ADATE	5
/* ADC Start conversion */
#define ADCSRA_ADSC     6
/* ADC Enable */
#define ADCSRA_ADEN     7 


/* ADC Whole Data Register H&L */
#define ADC_Result      (*(volatile uint16_t *) 0x24) 

/* ADC LOW Byte Data Register */
#define ADCL            (*(volatile uint8_t *) 0x24) 

#endif /* ADC_REG_H_ */