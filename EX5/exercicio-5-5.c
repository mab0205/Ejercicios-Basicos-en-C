/*5) Palíndromos são números que têm o mesmo valor se lidos da esquerda para a direita
ou da direita para a esquerda. Exemplos: 44, 232, etc. Faça um programa que determine
e escreva todos os números inteiros entre 1000 que 10000 que são palíndromos.*/

//Martin Avila Buitron

#include <stdio.h>

void Palidromo(int numero){
	
	int falta,numinv=0,resto=0;
	falta=numero;
	
	while(falta!=0)
	{
 		resto=falta%10;
 		numinv=numinv*10+resto;
		falta=falta/10;
	}
  		
  	if(numinv==numero){
  		
  	  printf("\n numero inteiro palindromo: %d\n",numero);
  	 	
	  }
	 
}

int main(){
	 int numero=1000;
  	
 	while (numero<10000){
   		
   	 Palidromo(numero);
   	 
   	 numero++;
   }
   
}


