/*****

3) 30) Descreva um algoritmo utilizando XOR (^) para criptografar e desencriptar uma
string

****/

#include <stdio.h>
#include <string.h>
#define N 100

int main (){
	 char nome[N];
	 int a=0, c=0, d=0;
	 int n=0, i=0;
	 
	printf("Entre com String: ");
	scanf ("%s",&nome);
	n = strlen(nome);
	
	
	printf("\nOriginal:");	
	while(i<n){
	printf(" %c", nome[i]);
	i++;
	}
	i=0;
	
	
	printf("\nEncriptado:");
	while(i<n){
	c= nome[i]^49;
	printf( " %c", c);
	i++;
	}
	i=0;
	
	
	printf("\nDesencriptado:");
	while(i<n){
	c= nome[i]^49;
	d=c^49;
	printf(" %c", d);
	i++;
	}
	
	
	return 0;
}






