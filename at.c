#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "at.h"

AT_DATA *data=NULL;

int parse(char ch){
	static int state=0;
	data.line_count=0;
	switch(state){
		case 0:
				if(strcmp(ch,"CR")==0)
					state=1;
				else
					state=50; //ERROR
		break;

		case 1:
				if(strcmp(ch,"LF")==0)
					state=2;
				else
					state=50;  //ERROR
		break;
		case 2:
				if(strcmp(ch,"E")==0)
					state=9;
				else
					if(strcmp(ch,"O")==0)
						state=8;
					else
						if(strcmp(ch,"+")==0)
							state=3;
						else
							state=50; //ERROR
		break;
		case 3:
				while(strcmp(ch,"CR")!=0)
				{
					data.data[data.line_count++][data.char_count];
				}	
				else
					state=4;
		break;
		case 4:
				if(strcmp(ch,"CR")==0)
					state=5;
				else
					state=50;
		break;
		case 5:
				if(strcmp(ch,"CR")==0)
						state=6;
					else
						if(strcmp(ch,"+")==0)
							state=3;
						else
							state=50; //ERROR
		break;
		case 6:
				if(strcmp(ch,"LF")==0)
					state=2;
				else
					state=50;  //ERROR
		break;
		case 8:
				if(strcmp(ch,"K")==0){
					state=13;
					ok=1;
				}
				else
					state=50;  //ERROR
		break;
		case 9:
				if(strcmp(ch,"R")==0)
					state=10;
				else
					state=50;  //ERROR
		break;
		case 10:
				if(strcmp(ch,"R")==0)
					state=11;
				else
					state=50;  //ERROR
		break;
		case 11:
				if(strcmp(ch,"O")==0)
					state=12;
				else
					state=50;  //ERROR
		break;
		case 12:
				if(strcmp(ch,"R")==0){
					state=13;
					ok=0;
				}
				else
					state=50;  //ERROR
		break;
		case 13:
				if(strcmp(ch,"CR")==0)
					state=14;
				else
					state=50;  //ERROR
		break;
		case 14:
				if(strcmp(ch,"LF")==0)
					return 0;
				else
					state=50;  //ERROR
		break;
		case 50:
				return 1;

	}
}