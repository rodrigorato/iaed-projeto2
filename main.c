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


short int command_aux(char command_str[]){
	int valor = strcmp(command_str,"sair");
	if (valor == 0)
		return 0;
	return strlen(command_str);
}

/* Coisas Globais */
fila* Queue_chq = nova_fila();

int main(){
	//TO-DO: All the stuff lolol
	/* maior comando sera infocliente, que tem 11 caracteres + 1(null byte)*/
	char command_str[12];
	short int commandval;
	unsigned int valor;
	unsigned long int refe, refb, refc;
	scanf("%s",command_str);
	commandval = command_aux(command_str);
	while(commandval != 0){
		switch(commandval){
			case 6: 
			/*cheque*/
				scanf("%u %lu %lu %lu",&valor,&refe,&refb,&refc);
				/*criaCheque vai devolver o apontador do novo cheque para ser posto na fila*/
				/* tenho que criar o node ou nao? */
				new_fila_node(criaCheque(criaValor(valor),
							  			 criaReferencia(refe),
						   	  			 criaReferencia(refb),
						   	  			 criaReferencia(refc));

				/* saber se cliente emissor e/ou benefeciente existem*/
				/*caso existam , apenas somar os valores aos respectivos clientes*/
				/* caso nao exista(m) cria-los*/

				break;

			case 8:
			/*processa*/
				tira_first(Queue_chq);
				/* preciso de ir buscar os valores e ref do cheque devolvido*/
				
				break;

			case 9:
			/*processaR*/
				scanf("%lu",&refc);
				search_and_destroy(Queue_chq, criaReferencia(refc));
				/* preciso de ir buscar o valor e refs do cheque devolvido*/
				break;

			case 10:
			/*infocheque*/
				scanf("%lu",&refc);
				printf("Cheque-info: ");
				escreveCheque(search_fila(Queue_chq, criaReferencia(refc)));
				putchar('\t');
				break;

			case 11:
			/*infocliente*/
				scanf("%d",&refc); /*refc neste caso stands for referencia cliente*/
				/*falta funcao de escrita do cliente*/
				criaReferencia(refc)

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