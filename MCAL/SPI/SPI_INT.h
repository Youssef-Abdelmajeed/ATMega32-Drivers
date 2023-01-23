/**
 * @file SPI_INT.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Serial Peripheral Interface Protocol interface file 
 * @version 0.1
 * @date 2023-01-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef SPI_INT_H_ 
#define SPI_INT_H_ 

/*SPI - Relationship Between SCK and the Oscillator Frequency*/

/*fosc/4*/
#define SPI_Prescaler4             0
/*fosc/16*/
#define SPI_Prescaler16            1
/*fosc/64*/
#define SPI_Prescaler64            2
/*fosc/128*/
#define SPI_Prescaler128           3
/*fosc/2*/
#define SPI_Prescaler2             4 
/*fosc/8*/
#define SPI_Prescaler8             5
/*fosc/32*/
#define SPI_Prescaler32            6
/*************************************/

/*SPI Data Order*/

#define LSB_FIRST                   1
#define MSB_FIRST                   2
/*************************************/

/*SPI - Masks*/

/*SPI Clock Rate Select 1 and 0 Mask*/
#define SPR01_MASK                  0xFC
/*SPI Clock Rate Select 2 MASK*/
#define SPI2X_MASK                  0xFE
/* SPI DATA MODE MASK */
#define SPI_MODE_MASK               0xF3
/*************************************/

/*SPI Error States*/

#define SPI_OK                      1
#define WRONG_FREQUENCY             2
#define WRONG_MODE                  3
#define WRONG_ORDER                 4
/*************************************/

/**
 * @brief Set SPI Relationship Between SCK and the Oscillator Frequency
 * 
 * @param clockRate SPI_Prescaler
 * @return uint8_t  Error States 
 */
uint8_t SPI_SetClockRate(uint8_t clockRate) ;
/**
 * @brief Set SPI Mode CPOL, CPHA Combinations  
 * 
 * @param mode     [0,1,2,3]
 * @return uint8_t Error States 
 */
uint8_t SPI_SetMode(uint8_t mode) ; 
/**
 * @brief Set SPI Data Order 
 * 
 * @param dataOrder LSB_FIRST, MSB_FIRST 
 * @return uint8_t  Error States 
 */
uint8_t SPI_SetDataOrder(uint8_t dataOrder);
/**
 * @brief Initialize SPI Protocol As Master 
 * 
 * @param clockRate SPI_Prescaler
 * @param dataMode  [0,1,2,3]
 * @param dataOrder LSB_FIRST, MSB_FIRST
 * @return uint8_t  Error States 
 */
uint8_t SPI_MasterInit(uint8_t clockRate, uint8_t dataMode,uint8_t dataOrder) ; 
/**
 * @brief Initialize SPI Protocol As Slave
 * 
 * @param clockRate SPI_Prescaler
 * @param dataMode  [0,1,2,3]
 * @param dataOrder LSB_FIRST, MSB_FIRST
 * @return uint8_t  Error States 
 */
uint8_t SPI_SlaveInit(uint8_t clockRate, uint8_t dataMode,uint8_t dataOrder) ; 
/**
 * @brief Master transmit to slave(s)
 * 
 * @param data 
 * @return uint8_t Error States
 */
uint8_t SPI_MasterSend(uint8_t data) ; 
/**
 * @brief Slave Receive data 
 * 
 * @return uint8_t data received 
 */
uint8_t SPI_SlaveReceive(void) ;  
/**
 * @brief A combination of send and receiving data
 * 
 * @param data to be send
 * @return uint8_t data received 
 */
uint8_t SPI_Tranceive(uint8_t data);


#endif /*SPI_INT_H_*/