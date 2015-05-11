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

Cli copiaCliente(Cli cliente){
	Cli copia = malloc(sizeof(Cliente));
	copia->referencia = cliente->referencia;
	copia->n_emit = cliente->n_emit;
	copia->n_receb = cliente->n_receb;
	copia->val_emit = cliente->val_emit;
	copia->val_receb = cliente->val_receb;
	return copia;
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

/*funcoes acrescentadas*/
void mudaEmit(Cli cliente, int numero, Val offset){
	(cliente->n_emit) += numero;
	(cliente->val_emit) += offset;
}

void mudaReceb(Cli cliente, int numero, Val offset){
	(cliente->n_receb) += numero;
	(cliente->val_receb) += offset;
}

int clienteValido(Cli cliente){
	return comparaReferencia(referenciaCliente(cliente), criaReferencia(-1));
}


void imprimeCliente(Cli cliente){
	escreveReferencia(referenciaCliente(cliente));
	printf(" %d ", nemitCliente(cliente));
	escreveValor(valemitCliente(cliente));
	printf(" %d ", nrecebCliente(cliente));
	escreveValor(valrecebCliente(cliente));
}