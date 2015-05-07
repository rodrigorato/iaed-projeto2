#include <stdio.h>
#include <stdlib.h>

#include "dados.h"
#include "clientes.h"
#include "avl.h"

#define key(cliente) referenciaCliente(cliente)
#define less(refa, refb) (comparaReferencia(refa, refb) < 0)
#define eq(refa, refb) (comparaReferencia(refa, refb) == 0)
#define deleteItem(it) libertaCliente(it)
#define visit(no) imprimeCliente(no->item)


arvore* novaArvore(){
	arvore* mytree = malloc(sizeof(arvore));
	mytree->root = NULL;
	return mytree;
}

int numElementos(arvore* avltree){
	if(avltree->root == NULL)
		return 0;
	else
		return count(avltree->root);
}

Cli procuraElemento(arvore* avltree, Ref referencia){
	link no_do_cliente = procura(avltree->root, referencia);
	return no_do_cliente->item;
}

void insereElemento(arvore* avltree, Cli cliente){
	link root_updated = insertR(avltree->root, cliente);
	avltree->root = root_updated;
}

void apagaElemento(arvore* avltree, Ref referencia){
	link root_updated = deleteR(avltree->root, referencia);
	avltree->root = root_updated;
}

void cutdownArvore(arvore* avltree){
	avltree->root = freeR(avltree->root);
	free(avltree);
}

void escreveClientesInorder(arvore* avltree){
	traverseInOrder(avltree->root);
}

link novoNode(Cli cliente, link l, link r){
	link finalnode = (link)malloc(sizeof(struct node));
	finalnode->item = cliente;
	finalnode->l = l;
	finalnode->r = r;
	finalnode->height = 1;
	return finalnode; 
}

link max(link h){
 if(h == NULL || h->r == NULL) 
 	return h;
 else 
 	return max(h->r);
}

link min(link h){
 if(h == NULL || h->l == NULL) 
 	return h;
 else 
 	return min(h->l);
} 

int count(link h){
	if(h == NULL)
		return 0;
	else
		return 1 + count(h->l) + count(h->r);
}

int height(link h){
	/* Devolve a altura da arvore apontada por h */
	if(h == NULL) return 0;
	return h->height;
}

link rotL(link h){
	/* Rotacao simples a esquerda. */
	int height_left, height_right;

 	link x = h->r;
 	h->r = x->l;
 	x->l = h;

 	height_left = height(h->l); height_right = height(h->r);
 	h->height = height_left > height_right ? height_left + 1 : height_right + 1;

 	height_left = height(h->l); height_right = height(x->r);
 	x->height = height_left > height_right ? height_left + 1 : height_right + 1;

 	return x;
}

link rotR(link h){
	/* Rotacao simples a direita. */
	int height_left, height_right;

 	link x = h->l;
 	h->l = x->r;
 	x->r = h;


 	height_left = height(h->l); height_right = height(h->r);
 	h->height = height_left > height_right ? height_left + 1 : height_right + 1;

 	height_left = height(x->l); height_right = height(h->r);
 	x->height = height_left > height_right ? height_left + 1 : height_right + 1;

 	return x; 
}

link rotLR(link h){
	/* Rotacao a esquerda seguida de
	 * uma rotacao a direita. */
	if(h == NULL) return h;
 	h->l = rotL(h->l);
 	return rotR(h);
}

link rotRL(link h){
	/* Rotacao a direita seguida de
	 * uma rotacao a esquerda. */
	if(h == NULL) return h;
	h->r = rotR(h->r);
 	return rotL(h); 
}

int balance(link h){
	/* Devolve a variacao de balanco da arvore */
	if(h == NULL) return 0;
 	return height(h->l)-height(h->r); 
}

link AVLbalance(link h){
	/* Equilibra a arvore apontada por h. */
	int balanceFactor;
	if(h == NULL) return h;
	balanceFactor = balance(h);
	if(balanceFactor > 1){
		if(balance(h->l) > 0)
			h = rotR(h);
		else
			h = rotLR(h);

	}else if(balanceFactor < -1){
		if(balance(h->r) < 0)
			h = rotL(h);
		else
			h = rotRL(h);

	}else {
		int height_left = height(h->l); 
		int height_right = height(h->r);
 		h->height = height_left > height_right ? height_left + 1 : height_right + 1; 
	}
	return h;
}



link insertR(link h, Cli cliente){
	/* Insere o cliente na arvore apontada por h
	 * Equilibrando-a se necessario. */
	if(h == NULL)
 		return novoNode(cliente, NULL, NULL);
 	if(less(key(cliente), key(h->item)))
 		h->l = insertR(h->l, cliente);
 	else
 		h->r = insertR(h->r, cliente);

 	h = AVLbalance(h);
 	return h; 
}

link deleteR(link h, Ref referencia){
	/* Apaga o da arvore o primeiro no com o
	 * cliente que tem a referencia dada. */

	if(h == NULL) 
		return h;
 	else if(less(referencia, key(h->item)))
 		h->l=deleteR(h->l,referencia);
 	else if(less(key(h->item), referencia)) 
 		h->r=deleteR(h->r,referencia) ;
 	else{
 		if(h->l !=NULL && h->r !=NULL){
 			link aux = max(h->l);
 			{	
 				Cli x; 
 				x= h->item; 
 				h->item = aux->item; 
 				aux->item = x;
 			}
 			h->l = deleteR(h->l, key(aux->item));
 		}
 		else{
 			link aux=h;
 			if(h->l == NULL && h->r == NULL) 
 				h = NULL;
 			else if(h->l==NULL) 
 				h = h->r;
 			else 
 				h = h->l;
 			deleteItem(aux->item);
 			free(aux);
 		}
 	}
 	h = AVLbalance(h);
 	return h; 	
}

link procura(link h, Ref referencia){ 
 	if(h == NULL)
 		return NULL;
 	if(eq(referencia, key(h->item)))
 		return h;
 	if(less(referencia, key(h->item)))
 		return procura(h->l, referencia);
 	else
 		return procura(h->r, referencia);
}

link freeR(link h){
	if(h == NULL)
		return h;
	h->l=freeR(h->l);
 	h->r=freeR(h->r);
 	return deleteR(h,key(h->item));
}

void traverseInOrder(link h){
	if (h == NULL)
 		return;
 	traverseInOrder(h->l);
 	visit(h); putchar('\n');
 	traverseInOrder(h->r);
}


int main(){
	/* to-do: actual program lol */
	arvore* mytree = novaArvore();
	/* varname         ref  */
	Cli z = criaCliente(0); 
	Cli a = criaCliente(1); 
	Cli b = criaCliente(22); 
	Cli c = criaCliente(333); 
	Cli d = criaCliente(4444); 
	Cli e = criaCliente(55555); 
	/*    n_emit, val_emit  n_receb  val_receb */
	mudaEmit(z, 0, 0); mudaReceb(z, 0, 0);
	mudaEmit(a, 1, 10); mudaReceb(a, 2, 20);
	mudaEmit(b, 3, 30); mudaReceb(b, 4, 40);
	mudaEmit(c, 5, 50); mudaReceb(c, 6, 60);
	mudaEmit(d, 7, 70); mudaReceb(d, 8, 80);
	mudaEmit(e, 9, 90); mudaReceb(e, 10, 100);


	printf("Numero de elementos na arvore: (supposed to be 0)\n%d\n", numElementos(mytree));


	insereElemento(mytree, z);
	insereElemento(mytree, a);
	insereElemento(mytree, b);

	escreveClientesInorder(mytree);

	insereElemento(mytree, c);
	insereElemento(mytree, d);
	insereElemento(mytree, e);
	
	escreveClientesInorder(mytree);

		


	libertaCliente(z); libertaCliente(a); libertaCliente(b); 
	libertaCliente(c); libertaCliente(d); libertaCliente(e);
	return 0;
}