/*	  Turno 9 - Grupo 9    *
 *						   *
 *	Alice Dourado   81205  *
 *	Nuno Vieira		81098  *
 *	Rodrigo Rato	81500  *
 *						   */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "cheques.h"
#include "clientes.h"
#include "fila.h"
#include "avl.h"


int comando(char* nome){
	/* Determina qual o comando a executar */
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

void processa_e_actualiza(arvore* clientes_arvore, Chq ch){
	/* Processa um determinado cheque */
	Cli cle, clb;

	cle = procuraElemento(clientes_arvore, refeCheque(ch));
	clb = procuraElemento(clientes_arvore, refbCheque(ch));
					
	mudaEmit(cle, -1, -valorCheque(ch));
	mudaReceb(clb, -1, -valorCheque(ch));

	if(nemitCliente(cle) == 0 && nrecebCliente(cle) == 0)
		apagaElemento(clientes_arvore, referenciaCliente(cle));

	if(nemitCliente(clb) == 0 && nrecebCliente(clb) == 0)
		apagaElemento(clientes_arvore, referenciaCliente(clb));

	libertaCheque(ch);
}

int main(){
	int cod;
	char op[12];

	Val valor;
	Ref refc, refe, refb;
	Cli cle, clb;
	Chq ch;

	fila* cheques_queue = nova_fila();
	arvore* clientes_arvore = novaArvore();
	
	scanf("%s", op);
	while((cod = comando(op)) != 6){
		switch(cod){
			case 0:
				/* A realizar: cheque - adiciona um cheque a pool de cheques*/
				valor = leValor();
				refe = leReferencia(); refb = leReferencia(); refc = leReferencia();
				ch = criaCheque(valor, refc, refe, refb);

				insertCheck(cheques_queue, ch);

				cle = procuraElemento(clientes_arvore, refe);
				if(!cle)
					insereElemento(clientes_arvore, cle = criaCliente(refe));

				clb = procuraElemento(clientes_arvore, refb);	
				if(!clb)
					insereElemento(clientes_arvore, clb = criaCliente(refb));

				mudaEmit(cle, 1, valorCheque(ch)); 
				mudaReceb(clb, 1, valorCheque(ch));
				
				break;
			case 1:
				/* A realizar: processa - processa o cheque mais velho na pool */
				if(fila_vazia(cheques_queue))
					printf("Nothing to process\n");
				else{
					ch = tira_first(cheques_queue);
					processa_e_actualiza(clientes_arvore, ch);
				}

				break;
			case 2:
				/* A realizar: processaR - processa um cheque por referencia */
				refc = leReferencia();
				ch = search_and_destroy(cheques_queue, refc);

				if(!ch){
					printf("Cheque "); escreveReferencia(refc); printf(" does not exist\n");
				}
				else
					processa_e_actualiza(clientes_arvore, ch);

				break;
			case 3:
				/* A realizar: infocheque - escreve a informacao de um determinado cheque */
				refc = leReferencia();
				printf("Cheque-info: ");
				imprimeCheque(search_fila(cheques_queue, refc));
				printf("\n");

				break;
			case 4:
				/* A realizar: infocliente - escreve a informacao de um determinado cliente */
				refe = leReferencia();
				printf("Cliente-info: ");
				imprimeCliente(procuraElemento(clientes_arvore, refe));
				printf("\n");

				break;
			case 5:
				/* A realizar: info - escreve a informacao de todos os clientes no sistema */
				if(numElementos(clientes_arvore) == 0)
					printf("No active clients\n");
				else
					escreveClientesInorder(clientes_arvore);

				break;
			case -1:
				/* A realizar: COMANDO INVALIDO */
				printf("INVALIDO\n");
				break;
		}
		scanf("%s", op);
	}
	
	/* A realizar: sair - escreve a informacao final e liberta toda a memoria associada */
	printf("%d %d ", numElementos(clientes_arvore), conta_cheques(cheques_queue));
	escreveValor(apaga_fila(cheques_queue)); printf("\n");
	cutdownArvore(clientes_arvore);

	return 0;
}