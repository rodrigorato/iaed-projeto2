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

/* Cria e devolve uma nova arvore, vazia. */
arvore* novaArvore(); 

/* Devolve o numero de elementos na arvore. */
int numElementos(arvore* avltree); 

/* Procura na arvore um cliente com referencia igual
   a que recebe. Caso nao exista devolve o cliente
   invalido (referencia = -1). 
   E necessario libertar o cliente invalido mais tarde. */
Cli procuraElemento(arvore* avltree, Ref referencia); 

/* Insere um novo cliente na arvore.
   Apenas faz com que o novo no da arvore
   fique com o cliente que recebe, nao guarda
   uma copia do mesmo. */
void insereElemento(arvore* avltree, Cli cliente);

/* Liberta a memoria associada ao cliente
   da arvore cuja referencia e a referencia dada. */
void apagaElemento(arvore* avltree, Ref referencia);

/* Liberta toda a memoria associada a arvore. */
void cutdownArvore(arvore* avltree);

/* Escreve no ecra todos os clientes que existem
   na arvore de forma ordenada e cada um
   numa linha diferente. */
void escreveClientesInorder(arvore* avltree);

/* Funcoes usadas na construcao e manutencao
   da arvore. Nao sera necessario usa-las fora 
   do ficheiro .c onde esta implementado este tipo. */
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
link procura(link h, Ref referencia);
link freeR(link h);
void traverseInOrder(link h);

#endif /* AVL_H */