#include <stdio.h>
#include "conio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
// #include "../bd.c"

int getSize(){
    int i, it;
    i = 0;
    for(it = 0; it < 10; it++){
        if(strlen(funcionarios[it].nome) != 0) {
            i++;
        }
    }
    return i;
}

bool login(char loginInput[31], char senhaInput[31]){

    int i;

    for(i = 0; i < 10; i++){
        if (!strcmp(funcionarios[i].login, loginInput) && !strcmp(funcionarios[i].senha, senhaInput)) {
            
            strcpy(logado[0].login, funcionarios[i].login);
            strcpy(logado[0].senha, funcionarios[i].senha);
            strcpy(logado[0].nome, funcionarios[i].nome);
            logado[0].registro =  funcionarios[i].registro;
            logado[0].salario = funcionarios[i].salario;

            return true;
        }
    }

    return false;

}