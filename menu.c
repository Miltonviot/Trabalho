#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "MovimentarCarros.h"
#include "Locacao_de_Carros.h"
#include "Cadastro_de_Novos_Veiculos.h"
#include "CadastrodeNovosClientes.h"
#include "Cadastro_de_Novas_Filiais.h"

int main (){

	Clientes cadastro [200];
	int condicional=8,Indice=0;

		while (condicional>0){
			puts("=============================================================================");
			puts("=============================================================================");
			puts("=Digite {0} para sair                                                       =");
			puts("=Digite {1} para Cadastro de Novos Clientes                                 =");
			puts("=Digite {2} para Cadastro de Novos Veiculos                                 =");
			puts("=Digite {3} para Cadastro de Novas Filiais                                  =");
			puts("=Digite {4} para Realizar uma locação                                       =");
			puts("=Digite {5} para Realizar uma transferencia entre Filiais                   =");
			puts("=============================================================================");
			puts("=============================================================================");

			scanf("%d",&condicional);
				if (condicional>0){
					switch (condicional){
					
					case 1:
					
						CadastrodeNovosClientes(cadastro, Indice);
						imprime_clientes(cadastro, Indice);
						Indice++;
					break;

					case 2:

						Cadastro_de_Novos_Veiculos();

					break;

					case 3:

						Cadastro_de_Novas_Filiais ();

					break;

					case 4:

						Locacao_de_Carros();

					break;

					case 5:

						MovimentarCarros();

					break;
					
					default :
					printf("Digite um numero valido\n");
					}
				}
				
		}
	return 0;
};