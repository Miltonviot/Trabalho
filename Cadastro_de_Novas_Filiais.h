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

int Cadastro_de_Novas_Filiais (Filiais * cadastro, int Indice){
	int condicional=1,i;
	Filiais novo;		

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
			scanf("%d",&novo.codigoFilial);
			puts("=============================================================================");
			puts("=============================================================================");
			getchar();
			puts ("Digite a cidade da filial");
			fgets(novo.cidadeFilial,101,stdin);
			puts("=============================================================================");
			puts("=============================================================================");					
			for(i = 0; i <= Indice; i++){
				if(novo.codigoFilial == cadastro[i].codigoFilial){
					condicional = 0;
					break;
				}
			}
			if(condicional != 0){
				Indice++;
				cadastro[Indice].codigoFilial = novo.codigoFilial;
				strcpy(cadastro[Indice].cidadeFilial , novo.cidadeFilial);
			}

		}
		getchar();
	}
	return Indice;	
}
#endif 