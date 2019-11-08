#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

int main(void) {
  int op, mesas[10], status[10], i, nmesa, encontrou;

  for (i = 0; i < 10; i++) {
    status[i] = 0; //0 -> Mesa livre, 1 -> Mesa ocupada
    mesas[i] = i + 1; //Preenche o vetor com os números das mesas
  }

  op = 1;
  while (op != 7) {
    //Apresenta o menu de opcoes para o usuario
    system("cls");
    printf("Unipizza\n");
    printf("=====================\n\n");
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
        getch();
        break;

        case 6:
          //Lista todas as mesassystem("cls);
          printf("Todas as mesas\n\n");
        printf("========================\n\n");
        printf("Mesa Status\n\n");
        encontrou = 0; //Flag para saber se existe pelo menos uma mesa livre

        for (i = 0; i < 10; i++) {
          if (status[i] == 1) //Se a mesa está ocupada
          {
            printf("  %d     Ocupada\n", mesas[i]);
          } else {
            printf("  %d     Disponível\n", mesas[i]);
          }
        }
      }
      getch();
      break;

    case 7:
    default:
      printf("Opção inválida!");
      getch();
      break;
    } //switch
  } //while
} // main