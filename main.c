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
	/*TO-DO: All the stuff lolol*/
	/*
	/* maior comando sera infocliente, que tem 11 caracteres + 1(null byte)*/
	char command_str[12];
	short int commandval;
	Val valor;
	Ref refc, refe, refb;
	Cli cle, clb;
	Chq c;
	scanf("%s",command_str);
	commandval = command_aux(command_str);
	while(commandval != 0){
		switch(commandval){
			case 6: 
			/*cheque*/
				valor = leValor();
				refe = leReferencia(); refb = leReferencia(), refc = leReferencia();
				insertCheck( Queue_chq, criaCheque( valor, refc, refe, refb));
				cle=procuraElemento(Client_base, refe);
				clb=procuraElemento(Client_base, refb);

				if !(clienteValido( cle))
					/* se o cliente emissor nao existir, cria um cliente com essa referencia*/	
					insereElemento(Client_base , criaCliente(refe));

				if !(clienteValido( clb))
					/* se o cliente benefeciente nao existir, cria um cliente com essa referencia*/	
					insereElemento(Client_base , criaCliente( refb ));

				mudaEmit(cle, 1, valor);
				mudaReceb(clb, 1, valor);
				break;

			case 8:
			/*processa*/
				if (fila_vazia(Queue_chq)) printf("Nothing to process\t");
				else{
					ch=tira_first(Queue_chq);
					cle=procuraElemento(Client_base, refeCheque(ch));
					clb=procuraElemento(Client_base, refbCheque(ch));
					mudaEmit(cle,-1,-valorCheque(ch));
					mudaReceb(clb,-1,-valorCheque(ch));
				}
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