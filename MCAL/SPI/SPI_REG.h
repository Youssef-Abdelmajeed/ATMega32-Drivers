/**
 * @file SPI_REG.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Serial Peripheral Interface Protocol Register file 
 * @version 0.1
 * @date 2023-01-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef SPI_REG_H_ 
#define SPI_REG_H_ 


/*SPI Control Register*/ 
#define SPCR                (*(volatile uint8_t *)0x2D) 
/*Clock Rate Select 0*/
#define SPCR_SPR0           0
/*Clock Rate Select 1*/
#define SPCR_SPR1           1
/*Clock Phase*/
#define SPCR_CPHA           2
/*Clock Polarity*/
#define SPCR_CPOL           3
/*Master/Slave Select*/
#define SPCR_MSTR           4
/*Data Order*/
#define SPCR_DORD           5
/*SPI Enable*/
#define SPCR_SPE            6
/*SPI Interrupt Enable*/
#define SPCR_SPIE           7

/*SPI Status Register*/
#define SPSR                (*(volatile uint8_t *)0x2E) 
/*SPI Clock Rate Select 2 (Double SPI Speed Bit)*/
#define SPSR_SPI2X          0
/*Write COLlision Flag*/
#define SPSR_WCOL           6
/*SPI Interrupt Flag */
#define SPSR_SPIF           7

/*SPI Data Register – SPDR*/
#define SPDR                (*(volatile uint8_t *)0x2F) 

#endif /*SPI_REG_H_*/
