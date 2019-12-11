#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

// extern int getIndexCli;

void menuCli(){

    int opMenuCli, exitMenuCli, codcli, achou;
    int getUserIndex;
    char nomecli[31], telcli[21];
    
    exitMenuCli = 0;
    achou = 0;

    while(exitMenuCli != 1){

      logo();
      printf("=======================\n");
      printf("||  MENU DE CLIENTES  ||\n");
      printf("=======================\n");
      printf("\nEscolha:\n");
      printf("[ 1 ] Para cadastrar um cliente\n");
      printf("[ 2 ] Para excluir um cliente\n");
      printf("[ 3 ] Para consultar um cliente\n");
      printf("[ 4 ] Para listar todos clientes\n");
      printf("[ 5 ] Para voltar ao menu principal\n");
      scanf("%i", &opMenuCli);

      // menu de clientes

      switch (opMenuCli)
      {
        case 1:

          logo();

          printf("Codigo do cliente: ");
          scanf("%i19[^\n]", &codcli);

          printf("Nome do cliente: ");
          scanf("%c", &temp); // temp statement to clear buffer
          scanf("%s19[^\n]", &nomecli);

          printf("Telefone do cliente: ");
          scanf("%c", &temp); // temp statement to clear buffer
          scanf("%s19[^\n]", &telcli);

          getUserIndex = getIndexCli();

          if(strlen(cli[getUserIndex].nomecli) == 0) {

            strcpy(cli[getUserIndex].nomecli, nomecli);
            strcpy(cli[getUserIndex].telcli, telcli);
            cli[getUserIndex].codcli =  codcli;

            printf("\nCliente cadastrado com sucesso!!");

          } else{
            printf("\nErro ao cadastrar cliente!!");
          }

          // opMenuCli = 0;
          getch();
          break;

        case 2:

          logo();
          printf("Digite o codigo do cliente que deseja excluir: ");
          scanf("%i", &codcli);

          achou = 0;

          for(int i = 0; i < 10; i++){

              if(cli[i].codcli == codcli){

                  strcpy(cli[i].nomecli, "");
                  strcpy(cli[i].telcli, "");
                  cli[i].codcli =  0;
                  achou = 1;
                  printf("\n\nCliente %s foi removido com sucesso!!", cli[i].nomecli);

              }

          }

          if(achou == 0){
              printf("\n\nCliente com codigo %i nao foi encontrado para remover..", codcli);
          }

          getch();
          break;
        
        case 3:

          logo();
          printf("Digite o codigo do cliente para consultar: ");
          scanf("%i", &codcli);

          achou = 0;

          for(int i = 0; i < 10; i++){

              if(cli[i].codcli == codcli){

                printf("  CLIENTE CADASTRADO\n\n");
                printf("==================================================================================================================\n");
                printf("||                NOME                ||                CODIGO                ||                TELEFONE                ||\n");
                printf("==================================================================================================================\n");

                if(strlen(cli[i].nomecli) != 0) {
                  printf("||              %s              ||              %i              ||              %s              \n", cli[i].nomecli, cli[i].codcli, cli[i].telcli);
                  printf("===============================================================================================================\n");
                }

                achou = 1;

              }

          }

          if(achou == 0){
              printf("\n\nCliente com codigo %i nao foi encontrado para consultar..", codcli);
          }

          opMenuCli = 0;
          getch();
          break;

        case 4:

          logo();

          printf("  CLIENTES CADASTRADOS\n\n");
          printf("=======================================================================================================================\n");
          printf("||                NOME                ||                CODIGO                ||                TELEFONE                ||\n");
          printf("========================================================================================================================\n");

          for(int i = 0; i < 10; i++){

            if(strlen(cli[i].nomecli) != 0) {
                printf("||              %s              ||              %i              ||              %s              \n", cli[i].nomecli, cli[i].codcli, cli[i].telcli);
                printf("==================================================================================================================\n");
            }

          }

          getch();
          break;

        case 5:

          logo();
          printf("\nSaindo do menu de clientes...");
          exitMenuCli = 1;
          getch();

          break;
      }

    }
}