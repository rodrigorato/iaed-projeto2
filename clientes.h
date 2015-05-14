#ifndef CLIENTES_H
#define CLIENTES_H

#include <stdio.h>
#include <stdlib.h>

#include "dados.h"

typedef struct CLIENTE{
	Ref referencia;
	int n_emit, n_receb;
	Val val_emit, val_receb;
}Cliente;

typedef Cliente* Cli;

/* Cria um cliente com a referencia dada, devolvendo-o */
Cli criaCliente(Ref referencia);

/* Devolve uma copia de um dado cliente */
Cli copiaCliente(Cli cliente);

/* Devolve a referencia de dado cliente */
Ref referenciaCliente(Cli cliente);

/* Devolve o numero de cheques que o cliente emitiu */
int nemitCliente(Cli cliente);

/* Devolve o numero de cheques que o cliente recebeu */
int nrecebCliente(Cli cliente);

/* Devolve o valor que o cliente emitiu pelos seus cheques */
Val valemitCliente(Cli cliente);

/* Devolve o valor que o cliente recebeu nos seus cheques */
Val valrecebCliente(Cli cliente);

/* Muda os valores respetivos as emissoes pela parte do cliente */
void mudaEmit(Cli cliente, int numero, Val offset);

/* Muda os valores respetivos ao que o cliente recebeu */
void mudaReceb(Cli cliente, int numero, Val offset);

/* Liberta a memoria associada a um cliente */
void libertaCliente(Cli cliente);

/* Imprime os valores de dado cliente */
void imprimeCliente(Cli cliente);


#endif /* CLIENTES_H */