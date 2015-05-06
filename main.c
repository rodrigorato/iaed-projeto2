#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "cheques.h"
#include "clientes.h"
#include "avl.h"
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
arvore* Client_base = novaArvore();

int main(){
	//TO-DO: All the stuff lolol
	/* maior comando sera infocliente, que tem 11 caracteres + 1(null byte)*/
	char command_str[12];
	short int commandval;
	int valor;
	long int refe, refb, refc;
	scanf("%s",command_str);
	commandval = command_aux(command_str);
	while(commandval != 0){
		switch(commandval){
			case 6: 
			/*cheque*/
				scanf("%d %ld %ld %ld",&valor,&refe,&refb,&refc);
				insertCheck( Queue_chq, criaCheque( criaValor(valor),
							  			 			criaReferencia(refc),
						   	  			 			criaReferencia(refe),
						   	  			 			criaReferencia(refb));

				if !(clienteValido( procuraElemento( criaReferencia(refe) )))
					/* se o cliente emissor nao existir, cria um cliente com essa referencia*/	
					insereElemento(Client_base , criaCliente(criaReferencia(refe)));

				if !(clienteValido( procuraElemento( criaReferencia(refb) )))
					/* se o cliente benefeciente nao existir, cria um cliente com essa referencia*/	
					insereElemento(Client_base , criaCliente(criaReferencia(refb)));

				mudaEmit(procuraElemento( criaReferencia(refe)) , 1, criaValor(valor));
				mudaReceb(procuraElemento( criaReferencia(refb)), 1, criaValor(valor));
				break;

			case 8:
			/*processa*/
				if /*numero de cheques == 0, não há cheques para processar*/
					printf("Nothing to process\t");
				else
				mudaEmit(/*procura na arvore o cliente*/criaReferencia(refe), -1, criaValor(valor));
				mudaReceb(/*procura na arvore o cliente*/criaReferencia(refb), -1, criaValor(valor));
				/* preciso de ir buscar os valores e ref do cheque devolvido*/
				
				break;

			case 9:
			/*processaR*/
				scanf("%ld",&refc);
				search_and_destroy(Queue_chq, criaReferencia(refc));
				/* preciso de ir buscar o valor e refs do cheque devolvido*/
				break;

			case 10:
			/*infocheque*/
				scanf("%ld",&refc);
				printf("Cheque-info: ");
				escreveCheque(search_fila(Queue_chq, criaReferencia(refc)));
				putchar('\t');
				break;

			case 11:
			/*infocliente*/
				scanf("%d",&refc); /*refc neste caso stands for referencia cliente*/
				printf("Cheque-info: ");
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