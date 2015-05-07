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

Cli criaCliente(Ref referencia);
Cli copiaCliente(Cli cliente);
Ref referenciaCliente(Cli cliente);
int nemitCliente(Cli cliente);
int nrecebCliente(Cli cliente);
Val valemitCliente(Cli cliente);
Val valrecebCliente(Cli cliente);
void mudaNEmit(Cli cliente, int offset);
void mudaNReceb(Cli cliente, int offset);
void mudaValEmit(Cli cliente, Val offset);
void mudaValReceb(Cli cliente, Val offset);

/*funcoes acrescentadas*/
void mudaEmit(Cli cliente, int numero, Val offset);
void mudaReceb(Cli cliente, int numero, Val offset);
/*cliente Valido != 0 se for vaildo , ==0 se for invalido*/
int clienteValido(Cli cliente);
/*fim funcoes acrecentadas*/

void libertaCliente(Cli cliente);
void imprimeCliente(Cli cliente);


#endif /* CLIENTES_H */