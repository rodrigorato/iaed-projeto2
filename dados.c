#include <stdio.h>

#include "dados.h"

Val criaValor(unsigned int valor){
	Val final = valor;
	return final;
}

Ref criaReferencia(unsigned long int referencia){
	Ref final = referencia;
	return final;
}

void escreveValor(Val valor){
	printf("%u", valor);
}

void escreveReferencia(Ref referencia){
	printf("%lu", referencia);
}

int comparaReferencia(Ref ref1, Ref ref2){
	return ref1 - ref2;
}