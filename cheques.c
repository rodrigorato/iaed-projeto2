#include <stdio.h>
#include <stdlib.h>

#include "dados.h"
#include "cheques.h"


Chq criaCheque(Val valor, Ref ref_c, Ref ref_e, Ref ref_b){
	Chq ChqPtr = malloc(sizeof(Cheque));
	ChqPtr->valor = valor;
	ChqPtr->ref_c = ref_c;
	ChqPtr->ref_e = ref_e;
	ChqPtr->ref_b = ref_b;
	return ChqPtr;
}

void libertaCheque(Chq cheque){
	free(cheque); 
}

Val valorCheque(Chq cheque){
	return cheque->valor;
}

Ref refcCheque(Chq cheque){
	return cheque->ref_c;
}

Ref refeCheque(Chq cheque){
	return cheque->ref_e;
}

Ref refbCheque(Chq cheque){
	return cheque->ref_b;
}

int chequeValido(Chq cheque){
	return comparaReferencia(refcCheque(cheque), criaReferencia(-1));
}

void imprimeCheque(Chq cheque){
	escreveReferencia(refcCheque(cheque)); putchar(' ');
	escreveValor(valorCheque(cheque)); putchar(' ');
	escreveReferencia(refeCheque(cheque)); printf(" --> ");
	escreveReferencia(refbCheque(cheque));
}