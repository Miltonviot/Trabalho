#ifndef CadastrodeNovosClientes_H
#define CadastrodeNovosClientes_H


typedef struct Clientes {
		char primeiroNome[100],UltimoNome[100],endereco[100],senha[7];

		unsigned int CPF[11];

		int identificador[5];
		
	}Clientes;


int CadastrodeNovosClientes(Clientes *cadastro );
void imprime_clientes(Clientes *cadastro, int indice);

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "MovimentarCarros.h"
#include "Locacao_de_Carros.h"
#include "Cadastro_de_Novos_Veiculos.h"
#include "CadastrodeNovosClientes.h"
#include "Cadastro_de_Novas_Filiais.h"



int CadastrodeNovosClientes(Clientes *cadastro, int Indice ) {

	FILE *Cadastro_de_Novos_Cliente;
	Cadastro_de_Novos_Cliente = fopen("Cadastro_de_Novos_Cliente.txt","w");
	if (Cadastro_de_Novos_Cliente == NULL){
		puts("Erro na Abertura do Arquivo \n");
		exit(1);   		
	}
	int aux=0;

	//Clientes cadastro [200];
	int condicional=1;
	//,Indice=0;

	//while (condicional>0){
		puts("=============================================================================");
		puts("=============================================================================");
		puts("DESEJA REALIZAR CADASTRO DE NOVOS CLIENTES ? {1} PARA SIM! {0} PARA NAO!");
	//	scanf("%d",&condicional);
		puts("=============================================================================");
		puts("=============================================================================");
		
		getchar();
	//	if(condicional >0){

			puts("=============================================================================");
			puts("=============================================================================");
			puts ("Digite o Primeiro nome do clinte ");
			fgets(cadastro[Indice].primeiroNome,101,stdin);
			puts("=============================================================================");
			puts("=============================================================================");
			
			int i=0;
			puts ("Digite o CPF  do clinte ");
				for(i=0;i<11;i++){
					scanf("%u",&cadastro[Indice].CPF[i]);	
				}getchar();
			puts("=============================================================================");
			puts("=============================================================================");

			puts ("Digite o Ultimo nome do clinte ");
			fgets(cadastro[Indice].UltimoNome,101,stdin);
			
			puts("=============================================================================");
			puts("=============================================================================");

			puts ("Digite A Senha do clinte (6 digitos) ");
			fgets(cadastro[Indice].senha,7,stdin);	
			getchar();
			
			puts("=============================================================================");
			puts("=============================================================================");
			getchar();
			puts ("Digite o Endereço do clinte ");
			fgets(cadastro[Indice].endereco,101,stdin);		
					
			
			puts("=============================================================================");
			puts("=============================================================================");

			puts("Digite o numero do cadastro ( Separado por espaço )");
			scanf("%d %d %d %d",&cadastro[Indice].identificador[0],&cadastro[Indice].identificador[1],&cadastro[Indice].identificador[2],&cadastro[Indice].identificador[3]);
			
			puts("=============================================================================");
			puts("=============================================================================");
			

			aux=((cadastro[Indice].identificador[0]*9)+(cadastro[Indice].identificador[1]*8)+(cadastro[Indice].identificador[2]*7)+(cadastro[Indice].identificador[3]*6));

				if (aux%11==0){
					
					aux=0;

				}else aux=1;
				
			
		/*	
		fprintf(Cadastro_de_Novos_Cliente, "\t=============================================================================\n");
		fprintf(Cadastro_de_Novos_Cliente, "\t=============================================================================\n");
		fprintf(Cadastro_de_Novos_Cliente, "\tCliente número:%d\n",Indice );
		fprintf(Cadastro_de_Novos_Cliente,"\tPrimeiro Nome:%s\n",cadastro[Indice].primeiroNome);
		fprintf(Cadastro_de_Novos_Cliente,"\tUltimo Nome:%s\n",cadastro[Indice].UltimoNome);
		fprintf(Cadastro_de_Novos_Cliente,"\tEndereço:%s\n",cadastro[Indice].endereco);
		fprintf(Cadastro_de_Novos_Cliente,"\tSenha:%s\n",cadastro[Indice].senha);
		fprintf(Cadastro_de_Novos_Cliente,"\tCPF:");
			for(i=0;i<11;i++){
				fprintf(Cadastro_de_Novos_Cliente,"%u",cadastro[Indice].CPF[i]);
			}printf("\n");
		fprintf(Cadastro_de_Novos_Cliente,"\n\tNumero da Conta:%d %d %d %d %d \n", cadastro[Indice].identificador[0],cadastro[Indice].identificador[1],cadastro[Indice].identificador[2],cadastro[Indice].identificador[3],aux);
		fprintf(Cadastro_de_Novos_Cliente, "\t=============================================================================\n");
		fprintf(Cadastro_de_Novos_Cliente, "\t=============================================================================\n");*/
		//Indice++;
		//}
		
	//}
fclose(Cadastro_de_Novos_Cliente);

return 0;

}

void imprime_clientes(Clientes *cadastro, int indice){
	int i;
	while(indice>=0){
		printf("\tCliente número:%d\n",indice );
		printf("\tPrimeiro Nome:%s\n",cadastro[indice].primeiroNome);
		printf("\tUltimo Nome:%s\n",cadastro[indice].UltimoNome);
		printf("\tEndereço:%s\n",cadastro[indice].endereco);
		printf("\tSenha:%s\n",cadastro[indice].senha);
		printf("\tCPF:");
			for(i=0;i<11;i++){
				printf("%u",cadastro[indice].CPF[i]);
			}printf("\n");
		printf("\n\tNumero da Conta:%d %d %d %d \n", cadastro[indice].identificador[0],cadastro[indice].identificador[1],cadastro[indice].identificador[2],cadastro[indice].identificador[3]);
		printf("\t=============================================================================\n");
		printf( "\t=============================================================================\n");
		indice--;		
	}
}
	
#endif

