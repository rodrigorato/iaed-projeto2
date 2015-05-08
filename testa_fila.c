#include <stdio.h>
#include <stdlib.h>

#include "dados.h"
#include "cheques.c"
#include "fila.h"


void escreveFilaTeste(link_f head){
	if(head == NULL)
		return;
	else{
		escreveCheque(head->cheque); putchar('\n');
		escreveFilaTeste(head->next);		
	}	
}

int main(){
	Chq chq_a = criaCheque(123, 1, 2, 3), 
		chq_b = criaCheque(456, 4, 5, 6), 
		chq_c = criaCheque(789, 7, 8, 9), 
		chq_d = criaCheque(987, 9, 8, 7), 
		chq_e = criaCheque(654, 6, 5, 4);
	
	fila* my_fila = nova_fila();
	escreveFilaTeste(my_fila->head);
	
	insertCheck(my_fila, chq_a);
	escreveFilaTeste(my_fila->head);
	return 0;
}