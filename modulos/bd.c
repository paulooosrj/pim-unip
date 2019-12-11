#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
  char login[31];
  char senha[31];
  char nome[31];
  int registro;
  float salario;
} TFun;

typedef struct { 
  char login[31];
  char senha[31];
  char nome[31];
  int registro;
  float salario;
} TFunLogado;

typedef struct {
  int codcli;
  char nomecli[31], telcli[21];
} Cliente;

typedef struct {
  char nome_pizza[30];
  int cod_pizza, valor_pizza;
} Pizza;

typedef struct {
  int venda_cod;
  int venda_codcli;
  int venda_codpizza;
  int venda_codbebida;
  float venda_valor;
  int venda_base_cod;
  int venda_status;
  char feedback[31];
} Venda;

typedef struct {
  int bebida_cod, bebida_qtd;
  char bebida_nome[31];
  float bebida_valor;
} Bebida;

typedef struct {
  int ingrediente_cod, ingrediente_qtd;
  char ingrediente_nome[31];
} Ingredientes;

typedef struct {
  int pizzaIndice;
  char pizzaRelatorio[31];
} PizzaPedidas;

TFunLogado logado[1];
TFun funcionarios[10];
Cliente cli[10];
Pizza pizza[10];
Venda venda[10];
Bebida bebidas[10];
Ingredientes ingredientes[10];
PizzaPedidas pizzaMaisPedida[3];

void setFun(void){

  strcpy(funcionarios[0].login, "admin");
  strcpy(funcionarios[0].senha, "admin");
  strcpy(funcionarios[0].nome, "admin");
  funcionarios[0].registro =  1;
  funcionarios[0].salario = 1000;

  strcpy(funcionarios[1].login, "user");
  strcpy(funcionarios[1].senha, "user");
  strcpy(funcionarios[1].nome, "user");
  funcionarios[1].registro =  2;
  funcionarios[1].salario = 11000;

  strcpy(cli[0].nomecli, "Joao");
  strcpy(cli[0].telcli, "11987772618");
  cli[0].codcli = 1;

  strcpy(cli[1].nomecli, "Maria");
  strcpy(cli[1].telcli, "11986782618");
  cli[1].codcli = 2;

  strcpy(pizza[0].nome_pizza, "Marguerita");
  pizza[0].cod_pizza = 1;
  pizza[0].valor_pizza = 30.00;

  strcpy(pizza[1].nome_pizza, "Calabresa");
  pizza[1].cod_pizza = 2;
  pizza[1].valor_pizza = 45.00;

  venda[0].venda_cod = 1;
  venda[0].venda_codcli = 1;
  venda[0].venda_codpizza = 1;
  venda[0].venda_codbebida = 1;
  venda[0].venda_valor = 100.00;
  venda[0].venda_base_cod = 1;
  venda[0].venda_status = 1;
  strcpy(venda[0].feedback, "muito bom!!");

  strcpy(bebidas[0].bebida_nome, "Coca Cola");
  bebidas[0].bebida_cod = 1;
  bebidas[0].bebida_qtd = 1;
  bebidas[0].bebida_valor = 10.00;

  strcpy(ingredientes[0].ingrediente_nome, "Farinha de Trigo");
  ingredientes[0].ingrediente_cod = 1;
  ingredientes[0].ingrediente_qtd = 1;


}
