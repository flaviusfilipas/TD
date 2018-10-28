/**
 *  Filipas Flavius
 *  Florea Natanael
 * 
 * */
#ifndef AT_H
#define AT_H
 
#define STR_CNT 9000
#define STR_SIZE 500

typedef struct {
    char data[STR_CNT][STR_SIZE + 1];
    int ok;
    int line_count;
    int char_count;
}AT_DATA;

typedef enum 
{ 
  STATE_MACHINE_NOT_READY,  
  STATE_MACHINE_READY_OK,  
  STATE_MACHINE_READY_WITH_ERROR  
}STATE_MACHINE_RETURN_VALUE; 

extern AT_DATA data;

STATE_MACHINE_RETURN_VALUE parse(char ch);
void printdata();
 
#endif