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


fila* nova_fila();
void insertCheck(fila* f,Chq cheque);
int fila_vazia(fila* f);
Chq tira_first(fila* f);
Chq search_and_destroy(fila* f, Ref ref);/*vai ser usado com o comando processaR,
                                          se nao encontrar devolve cheque invalido*/
Chq search_fila(fila* f,Ref ref);/*vai ser usado com o comando infocheque*/




#endif /* FILA_H */  