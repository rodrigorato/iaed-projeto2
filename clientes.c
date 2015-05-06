#include <stdio.h>
#include <stdlib.h>

#include "clientes.h"
#include "dados.h"


Cli criaCliente(Ref referencia){
	Cli CliPtr = malloc(sizeof(Cliente));
	CliPtr->referencia = referencia;
	CliPtr->n_emit = CliPtr->n_receb = 
	CliPtr->val_emit = CliPtr->val_receb = 0;
	return CliPtr;
}


Ref referenciaCliente(Cli cliente){
	return cliente->referencia;
}

int nemitCliente(Cli cliente){
	return cliente->n_emit;
}

int nrecebCliente(Cli cliente){
	return cliente->n_receb;
}

Val valemitCliente(Cli cliente){
	return cliente->val_emit;
}

Val valrecebCliente(Cli cliente){
	return cliente->val_receb;
}

void mudaNEmit(Cli cliente, int offset){
	(cliente->n_emit) += offset;
}

void mudaNReceb(Cli cliente, int offset){
	(cliente->n_receb) += offset;
}

void mudaValEmit(Cli cliente, Val offset){
	(cliente->val_emit) += offset;
}

void mudaValReceb(Cli cliente, Val offset){
	(cliente->val_receb) += offset;
}

void libertaCliente(Cli cliente){
	free(cliente);
}

int main(){
	return 0;
}