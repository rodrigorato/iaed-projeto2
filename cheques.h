#ifndef CHEQUES_H
#define CHEQUES_H

#include <stdio.h>
#include <stdlib.h>

#include "dados.h"

typedef struct CHEQUE{
	Val valor;
	Ref ref_c, ref_e, ref_b; 
}Cheque;

typedef Cheque* Chq;

Chq criaCheque(Val valor, Ref ref_c, Ref ref_e, Ref ref_b);
void libertaCheque(Chq cheque);
Val valorCheque(Chq cheque);
Ref refcCheque(Chq cheque);
Ref refeCheque(Chq cheque);
Ref refbCheque(Chq cheque);
int chequeValido(Chq cheque); /* 0 se o cheque for invalido, qualquer outro valor em caso contrario */
void imprimeCheque(Chq cheque);
/* void escreveCheque(Chq ch1); - eventualmente useless */


#endif /* CHEQUES_H */