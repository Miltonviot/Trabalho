#ifndef Cadastro_de_Novos_Veiculos_H
#define Cadastro_de_Novos_Veiculos_H

typedef struct Veiculos {
		char placaDoVeiculo[100],modeloDoCarro[100],anoDeFabricacao[100],estadoDoCarro[100];
		unsigned long  int KM;
		int emLocacao;
		
	}Veiculos;

	int Cadastro_de_Novos_Veiculos();	
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "MovimentarCarros.h"
#include "Locacao_de_Carros.h"
#include "Cadastro_de_Novos_Veiculos.h"
#include "CadastrodeNovosClientes.h"
#include "Cadastro_de_Novas_Filiais.h"
int Cadastro_de_Novos_Veiculos (){

	FILE *Cadastro_de_Novos_Veiculos;
	Cadastro_de_Novos_Veiculos = fopen("Cadastro_de_Novos_Veiculos.txt","w");
	if (Cadastro_de_Novos_Veiculos == NULL){
		puts("Erro na Abertura do Arquivo \n");

		exit(1);
	}
	Veiculos cadastro[200];

	int condicional=1,Indice=0;
		
		while (condicional>0){
			puts("=============================================================================");
			puts("=============================================================================");
			puts("DESEJA REALIZAR CADASTRO DE NOVO VEÍCULO ? {1} PARA SIM! {0} PARA NAO!");
			scanf("%d",&condicional);
			puts("=============================================================================");
			puts("=============================================================================");
			getchar();
		
				if (condicional >0){
					puts ("Digite A Placa do Veículo");
					fgets(cadastro[Indice].placaDoVeiculo,101,stdin);
					puts("=============================================================================");
					puts("=============================================================================");
					
					puts ("Digite O modelo do Veículo");
					fgets(cadastro[Indice].modeloDoCarro,101,stdin);
					puts("=============================================================================");
					puts("=============================================================================");


					puts ("Digite O ano de fabricação do Veículo");
					fgets(cadastro[Indice].anoDeFabricacao,101,stdin);
					puts("=============================================================================");
					puts("=============================================================================");
						

					puts ("Digite o estado do carro");
					fgets(cadastro[Indice].estadoDoCarro,101,stdin);
					puts("=============================================================================");
					puts("=============================================================================");	

					puts ("Digite a quilometragem do carro (só Número)");
					scanf("%lu",&cadastro[Indice].KM);
					puts("=============================================================================");
					puts("=============================================================================");	



					printf("%s\n",cadastro[Indice].placaDoVeiculo );
					printf("%s\n",cadastro[Indice].modeloDoCarro );
					printf("%s\n",cadastro[Indice].anoDeFabricacao );
					printf("%s\n",cadastro[Indice].estadoDoCarro );
					printf("%.2lu\n",cadastro[Indice].KM );
					Indice++;
				}getchar();
		}
fclose(Cadastro_de_Novos_Veiculos);
return 0;

}
#endif 