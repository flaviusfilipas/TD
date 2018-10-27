#include "at.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
    FILE *f = fopen("test_file_copn_ok.txt", "rb");
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
          /*bla bla = */  parse(c);
        }
    }
     printf("%s",data);
}