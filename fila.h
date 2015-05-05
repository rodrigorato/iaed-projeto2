#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

#include "cheques.h"
#include "dados.h"



typedef struct {
	link_f head;
	link_f tail;
} fila;

typedef struct fila_node* link_f;

struct fila_node{
	Chq check;
	link next;
};

link_f new_fila_node(Chq cheque);
fila* nova_fila();
void insertCheck(fila* f,Chq cheque);
int fila_vazia(fila* f);
Chq tira_first(fila* f);
Chq search_and_destroy(fila* f, Ref ref);
Chq search_fila(fila* f,Ref ref);



#endif /* FILA_H */  