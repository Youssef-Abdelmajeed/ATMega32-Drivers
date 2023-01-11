/**
 * @file TimerOne_INT.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief Timer one interface file 
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef TIMER_1_INT_H_ 
#define TIMER_1_INT_H_ 

/**
 * @brief Set Timer1 prescaler mode 
 * 
 * @param Pmode Timer Prescaler [ Stoped, NoPrescaler, Prescaler8, Prescaler64, Prescaler256, Prescaler1024, External_onRising, External_onFalling ]
 * @return uint8_t uint8_t TimerOk in case if the prescaler is successfully set and WrongSelection otherwise 
 */
uint8_t Timer1_SetPrescaler(uint8_t Pmode) ; 
/**
 * @brief Set Timer1 wave generation mode 
 * 
 * @param Wmode Timer wave mode
 * @return uint8_t TimerOk in case if the wave mode is successfully set and WrongSelection otherwise 
 */
uint8_t Timer1_SetWaveMode(uint8_t Wmode) ; 
/**
 * @brief Initialize Timer1 Prescaler and Wave generation mode 
 * 
 * @param Pmode Timer Prescaler [ Stoped, NoPrescaler, Prescaler8, Prescaler64, Prescaler256, Prescaler1024, External_onRising, External_onFalling ]
 * @param Wmode Timer wave mode 
 * @return uint8_t TimerOk in case if the timer got successfully initalized and WrongSelection otherwise  
 */
uint8_t Timer1_init(uint8_t Pmode,uint8_t Wmode) ; 
/**
 * @brief Set the callback function of the timer1 in Normal mode 
 * 
 * @param callback address of the callback function 
 * @return uint8_t TimerOk in case if the callback successfully got set and NULL_POINTER otherwise 
 */
uint8_t  Timer1_SetOverFlow_Callback(void(*callback)(void)) ; 
/**
 * @brief Set the output compare match A callback function
 * 
 * @param callback address of the callback function 
 * @return uint8_t TimerOk in case if the callback successfully got set and NULL_POINTER otherwise 
 */
uint8_t Timer1_SetOutputCompareA_Callback(void(*callback)(void));
/**
 * @brief Set the output compare match B callback function
 * 
 * @param callback address of the callback function 
 * @return uint8_t TimerOk in case if the callback successfully got set and NULL_POINTER otherwise 
 */
uint8_t Timer1_SetOutputCompareB_Callback(void(*callback)(void)); 
/**
 * @brief set overflow register value 
 * 
 * @param value 
 * @return uint8_t TimerOK 
 */
uint8_t Timer1_SetOverFlowRegister(uint16_t value) ; 
/**
 * @brief set output compare match A register value 
 * 
 * @param value 
 * @return uint8_t TimerOK 
 */
uint8_t Timer1_SetOutputCompareRegisterA(uint16_t value);
/**
 * @brief set output compare match B register value 
 * 
 * @param value 
 * @return uint8_t TimerOK 
 */
uint8_t Timer1_SetOutputCompareRegisterB(uint16_t value); 

#endif /* TIMER_1_INT_H_ */