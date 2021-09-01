#include <stdio.h> //> para bucar el archivo stdio dentro de las bibliotecas de archivos de C
#include <stdlib.h>
#include <string.h>
/*MARTIN AVILA RA02274183*/
/*
Pregunta 2) (2.5pt) Considere los dos casos de asignación estática (en la pila) presentados.
 Vuelva a crearlos usando la asignación dinámica (en el montón).
Demuestre el uso de cada caso imprimiendo el contenido de los vectores en la pantalla.

char str1 [] [3] = {"aa", "bb", "cc", "dd"};
char * str2 [] = {"aa", "bb", "cc", "dd"};
*/

void imprime(char **str){
    int i, n=4;
    for(i=0;i<n;i++){
        printf("%s",str[i]);
    }
        printf("\n");
}

int main(){
    char **str = NULL;
    char **str2= NULL;
    int i;

    str=(char**)malloc(4*sizeof(char*));

    str[0]="aa";
    str[1]="bb";
    str[2]="cc";
    str[3]="dd";

   // printf("Strings: %d \n\n",str );
    imprime(str);
    //imprime(str1);

    free(str);

    /*************************/

    str2=(char**)malloc(4*sizeof(char*));

     for(i=0;i<4;i++){
        str2[i]=(char*)malloc(3*sizeof(char));
    }


    strcpy(str2[0],"aa" );
    strcpy(str2[1],"bb" );
    strcpy(str2[2],"cc" );
    strcpy(str2[3],"dd" );
    /*str2[1]="bb";
    str2[2]="cc";
    str2[3]="dd";*/

    imprime(str2);

    for(i=0; i<4; i++){
        free(str2[i]);
    }

    free(str2);

}
