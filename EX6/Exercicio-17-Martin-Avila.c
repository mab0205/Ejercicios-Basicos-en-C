/*17) Escreva um programa que receba oito digitos binários (0 ou 1), representando um
valor binário de oito bits, e escreva o valor correspondente em decimal, octal e
hexadecimal.*/
//Martin Avila 

#include <stdio.h>
#include <math.h>
#define N 8

int decimal(int vector[N], int i, int potencia);
int octal(int dec);
int hexadecimal(int dec);

int leBinario(){
    int b;
    scanf ("%d", &b);

    while (b!=0 && b !=1){
        printf("Valor invalido, entre com um novo numero: ");
        scanf ("%d", &b);
    }
    return b;
}



int main(){

    int dec = 0, oct= 0, hex;
    int vector[N], i=0;
    int potencia=0, pot=0;

    printf("Entre com oito digitos binarios: ");
    while(i<8)
        {
     vector[i]=leBinario(); //funçao scanf binario
     dec= decimal(vector, i, potencia) + dec;
     i++;
     potencia++;
    }
    
	octal(dec); //funçao octal
    printf("\nValor em decimal : %d\n", dec);
	hexadecimal(dec); //funçao hemadecimal

    return 0;


}

int decimal(int vector[N], int i, int potencia){
	int res;
    res= (vector[i]*pow(2, potencia));
    return res;
}



int octal(int dec){
    int oct[N], div, res, i=0;
    div = dec;
    do{
		oct[i] = div%8;
        div = div/8;
        i++;
    }while(div > 8);
    
    oct[i]=div;
    printf("Valor em octal: ");
    
    for(i;i>=0;i--){ //para correr de atras hacia adelante 
    	printf("%d ", oct[i]);
	}

 	return 0;
}



int hexadecimal(int dec){
	int div, res, i= 0;
	char hex[N];
    div = dec;
    do{
		hex[i]= div%16;
        div = div/16;
        i++;
    }while(div > 16);
    
    hex[i]=div;
    printf("Valor em hexadecimal: ");
    
    for(i; i>=0; i--){ //para correr de atras hacia adelante 
    	printf("%d ", hex[i]);
	}	
		
 	return 0;
}








