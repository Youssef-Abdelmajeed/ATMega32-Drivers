/**
 * @file SPI_PRG.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Serial Peripheral Interface Protocol Implementation file 
 * @version 0.1
 * @date 2023-01-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "\LIB\STD_TYPES.h"
#include "\LIB\BIT_MATH.h"
#include "SPI_REG.h"
#include "SPI_INT.h"

inline uint8_t SPI_SetClockRate(uint8_t clockRate)
{
    uint8_t errorState ; 
    if(clockRate>6)
    {
        errorState = WRONG_FREQUENCY ; 
    }
    else
    {
        /*clear SPCR Bits 1:0*/
        SPCR &= SPR01_MASK ; 
        /*Set Clock Rate Select 1:0*/
        SPCR = clockRate&(~SPR01_MASK);
        /*clear SPSR Bit 0*/
        SPSR &=SPI2X_MASK ; 
        /*Set Clock Rate Select 2*/
        SPSR = clockRate&(~SPI2X_MASK);
        errorState = SPI_OK ; 
    }
    return errorState ; 
}
inline uint8_t SPI_SetMode(uint8_t mode)
{
    uint8_t errorState ; 
    if (mode>3)
    {
        errorState = WRONG_MODE ; 
    }
    else
    {
        /*Clear CPOL & CPHA Bits in SPCR Register*/
        SPCR &= SPI_MODE_MASK ; 
        /*Set CPOL & CPHA from mode selection*/
        SPCR = (mode<<2) ; 
        errorState = SPI_OK ; 
    }
    return errorState ; 
}
inline uint8_t SPI_SetDataOrder(uint8_t dataOrder)
{
    uint8_t errorState ; 
    switch (dataOrder)
    {
    case LSB_FIRST:
        setBit(SPCR,SPCR_DORD) ; 
        errorState = SPI_OK ; 
        break;
    case MSB_FIRST:
        clearBit(SPCR,SPCR_DORD) ; 
        errorState = SPI_OK ; 
        break; 
    
    default:
        errorState = WRONG_ORDER ; 
        break;
    }
    return errorState ; 
}
uint8_t SPI_MasterInit(uint8_t clockRate, uint8_t dataMode,uint8_t dataOrder)
{
    if(SPI_SetClockRate(clockRate)!=SPI_OK)
    {
        return WRONG_FREQUENCY ; 
    }
    if(SPI_SetMode(dataMode)!=SPI_OK)
    {
        return WRONG_MODE ; 
    }
    if(SPI_SetDataOrder(dataOrder)!=SPI_OK)
    {
        return WRONG_ORDER ; 
    }
    /*Set Master Mode*/
    setBit(SPCR,SPCR_MSTR) ; 
    /*Set SPI Enable*/
    setBit(SPCR,SPCR_SPE) ; 

    return SPI_OK ; 
}
uint8_t SPI_SlaveInit(uint8_t clockRate, uint8_t dataMode,uint8_t dataOrder)
{
    if(SPI_SetClockRate(clockRate)!=SPI_OK)
    {
        return WRONG_FREQUENCY ; 
    }
    if(SPI_SetMode(dataMode)!=SPI_OK)
    {
        return WRONG_MODE ; 
    }
    if(SPI_SetDataOrder(dataOrder)!=SPI_OK)
    {
        return WRONG_ORDER ; 
    }
    /*Set slave Mode*/
    clearBit(SPCR,SPCR_MSTR) ; 
    /*Set SPI Enable*/
    setBit(SPCR,SPCR_SPE) ; 

    return SPI_OK ; 
}
uint8_t SPI_MasterSend(uint8_t data) 
{
    /*Send Data*/
    SPDR = data ; 
    /*Wait for data to be transmitted*/
    while (getBit(SPSR,SPSR_SPIF)!=1) ; 
    return SPI_OK ; 
}

uint8_t SPI_SlaveReceive(void) 
{
    /*Wait for data to be transmitted*/
    while (getBit(SPSR,SPSR_SPIF)!=1) ;
    /* return data*/ 
    return SPDR ; 
}

