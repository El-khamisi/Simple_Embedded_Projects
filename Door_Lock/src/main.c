/*
 * Door_Lock.c
 *
 * Created: 2020-07-24 2:39:30 PM
 * Author : Mohammed El-khamisi
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif


#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"

#define dm(x)		_delay_ms(x)
#define du(x)		_delay_us(x)
#define bool char
#define true 1
#define false 0

char arr[4][3]= {{'1','2','3'},
				{'4','5','6'},			
				{'7','8','9'},
				{'*','0','#'}};
					
					
 volatile char pass[]={'2','9','7','9'},tray[]={'.','.','.','.'};

volatile int c=0;
void read_key();
void message(char *st);
void res_pass();
	
char main(void)
{
	DDRD=0xf0;

	initialization();
	text("Enter 4D PIN No.:");
	
	while(1)
	{
		read_key();
	}
	
	


}


void read_key()
{
	for (int i=4; i<8; i++)
	{
		PORTD=(1<<i);
		for (int j=1; j<4; j++)
		{
			if (PIND & (1<<j) )
			{
				while(PIND & (1<<j));
				
				bool f=true;
				if (arr[i-4][j-1] == '*')		//if pressed star check the password 
				{
					
					for (int i=0 ; i<4; i++)
					{
						if (pass[i] !=tray[i])
						{
							f=false;
							message("Incorrect");
							break;
						}
					}
					if (f)
					{
						message("Correct");
					}
					
					res_pass();
					dm(5);
					text("Enter 4D PIN No.:");
				}
				
				
				
				
				else if (arr[i-4][j-1] == '#')			//if pressed '#' reset 
				{
		
					message("Clear");
					res_pass();
					dm(5);
					text("Enter 4D PIN No.:");
				}
				
				
				
				

				else									//if pressed any number else save it to the array 
				{
						if(c<4)
						{
							charr(arr[i-4][j-1]);
							tray[c]=arr[i-4][j-1];
							c++;
						}
						else
						{
							message("PIN must be 4D");
							res_pass();
							dm(5);
							text("Enter 4D PIN No.:");
							
					
						}
				}
				
				
				
				
			}
		}
		dm(10);
	}
	
	
	
	return;
	
	
}



void message(char *st)
{
	command(0x01);
	dm(5);
	text(st);
	dm(1000);
	command(0x01);
	
}
void res_pass()
{
	for(int i=0; i<4; i++)tray[i]='.'; c=0;
}