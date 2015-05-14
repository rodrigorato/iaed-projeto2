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
	free(f->head);
	f->head=temp;
	f->nche-=1;
	return cheque;
}

Chq search_and_destroy(fila* f, Ref ref){
	link_f temp=f->head,aux=NULL;
	Chq c;
	for (;temp && (comparaReferencia(refcCheque(temp->check),ref)!=0);aux =temp,temp=temp->next);
	if(!temp) /*caso em que o cheque com a referencia dada nao existe*/
		return NULL;
	else {
		if (!aux) return tira_first(f);
		aux->next=temp->next;
		c=temp->check;
		if (!temp->next) f->tail=aux;
		f->nche-=1;
	}
	free(temp);
	return c;
}

Chq search_fila(fila* f,Ref ref){
	link_f temp=f->head;
	Chq c;
	for (;temp && (comparaReferencia(refcCheque(temp->check),ref)!=0) ;temp=temp->next);
	c = temp->check ;
	return c;
}

int conta_cheques(fila* f){
	return f->nche;
}


Val apaga_fila(fila* f){
	Val total=criaValor(0);
	Chq Cheque;
	while (!fila_vazia(f)){
		Cheque = tira_first(f);
		total += valorCheque(Cheque);
		libertaCheque(Cheque);
	}
	free(f);
	return total;
}