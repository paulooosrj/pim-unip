#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

void logo(void){
  system("cls");
  printf("=====================================\n");
  printf("||                                  ||\n");
  printf("||             UNIPIZZA             ||\n");
  printf("||                                  ||\n");
  printf("=====================================\n\n\n");
}

int getIndexCli(){
    int i, it;
    i = 0;
    for(it = 0; it < 10; it++){
        if(strlen(cli[it].nomecli) != 0) {
            i++;
        }
    }
    return i;
}

int getVendas(){
    int i, it;
    i = 0;
    for(it = 0; it < 10; it++){
        if(venda[it].venda_cod != 0) {
            i++;
        }
    }
    return i;
}