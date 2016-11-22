#ifndef Cadastro_de_Novas_Filiais_H
#define Cadastro_de_Novas_Filiais_H

typedef struct Filiais {
		char cidadeFilial[100];
		int codigoFilial;
		
		
	}Filiais;

	int Cadastro_de_Novas_Filiais();	

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "MovimentarCarros.h"
#include "Locacao_de_Carros.h"
#include "Cadastro_de_Novos_Veiculos.h"
#include "CadastrodeNovosClientes.h"
#include "Cadastro_de_Novas_Filiais.h"

int Cadastro_de_Novas_Filiais (){

	FILE *Cadastro_de_Novas_Filiais;
	Cadastro_de_Novas_Filiais = fopen("Cadastro_de_Novas_Filiais.txt","w");
	if (Cadastro_de_Novas_Filiais == NULL){
		puts("Erro na Abertura do Arquivo \n");

		exit(1);
	}
	Filiais cadastro[200];

	int condicional=1,Indice=0;
		
		while (condicional>0){

			puts("=============================================================================");
			puts("=============================================================================");
			puts("DESEJA REALIZAR CADASTRO DE NOVA FILIAL ? {1} PARA SIM! {0} PARA NAO!");
			scanf("%d",&condicional);
			puts("=============================================================================");
			puts("=============================================================================");
			getchar();
			if (condicional>0){

					puts("=============================================================================");
					puts("=============================================================================");
					puts ("Digite o código da filial");
					scanf("%d",&cadastro[Indice].codigoFilial);
					puts("=============================================================================");
					puts("=============================================================================");
					getchar();
					puts ("Digite a cidade da filial");
					fgets(cadastro[Indice].cidadeFilial,101,stdin);
					puts("=============================================================================");
					puts("=============================================================================");
					
					fprintf(Cadastro_de_Novas_Filiais, "Código da Filial |%d| Cidade da filial |%s\n",cadastro[Indice].codigoFilial,cadastro[Indice].cidadeFilial );
					
			}
		}Indice++;

return 0;
}
#endif 