#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "cheques.h"
#include "clientes.h"
#include "fila.h"
#include "avl.h"


int comando(char* nome){
	int i;
	char *ops[] = {"cheque",		/* id = 0 */
				   "processa",		/* id = 1 */
				   "processaR",		/* id = 2 */
				   "infocheque",	/* id = 3 */
				   "infocliente",	/* id = 4 */
				   "info",			/* id = 5 */
				   "sair"};			/* id = 6 */
				   
	for(i=0; i <= 6; i++)
		if(!strcmp(nome, ops[i]))
			return i;
			
	return -1;	   					/* comando nao existe */
}

int main(){
	int cod;
	char op[12];
	
	scanf("%s", op);
	while((cod = comando(op)) != 6){
		switch(cod){
			case 0:
				/* A realizar: cheque */
				printf("cheque\n");
				break;
			case 1:
				/* A realizar: processa */
				printf("processa\n");
				break;
			case 2:
				/* A realizar: processaR */
				printf("processaR\n");
				break;
			case 3:
				/* A realizar: infocheque */
				printf("infocheque\n");
				break;
			case 4:
				/* A realizar: infocliente */
				printf("infocliente\n");
				break;
			case 5:
				/* A realizar: info */
				printf("info\n");
				break;
			case -1:
				/* A realizar: COMANDO INVALIDO */
				printf("INVALIDO\n");
				break;
		}
		scanf("%s", op);
	}
	
	/* A realizar: sair */
	
	return 0;
}