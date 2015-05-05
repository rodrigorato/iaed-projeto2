#include <stdio.h>
#include <stdlib.h>

#include "cheques.h"
#include "dados.h"
#include "fila.h"


link_f new_fila_node(Chq cheque);
fila* nova_fila(){
	fila * f = malloc(sizeof(fila));
	f->head=NULL;
	f->tail=NULL;
	return f;
}
void insertCheck(fila* f,Chq cheque){
	link x = (link)malloc(sizeof(struct fila_node));
	x->check=cheque;
	x->next=NULL;
	if(!f->head) f->head=x;
	else f->tail->next=x;
	f->tail=x;
}
int fila_vazia(fila* f){
	return (f->head==NULL);
}

Chq tira_first(fila* f){
	Chq cheque = f->head->check;
	link_f temp=f->head->next;
	free(f->head);
	f->head=temp;
	return cheque;
}
Chq search_and_destroy(fila* f, Ref ref);
Chq search_fila(fila* f,Ref ref);
