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
	if(!f->head){
		x->next=NULL;
		f->head=x;
		f->tail=x;
	}
	else
		x->next=f->head;
		f->tail=x;
		

}
int fila_vazia(fila* f);
void tira_first(fila* f);
Chq search_and_destroy(fila* f, Ref ref);
Chq search_fila(fila* f,Ref ref);
