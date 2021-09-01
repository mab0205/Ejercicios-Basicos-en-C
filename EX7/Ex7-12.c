#include <stdio.h> // <> para bucar el archivo stdio dentro de las bibliotecas de archivos de C
#include "leitor.h" // archivo para modularizar el codigo // "" se usa para buscar el archivo con nombre de leitor.h
#include <stdlib.h>
#include <string.h>

/*
Listado 7, Ej.12)
Considere los siguientes dos vectores:
char str [] [3] = {"aa", "bb", "cc", "dd"};
char * str [] = {"aa", "bb", "cc", "dd"};

¿Son iguales? ¿Cómo recrear cada vector usando asignación dinámica (malloc) en lugar de asignación estática?

Cree una función que tome el vector como parámetro e imprima las cuatro cadenas. ¿Se puede lograr esto con un solo prototipo o
se requieren diferentes prototipos para cada sintaxis vectorial? Envíe un archivo de texto (txt, doc, odt, etc.) con su explicación.
*/

void imprime(char **str){
    int i, n=3;
    for(i=0;i<n;i++){
        printf("%s",str[i]);
    }

}

int main(){
    char** str = NULL;
    //char str1[][3] = {"aa","bb","cc","dd"};// No caso se coloca,  o vetor da erro porque a funcao nao pode impremir esta estrutura
    /*char * string1 = (char*)malloc(20);
    char * string2 = (char*)malloc(20);
    char * string3 = (char*)malloc(20);*/

    str=(char**)malloc(3*sizeof(char*));


    str[0]="aa";
    str[1]="bb";
    str[2]="cc";

   // printf("%s %s %s",nomes[0], nomes[1],nomes[2]);
     /*for(i=0;i<n;i++){
        printf("%s",nomes[i]);
    }*/
    printf("Strings: %d\n\n",str );
    imprime(str);
    //imprime(str1);

    free(str);
}


