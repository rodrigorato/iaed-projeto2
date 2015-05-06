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
void insertCheck(fila* f,Chq cheque); /*comando: cheque*/
int fila_vazia(fila* f); /*comando: processa*/
Chq tira_first(fila* f); /*comando: processa*/ 
Chq search_and_destroy(fila* f, Ref ref);/*comando: processaR,
                                          se nao encontrar devolve cheque invalido*/
Chq search_fila(fila* f,Ref ref);/*comando: infocheque*/
int conta_cheques(fila* f);/*comando: sair*/
void apaga_fila(fila* f); /*comando: sair*/





#endif /* FILA_H */  