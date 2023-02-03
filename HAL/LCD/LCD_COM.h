/**
 * @file LCD_COM.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief LCD command file  (HAL)
 * @version 0.1
 * @date 2022-09-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef LCD_COM_H_
#define LCD_COM_H_

/*
    functionSet 8 bit 
    0b  0   0   1   DL  N   F   -   - 
    DL = 1  | 8 bit Mode  
    N  = 1  | 2  line display (1/16 duty)
    F  = 0  | 5 x 7 dots (font)
*/
#define functionSet8bit		0b00111000 
/*
    functionSet 4 bit 
    0b  0   0   1   DL  N   F   -   - 
    DL = 0  | 8 bit Mode  
    N  = 1  | 2  line display (1/16 duty)
    F  = 0  | 5 x 7 dots (font)
*/
#define functionSet4bit		0b00101000 
/*
    display ON/OFF 
    0b  0   0   0   0	1	D   C   B 
    D  = 1  | the entire display is on    
    C  = 0  | Cursor display (off)
    B  = 0  | character indicated by the cursor blink (off)
*/
#define DisplayOn_OFF		0b00001100
/*
    display clear 
    0b  0   0   0   0    0   0   0   1 
*/
#define DisplayClear		0b00000001
/*
    Entry Mode Set 
    0b  0   0   0   0    0   1   I/D   SH 
    I/D  = 1    | Increment by 1    
    SH   = 0    | No shift 
*/
#define EntryModeSet		0b00000110
/*
    LCD HOME 
    0b  0   0   0   0    0    0   1   0 
*/
#define LCDHome				0b00000010
/*
    Cursor Shift  
    0b  0   0   0   1   S/C   R/L   -   -
    S/C   = 0     
    R/L   = 1   
    Shift the cursor to the right by 1 
*/
#define CursorShift			0b00010100
/*
    Display Shift Left   
    0b  0   0   0   1   S/C   R/L   -   -
    S/C   = 1     
    R/L   = 0   
    Shift the screen to the left by 1 
*/
#define DisplayShiftLeft    0b00011000
/*
    Display Shift Right 
    0b  0   0   0   1   S/C   R/L   -   -
    S/C   = 1     
    R/L   = 1   
    Shift the screen to the right by 1 
*/
#define DisplayShiftRight	0b00011100
/**
 * @brief Go to the first row 
 * 
 */
#define FirstRow            0b10000000
/**
 * @brief Go to second row
 * 
 */
#define SecondRow           0b11000000
/**
 * @brief set the CGRAM address 
 * 
 */
#define SetCGRAM			0b01000000
/**
 * @brief set the DDRAM address 
 * 
 */
#define SetDDRAM			0b10000000

#endif /* LCD_COM_H_ */