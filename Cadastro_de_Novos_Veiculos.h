#ifndef Cadastro_de_Novos_Veiculos_H
#define Cadastro_de_Novos_Veiculos_H

typedef struct Veiculos {
		char placaDoVeiculo[100],modeloDoCarro[100],anoDeFabricacao[100],estadoDoCarro[100];
		unsigned long  int KM;
		int emLocacao;
		int codigoFilial;
		
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
int Cadastro_de_Novos_Veiculos (Veiculos * cadastro_veiculos, int Indice, Filiais * filial, int Indice_filiais){
	Veiculos novo;

	int condicional=1, i=0;
	
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
			fgets(novo.placaDoVeiculo,101,stdin);
			puts("=============================================================================");
			puts("=============================================================================");
			
			puts ("Digite O modelo do Veículo");
			fgets(novo.modeloDoCarro,101,stdin);
			puts("=============================================================================");
			puts("=============================================================================");

			puts ("Digite O ano de fabricação do Veículo");
			fgets(novo.anoDeFabricacao,101,stdin);
			puts("=============================================================================");
			puts("=============================================================================");				

			puts ("Digite O estado do carro");
			fgets(novo.estadoDoCarro,101,stdin);
			puts("=============================================================================");
			puts("=============================================================================");	

			puts ("Digite A quilometragem do carro (só Número)");
			scanf("%lu",&novo.KM);
			puts("=============================================================================");
			puts("=============================================================================");	
		
			puts ("Digite código da filial");
			scanf("%d",&novo.codigoFilial);
			puts("=============================================================================");
			puts("=============================================================================");	
		
			condicional=0;
			//percorrer o vetor em busca da placa
			for(i = 0; i <= Indice; i++){
				if(strcmp(novo.placaDoVeiculo,cadastro_veiculos[i].placaDoVeiculo)==0){
					printf("placa já está cadastrada\n");
					condicional=0;
					break;
				}
			}

			//percorrer o vetor em busca da placa
			for(i = 0; i <= Indice_filiais; i++){
				if(novo.codigoFilial == filial[i].codigoFilial){
					printf("filial existe!!\n");
					condicional++;
					break;
				}
			}

			if(condicional == 1 ){
				Indice++;
				strcpy(cadastro_veiculos[Indice].placaDoVeiculo , novo.placaDoVeiculo );
				strcpy(cadastro_veiculos[Indice].modeloDoCarro , novo.modeloDoCarro );
				strcpy(cadastro_veiculos[Indice].anoDeFabricacao , novo.anoDeFabricacao );
				strcpy(cadastro_veiculos[Indice].estadoDoCarro , novo.estadoDoCarro );
				cadastro_veiculos[Indice].KM = novo.KM;						
				cadastro_veiculos[Indice].codigoFilial = novo.codigoFilial;						
			}
			condicional = 1;
		}
		getchar();
	}
	return Indice;
}

void listarVeiculos(Veiculos * veiculos, int Indice){
	int i = 0;
	while(i<=Indice){
		printf("\tVeiculo número:%d\n",i );
		printf("\tModelo:%s\n",veiculos[i].modeloDoCarro);
		printf("\tPlaca:%s\n",veiculos[i].placaDoVeiculo);
		i++;
	}
}



#endif 
