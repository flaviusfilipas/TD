#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "at.h"

AT_DATA data;

int parse(char ch){
	static int state=0;
	data.line_count=0;
	
	switch(state){
		case 0:
				if(ch == 13)
					state=1;
				else
					state=50; //ERROR
		return;

		case 1:
				if(ch == 10)
					state=2;
				else
					state=50;  //ERROR
		return;
		case 2:
				if(ch == 'E')
					state=9;
				else
					if(ch == 'O')
						state=8;
					else
						if(ch == '+')
							state=3;
						else
							state=50; //ERROR
		return;
		case 3:
				if(ch == 13)
				{
					data.data[data.line_count][data.char_count++];
				}	
				else
					state=4;
		return;
		case 4:
				if(ch == 13)
					state=5;
				else
					state=50;
		return;
		case 5:
				if(ch == 13)
						state=6;
					else
						if(ch == '+'){ 
							state=3;
							data.line_count++;
						}
						else
							state=50; //ERROR
		return;
		case 6:
				if(ch == 10)
					state=2;
				else
					state=50;  //ERROR
		return;
		case 8:
				if(ch == 'K'){
					state=13;
					data.ok=1;
				}
				else
					state=50;  //ERROR
		return;
		case 9:
				if(ch == 'R')
					state=10;
				else
					state=50;  //ERROR
		return;
		case 10:
				if(ch == 'R')
					state=11;
				else
					state=50;  //ERROR
		return;
		case 11:
				if(ch == 'O')
					state=12;
				else
					state=50;  //ERROR
		return;
		case 12:
				if(ch == 'R'){
					state=13;
					data.ok=0;
				}
				else
					state=50;  //ERROR
		return;
		case 13:
				if(ch == 13)
					state=14;
				else
					state=50;  //ERROR
		return;
		case 14:
				if(ch == 10)
					return 0;
				else
					state=50;  //ERROR
		return;
		case 50:
				return 1;

	}
}