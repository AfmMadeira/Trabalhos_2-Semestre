/** Autor :
 *  
 * 		- André Filipe Marques Madeira - 46951 - LT11N
 * 
 * Programa :
 * 	
 * 		- Elabore um programa que leia, do standard input (teclado), uma sequência de três ou mais valores inteiros terminada 
 * 	por um valor negativo, que representam as classificações dos alunos de uma turma e determina os seguintes valores:
 * 	 	- A média linear arredondada de toda a sequência de valores.
 * 		- A maior nota e havendo várias iguais à maior indicar o total de ocorrências
 * 		- A menor nota e havendo várias iguais à menor indicar o total de ocorrências
 *      - A média centrada arredondada retirando todas as notas de maior valor e todas as notas de menor.
 * 
 * Estado : 
 * 
 * 		- Finalizado. 
 */
 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_SEQ 500

int main(){
	
	// Declaração de variaveis
	int dim_seq = 0;					// Contador da dimensao do array seq[]
	int seq[MAX_SEQ];					// array seq[]
	int notasMinimas = 0;				// Para calcular quantas vezes ocorreu as notas Minimas
	int notasMaximas = 0;				// Para calcular quantas vezes ocorreu as notas maximas
	int soma = 0;						// Para calcular a soma
	float media_linear;					// Para calcular a media linear
	float media_centrada;				// Para calcular a media centrada

	// Introdução ao programa
	printf("\n");
	printf("Bem Vindos ao Programa!\n-----------------------\n");
	printf("Este programa tem como objectivo receber uma sequencia de 3 ou mais numeros inteiros terminada por um valor negativo , que representam as classificações de uma turma e calcular:\n");
	printf("	- A media Linear arredondada de toda a sequencia de valores\n");
	printf("	- A maior nota e havendo varias iguais à maior nota indicar o total de ocorrencias\n");
	printf("	- A menor nota e havendo varias iguais à menor nota indicar o total de ocorrencias\n");
	printf("	- A media centrada arredondada retirando todas as notas de maior valor e todas as notas de menor valor\n");
	printf("-------------------------------------------------\n");
	
	// E pedido ao utilizador que insira no minimo 3 notas. 
	printf("Digite 3 ou mais notas e termine com -1 : ");
		for( int i = 0; i <= MAX_SEQ; i++){			// ciclo for que percorre a dimensao definida do array
			scanf("%d",&seq[i]);					// scanf fica responsavel por armazenar os valores recebidos no array seq[]
			dim_seq++;								// ha medida que vao ser inseridos numeros, a dimensao do array seq vai aumentando. 
			if ( seq[i] < 0 ) break;				// se for introduzido um valor negativo o ciclo for para. 
			// a funcao isdigit verifica se o valor introduzido e digito ou nao,ou seja, se for digito ele assume == 0, se nao for digito ele assum !=0.
			if(((isdigit((seq[i]+'0')) != 0) && (isdigit(seq[i]+'0')  != 1)) || (seq[i] > 20)){
				printf("Deverão ser digitados pelo menos 3 numeros entre 0 e 20\n");
				return 0;
			}	
		}
		
	// Se forem introduzidos menos que 3 numeros, o programa da erro. 
	if(dim_seq-1 < 3){
		printf("Deverão ser digitados pelo menos 3 numeros entre 0 e 20\n");
		return 0;
	}
	
	// ordenar o array
	// Sao comparados e ordenados os 2 elementos sucessivos EX: seq[0] com seq[1].
	for ( int i = 0; i < dim_seq-2; i++){
		for ( int j = 0 ; j < dim_seq-2 ; j++){
			int elem;
			if ( seq[j] > seq[j+1]){ 
				elem = seq[j];
				seq[j] = seq[j+1];
				seq[j+1] = elem;
			}		
		}
	}
	
	// calculo das notas minimas. Como esta ordenado, se a primeira posiçao for igual a i conta as vezes que aparece. 
	for ( int i = 0; i <= dim_seq-2; i++){
		if ( seq[0] == seq[i]) notasMinimas++;	
	}
	// calculo das notas maximas. Como esta ordenado, a ultima possição e a maior, logo se se repetir ele conta. 
	for ( int i = dim_seq-2; i>=0; i--){
		if (seq[dim_seq-2] == seq[i]) notasMaximas++;
	}
	// calculo da soma dos n elementos do array
	for ( int i = 0; i <= dim_seq-2; i++){
		soma += seq[i];	
	}
	// Calculo da Media Linear
	media_linear = (double)soma / (double)(dim_seq-1) ;
		
	//Calculo da media centrada
	soma = 0; 					// fazer um reset a variavel porque foi usada no ciclo for anterior 
	for(int i = notasMinimas; i <= (dim_seq-2)-notasMaximas; i++){
		soma += seq[i];	
	}
		// Media centrada e retirar as notas de maior e menor valor. 
		media_centrada = (double) soma / (double)((dim_seq-1)-(notasMinimas + notasMaximas));
	
	// Respostas a aparecer no output
	printf(" A media linear da turma é = %.0f\n",media_linear+0.01);
		if ( notasMinimas == 1){
			printf(" A nota minima = %d e ocorreu %d vez\n",seq[0], notasMinimas);
		}else{
			printf(" A nota minima = %d e ocorreu %d vezes\n",seq[0], notasMinimas);
		}
		if (notasMaximas == 1){
			printf(" A nota maxima = %d e ocorreu %d vez\n",seq[dim_seq-2], notasMaximas);
		}else{
			printf(" A nota maxima = %d e ocorreu %d vezes\n",seq[dim_seq-2], notasMaximas);
		}
		printf(" A media centrada da turma é = %.0f\n",media_centrada+0.01);
		return 0;	
}
	


	


		
		
	
	
	
