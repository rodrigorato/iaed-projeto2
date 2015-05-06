#include <stdio.h>
#include <stdlib.h>

#include "cheques.h"
#include "dados.h"
#include "fila.h"


fila* nova_fila(){
	fila * f = malloc(sizeof(fila));
	f->head=NULL;
	f->tail=NULL;
	f->nche=0;
	return f;
}
void insertCheck(fila* f,Chq cheque){
	link_f x = (link_f)malloc(sizeof(struct fila_node));
	x->check=cheque;
	x->next=NULL;
	if(!f->head) f->head=x;
	else f->tail->next=x;
	f->tail=x;
	f->nche+=1;
}
int fila_vazia(fila* f){
	return (f->head==NULL);
}

Chq tira_first(fila* f){
	Chq cheque = f->head->check;
	link_f temp=f->head->next;
	if (f->tail==f->head) f->tail=NULL;
	libertaCheque(f->head->check);
	free(f->head);
	f->head=temp;
	f->nche-=1;
	return cheque;
}

Chq search_and_destroy(fila* f, Ref ref){
	link_f temp=f->head,aux=NULL;
	Chq c;
	for (;temp && (comparaReferencia(refcCheque(temp->check),ref)!=0);aux =temp,temp=temp->next);
	if (!temp) c = criaCheque(0,-1,0,0);
	else {
		if (!aux) return tira_first(f);
		aux->next=temp->next;
		c=temp->check;
		if (!temp->next) f->tail=aux;
		f->nche-=1;
	}
	libertaCheque(temp->check);
	free(temp);
	return c;
}

Chq search_fila(fila* f,Ref ref){
	link_f temp=f->head;
	Chq c;
	for (;temp && (comparaReferencia(refcCheque(temp->check),ref)!=0) ;temp=temp->next);
	c = temp->check ;
	libertaCheque(temp->check);
	free(temp);
	return c;
}

int conta_cheques(fila* f){
	return f->nche;
}

void apaga_fila(fila* f){
	link_f temp=f->head;
	for (;temp ;temp=temp->next){
		libertaCheque(f->head->check);
		free(f->head);
		f->head=temp->next;
	}
	free(f);
}
