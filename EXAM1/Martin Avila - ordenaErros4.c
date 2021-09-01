#include <stdio.h>
#include <string.h>
//Martin Avila Buitron
/*
 * Ordena um vetor "v" de tamanho "n" por Selection Sort
 *
 * Entradas:
 * v - vetor a ser ordenado
 * n - quantidade de elementos dentro de "v"
 *
 * Saída:
 * v - o vetor de entrada é modificado pela ordenação
*/

//              numeros      10
void ordenaVetor( int *v, int n)
{
    int i = 0, j = 0, menor, ap;

    for(i =0; i < n; i++){
        menor = i;


        for(j = i; j < n; j++){
            if(v[menor]>v[j]){
            menor= j;
            }
            ap= v[i];//salva o valor *v

    }


        // troca o elemento atual pelo menor
        if(menor != i){
            v[i]=v[menor];
             v[menor]=ap ;
       }
    }
}

/*
 * Imprime um vetor "v" de tamanho "n"
 *
 * Entradas:
 * v - vetor a ser exibido
 * n - quantidade de elementos dentro de "v"
*/
//               numeros      10
void imprimeVetor( int *v, int n)
{
    int i = 0;

    for(i = 0; i < n; i++){
        printf("%d ", v[i]);}
}

int main()
{
    int v[10] = {22, 14, 1, 5, 3, 2, -1, 0, 0, 4};
    int n = sizeof(v)/4;
	printf("sz%d\n", n);

    printf("Vetor original: \n");
    imprimeVetor(v, n);

    ordenaVetor(v, n);
    //printf("ap:%d\n",v[1]);

   printf("\n\n Vetor ordenado: \n");
   imprimeVetor(v, n);


    return 0;
}
