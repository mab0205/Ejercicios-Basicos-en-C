#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
/*Cree un programa que tome un argumento, el nombre de un archivo, por l�nea de comando. 
El programa debe recibir una cadena como entrada del usuario y buscar cu�ntas veces aparece la cadena en el archivo.

Ejemplo de llamada de programa:
programa.exe entrada.txt

El programa debe solicitar la entrada del usuario, la cadena que se buscar� en el archivo de texto. Alternativamente, 
este par�metro se puede pasar como otro par�metro de l�nea de comando:
programa.exe input.txt cadena

NOTA: ser� necesario trabajar con la definici�n est�ndar de la funci�n principal: int main (int args, char * argv [])*/

int Procura(FILE *file, char *string, int num);
int main(int args, char *argv[])
{
    FILE *file = NULL;
	file = fopen(argv[1], "r");
    char *string = NULL;
    int num = 0, igual = 0;

    
    string = argv[2];

    num = strlen(string);

    printf("\nPalavra leidas: %s\n", string);

    igual = Procura(file, string, num);

    printf("Palavras iguais : %d\n", igual);

    return 0;
}

int Procura(FILE *file, char *string, int num)
{

    int i = 0, n = 0;
    char ltra = NULL;

    ltra = fgetc(file);

    while (ltra != EOF) {

        if (ltra == string[i]){
            i++;
        }else {
            i = 0;
        }

        if (i == num) {
            n++;
        }

        ltra = fgetc(file);
    }

    return n;
}
