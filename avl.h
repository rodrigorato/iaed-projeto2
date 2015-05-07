#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

#include "dados.h"
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
int numElementos(arvore* avltree); 

/* Devolve um ponteiro para o primeiro cliente que existe
   na arvore cuja referencia e a dada. Devolve o cliente invalido
   caso nao exista. */
Cli procuraElemento(arvore* avltree, Ref referencia); 

/* Insere o novo Cliente na arvore. */
void insereElemento(arvore* avltree, Cli cliente);

/* Liberta a memoria associada ao cliente
   da arvore cuja referencia e a referencia dada- */
void apagaElemento(arvore* avltree, Ref referencia);

/* Liberta toda a memoria associada a arvore
   cuja raiz e apontada por h. 
   NESTE MOMENTO ESTA A LIBERTAR A ARVORE TODA
   NUNO? ISTO E PRECISO? */
void cutdownArvore(arvore* avltree);

/* Escreve no ecra todos os clientes na arvore 
   apontada por h no formato pedido. */
void escreveClientesInorder(arvore* avltree);

/* As seguintes funcoes nao sao necessarias fora deste
   ficheiro - os comentarios estao no proprio codigo. */
link novoNode(Cli cliente, link l, link r);
link max(link h);
link min(link h);
int count(link h);
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
link freeR(link h);
void traverseInOrder(link h);

#endif /* AVL_H */