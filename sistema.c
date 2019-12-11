#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
 
// setar variaveis

int op, lojaAtual, opLogin, exitMenu, mesas[10], status[10], i, nmesa, encontrou, lucroBases[3], vendaValor, achouVenda, vendaCodFinal, codVenda, opRelatorio;
int isLogged, strCod_pizza, sizePizzas, npizza, tipoEstoque, tipoPedido, produtoCod, produtoQtd, vendaCod, pizzaIndice, pizzaMaisPedidaIndice, unidadeMaisPedida, unidadeIndicePedida;
float valorUnidade, unidadeRelatorioValor;
char iLogin[31], iSenha[31], strNome_pizza[31], produtoNome[31], tipoProdutoList[31], statusVenda[31], temp;

#include "modulos/bd.c"
#include "modulos/funcoes.c"
#include "modulos/login/login.c"
#include "modulos/login/cadastro.c"
#include "modulos/cliente/menucli.c"

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

void fazerLogin(){

      logo();
      printf("=======================\n");
      printf("||  Escolha sua base  ||\n");
      printf("=======================\n");
      printf("[ 1 ] Para base Moema\n");
      printf("[ 2 ] Para base Campo Belo\n");
      printf("[ 3 ] Para base Santo Amaro\n");
      scanf("%i", &lojaAtual);

      logo();
      printf("=====================\n");
      printf("||  TELA DE LOGIN  ||\n");
      printf("=====================\n");
      printf("\nEscolha:\n");
      printf("[ 1 ] Para Login\n");
      printf("[ 2 ] Para Cadastro\n");
      scanf("%i", &opLogin);

    
    while(isLogged != 1){

      // cadastrar

      switch (opLogin)
      {
        case 1:

          logo();
          printf("=====================\n");
          printf("||  TELA DE LOGIN  ||\n");
          printf("=====================\n");

          printf("Login: ");
          scanf("%c", &temp); // temp statement to clear buffer
          scanf("%s19[^\n]", &iLogin);

          printf("Senha: ");
          scanf("%c", &temp); // temp statement to clear buffer
          scanf("%s19[^\n]", &iSenha);

          if(login(iLogin, iSenha)){
            isLogged = 1;
            printf("\n\nBem vindo funcionario %s!!", logado[0].nome);
            opLogin = 0;
          } else {
            printf("Nenhum funcionario foi encontrado, tente fazer o cadastro.");
            opLogin = 0;
          }

          getch();
          break;

        case 2:

          logo();
          printf("=======================\n");
          printf("||  TELA DE CADASTRO  ||\n");
          printf("=======================\n");

          if(cadastro()){
            printf("\nCadastrou!!!");
            isLogged = 1;
          } else{
            int sizeArr = getSize(funcionarios);
            if(sizeArr >= 10){ 
              printf("\nNao cadastrou, atingiu o limite de funcionarios cadastrados!!!");
            } else{
              printf("\nNao cadastrou, ocorreu algum erro!!!");
            }
          }

          getch();
          break;
      }

    }
}

int main() {


  // sistema de login

  isLogged = 0;
  exitMenu = 0;

  setFun();

  fazerLogin();

  // fim do sistema de login //
  for (i = 0; i < 10; i++) {
      status[i] = 0; //0 -> Mesa livre, 1 -> Mesa ocupada
      mesas[i] = i + 1; //Preenche o vetor com os números das mesas
  }
  
  while(exitMenu == 0){

    if(isLogged == 1){

      op = 1;

      while (op != 8) {

        //Apresenta o menu de opcoes para o usuario
        logo();
        printf("[ 1 ] - Cadastrar uma pizza\n");
        printf("[ 2 ] - Listar todas pizzas\n");
        printf("[ 3 ] - Menu de Clientes\n");
        printf("[ 4 ] - Para ter acesso ao estoque\n");
        printf("[ 5 ] - Menu de Pedidos\n");
        printf("[ 6 ] - Relatorios\n");
        printf("[ 7 ] - Para voltar para o login\n");
        printf("[ 8 ] - Sair\n");
        scanf("%d", & op);
        // O comando switch é um comando condicional, analisa a opção escolhida pelo usuário

        switch (op) {
          case 1:
            // Realiza o cadastro de uma pizza
            logo();

            printf("Informe o numero da pizza que deseja cadastrar: ");
            scanf("%i", &npizza);

            if (strlen(pizza[npizza - 1].nome_pizza) != 0 || (npizza - 1) > 9) // Verifica se a pizza ja esta cadastrada
            {
              printf("\nOcorreu um erro ao cadastrar. Verifique outra opcao");
            } else // Se a pizza ja nao for cadastrada
            {
              
              printf("Digite o nome da pizza: ");
              scanf("%c", &temp); // temp statement to clear buffer
              scanf("%31[0-9a-zA-Z ]", &strNome_pizza);

              printf("Digite o valor da pizza: ");
              scanf("%f", &pizza[npizza - 1].valor_pizza);

              strcpy(pizza[npizza - 1].nome_pizza, strNome_pizza);
              pizza[npizza - 1].cod_pizza = npizza;

              if(strlen(pizza[npizza - 1].nome_pizza) != 0){
                printf("\nPizza cadastrada com sucesso!!");
                op = 1;
              }
              
            }

            getch();
            break;
          case 2:
            //Realiza a listagem das pizzas
            system("cls");
            logo();
            printf("                       PIZZAS CADASTRADAS\n\n");
            printf("====================================================================================================================\n");
            printf("||            ID            ||            NOME            ||            CODIGO            ||          VALOR        ||\n");
            printf("====================================================================================================================\n");
            for (i = 0; i < 10; i++) {
              if (strlen(pizza[i].nome_pizza) != 0) // Se a pizza existe
              {
                printf("||            %d            ||            %s            ||            %d            ||            %.2f            ||\n", i, pizza[i].nome_pizza, pizza[i].cod_pizza, pizza[i].valor_pizza);
                printf("====================================================================================================================\n");
              }
            }
            getch();

            break;
          case 3:
            // Chama menu dos clientes
            menuCli();
            break;
          case 4:
            // Realiza o cadastro de estoque
            logo();
            printf("=======================\n");
            printf("||      ESTOQUE      ||\n");
            printf("=======================\n");
            printf("\nEscolha:\n");
            printf("[ 1 ] Para inserir ingredientes\n");
            printf("[ 2 ] Para inserir bebidas\n");
            printf("[ 3 ] Para listar o estoque\n");

            scanf("%d", &tipoEstoque);

            
            switch (tipoEstoque)
            {
            case 1:

              logo();
              printf("=======================\n");
              printf("||      ESTOQUE      ||\n");
              printf("=======================\n");

              printf("Informe o codigo do ingrediente: ");
              scanf("%d", &produtoCod);

              if (strlen(ingredientes[produtoCod - 1].ingrediente_nome) != 0 || (produtoCod - 1) > 9) // Verifica se a pizza ja esta cadastrada
              {
                printf("\nOcorreu um erro ao cadastrar o ingrediente. Verifique outra opcao");
                getch();
              } else // Se a pizza ja nao for cadastrada
              {

                printf("Informe o nome do ingrediente: ");
                scanf("%c", &temp); // temp statement to clear buffer
                scanf("%31[0-9a-zA-Z ]", &produtoNome);

                printf("Informe a quantidade: ");
                scanf("%d", &produtoQtd);

                strcpy(ingredientes[produtoCod - 1].ingrediente_nome, produtoNome);
                ingredientes[produtoCod - 1].ingrediente_cod = produtoCod;
                ingredientes[produtoCod - 1].ingrediente_qtd = produtoQtd;

                if(strlen(ingredientes[produtoCod - 1].ingrediente_nome) != 0){
                  printf("\nIngrediente cadastrado com sucesso!!");
                  getch();
                }
                
              }
              break;
            case 2:
              logo();
              printf("=======================\n");
              printf("||      ESTOQUE      ||\n");
              printf("=======================\n");

              printf("Informe o codigo da bebida: ");
              scanf("%d", &produtoCod);

              if (strlen(bebidas[produtoCod - 1].bebida_nome) != 0 || (produtoCod - 1) > 9) // Verifica se a pizza ja esta cadastrada
              {
                printf("\nOcorreu um erro ao cadastrar a bebida. Verifique outra opcao");
                getch();
              } else // Se a pizza ja nao for cadastrada
              {

                printf("Informe o nome da bebida: ");
                scanf("%c", &temp); // temp statement to clear buffer
                scanf("%31[0-9a-zA-Z ]", &produtoNome);

                printf("Informe o valor da bebida: ");
                scanf("%f", &bebidas[produtoCod - 1].bebida_valor);

                printf("Informe a quantidade: ");
                scanf("%d", &produtoQtd);

                strcpy(bebidas[produtoCod - 1].bebida_nome, produtoNome);
                bebidas[produtoCod - 1].bebida_cod = produtoCod;
                bebidas[produtoCod - 1].bebida_qtd = produtoQtd;

                if(strlen(bebidas[produtoCod - 1].bebida_nome) != 0){
                  printf("\nIngrediente cadastrado com sucesso!!");
                  getch();
                }
                
              }
              break;
            case 3:
              logo();
              printf("                       ESTOQUE\n\n");
              printf("============================================================================================================================================================\n");
              printf("||            QUANTIDADE            ||                NOME                ||                CODIGO                ||                TIPO                ||\n");
              printf("============================================================================================================================================================\n");
              
              for (i = 0; i < 10; i++) {
                if (strlen(ingredientes[i].ingrediente_nome) != 0) // Se a pizza existe
                {
                  strcpy(tipoProdutoList, "ingrediente");
                  printf("||              %d              ||              %s              ||              %d              ||              %s              \n", ingredientes[i].ingrediente_qtd, ingredientes[i].ingrediente_nome,ingredientes[i].ingrediente_cod, tipoProdutoList);
                  printf("=========================================================================================================================================================\n");
                }
              }
              for (i = 0; i < 10; i++) {
                if (strlen(bebidas[i].bebida_nome) != 0) // Se a pizza existe
                {
                   strcpy(tipoProdutoList, "bebida");
                  printf("||              %d              ||              %s              ||              %d              ||              %s              \n", bebidas[i].bebida_qtd, bebidas[i].bebida_nome, bebidas[i].bebida_cod, tipoProdutoList);
                  printf("=========================================================================================================================================================\n");
                }
              }
              getch();
              break;
            default:
              printf("Operacao invalida de estoque!");
              getch();
              break;
            }

            break;

          case 5:
            // Realiza o pedido
            logo();
            printf("=======================\n");
            printf("||      PEDIDOS      ||\n");
            printf("=======================\n");
            printf("\nEscolha:\n");
            printf("[ 1 ] Para criar um pedido\n");
            printf("[ 2 ] Para cancelar um pedido\n");
            printf("[ 3 ] Para finalizar um pedido\n");
            printf("[ 4 ] Para registrar um feedback\n");
            printf("[ 5 ] Para listar os pedidos\n");

            scanf("%d", &tipoPedido);

            
            switch (tipoPedido)
            {
            case 1:

              logo();
              printf("=======================\n");
              printf("||      PEDIDOS      ||\n");
              printf("=======================\n");

              printf("Informe o codigo da venda: ");
              scanf("%d", &vendaCod);

              vendaCodFinal = getVendas();

              if (venda[vendaCodFinal].venda_cod != 0 || vendaCodFinal > 9 || 0 > vendaCodFinal) // Verifica se a pizza existe
              {
                printf("\nOcorreu um erro ao cadastrar o pedido. Verifique outra opcao");
                getch();
              } else // Se a pizza ja nao for cadastrada
              {

                printf("Informe o codigo do cliente: ");
                scanf("%d", &venda[vendaCodFinal].venda_codcli);

                printf("Informe o codigo da pizza: ");
                scanf("%d", &venda[vendaCodFinal].venda_codpizza);

                printf("Informe o codigo da bebida: ");
                scanf("%d", &venda[vendaCodFinal].venda_codbebida);

                vendaValor = 0;

                if(pizza[venda[vendaCodFinal].venda_codpizza - 1].valor_pizza > 0 && bebidas[venda[vendaCodFinal].venda_codbebida  - 1].bebida_valor > 0){
                    vendaValor = pizza[venda[vendaCodFinal].venda_codpizza  - 1].valor_pizza + bebidas[venda[vendaCodFinal].venda_codbebida  - 1].bebida_valor;
                } else {
                  printf("Valor nao encontrado!!");
                  getch();
                }

                venda[vendaCodFinal].venda_valor = vendaValor;

                venda[vendaCodFinal].venda_base_cod = lojaAtual;
                
                venda[vendaCodFinal].venda_status = 0;

                venda[vendaCodFinal].venda_cod = vendaCod;

                if(venda[vendaCodFinal].venda_valor > 0){
                  printf("\nVenda cadastrada com sucesso!!");
                  getch();
                } else {
                  printf("Erro ao cadastrar a venda!!");
                  getch();
                }
                
              }
              break;
              case 2:

                logo();
                printf("Digite o codigo da venda que deseja cancelar: ");
                scanf("%i", &codVenda);

                achouVenda = 0;

                for(int i = 0; i < 10; i++){

                    if(venda[i].venda_cod == codVenda){

                        venda[i].venda_status = 0;
                        venda[i].venda_cod =  0;
                        venda[i].venda_codbebida = 0;
                        venda[i].venda_codcli = 0;
                        venda[i].venda_codpizza = 0;
                        venda[i].venda_base_cod = 0;
                        venda[i].venda_valor = 0.00;

                        achouVenda = 1;
                        printf("\n\nVenda %d foi removida com sucesso!!", codVenda);

                    }

                }

                if(achouVenda == 0){
                    printf("\n\nVenda com codigo %i nao foi encontrada para remover..", codVenda);
                }

                getch();
                break;
              case 3:

                logo();
                printf("Digite o codigo da venda que deseja finalizar: ");
                scanf("%i", &codVenda);

                achouVenda = 0;

                for(int i = 0; i < 10; i++){

                    if(venda[i].venda_cod == codVenda){

                        venda[i].venda_status = 1;

                        achouVenda = 1;
                        printf("\n\nVenda %d foi finalizada com sucesso!!", codVenda);

                    }

                }

                if(achouVenda == 0){
                    printf("\n\nVenda com codigo %i nao foi encontrada para remover..", codVenda);
                }

                getch();
                break;
              case 4:

                logo();
                printf("Digite o codigo da venda que deseja registrar um feedback: ");
                scanf("%i", &codVenda);

                achouVenda = 0;

                for(int i = 0; i < 10; i++){

                    if(venda[i].venda_cod == codVenda){

                        printf("Digite o feedback do cliente: ");
                        scanf("%c", &temp); // temp statement to clear buffer
                        scanf("%[^\n]", venda[i].feedback);

                        achouVenda = 1;
                        printf("\n\nO feedback da venda %i foi registrado com sucesso!!", codVenda);

                    }

                }

                if(achouVenda == 0){
                    printf("\n\nVenda com codigo %i nao foi encontrada para adicionar feedback..", codVenda);
                }

                getch();
                break;
              case 5:

                logo();
                printf("=======================\n");
                printf("||      PEDIDOS      ||\n");
                printf("=======================\n");

                printf("================================================================================================\n");
                printf("||  CODIGO  ||  CODIGO CLIENTE  ||  VALOR  ||  BASE  ||      STATUS      ||      FEEDBACK      ||\n");
                printf("================================================================================================\n");

                for(i = 0; i < 10; i++){

                  if(venda[i].venda_valor > 0){
                    if(venda[i].venda_status == 1){
                      strcpy(statusVenda, "finalizada");
                    } else{
                      strcpy(statusVenda, "pendente");
                    }
                    if(strlen(venda[i].feedback) != 0){
                        printf("||    %d    ||       %d       ||    %.2f    ||    %d    ||    %s    ||    %s    ||\n", venda[i].venda_cod, venda[i].venda_codcli, venda[i].venda_valor, venda[i].venda_base_cod, statusVenda, venda[i].feedback); 
                    } else{
                        printf("||    %d    ||       %d       ||    %.2f    ||    %d    ||    %s    ||    N/D    ||\n", venda[i].venda_cod, venda[i].venda_codcli, venda[i].venda_valor, venda[i].venda_base_cod, statusVenda, venda[i].feedback);
                    }
                    
                    printf("================================================================================================\n");
                  }

                }

                getch();
                break;
              default:
                printf("Operacao invalida de estoque!");
                getch();
                break;
            }

            break;

          case 6:
            // Menu de relatorios
            logo();
            printf("=========================\n");
            printf("||      RELATORIOS      ||\n");
            printf("=========================\n");
            printf("\nEscolha:\n");
            printf("[ 1 ] Para listar as pizzas mais vendidas por unidade\n");
            printf("[ 2 ] Para listar a unidade que mais vendeu\n");
            printf("[ 3 ] Para listar faturamento por unidade\n");
            printf("[ 4 ] Para listar faturamento da rede\n");
            printf("[ 5 ] Para listar as perdas possiveis da rede\n");
            scanf("%i", &opRelatorio);

            switch (opRelatorio)
            {
            case 1:

              logo();

              printf("=========================================================================\n");
              printf("||       UNIDADE       ||       PIZZA       ||        QUANTIDADE        ||\n");
              printf("=========================================================================\n");
              
              for(i = 0; i < 3; i++){

                pizzaMaisPedidaIndice = 0;

                for(int ii = 0; ii < 10; ii++){

                  pizzaIndice = 0;
                  
                  for(int iii = 0; iii < 10; iii++){

                    if(venda[iii].venda_codpizza == pizza[ii].cod_pizza && venda[iii].venda_base_cod == (i + 1)){
                      pizzaIndice++;
                    }

                  }

                  if(pizzaIndice > pizzaMaisPedidaIndice){
                    pizzaMaisPedidaIndice = pizzaIndice;
                    pizzaMaisPedida[i].pizzaIndice = pizzaIndice;
                    strcpy(pizzaMaisPedida[i].pizzaRelatorio, pizza[ii].nome_pizza);
                  }

                }

                if(strlen(pizzaMaisPedida[i].pizzaRelatorio) != 0){
                    printf("||       %i       ||       %s       ||        %i        ||\n", (i + 1), pizzaMaisPedida[i].pizzaRelatorio, pizzaMaisPedida[i].pizzaIndice);
                } else {
                    printf("||       %i       ||           N/D          ||        %i        ||\n", (i + 1), pizzaMaisPedida[i].pizzaIndice);
                }
                
                printf("=========================================================================\n");

              }

              getch();
              break;

            case 2:

              logo();
              printf("=======================================================================================================\n");
              printf("||       UNIDADE       ||       PEDIDOS       ||       RENDA DIARIA       ||       RENDA MENSAL       ||\n");
              printf("=======================================================================================================\n");
              
              for(i = 0; i < 3; i++){

                pizzaMaisPedidaIndice = 0;

                for(int ii = 0; ii < 10; ii++){

                  valorUnidade = 0.00;
                  pizzaIndice = 0;
                  
                  for(int iii = 0; iii < 10; iii++){

                    if(venda[iii].venda_codpizza == pizza[ii].cod_pizza && venda[iii].venda_base_cod == (i + 1)){
                      valorUnidade += venda[iii].venda_valor;
                      pizzaIndice++;
                    }

                  }

                  if(pizzaIndice > pizzaMaisPedidaIndice){
                    pizzaMaisPedida[i].pizzaIndice = pizzaIndice;
                    strcpy(pizzaMaisPedida[i].pizzaRelatorio, pizza[ii].nome_pizza);

                    for(int iPizzaPedida = 0; iPizzaPedida < 3; iPizzaPedida++){
                      if(pizzaIndice > pizzaMaisPedida[iPizzaPedida].pizzaIndice){
                        unidadeIndicePedida = pizzaIndice;
                        unidadeMaisPedida = (i + 1);
                        unidadeRelatorioValor = valorUnidade;
                      }
                    }

                  }

                }

              }

              printf("||         %i         ||       %i       ||        %.2f        ||        %.2f        ||\n", unidadeMaisPedida, unidadeIndicePedida, (unidadeRelatorioValor / 30), unidadeRelatorioValor);
              printf("=======================================================================================================\n");

              getch();
              break;
            
            
            case 3:

              logo();
              
              printf("Informe o codigo da unidade: ");
              scanf("%d", &vendaCod);

              valorUnidade = 0.00;

              for(i = 0; i < 10; i++){

                if(venda[i].venda_base_cod == vendaCod){
                  valorUnidade += venda[i].venda_valor;
                }

              }

              logo();
              printf("================================================================================\n");
              printf("||       UNIDADE       ||       RENDA DIARIA       ||       RENDA  MENSAL      ||\n");
              printf("================================================================================\n");
              printf("||         %i         ||       %.2f       ||       %.2f       ||\n", vendaCod, (valorUnidade / 30), valorUnidade);
              printf("================================================================================\n");

              getch();
              break;
            
            case 4:

              valorUnidade = 0.00;

              for(i = 0; i < 10; i++){

                valorUnidade += venda[i].venda_valor;

              }

              logo();
              printf("======================================================================================\n");
              printf("||       RENDA TOTAL DA REDE POR MES       ||       RENDA TOTAL DA REDE POR DIA      ||\n");
              printf("======================================================================================\n");
              printf("||              %.2f              ||              %.2f              ||\n", valorUnidade, (valorUnidade / 30));
              printf("======================================================================================\n");

              getch();
              break;
             case 5:

              valorUnidade = 0.00;

              for(i = 0; i < 10; i++){

                if(venda[i].venda_status == 0){
                  valorUnidade -= venda[i].venda_valor;
                }

              }

              logo();
              printf("========================================\n");
              printf("||       POSSIVEIS PERDA DA REDE       ||\n");
              printf("========================================\n");
              printf("||              %.2f                   ||\n", valorUnidade);
              printf("========================================\n");

              getch();
              break;
            
            default:
              printf("Nao foi encontrada esta opcao no menu!");
              break;
            }

            getch();
            break;
          case 7:
            printf("Voltando para tela de login...\n");
            isLogged = 0;
            fazerLogin();
            getch();
            break;  
          case 8:
          default:
            printf("Saindo!");
            exitMenu = 1;
            getch();
            break;
        } //switch

      } //while

    }

  } //while

  return 0;
} // main
