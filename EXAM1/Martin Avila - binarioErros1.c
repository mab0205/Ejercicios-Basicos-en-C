#include <stdio.h>
//Martin Avila Buitron
/*
 * Converte um valor para bin�rio.
 *
 * Entradas:
 * valor - vari�vel contendo um valor de 8 bits (entre 0 a 255) a ser convertido
 *
 * Sa�das:
 * saida - um vetor com 8 casas para armazenar o valor com 8 bits
 *         a casa 0 cont�m o bit menos significativo
*/
//                   0-255       binario
void paraBinario(int valor, char saida[8])
{
    int i = 0;

    for(i = 0; i < 8; i++)
        saida[i] =(1 & (valor >> i)); //converte para binario 
}

/*
 * Imprime um valor bin�rio
 *
 * Entradas:
 * binario - um vetor com 8 bits
*/
//                          vari�vel binario
void imprimeBinario(const char binario[8])
{
    int i = 0;

    for(i = 7; i >= 0; i--)
        printf("%d ", binario[i]);

}

int main()
{
    int decimal = 0;
    char binario[8] = {0};

    printf("================= ");
    printf("Calculadora decimal para binario");
    printf(" =================\n\n");

    /* l� uma entrada do usu�rio a ser convertida para bin�rio */
    do
    {
        printf("Entre com um valor decimal entre 0 a 255: ");
        scanf("%d", &decimal);
    }while(decimal < 0 || decimal > 255);


    /* realiza a convers�o, o valor � armazenado na vari�vel binario */
    paraBinario(decimal, binario);


    /* mostra o resultado */
    printf("\nValor em binario: \n");
    imprimeBinario(binario);

    return 0;
}
