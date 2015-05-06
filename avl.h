#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

#include "clientes.h"

struct node{
	Cli item;
	struct node *l;
	struct node *r;
	int height;
};

typedef struct node *link;

typedef struct {
	link root;
} arvore;

/* Cria uma nova arvore vazia e devolve o link inicial */
arvore* novaArvore(); 

/* Devolve o numero de elementos na arvore apontada por h */
int numElementos(arvore* root); 

/* Devolve um ponteiro para o primeiro cliente que existe
   na arvore cuja referencia e a dada. Devolve o cliente invalido
   caso nao exista. */
Cli procuraElemento(arvore* root, Ref referencia); 

/* Insere o novo Cliente na arvore e devolve
   um apontador para a raiz da arvore. */
void insereElemento(link h, Cli cliente);

/* Liberta a memoria associada ao cliente
   da arvore cuja referencia e a referencia dada- */
void apagaElemento(link h, Ref referencia);

/* Liberta toda a memoria associada a arvore
   cuja raiz e apontada por h. */
void cutdownArvore(link h);

/* Escreve no ecra todos os clientes na arvore 
   apontada por h no formato pedido. */
void escreveClientesInorder(link h);

/* Cria e devolve o novo node para as infos que recebe. */
link novoNode(Cli cliente, link l, link r);

/* As seguintes funcoes nao sao necessarias fora deste
   ficheiro - os comentarios estao no proprio codigo. */
link max(link h);
link min(link h)
int height(link h);
link rotR(link h);
link rotL(link h);
link rotLR(link h);
link rotRL(link h);
int balance(link h);
link AVLbalance(link h);
link insertR(link h, Cli cliente);
link deleteR(link h, Ref referencia);
link procura(link h, Ref referencia); /* Atencao com este gajo! */

#endif /* AVL_H */