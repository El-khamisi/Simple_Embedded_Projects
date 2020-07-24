/*
 * LCD.h
 *
 * Created: 2020-03-13 10:31:30 AM
 *  Author: M.El5amisi
 */ 


#define F_CPU 16000000UL

#ifndef LCD_H_
#define LCD_H_
#include <avr/io.h>
#include <util/delay.h>

#define A 0x3A
#define B 0x37
#define C 0x34
#define D 0x31
#define output 1
#define input 0
#define high 1
#define low 0

#define mod 4			// Mode of LCD which must be (4bit OR 8bit)


#define Data_Pins A      //the port where data pins is connected
#define RS_port B					 // port of		RS pin
#define RS_pin 0					 // no. of		RS pin

#define Enable_port B				 // port of		Enable pin
#define Enable_pin 1				 // no. of		Enable pin





void setup_pin(uint8_t port , uint8_t pin, uint8_t state);		//ToSetup to any Pin
void write_pin(uint8_t port , uint8_t pin, uint8_t state);		//ToWrite to any Pin



volatile void initialization();							//initialization of LCD
volatile void command (volatile uint8_t cmd);			//Write any Command	

volatile void charr ( char c);							//Send character to LCD
volatile void text(char *str);							//Send Strings to LCD



#endif /* LCD_H_ */