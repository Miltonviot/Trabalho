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
int Cadastro_de_Novos_Veiculos (Veiculos * cadastro_veiculos, int Indice){
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

			puts ("Digite o estado do carro");
			fgets(novo.estadoDoCarro,101,stdin);
			puts("=============================================================================");
			puts("=============================================================================");	

			puts ("Digite a quilometragem do carro (só Número)");
			scanf("%lu",&novo.KM);
			puts("=============================================================================");
			puts("=============================================================================");	
		
			//percorrer o vetor em busca da placa
			for(i = 0; i <= Indice; i++){
				if(strcmp(novo.placaDoVeiculo,cadastro_veiculos[i].placaDoVeiculo)==0){
					printf("placa já está cadastrada\n");
					condicional = 0;
					break;
				}
			}
			if(condicional != 0 ){
				Indice++;
				strcpy(cadastro_veiculos[Indice].placaDoVeiculo , novo.placaDoVeiculo );
				strcpy(cadastro_veiculos[Indice].modeloDoCarro , novo.modeloDoCarro );
				strcpy(cadastro_veiculos[Indice].anoDeFabricacao , novo.anoDeFabricacao );
				strcpy(cadastro_veiculos[Indice].estadoDoCarro , novo.estadoDoCarro );
				cadastro_veiculos[Indice].KM = novo.KM;						
				//cadastro_veiculos[Indice].codigoFilial = novo.codigoFilial;						
			}
			condicional = 0;
		}
		getchar();
	}
	return Indice;
}
<<<<<<< HEAD


void listarVeiculos(Veiculos * veiculos, int Indice){
	int i = Indice;
	while(i>=0){
		printf("\tVeiculo número:%d\n",i );
		printf("\tModelo:%s\n",veiculos[i].modeloDoCarro);
		printf("\tPlaca:%s\n",veiculos[i].placaDoVeiculo);
		i--;
	}
}

#endif 
=======
#endif 
>>>>>>> e43dfcdb8a89ab245fad8e822f3737457430d03a
