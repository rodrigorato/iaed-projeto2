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

/* Cria e devolve um cheque com os dados que recebe */
Chq criaCheque(Val valor, Ref ref_c, Ref ref_e, Ref ref_b);

/* Liberta a memoria associada a determinado cheque */
void libertaCheque(Chq cheque);

/* Recebe um cheque e devolve o seu valor */
Val valorCheque(Chq cheque);

/* Recebe um cheque e devolve a sua referencia */
Ref refcCheque(Chq cheque);

/* Recebe um cheque e devolve a referencia do emitente */
Ref refeCheque(Chq cheque);

/* Recebe um cheque e devolve a referencia do beneficiario */
Ref refbCheque(Chq cheque);

/* Imprime os dados de um cheque */
void imprimeCheque(Chq cheque);

#endif /* CHEQUES_H */