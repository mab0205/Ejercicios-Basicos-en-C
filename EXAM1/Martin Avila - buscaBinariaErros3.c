#include <stdio.h>
//Martin Avila Buitron
/*
 * Realiza busca binária em um vetor, retornando
 * o índice do valor sendo procurado.
 *
 * Entradas:
 *
 * v - ponteiro para um vetor de inteiros
 * o vetor deve estar ordenado em ordem crescente
 *
 * tamanho - quantidade de elementos dentro de "v"
 *
 * valor - alvo da busca
 *
 *
 * Saídas: índice do valor sendo procurado ou
 * -1 se o valor não for encontrado.
*/

//                lista       n           valor
int buscaBinaria(int *v, int tamanho, int valor)
{
    int meio = 0, primeiro = 0, ultimo = tamanho-1;

    while(primeiro <= ultimo)
    {
        meio = (primeiro + ultimo) / 2;

        if(valor > v[meio]){

            primeiro = meio + 1;

        }
        else if(valor < v[meio])
        {
            ultimo = meio - 1;

        }
        else
        {
            return meio;
        }
    }
    return -1;
}


int main()
{
    int lista[100] = {0};
    int i = 0, valor = 0, n = 0;
    int indice = 0;

    printf("Entre com a quantidade de elementos que deseja inserir: ");
    scanf("%d", &n);

    printf("Entre com os itens em ordem ascendente\n");

    for (i = 0; i < n; i++)
    {
        printf("Insira o item %d : ", i + 1);
        scanf("%d", &lista[i]);
    }

    printf("Entre com o valor que deseja procurar: ");
    scanf("%d", &valor);

	printf("\ntamanho: %d\n", n );
    indice = buscaBinaria(lista, n, valor);

    if(indice == -1){
    printf("\nValor nao encontrado");
	}

    else{
    	printf("\nValor encontrado no indice: %d\n", indice+1);
	}


    return 0;
}

