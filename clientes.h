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
Ref referenciaCliente(Cli cliente);
int nemitCliente(Cli cliente);
int nrecebCliente(Cli cliente);
Val valemitCliente(Cli cliente);
Val valrecebCliente(Cli cliente);
void mudaNEmit(Cli cliente, int offset);
void mudaNReceb(Cli cliente, int offset);
void mudaValEmit(Cli cliente, Val offset);
void mudaValReceb(Cli cliente, Val offset);
void libertaCliente(Cli cliente);


#endif /* CLIENTES_H */