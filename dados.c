#include <stdio.h>
#include <stdlib.h>

#include "dados.h"

Val criaValor(int valor){
	Val final = valor;
	return final;
}

Ref criaReferencia(long int referencia){
	Ref final = referencia;
	return final;
}

void escreveValor(Val valor){
	printf("%d", valor);
}

void escreveReferencia(Ref referencia){
	printf("%ld", referencia);
}

int comparaReferencia(Ref ref1, Ref ref2){
	return ref1 - ref2;
}

Ref leReferencia(){
	long int ref;
	scanf("%ld",&ref);
	return criaReferencia(ref);
}

Val leValor(){
	int valor;
	scanf("%d",&valor);
	return criaValor(valor);
}