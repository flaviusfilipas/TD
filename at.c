/**
 * Filipas Flavius
 * Florea Natanael
 * 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "at.h"

AT_DATA data;
static int state=0;

void printdata(){
	int i;
	for(i = 0; i <= data.line_count; i++){
		printf("%s\n", data.data[i]);
	}

	printf("\n##Summary##\n");
	printf("Total lines: %d\n", data.line_count);
	printf("Result: %d\n",data.ok); //se afiseaza daca rezulatul e error(0) sau ok (1)
}

void log(int state, char ch){
	printf("[DEBUG] state: %d with char (%d)\n", state, ch);
}

STATE_MACHINE_RETURN_VALUE parse(char ch){

	if(state == 0){
		data.line_count = 0;
		data.char_count = 0;
	}
	
	//log(state, ch);
	switch(state){
		case 0:
				if(ch == 13){
					state=1;
				}
				else
					return STATE_MACHINE_READY_WITH_ERROR;
		break;

		case 1:
				if(ch == 10){
					state=2;
				}				
				else
					return STATE_MACHINE_READY_WITH_ERROR;
		break;
		case 2:
				if(ch == 'E')
					state=9;
				else if(ch == 'O')
					state=8;
				else if(ch == '+'){
					data.char_count = 0;
					state=3;
				}
				else
					return STATE_MACHINE_READY_WITH_ERROR;
		break;
		case 3:
				if(ch == 13)
				{
					state=4;
				}	
				else
					data.data[data.line_count][data.char_count++] = ch;
		break;
		case 4:
				if(ch == 10)
					state=5;
				else
					return STATE_MACHINE_READY_WITH_ERROR;
		break;
		case 5:
				if(ch == 13)
					state=6;
				else if(ch == '+'){ 
					state=3;
					data.data[data.line_count][data.char_count] = 0;
					data.char_count = 0;
					data.line_count++;
				}
				else
					return STATE_MACHINE_READY_WITH_ERROR;
		break;
		case 6:
				if(ch == 10)
					state=2;
				else
					return STATE_MACHINE_READY_WITH_ERROR;
		break;
		case 8:
				if(ch == 'K'){
					state=13;
					data.ok=1;
				}
				else
					return STATE_MACHINE_READY_WITH_ERROR;
		break;
		case 9:
				if(ch == 'R')
					state=10;
				else
					return STATE_MACHINE_READY_WITH_ERROR;
		break;
		case 10:
				if(ch == 'R')
					state=11;
				else
					return STATE_MACHINE_READY_WITH_ERROR;
		break;
		case 11:
				if(ch == 'O')
					state=12;
				else
					return STATE_MACHINE_READY_WITH_ERROR;
		break;
		case 12:
				if(ch == 'R'){
					state=13;
					data.ok=0;
				}
				else
					return STATE_MACHINE_READY_WITH_ERROR;
		break;
		case 13:
				if(ch == 13)
					state=14;
				else
					return STATE_MACHINE_READY_WITH_ERROR;
		break;
		case 14:
				if(ch == 10)
					return STATE_MACHINE_READY_OK;
				else
					return STATE_MACHINE_READY_WITH_ERROR;
	}

	return STATE_MACHINE_NOT_READY;
}
