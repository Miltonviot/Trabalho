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

int MovimentarCarros (){

	FILE *MovimentarCarros;
	MovimentarCarros = fopen("MovimentarCarros.txt","w");
	if (MovimentarCarros == NULL){
		puts("Erro na Abertura do Arquivo \n");

		exit(1);
	}

	Movimentar cadastro[200];

	int condicional=1,Indice=0;
		
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
				}
			}Indice++;
return 0;
}



#endif 