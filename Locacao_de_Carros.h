#ifndef Locacao_de_Carros_H
#define Locacao_de_Carros_H

typedef struct Locacao {
		unsigned long  int KM,custoInicial,custoKM;
		int codigoFilial,custoLocacao;
		char placaDoVeiculo[100],dataLocacao[16];

		
		
	}Locacao;

int Locacao_de_Carros();

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "MovimentarCarros.h"
#include "Locacao_de_Carros.h"
#include "Cadastro_de_Novos_Veiculos.h"
#include "CadastrodeNovosClientes.h"
#include "Cadastro_de_Novas_Filiais.h"
int Locacao_de_Carros (){

	FILE *Locacao_de_Carros;
	Locacao_de_Carros = fopen("Locacao_de_Carros.txt","w");
	if (Locacao_de_Carros == NULL){
		puts("Erro na Abertura do Arquivo \n");

		exit(1);
	}

	Locacao cadastro[200];
	Clientes cadastros [200];

	int condicional=1,Indice=0;
		
		while (condicional>0){
			puts("=============================================================================");
			puts("=============================================================================");
			puts("DESEJA REALIZAR NOVA LOCAÇÃO ? {1} PARA SIM! {0} PARA NAO!");
			scanf("%d",&condicional);
			puts("=============================================================================");
			puts("=============================================================================");
			getchar();

				if (condicional>0){

					puts("=============================================================================");
					puts("=============================================================================");
					puts("Digite o código da filial");
					scanf("%d",&cadastro[Indice].codigoFilial);
					getchar();
					puts("=============================================================================");
					puts("=============================================================================");
					puts("Digite a placa do carro escolido");
					fgets(cadastro[Indice].placaDoVeiculo,101,stdin);
					puts("=============================================================================");
					puts("=============================================================================");
					puts("Digite o KM inicial ");
					scanf("%lu",&cadastro[Indice].KM);
					puts("=============================================================================");
					puts("=============================================================================");
					puts("Digite a data de locação ");
					fgets(cadastro[Indice].dataLocacao,17,stdin);
					puts("=============================================================================");
					puts("=============================================================================");
					puts("Digite o numero do cadastro ( Separado por espaço )");
					scanf("%d %d %d %d",&cadastros[Indice].identificador[0],&cadastros[Indice].identificador[1],&cadastros[Indice].identificador[2],&cadastros[Indice].identificador[3]);
					puts("=============================================================================");
					puts("=============================================================================");
					
					puts("Digite o custo inicial de locação e o custo por KM rodado ");
					scanf("%lu %lu",&cadastro[Indice].custoInicial,&cadastro[Indice].custoKM);
					puts("=============================================================================");
					puts("=============================================================================");
					
				
				}

		}Indice++;

return 0;
}



#endif 
