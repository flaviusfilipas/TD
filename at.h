#ifndef AT_H
#define AT_H
 
#define STR_CNT 1000
#define STR_SIZE 200

typedef struct {
    char data[STR_CNT][STR_SIZE+1];
    int ok;
    int line_count;
    int char_count;
}AT_DATA;

extern AT_DATA data;

int parse(char ch);
void printdata();
 
#endif