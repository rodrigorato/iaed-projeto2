#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

#include "cheques.h"
#include "dados.h"

typedef struct fila_node* link_f;

struct fila_node{
	Chq check;
	link_f next;
};

typedef struct {
	link_f head;
	link_f tail;
	int    nche;
} fila;

/*cria uma fila e devolve o seu ponteiro*/
fila* nova_fila();

/*recebe a fila e o cheque que é posto na fila, usada no commando 'cheque'*/
void insertCheck(fila* f,Chq cheque); 

/*recebe a fila e verifica se está vazia, usada no comando 'processa'*/
int fila_vazia(fila* f); 

/*recebe a fila, elimina o 1º node da mesma e devolve o cheque retirado, usada no comando 'processa'*/ 
Chq tira_first(fila* f); 

/*recebe a fila e a referencia dum cheque, elimina o seu node e devolve o cheque,
  se nao encontrar cheque com a referencia dada devolve cheque invalido. usada no comando 'processaR*/
Chq search_and_destroy(fila* f, Ref ref);

/*recebe a fila e a referencia dum cheque, e devolve o cheque correspondente a essa referencia.
  usada no comando 'infocheque*/
Chq search_fila(fila* f,Ref ref);

/*recebe a fila e devolve o numero total de cheques, usada no comando 'sair'*/
int conta_cheques(fila* f);

/*recebe a fila e elimina-a e todo o seu conteudo, devolve o valor total de todos os cheques.
  usada no comando 'sair'*/
Val apaga_fila(fila* f); 

#endif /* FILA_H */  