/**
 * Filipas Flavius
 * Florea Natanael
 * 
 * */
#include "at.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: program_test <fisier_test>\n");
        return 0;
    }

    FILE *f = fopen(argv[1], "rb");
    char c;
    if(!f){
        printf("Eroare la deschiderea fisierului\n");
        return;
    }
    while (!feof(f)){
        c = fgetc(f);
        if(c == EOF){
            break;
        }
        else{
          switch(parse(c)){
              case STATE_MACHINE_NOT_READY:
                continue;
              case STATE_MACHINE_READY_OK:
                printf("Data has been read successfully!\n");
                printdata();
                return 0;
              case STATE_MACHINE_READY_WITH_ERROR:
                printf("There has been an error while reading data.\n");
                return 0;
          }
        }
    }

}