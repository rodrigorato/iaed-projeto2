#ifndef DADOS_H
#define DADOS_H

#include <stdio.h>

typedef unsigned int Val;
typedef unsigned long int Ref;

/* Recebe um inteiro positivo e devolve um valor */
Val criaValor(unsigned int valor);

/* Recebe um inteiro positivo e longo e devolve uma referencia */
Ref criaReferencia(unsigned long int referencia);

/* Recebe um valor e escreve-o para o std output */
void escreveValor(Val valor);

/* Recebe uma referencia a escreve-a para o std output */
void escreveReferencia(Ref referencia);

/* Recebe duas referencias e devolve:
		0 caso sejam iguais;
		Um numero POSITIVO se a ref1 > ref2;
		Um numero NEGATIVO se a ref1 < ref2; */
int comparaReferencia(Ref ref1, Ref ref2);

#endif /* DADOS_H */