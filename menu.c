#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "MovimentarCarros.h"
#include "Locacao_de_Carros.h"
#include "Cadastro_de_Novos_Veiculos.h"
#include "CadastrodeNovosClientes.h"
#include "Cadastro_de_Novas_Filiais.h"

int main (){

	Clientes cadastro_clientes [200];
	int Indice_clientes=-1;

	Filiais cadastro_filiais[200];
	int Indice_filiais=-1;

	Veiculos cadastro_veiculos[200];
	int Indice_veiculos=-1;

	Locacao cadastro_locacao[200];
	int Indice_locacao=-1;

	Movimentar cadastro_movimento[200];
	int Indice_movimento=-1;

	int condicional=8;

		while (condicional>0){
			puts("=============================================================================");
			puts("=============================================================================");
			puts("=Digite {0} para sair                                                       =");
			puts("=Digite {1} para Cadastro de Novos Clientes                                 =");
			puts("=Digite {2} para Cadastro de Novos Veiculos                                 =");
			puts("=Digite {3} para Cadastro de Novas Filiais                                  =");
			puts("=Digite {4} para Realizar uma locação                                       =");
			puts("=Digite {5} para Encerrar uma locação                                       =");
			puts("=Digite {6} para Realizar uma transferencia entre Filiais                   =");
			puts("=Digite {7} para listar Clientes 								=");
			puts("=Digite {8} para listar Filiais 			                      =");
			puts("=Digite {9} para listar Veiculos 			                      =");
			puts("=============================================================================");
			puts("=============================================================================");

			scanf("%d",&condicional);
				if (condicional>0){
					switch (condicional){
					
					case 1:
						Indice_clientes = CadastrodeNovosClientes(cadastro_clientes, Indice_clientes);
						
					break;

					case 2:
						Indice_veiculos = Cadastro_de_Novos_Veiculos(cadastro_veiculos, Indice_veiculos);
						

					break;

					case 3:
						Indice_filiais = Cadastro_de_Novas_Filiais(cadastro_filiais, Indice_filiais);

					break;

					case 4:
						Indice_locacao = Locacao_de_Carros(cadastro_locacao, Indice_locacao, cadastro_clientes, Indice_clientes, cadastro_filiais, Indice_filiais, cadastro_veiculos, Indice_veiculos);
						listarLocacoes(cadastro_locacao, Indice_locacao);
					break;

					case 5:
						Indice_locacao = encerrar_Locacao_de_Carros(cadastro_locacao, Indice_locacao, cadastro_clientes, cadastro_filiais, cadastro_veiculos);
						listarLocacoes(cadastro_locacao, Indice_locacao);
					break;

					case 6:
						Indice_movimento = MovimentarCarros(cadastro_movimento, Indice_movimento,cadastro_filiais,cadastro_veiculos);
						listarMovimentos(cadastro_movimento, Indice_movimento);
					break;
					
					case 7:
						listarClientes(cadastro_clientes, Indice_clientes);
					break;

					case 8:
						listarFiliais(cadastro_filiais, Indice_filiais);
					break;

					case 9:
						listarVeiculos(cadastro_veiculos, Indice_veiculos);
					break;

					
					default :
					printf("Digite um numero valido\n");
					}
				}

		}
	return 0;
};