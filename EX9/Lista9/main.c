#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tamanho(int *x, unsigned int tamx, int *y, unsigned int tamy);

int * encontraIguais(int *x, unsigned int tamx, int *y, unsigned int tamy ){
    int i = 0, j = 0;
    int n = 0, w;
    int tvetor = 0;
    int *v = NULL;

    tvetor = tamanho(x, tamx, y, tamy);

    v = (int*)malloc(tvetor * sizeof(int));

    for (i = 0; i < tamx; i++)
    {
        for (j = 0; j < tamy; j++)
        {
            if (x[i] == y[j])
            {
                v[n] = x[i];
                n++;
            }
        }
    }
    return (v);
}

int main(void){
    int i, n=3, tamv=0, j;
    int* v = NULL;
    int* vetor1 = NULL;
    int* vetor2 = NULL;

    int valor1, valor2 , valor3, valor4 , valor5 , valor6 , valor7;
    int tam1=3, tam2=4 ;

    printf("Entre com 3 valores do primero vetor: \n");
    scanf("%d %d %d", &valor1 , &valor2, &valor3 );
    printf("Entre com 4 valores do segundo vetor: \n");
    scanf("%d %d  %d %d", &valor4 , &valor5, &valor6, &valor7);

    vetor1=(int*)malloc(3*sizeof(int*));
    vetor2=(int*)malloc(4*sizeof(int*));
    v =(int*)malloc(4*sizeof(int*));

    vetor1[0]= valor1;
    vetor1[1]= valor2;
    vetor1[2]= valor3;

    vetor2[0]= valor4;
    vetor2[1]= valor5;
    vetor2[2]= valor6;
    vetor2[3]= valor7;

    v = encontraIguais(vetor1, tam1, vetor2, tam2);

    printf("\nPrimero vetor: %d %d %d\n", vetor1[0], vetor1[1], vetor1[2]);
    printf("Segundo vetor: %d %d %d %d \n", vetor2[0], vetor2[1], vetor2[2], vetor2[3]);

    printf("\nNumeros repetidos: ");


    tamv = tamanho(vetor1, tam1, vetor2, tam2);
    printf("tamanho vetor: %d \n", tamv);

    for (i = 0; i < tamv; i++)
    {
        printf("%d \n", v[i]);
    }

    free(vetor1);
    free(vetor2);
    free(v);
}


int tamanho(int *x, unsigned int tamx, int *y, unsigned int tamy){
int i = 0, j = 0;
    int tvetor = 0;

for (i = 0; i < tamx; i++){
    for (i = 0; i < tamx; i++)
    {
        for (j = 0; j < tamy; j++)
        {
            if (x[i] == y[j])
            {
                tvetor++;
            }
        }
    }
}
return (tvetor);
}
