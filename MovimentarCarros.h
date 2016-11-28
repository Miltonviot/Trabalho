//MovimentarCarros

#ifndef MovimentarCarros_H
#define MovimentarCarros_H

typedef struct Movimentar {
		int codigoFilial;
		char placaDoVeiculo[100];

		
		
	}Movimentar;

int MovimentarCarros();

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "MovimentarCarros.h"
#include "Locacao_de_Carros.h"
#include "Cadastro_de_Novos_Veiculos.h"
#include "CadastrodeNovosClientes.h"
#include "Cadastro_de_Novas_Filiais.h"

int MovimentarCarros (Movimentar *cadastro, int Indice, Filiais * filiais, Veiculos * veiculos){

	Movimentar novo;
	int emLocacao;

	int condicional=1,i;
	
	while (condicional>0){
		puts("=============================================================================");
		puts("=============================================================================");
		puts("DESEJA REALIZAR TRANSFERENCIA ENTRE FILIAIS? {1} PARA SIM! {0} PARA NAO!");
		scanf("%d",&condicional);
		puts("=============================================================================");
		puts("=============================================================================");
		getchar();

		if (condicional>0){

			puts("=============================================================================");
			puts("=============================================================================");		
			puts("Digite a placa do carro escolido");
			fgets(cadastro[Indice].placaDoVeiculo,101,stdin);
			puts("=============================================================================");
			puts("=============================================================================");
			puts ("Digite o código da filial");
			scanf("%d",&cadastro[Indice].codigoFilial);
			puts("=============================================================================");
			puts("=============================================================================");

			condicional = 0;
			//verificar se existe filial
			for(i = 0; i <= Indice; i++){
				if(novo.codigoFilial == filiais[i].codigoFilial){
					condicional++;
				}
			}

			//verificar se existe veículo
			for(i = 0; i <= Indice; i++){
				if(strcmp(novo.placaDoVeiculo, veiculos[i].placaDoVeiculo)==0){
					condicional++;
					emLocacao = i;
				}
			}
			if(condicional == 2){//existe filial e veículo
				Indice++;
				cadastro[Indice].codigoFilial  = novo.codigoFilial;
				strcpy(cadastro[Indice].placaDoVeiculo, novo.placaDoVeiculo);
			}
		}
	}
return Indice;
}

void listarMovimentos(Movimentar * cadastro, int Indice){
	int i = Indice;
	while(i>=0){
		printf("\tMovimentação número:%d\n",i );
		printf("\tPlaca:%s\n",cadastro[i].placaDoVeiculo);
		printf("\tCódigo do filial:%d\n",cadastro[i].codigoFilial);
		i--;
	}
}


#endif 