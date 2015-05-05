#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "cheques.h"
#include "clientes.h"
#include "lista.h"
#include "fila.h"


void cria_cheque(valor, refe, refb, refc);
void processsa();
void processaR(int refc);
void infocheque(int refc);
void infocliente(int refc);
void info();
void sair();


int command_aux(char command_str[]){
	int valor = strcmp(command_str,"sair");
	if (valor == 0)
		return 0;
	return strlen(command_str);
}


int main(){
	//TO-DO: All the stuff lolol
	/* maior comando sera infocliente, que tem 11 caracteres + 1(null byte)*/
	char command_str[12];
	int commandval, valor, refe, refb, refc;
	scanf("%s",command_str);
	commandval = command_aux(command_str);
	while(commandval != 0){
		switch(commandval){
			case 6: 
			/*cheque*/
				scanf("%d %d %d %d",valor,refe,refb,refc);

				break;

			case 8:
			/*processa*/
				
				break;

			case 9:
			/*processaR*/
				scanf("%d",refc);

				break;

			case 10:
			/*infocheque*/
				scanf("%d",refc);

				break;

			case 11:
			/*infocliente*/
				scanf("%d",refc);

				break;

			case 4:
			/*info*/

				break;

			default:
				printf("ERRO - Comando invalido");
				break;
		}
		scanf("%s",command_str);
		commandval = command_aux(command_str);
	}
	/*imprime final*/
	return 0;
}