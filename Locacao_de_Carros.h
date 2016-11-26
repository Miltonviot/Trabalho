#ifndef Locacao_de_Carros_H
#define Locacao_de_Carros_H

typedef struct Locacao {
		unsigned long  int KM, custoInicial, custoKM;
		int codigoFilial, custoLocacao, codigo_cliente[4];
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
int Locacao_de_Carros (Locacao * locacao, int Indice, Clientes * clientes, Filiais * filiais, Veiculos * veiculos){

	Locacao novo;	
	int condicional=1, i, emLocacao;
		
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
			scanf("%d",&novo.codigoFilial);
			getchar();
			puts("=============================================================================");
			puts("=============================================================================");
			puts("Digite a placa do carro escolido");
			fgets(novo.placaDoVeiculo,101,stdin);
			puts("=============================================================================");
			puts("=============================================================================");
			puts("Digite o KM inicial ");
			scanf("%lu",&novo.KM);
			puts("=============================================================================");
			puts("=============================================================================");
			puts("Digite a data de locação ");
			fgets(novo.dataLocacao,17,stdin);
			puts("=============================================================================");
			puts("=============================================================================");
			puts("Digite o numero do locacao ( Separado por espaço )");
			scanf("%d %d %d %d",&novo.codigo_cliente[0],&novo.codigo_cliente[1],&novo.codigo_cliente[2],&novo.codigo_cliente[3]);
			puts("=============================================================================");
			puts("=============================================================================");
			
			puts("Digite o custo inicial de locação e o custo por KM rodado ");
			scanf("%lu %lu",&novo.custoInicial,&novo.custoKM);
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
					if(veiculos[i].emLocacao == 0){
						condicional++;
						emLocacao = i;
					}
				}
			}

			//verificar se existe cliente
			for(int x = 0; x <= Indice; x++){
				for(i = 0; i < 4; i++){
					if(novo.codigo_cliente[i] == clientes[x].identificador[i]){
						condicional++;
					}
				}
			}
			
			//verificar se existe veículo
			for(i = 0; i <= Indice; i++){
				if(strcmp(novo.placaDoVeiculo, locacao[i].placaDoVeiculo)==0){
					condicional++;
					emLocacao = i;
				}
			}

			if(condicional == 3){//existe filial, veículo e cliente.
				Indice++;
				locacao[Indice].codigoFilial  = novo.codigoFilial;
				strcpy(locacao[Indice].placaDoVeiculo, novo.placaDoVeiculo);
				for(i = 0; i < 4; i++)
					locacao[Indice].codigo_cliente[i] = novo.codigo_cliente[i];
				locacao[Indice].KM = novo.KM;
				strcpy(locacao[Indice].dataLocacao, novo.dataLocacao);
				locacao[Indice].custoInicial = novo.custoInicial;
				locacao[Indice].custoKM = novo.custoKM;
				veiculos[emLocacao].emLocacao = 1;
			}
		}
	}
	return Indice;
}

int encerrar_Locacao_de_Carros (Locacao * locacao, int Indice, Clientes * clientes, Filiais * filiais, Veiculos * veiculos){

	Locacao novo;	
	int condicional=1, i, emLocacao;
		
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
			puts("Digite a KM Final ");
			scanf("%lu",&novo.KM);
			puts("=============================================================================");
			puts("=============================================================================");
			puts("Digite a data de encerramento ");
			fgets(novo.dataLocacao,17,stdin);
			puts("=============================================================================");
			puts("=============================================================================");
			puts("Digite o numero do locacao ( Separado por espaço )");
			scanf("%d %d %d %d",&novo.codigo_cliente[0],&novo.codigo_cliente[1],&novo.codigo_cliente[2],&novo.codigo_cliente[3]);
			puts("=============================================================================");
			puts("=============================================================================");
			
			
			condicional = 0;
			
			//verificar se existe locação
			for(i = 0; i <= Indice; i++){
				if(strcmp(novo.placaDoVeiculo, locacao[i].placaDoVeiculo)==0){
					condicional++;
					emLocacao = i;
				}
			}

			if(condicional == 3){//existe filial, veículo e cliente.
				Indice++;
				locacao[Indice].codigoFilial  = novo.codigoFilial;
				strcpy(locacao[Indice].placaDoVeiculo, novo.placaDoVeiculo);
				for(i = 0; i < 4; i++)
					locacao[Indice].codigo_cliente[i] = novo.codigo_cliente[i];
				locacao[Indice].KM = novo.KM;
				strcpy(locacao[Indice].dataLocacao, novo.dataLocacao);
				locacao[Indice].custoInicial = novo.custoInicial;
				locacao[Indice].custoKM = novo.custoKM;
				veiculos[emLocacao].emLocacao = 1;
			}
		}
	}
	return Indice;
}


void listarVeiculos(Locacao * locacao, int Indice){
	int i = Indice;
	while(i>=0){
		printf("\tCliente número:%d\n",Indice );
		printf("\tPrimeiro Nome:%s\n",locacao[Indice].placaDoVeiculo);
		printf("\tUltimo Nome:%d\n",locacao[Indice].codigo_cliente[0]);
		printf("\tEndereço:%d\n",locacao[Indice].codigoFilial);
		printf("\tSenha:%s\n",locacao[Indice].dataLocacao);
		i--;
	}
}
#endif 
