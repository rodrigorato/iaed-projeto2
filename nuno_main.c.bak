#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "cheques.h"
#include "clientes.h"
#include "avl.h"
#include "fila.h"

/* Funcoes do programa e respectivas ordem de input
void cria_cheque(valor, refe, refb, refc);
void processsa();
void processaR(int refc);
void infocheque(int refc);
void infocliente(int refc);
void info();
void sair();*/


short int command_aux(char command_str[]){
	/*funcao auxiliar ao menu que calcula o comprimento do comando
	0 se for sair,se nao, tamanho do comando*/
	int valor = strcmp(command_str,"sair");
	if (valor == 0)
		return 0;
	return strlen(command_str);
}


int main(){
	/*criacao da fila e da arvore*/
	fila* Queue_chq = nova_fila();
	arvore* Client_base = novaArvore();

	/* maior comando sera infocliente, que tem 11 caracteres + 1(null byte)*/
	/*decalracao das variaveis*/
	char command_str[12];
	short int commandval;
	Val valor;
	Ref refc, refe, refb;
	Cli cle, clb;
	Chq ch;
	/*1a iteracao da decisao do comando*/
	scanf("%s",command_str);
	commandval = command_aux(command_str);

	while(commandval != 0){
		switch(commandval){
			case 6: 
			/*criar cheque, cheque <valor> <refemitente> <refbenefeciente> <refcheque>*/
				valor = leValor();
				refe = leReferencia(); refb = leReferencia(), refc = leReferencia();
				if(comparaReferencia(refe, refb)){
					/*apenas cria o cheque se as referencias forem diferentes
					caso nao especificado no enunciado. Nao imprime nada*/
					insertCheck( Queue_chq, criaCheque( valor, refc, refe, refb));
					cle=procuraElemento(Client_base, refe);
					clb=procuraElemento(Client_base, refb);
					/*se o cliente emissor ou benificiente nao existir, são criaddos novos clientes
					os 1os sao libertos se forem invalidos(nao existirem)*/
					if (!clienteValido(cle)){
						libertaCliente(cle);
						cle=criaCliente(refe);
						insereElemento(Client_base , cle);
					}
					if (!clienteValido(clb)){
						libertaCliente(clb);
						clb=criaCliente(refb );
						insereElemento(Client_base , clb);
					}
					/*certamente que existem, logo pode se alterar os seus valores*/
					mudaEmit(cle, 1, valor);
					mudaReceb(clb, 1, valor);
				}
				break;

			case 8:
			/*processa o 1o cheque da fila, processa*/
				if (fila_vazia(Queue_chq)) printf("Nothing to process\n");
				else{
					/*retira o 1o da fila e guarda-o fazendo as respectivas mudancas aos
					clientes, sendo que se um deles ficar com o numero de cheques emitidos
					e numero de cheques que e benfactor, esse cliente e retirado da 
					arvore*/
					ch=tira_first(Queue_chq);
					cle = procuraElemento(Client_base, refeCheque(ch));
					clb = procuraElemento(Client_base, refbCheque(ch));
					mudaEmit(cle,-1,-valorCheque(ch));
					mudaReceb(clb,-1,-valorCheque(ch));
					if( (!nemitCliente(cle)) && (!nrecebCliente(cle)) )
						apagaElemento(Client_base, referenciaCliente(cle));

					if( (!nemitCliente(clb)) && (!nrecebCliente(clb)) )
						apagaElemento(Client_base, referenciaCliente(clb));

					libertaCheque(ch);
				}
				break;

			case 9:
			/*processa o cheque da referencia recebida, processaR <refcheque>*/
				refc=leReferencia();
				/*le a referencia e procura o cheque na fila retirando o logo*/
				ch=search_and_destroy(Queue_chq, refc);
				if (!chequeValido(ch)){
					printf("Cheque ");
					escreveReferencia(refc);
					printf(" does not exist\n");
				}
				else{
					/*cheque existe, logo clientes existem e os seus valores podem
					ser alterados. Se um dos clientes ficar com os numeros a zero
					e apagado da base de clientes*/
					cle = procuraElemento(Client_base, refeCheque(ch));
					clb = procuraElemento(Client_base, refbCheque(ch));

					mudaEmit(cle,-1,-valorCheque(ch));
					mudaReceb(clb,-1,-valorCheque(ch));


					if( (!nemitCliente(cle)) && (!nrecebCliente(cle)) )
						apagaElemento(Client_base, referenciaCliente(cle));

					if( (!nemitCliente(clb)) && (!nrecebCliente(clb)) )
						apagaElemento(Client_base, referenciaCliente(clb));

				}
				libertaCheque(ch);
				break;

			case 10:
			/*info cheque, infocheque <refcheque>*/
				refc=leReferencia();
				printf("Cheque-info: ");
				/*procura o na fila e imprime o*/
				imprimeCheque(search_fila(Queue_chq,refc));
				putchar('\n');
				break;

			case 11:
			/*info cliente, infocliente <refcliente>*/
				refc=leReferencia();
				printf("Cliente-info: ");
				/*procura o na base de clientes e imprime os seus valores*/
				imprimeCliente(procuraElemento(Client_base,refc));
				putchar('\n');
				break;

			case 4:
			/*imprime os valores dos clientes ordenados ascendente de referencia
			se nao existir clientes, imprime No active Clients, info*/
				if (!numElementos(Client_base)) printf("No active clients\n");
				else escreveClientesInorder(Client_base);
				break;

		}
		scanf("%s",command_str);
		commandval = command_aux(command_str);
	}
	/*ao sair, escreve o num de clientes, numero de cheques e o valor dos
	cheques por processar. Apaga a fila e a arvore tambem*/
	printf("%d %d ",numElementos(Client_base),	conta_cheques(Queue_chq));
	escreveValor(apaga_fila(Queue_chq));
	putchar('\n');
	cutdownArvore(Client_base);
	return 0;
}