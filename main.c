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
	Chq ch;
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
				/*se o cliente emissor ou benificiente nao existir, são criaddos novos clientes*/
				if !(clienteValido( cle)){
					cle=criaCliente(refe);
					insereElemento(Client_base , cle);
				}
				if !(clienteValido( clb)){
					clb=criaCliente( refb );
					insereElemento(Client_base , clb);
				}
				mudaEmit(cle, 1, valor);
				mudaReceb(clb, 1, valor);
				break;

			case 8:
			/*processa*/
				if (fila_vazia(Queue_chq)) printf("Nothing to process\n");
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
				refc=leReferencia();
				ch=search_and_destroy(Queue_chq, refc);
				if (!chequeValido(ch)){
					printf("Cheque ");
					escreveReferencia(refc);
					printf(" does not exist\n");
				}
				else{
					cle=procuraElemento(Client_base, refc);
					clb=procuraElemento(Client_base, refc);
					mudaEmit(cle,-1,-valorCheque(ch));
					mudaReceb(clb,-1,-valorCheque(ch));
				}
				break;

			case 10:
			/*infocheque*/
				refc=leReferencia();
				printf("Cheque-info: ");
				imprimeCheque(search_fila(Queue_chq,refc));
				putchar('\n');
				break;

			case 11:
			/*infocliente*/
				refc=leReferencia();/*refc neste caso stands for referencia cliente*/
				printf("Cheque-info: ");
				procuraElemento(Client_base,refc);
				imprimeCliente(procuraElemento(Client_base,refc));
				putchar('\n');
				break;

			case 4:
			/*info*/
				escreveClientesInorder(Client_base);
				break;

			default:
				printf("ERRO - Comando invalido");
				break;
		}
		scanf("%s",command_str);
		commandval = command_aux(command_str);
	}
	printf("%d %d ",numElementos(Client_base),	conta_cheques(Queue_chq));
	escreveValor(apaga_fila(Queue_chq));
	return 0;
}