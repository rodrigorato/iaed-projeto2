#ifndef CHEQUES_H
#define CHEQUES_H

#include <stdio.h>

#include "dados.h"

typedef struct CHEQUE{
	Val valor;
	Ref ref_c, ref_e, ref_b; 
}Cheque;

typedef Cheque* Chq;

Chq criaCheque(Val valor, Ref ref_c, Ref ref_e, Ref ref_b);
void libertaCheque(Chq cheque);
void escreveCheque(Chq ch1);


#endif /* CHEQUES_H */