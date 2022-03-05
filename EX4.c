/** Autor: 
 * 
 * 		- André Filipe Marques Madeira - 46951 - LT11N
 * 
 * Programa:
 * 
 * 		- Realize um programa para determinar um valor aproximado de π, utilizando a série apresentada abaixo. O cálculo é 
 * 	realizado gerando um determinado número de termos da série. O número de termos a serem considerados é lido do 
 * 	standard input (teclado) (maior ou igual que 30000).
 * 
 * Estado:
 * 
 * 		- Finalizado
 */

#include <stdio.h>
#include <string.h>

int main(){
	
	//Declaração de variaveis
	int n;							// valor inserido pelo utilizador
	double numerador = 1;			// no primiero ciclo, o numerador é 1. 
	double denominador = 1;			// no primeiro ciclo o denominador é 1.
	double pi = 0.0;				// resultado
	int valido_1_0 = 0;
	
	// Introdução ao programa
	printf("Bem vindos ao Programa!\n------------------------------\n");
	printf("Este programa tem como objectivo calcular o valor de pi\n");
	printf("\n");
	
	// E pedido ao utilizador que insira os n termos, e se for inferior a 30000 da erro. 
	printf("Digite o total de termos >=30000\n");
	while ( valido_1_0 == 0){	
		if ( scanf("%d", &n) !=1){
			printf("Valor Invalido");
		}else{
			if ( n < 30000){
				printf("Valor inserido tem de ser >=30000\n");
				valido_1_0 = 0;
			}else{
				valido_1_0 = 1;
			}
		}
	}
	
	//calculo do pi
	// o ciclo for vai ser o meu somatorio. Vou fazer somatorio a comecar em k=1 e vai ate o valor inserido pelo utilizador. 
	for( int k = 1; k <= n; ++k){
		pi += 4*(numerador/denominador); 		// Devisao do numerador pelo denominador ((-1)^k+1 - numerador / //2k-1 - denominador).
			// Preparar o proximo ciclo
			numerador = -numerador;				// (-1)^k+1 - o numerador vai variando de 1 para -1 em cada ciclo. 
			denominador += 2;					// //2k-1 - o denomiandor no primeiro ciclo comeca em 1, no segundo é 3, no terceiro e 5 e assim sucessivamente
	}
	
	// Resultados no output
	printf("O valor de pi é: %f\n",pi);
	printf("\n");		
}
	
	
	
	
	
		
	
