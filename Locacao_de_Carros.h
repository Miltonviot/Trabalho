#ifndef Locacao_de_Carros_H
#define Locacao_de_Carros_H

typedef struct Locacao {
		unsigned long  int KM, custoInicial, custoKM;
		int codigoFilial, custoLocacao, codigo_cliente[5],codigoLocacao;
		char placaDoVeiculo[100], dataLocacao[16];		
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
int Locacao_de_Carros (Locacao * locacao, int Indice, Clientes * clientes,int Indice_clientes, Filiais * filiais, int Indice_filiais, Veiculos * veiculos, int Indice_veiculos){

	Locacao novo;	
	int condicional=1, i,x, emLocacao;
		
	while (condicional>0){
		puts("=============================================================================");
		puts("=============================================================================");
		puts("DESEJA REALIZAR NOVA LOCAÇÃO ? {1} PARA SIM! {0} PARA NAO!");
		scanf("%d",&condicional);
		puts("=============================================================================");
		puts("=============================================================================");
		getchar();

		if (condicional>0){
			/*
			puts("=============================================================================");
			puts("=============================================================================");
			puts("Digite o código da filial");
			scanf("%d",&novo.codigoFilial);
			getchar();*/
			puts("=============================================================================");
			puts("=============================================================================");
			puts("Digite a placa do carro escolido");
			fgets(novo.placaDoVeiculo,101,stdin);
			puts("=============================================================================");
			puts("=============================================================================");
			/*
			puts("Digite o KM inicial ");
			scanf("%lu",&novo.KM);
			puts("=============================================================================");
			puts("=============================================================================");*/
			puts("Digite a data de locação ");
			fgets(novo.dataLocacao,17,stdin);
			puts("=============================================================================");
			puts("=============================================================================");
			
			puts("Digite o numero do cadastro do locatario");
			char *cpfc = (char*)malloc(sizeof(5));
			fgets(cpfc,101,stdin);	// preguiça de renomear ta passando código nao cpf
			int  identificador[5];
			printf("%s\n", cpfc);
			converte_char_to_int(cpfc,identificador,5);
					
			puts("=============================================================================");
			puts("=============================================================================");
			
			puts("Digite o custo inicial de locação e o custo por KM rodado ");
			scanf("%lu %lu",&novo.custoInicial,&novo.custoKM);
			puts("=============================================================================");
			puts("=============================================================================");

			condicional = 0;
			//verificar se existe filial
			for(i = 0; i <= Indice_filiais; i++){
				printf("código = %d\n", filiais[i].codigoFilial);
				if(novo.codigoFilial == filiais[i].codigoFilial){
					condicional++;
					break;
				}
			}

			//verificar se existe veículo e se ele já está locado
			for(i = 0; i <= Indice_veiculos; i++){
				printf("Placa = %s\n", veiculos[i].placaDoVeiculo);
				if(strcmp(novo.placaDoVeiculo, veiculos[i].placaDoVeiculo)==0){
					if(veiculos[i].emLocacao == 0){
						condicional++;
						emLocacao = i;
						break;
					}
				}
			}

			//verificar se existe cliente
			int x;
			for(x = 0; x <= Indice_clientes; x++){

				for(i = 0; i < 5; i++){
					printf("Identificador = %d", clientes[x].identificador[i]);
					if(novo.codigo_cliente[i] == clientes[x].identificador[i]){
						condicional++;
					}
				}
			}
			
			printf("condicional = %d\n",condicional );
			if(1){//existe filial, veículo e cliente.
				Indice++;
				locacao[Indice].codigoFilial  = novo.codigoFilial;
				strcpy(locacao[Indice].placaDoVeiculo, novo.placaDoVeiculo);
				for(i = 0; i < 5; i++)
					locacao[Indice].codigo_cliente[i] = identificador[i];
				locacao[Indice].KM = novo.KM;
				strcpy(locacao[Indice].dataLocacao, novo.dataLocacao);
				locacao[Indice].custoInicial = novo.custoInicial;
				locacao[Indice].codigoLocacao = Indice;
				locacao[Indice].custoKM = novo.custoKM;
				veiculos[emLocacao].emLocacao = 1;
			}
		}
	}
	return Indice;
}

int encerrar_Locacao_de_Carros (Locacao * locacao, int Indice, Clientes * clientes, Filiais * filiais, Veiculos * veiculos, int Indice_veiculos){

	Locacao novo;	
	int condicional=1, i, emLocacao;
		
	while (condicional>0){
		puts("=============================================================================");
		puts("=============================================================================");
		puts("DESEJA ENCERRAR UMA LOCAÇÃO ? {1} PARA SIM! {0} PARA NAO!");
		scanf("%d",&condicional);
		puts("=============================================================================");
		puts("=============================================================================");
		getchar();

		if (condicional>0){


			puts("=============================================================================");
			puts("=============================================================================");
			puts("Digite o código da Locacao");
			scanf("%d",&novo.codigoLocacao);

			puts("=============================================================================");
			puts("=============================================================================");
			puts("Digite a KM Final ");
			scanf("%lu",&novo.KM);

			
			condicional = 0;
			
			//verificar se existe locação
			for(i = 0; i <= Indice_veiculos; i++){
				if(strcmp(novo.placaDoVeiculo, locacao[i].placaDoVeiculo)==0){
					condicional++;
					emLocacao = i;
				}
			}

			for(i=0; i<Indice; i++){
				if(novo.codigoLocacao =locacao[i].codigoLocacao){
					break;
				}
			}

			if(condicional == 1){//existe filial, veículo e cliente.
				printf("%d\n",novo.codigoFilial);
				printf("%s\n",locacao[Indice].placaDoVeiculo);
				for(i = 0; i < 5; i++)
					printf("%d\n",locacao[Indice].codigo_cliente[i]);
				printf("Custo inicial %lu\n",locacao[Indice].custoInicial );
				printf("KM inicial%lu\n", locacao[Indice].KM);
				printf("KM final%lu\n",novo.KM );
				printf("Custo por KM%lu\n",locacao[Indice].custoKM);
				printf("Custo final = %lu\n",(novo.KM-locacao[Indice].KM )* locacao[Indice].custoKM + locacao[Indice].custoInicial);				
				
				locacao[Indice].codigoLocacao = Indice;
				locacao[Indice].custoLocacao =(novo.KM-locacao[Indice].KM )* locacao[Indice].custoKM + locacao[Indice].custoInicial;
		
				veiculos[emLocacao].KM += novo.KM;
				veiculos[emLocacao].emLocacao = 0;
			}
		}
	}
	return Indice;
}


void listarLocacoes(Locacao * locacao, int Indice){
	int i =0 ;
	printf("%d\n",i );
	while(i<=Indice){
		printf("\tLocacao número:%d\n",i);
		printf("\tPlaca:%s\n",locacao[i].placaDoVeiculo);
		printf("\tCódigo do Cliente:");
		for (int a=0;a<5;a++)
			printf("[%d]",locacao[i].codigo_cliente[a]);
		printf("\n\tData de locação:%s\n\n",locacao[i].dataLocacao);
		
		i++;
	}
}
#endif 
