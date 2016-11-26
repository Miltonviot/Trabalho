#ifndef CadastrodeNovosClientes_H
#define CadastrodeNovosClientes_H


typedef struct Clientes {
		char primeiroNome[100],UltimoNome[100],endereco[100],senha[7];
		int CPF[11];
		int identificador[5];		
	}Clientes;


int CadastrodeNovosClientes(Clientes *cadastro, int Indice );
void imprime_clientes(Clientes *cadastro, int indice);
void converte_char_to_int(char *cpfc, int * cpf);
int verificar_cpf(int *cpf) ;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "MovimentarCarros.h"
#include "Locacao_de_Carros.h"
#include "Cadastro_de_Novos_Veiculos.h"
#include "CadastrodeNovosClientes.h"
#include "Cadastro_de_Novas_Filiais.h"


int CadastrodeNovosClientes(Clientes *cadastro, int Indice ) {
	Clientes novo;
	int aux=0;
	char *cpfc = (char*)malloc(sizeof(11));
	int condicional=1;

	while (condicional>0){
		puts("=============================================================================");
		puts("=============================================================================");
		puts("DESEJA REALIZAR CADASTRO DE NOVO CLIENTE ? {1} PARA SIM! {0} PARA NAO!");
		scanf("%d",&condicional);
		puts("=============================================================================");
		puts("=============================================================================");
		getchar();

		if (condicional == 1){
			puts("=============================================================================");
			puts("=============================================================================");
			puts ("Digite o Primeiro nome do clinte ");
			fgets(novo.primeiroNome,101,stdin);
			puts("=============================================================================");
			puts("=============================================================================");
			
			puts ("Digite o CPF  do clinte ");
			fgets(cpfc,101,stdin);	
			converte_char_to_int(cpfc,novo.CPF);
			if(verificar_cpf(novo.CPF))
				aux = 1;
			else
				aux = 0;

			puts("=============================================================================");
			puts("=============================================================================");

			puts ("Digite o Ultimo nome do clinte ");
			fgets(novo.UltimoNome,101,stdin);
			
			puts("=============================================================================");
			puts("=============================================================================");

			puts ("Digite A Senha do clinte (6 digitos) ");
			fgets(novo.senha,7,stdin);	
			getchar();
			
			puts("=============================================================================");
			puts("=============================================================================");
			getchar();
			puts ("Digite o Endereço do clinte ");
			fgets(novo.endereco,101,stdin);		
					
			
			puts("=============================================================================");
			puts("=============================================================================");

			puts("Digite o numero do cadastro ( Separado por espaço )");
			scanf("%d %d %d %d",&novo.identificador[0],&novo.identificador[1],&novo.identificador[2],&novo.identificador[3]);
			
			puts("=============================================================================");
			puts("=============================================================================");
			
			if(aux){
				int i,x,y=1;
				for(i=0; i<=Indice;i++){
					if(cadastro[i].CPF[0] == novo.CPF[0]){
						y=0;
						for(x=0;x<11;x++){
							if(cadastro[i].CPF[x] != novo.CPF[x]){
								y=1;
								break;
							}
						}
						if(y==1) break;
					}
				}
				if(y==1){
					Indice++;
					strcpy(cadastro[Indice].primeiroNome, novo.primeiroNome);
					strcpy(cadastro[Indice].UltimoNome, novo.UltimoNome);
					strcpy(cadastro[Indice].endereco, novo.endereco);
					strcpy(cadastro[Indice].senha, novo.senha);
					
					for(i=0;i<11;i++)
						cadastro[Indice].CPF[i]=novo.CPF[i];
					for(i=0;i<4;i++)
						cadastro[Indice].identificador[i]=novo.identificador[i];
				}
			}
		}
	}
		return Indice;
}

void listarClientes(Clientes *cadastro, int indice){
	int i;
	while(indice>=0){
		printf("\tCliente número:%d\n",indice );
		printf("\tPrimeiro Nome:%s\n",cadastro[indice].primeiroNome);
		printf("\tUltimo Nome:%s\n",cadastro[indice].UltimoNome);
		printf("\tEndereço:%s\n",cadastro[indice].endereco);
		printf("\tSenha:%s\n",cadastro[indice].senha);
		printf("\tCPF:");
			for(i=0;i<11;i++){
				printf("%u",cadastro[indice].CPF[i]);
			}printf("\n");
		printf("\n\tNumero da Conta:%d %d %d %d \n", cadastro[indice].identificador[0],cadastro[indice].identificador[1],cadastro[indice].identificador[2],cadastro[indice].identificador[3]);
		printf("=============================================================================\n");
		printf("=============================================================================\n");
		indice--;		
	}
}

void converte_char_to_int(char *cpfc, int * cpf){
	int i;
	for(i=0;i<11;i++){
		if(cpfc[i] >=48 && cpfc[i] <=57){
			switch(cpfc[i]){
				case('0'):{
					cpf[i]= 0;
					break;
				}
				case('1'):{
					cpf[i]= 1;
        			break;
				}
				case('2'):{
					cpf[i]= 2;
        			break;
				}
				case('3'):{
					cpf[i]= 3;
        			break;
				}
				case('4'):{
					cpf[i]= 4;
        			break;
				}
				case('5'):{
					cpf[i]= 5;
        			break;
				}
				case('6'):{
					cpf[i]= 6;
        			break;
				}
				case('7'):{
					cpf[i]= 7;
        			break;
				}
				case('8'):{
					cpf[i]= 8;
        			break;
				}
				case('9'):{
					cpf[i]= 9;
        			break;
				}
			}
		}
	}
}

int verificar_cpf(int *cpf) { 	
	int status, dv_informado,soma,posicao,digito[11],dv,i;
	for (i = 0; i <= 8; i++) { 
		digito[i]=cpf[i];
	}

	dv_informado = cpf[9]*10+cpf[10];
	posicao = 10; 
	soma = 0; 
	for (i = 0; i <= 8; i++) { 
		soma = soma + digito[i] * posicao; 
		posicao = posicao - 1; 
	} 
	digito[9] = soma % 11; 
	if (digito[9] < 2) { 
		digito[9] = 0; 
	}else{
		digito[9] = 11 - digito[9]; 
	}
	posicao = 11; 
	soma = 0; 
	for (i = 0; i <= 9; i++) { 
		soma = soma + digito[i] * posicao; posicao = posicao - 1; 
	} 
	digito[10] = soma % 11; 
	if (digito[10] < 2) { 
		digito[10] = 0; 
	} else {
		digito[10] = 11 - digito[10]; 
	} 
	dv = digito[9] * 10 + digito[10];
	if (dv != dv_informado) {
		status = 0;
	}else 
		status = 1; 

	return status; 
}
	
#endif

