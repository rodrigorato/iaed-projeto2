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

void escreveCheque(Chq ch1){
	escreveReferencia(ch1->ref_c); putchar(' ');
	escreveValor(ch1->valor); putchar(' ');
	escreveReferencia(ch1->ref_e); printf(" --> ");	
	escreveReferencia(ch1->ref_b);
}