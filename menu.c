#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

#define LOGIN_MAX 64
#define SENHA_MAX 32
#define MAXSIZE 100


struct usuario_t {
  char login[64];
  char senha[32];
};

/***
 *      _    _       _       _              
 *     | |  | |     (_)     (_)             
 *     | |  | |_ __  _ _ __  _ __________ _ 
 *     | |  | | '_ \| | '_ \| |_  /_  / _` |
 *     | |__| | | | | | |_) | |/ / / / (_| |
 *      \____/|_| |_|_| .__/|_/___/___\__,_|
 *                    | |                   
 *                    |_|                   
 */

void logo(){
  system("cls");
  printf("=====================================\n");
  printf("||                                  ||\n");
  printf("||             UNIPIZZA             ||\n");
  printf("||                                  ||\n");
  printf("=====================================\n\n\n");
}

int main(void) {

  // setar variaveis

  FILE * fp;
  struct usuario_t usuario;
  int op, opLogin, isLogged, mesas[10], status[10], i, nmesa, encontrou;
  char login[LOGIN_MAX];
  char senha[SENHA_MAX];
  char line[MAXSIZE];

  
  // sistema de login

  logo();
  printf("=====================\n");
  printf("||  TELA DE LOGIN  ||\n");
  printf("=====================\n");
  printf("\nEscolha:\n");
  printf("[ 1 ] Para Login\n");
  printf("[ 2 ] Para Cadastro\n");
  scanf("%i", &opLogin);

  isLogged = 0;
  while(isLogged != 1){
    
    // cadastrar
    switch (opLogin) {
      // incio do login
      case 1:
        logo();
        fp = fopen("login", "rb");

        if (!fp) {
          // login
          memset(&usuario, 0, sizeof(struct usuario_t));

          printf("Cadastro de usuario: \n");
          printf("Login: ");
          scanf("%s", & usuario.login);
          printf("Senha: ");
          scanf("%s", & usuario.senha);

          fp = fopen("login", "awb");
          if (!fp) {
            printf("Nao foi possivel criar o arquivo de login");
          }
          fwrite(&usuario, sizeof(struct usuario_t), 1, fp);
          fclose(fp);
          // fim do login
          fp = fopen("login", "rb");
          if (!fp) {
            printf("Nao foi possivel encontrar o arquivo de login\n");
          }
        }

        // while ((fgets(line, MAXSIZE, fp)) != NULL) {
        //     printf("%s\n", line);
        // }

        memset(&usuario, 0, sizeof(struct usuario_t));

        fread(&usuario, sizeof(struct usuario_t), 2, fp);
        fclose(fp);

        if (!strcmp("", usuario.login)) {

          int ch = 0;
          int lines = 0;

          lines++;
          while ((ch = fgetc(fp)) != EOF){
              if (ch == '\n'){
                lines++;
              }
          }

          printf("Nenhum usuario encontrado, abrindo cadastro!\n");
        
          // cadastrar

          memset(&usuario, 0, sizeof(struct usuario_t));

          printf("Cadastro de usuario: \n");
          printf("Login: ");
          scanf("%s", & usuario.login);
          printf("Senha: ");
          scanf("%s", & usuario.senha);

          fp = fopen("login", "awb");
          if (!fp) {
            printf("Nao foi possivel criar o arquivo de login");
          }
          fwrite(&usuario, sizeof(struct usuario_t), lines++, fp);
          fclose(fp);
          getch();

          // fim do cadastrar
        } else {

          printf("Usuario: %s, Senha: %s", usuario.login, usuario.senha);
          printf("Login: ");
          scanf("%s", & login);
          printf("Senha: ");
          scanf("%s", & senha);

          if (!strcmp(login, usuario.login) && !strcmp(senha, usuario.senha)) {
            printf("\n\nBem vindo %s\n", usuario.login);
            isLogged = 1;
          } else {
            printf("Usuario ou senha invalidos!\n");
            getch();
          }

        }
        break;
      // inicio do cadastrar
      case 2:

        logo();

        memset(&usuario, 0, sizeof(struct usuario_t));

        printf("Cadastro de usuario: \n");
        printf("Login: ");
        scanf("%s", & usuario.login);
        printf("Senha: ");
        scanf("%s", & usuario.senha);

        fp = fopen("login", "awb");
        if (!fp) {
          printf("Não foi possível criar o arquivo de login");
        }

        int ch = 0;
        int lines = 0;
        lines++;
        while ((ch = fgetc(fp)) != EOF){
            if (ch == '\n'){
                lines++;
            }
        }

        if(fwrite(&usuario, sizeof(struct usuario_t), (lines++), fp)){
          printf("Usuario inserido com sucesso!!");
          opLogin = 1;
          getch();
        }
        fclose(fp);
        break;
      // fim do cadastrar

    }
  }

  // fim do sistema de login //

  for (i = 0; i < 10; i++) {
    status[i] = 0; //0 -> Mesa livre, 1 -> Mesa ocupada
    mesas[i] = i + 1; //Preenche o vetor com os números das mesas
  }

  op = 1;
  while (op != 7 && isLogged == 1) {
    //Apresenta o menu de opcoes para o usuario
    logo();
    printf("1- Reservar mesa\n");
    printf("2- Liberar mesa \n");
    printf("3- Alocar cliente\n");
    printf("4- Listar mesas ocupadas\n");
    printf("5- Listar mesas livres\n");
    printf("6- Listar todas as mesas\n");
    printf("7- Sair\n");
    scanf("%d", & op);
    // O comando switch é um comando condicional, analisa a opção escolhida pelo usuário

    switch (op) {
    case 1:
      //Realiza a reserva de uma mesa cujo número foi informado
      system("cls");

      printf("Informe o numero da mesa que deseja reservar: ");
      scanf("%d", & nmesa);

      if (status[nmesa - 1] == 1) //Verifica se a mesa já esta reserva
      {
        printf("Mesa ja reservada. Verifique outra opcao");
        getch();
      } else //Se a mesa estiver livre faz a reserva
      {
        for (i = 0; i < 10; i++) {
          if (nmesa == mesas[i]) {
            status[i] = 1;
            printf("Reserva realizada com sucesso!");
            getch();
          }
        }
      }
      break;
    case 2:
      //Realiza a liberação de uma mesa
      system("cls");
      printf("Informe o numero da mesa que deseja liberar: ");
      scanf("%d", & nmesa);

      if (status[nmesa - 1] == 0) //Verifica se a mesa já esta liberada
      {
        printf("Esta mesa ja esta livre. Verifique outra opcao");
        getch();
      } else //Se a mesa está ocupada, faz a liberação
      {
        for (i = 0; i < 10; i++) {
          if (nmesa == mesas[i]) {
            status[i] = 0;
            printf("Liberacao realizada com sucesso!");
            getch();
          }
        }
      }
      break;
    case 3:
      //Aloca o Cliente na primeira mesa livre encontrada
      i = 0;
      encontrou = 0;
      while (i < 10) {
        if (status[i] == 0) {
          status[i] = 1;
          printf("O cliente foi alocado na mesa: %d", mesas[i]);
          getch();
          i = 10;
          encontrou = 1;
        }
        i++;
      }
      if (encontrou == 0) {
        printf("Nao existe mesa disponivel");
        getch();
      }
      break;
    case 4:
      //Lista as mesas ocupadas
      system("cls");
      printf("Mesas ocupadas\n");
      printf("==============\n\n");
      printf("Mesa Status\n\n");
      encontrou = 0; //Flag para saber se existe pelo menos uma mesa ocupada
      for (i = 0; i < 10; i++) {
        if (status[i] == 1) {
          printf(" %d      Ocupada\n", mesas[i]);
          encontrou = 1;
        }
      }
      if (encontrou == 0) {
        printf("Todas as mesas estao disponiveis");
      }
      getch();
      break;

    case 5:
      //Lista as mesas livres
      system("cls");
      printf("Mesas disponiveis\n");
      printf("=================\n\n");
      printf("Mesa Status\n\n");
      encontrou = 0; //Flag para saber se existe pelo menos uma mesa disponível

      for (i = 0; i < 10; i++) {
        if (status[i] == 0) {
          printf("   %d     Disponivel\n", mesas[i]);
          encontrou = 1;
        }
      }
      if (encontrou == 0) {
        printf("Todas as mesas estao Ocupadas");
      }

      getch();
      break;

    case 6:
      // Lista todas as mesas
      system("cls");
      printf("Todas as mesas\n\n");
      printf("========================\n\n");
      printf("Mesa Status\n\n");
      encontrou = 0; //Flag para saber se existe pelo menos uma mesa livre

      for (i = 0; i < 10; i++) {
        if (status[i] == 1) //Se a mesa está ocupada
        {
          printf("  %d     Ocupada\n", mesas[i]);
        } else {
          printf("  %d     Disponivel\n", mesas[i]);
        }
      }
      getch();
      break;
    case 7:
    default:
      printf("Saindo!");
      getch();
      break;
    } //switch
  } //while
} // main
