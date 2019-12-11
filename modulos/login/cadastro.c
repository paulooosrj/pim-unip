#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

bool cadastro(){

    char strLogin[31], strSenha[31];
    char strNome[31];
    int strRegistro;
    float strSalario;

    int i;
    int sizeArr = getSize(funcionarios);

    printf("Login: ");
    scanf("%c", &temp); // temp statement to clear buffer
    scanf("%s19[^\n]", &strLogin);

    printf("Senha: ");
    scanf("%c", &temp); // temp statement to clear buffer
    scanf("%s19[^\n]", &strSenha);

    bool isUser = login(strLogin, strSenha);

    if(isUser || sizeArr >= 10){
        printf("Esse funcionario ja e existente!");
    } else {

        char strNome[31];

        printf("Digite seu nome: ");
        scanf("%c", &temp); // temp statement to clear buffer
        scanf("%s19[^\n]", &strNome);

        sizeArr++;

        strcpy(funcionarios[sizeArr].login, strLogin);
        strcpy(funcionarios[sizeArr].senha, strSenha);
        strcpy(funcionarios[sizeArr].nome, strNome);
        funcionarios[sizeArr].registro =  1;
        funcionarios[sizeArr].salario = 1000;

        bool isLogin = login(strLogin, strSenha);

        return isLogin;

    }

    return false;

}
