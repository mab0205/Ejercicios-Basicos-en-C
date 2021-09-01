#include <stdio.h>
#include <string.h>
//Martin Avila Buitron
/*
 * Inverte as letras de posição numa string
 *
 * Entrada:
 * palavra - uma string a ser invertidas
 *
 * Saída:
 * o vetor de entrada será modificado
 *
 * Exemplo:
 * char p[] = "teste";
 * inverte(p);
 * p -> contém "etset"
*/

//                palavras
void inverte(char *palavra)
{
    int i = 0;
    
    int n = strlen(palavra);
	
	char invertir[100]={0};
 
	strcpy( invertir, palavra);
		
    for(i = 0; i < n; i++)
    {
		// palavra[n+1] = palavra[i];
    	// palavra[i] = palavra[n-i];
    	//palavra[n] = palavra[n+1];
        palavra[i]= invertir[((n-1)-i)];		       
	}
	//printf("%s\n", palavra ); 
	
}



int main()
{
    int i = 0;
    
    char palavras[20][100] = {0};

    /* lê até 20 palavras do usuário */
    for(i = 0; i < 20; i++)
    {
        printf("Entre com a palavra %d ou ponto (.) para terminar: ", i+1);
        scanf("%s", &palavras[i]);

        /* para se a entrada for um ponto */
        if(strcmp(palavras[i], ".") == 0) {
        	i--;
            break;
        }

    }

    printf("\nForam lidas %d palavras\n", i + 1);

    /*imprime as palavras invertidas na ordem inversa da inserção*/

    printf("Palavras na ordem inversa:\n");
    for( i ; i >= 0; i--)
    {
        inverte(&palavras[i]);
        printf("%s\n", palavras[i]); 
    }
    
    return 0;
}

