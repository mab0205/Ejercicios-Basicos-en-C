#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
Escriba un programa que dibuje un círculo con un radio especificado por el usuario, en un archivo de texto.
 El radio debe ser un parámetro por línea de comando (terminal, indicador, no use scanf).
  El interior del círculo debe llenarse con espacios vacíos.
 El perímetro externo se debe completar con los dígitos RA del estudiante, en la misma secuencia. Adjunto a la actividad hay un ejemplo del llamado "circulo.exe 10".
 */

void imprime(int n, int *RA){
	FILE *file ;
    file = fopen("resolucion.txt" , "w");
 int j=0, i=0, c=0;
    //scanf("%d", &n);

    if (file ==NULL){
    printf ("error en el archivo");
    //return 1;

    }

    for ( j=0 ; j<= n*2 ; j++){

        for( i=0 ;i<= n*2 ; i++){
            if(pow((i - n), 2.0)+pow(j - n, 2.0) >=  pow( n, 2)){

                    if(c<7){
                   // printf("%d", RA[c]);
                    fprintf( file, "%d" , RA[c]);
                    c++;

                    }else{
                        //printf("%d", RA[c]);
                        fprintf( file, "%d", RA[c]);
                        c=0;
                    }

            }else{
               // printf(" ");
                fprintf( file, " ", RA[c]);
            }
        }
       // printf("\n");
        fprintf( file, "\n", RA[c]);
    }

}

int main(int args, char *argv[]){

    int raio = atoi(argv[1]);
    int RA[8]={0,2,2,7,4,1,8,3};


    //printf("Entre com o raio do circulo: ");
    //scanf("%d", &raio);

    printf("\n");

    imprime(raio, RA);
    printf("\n");


    return 0;
}



