#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cabecalho.h"

/*Martin Avila RA02274183*/

/*Escriba un módulo de Estudiantes que contenga un archivo de encabezado (.h) y un archivo de código (.c), con dos funciones:

Estudiantes * loadStudents (archivo const char *, unsigned int * cantidad);
void imprimeAlunos (estudiantes const * estudiantes, cantidad int sin firmar);

- Students es una estructura que contiene 256 caracteres para el nombre de un estudiante y un doble para la calificación del estudiante. Utilice typedef al definir la estructura.

- loadStudents recibe dos parámetros. El primer parámetro es el nombre de un archivo de texto que contiene los nombres y las calificaciones de los estudiantes, en el formato:

NOMBRE1 NOTA1
NOMBRE2 NOTA2
...
NOMBRE NOTAn

La función loadStudents debería asignar dinámicamente un vector para almacenar los estudiantes leídos del archivo y devolver ese vector.

Se emite el segundo parámetro. El número de registros almacenados en el vector debe devolverse por referencia (puntero) en el segundo parámetro, cantidad.

- imprimeAlunos recibe dos parámetros, donde el primero es un vector de estudiantes y el segundo el número de registros en el vector. Esta función imprime el contenido del vector.*/


void imprimeAlunos(const Alunos * alunos, unsigned int quantidade){ //funcao prar imprimir
    int i = 0;
	printf("Nome do Aluno\tNota do Aluno \n");
    for (i = 0; i < quantidade; i++)
    {
        printf("%d. %s\t",  i+1,  alunos[i].nome); //nome com a posicao
        printf(" %.1f\n",  alunos[i].nota);
    }
}

Alunos *carregaAlunos(const char *file, unsigned int *quantidade){
Alunos *Nomes;

int  i= 0, j= 0, cont= 0, x=0;//cont numero de alumnos en el txt
int letra = 0;
char vetor[100];
double nota=0;

while((letra = fgetc(file))!=EOF){
   if (letra == '\n' || letra ==EOF){
     x++; //numero de alumnos en el txt
   }
}
rewind(file);

Nomes = (Alunos *)malloc(x * sizeof(Alunos));

while((letra = getc(file))!=EOF){

	 if(letra == '\n' || letra == EOF){
		 sscanf(vetor, "%lf", &nota); //fucao pra nota seja double
            Nomes[cont].nota = nota;
            strcpy(vetor, "0" );
            j = 0;
            cont++;
	}else if(letra == ' '){
       strcpy(Nomes[cont].nome, vetor);//fucao cpiar nome
            for (i = 0; i < j; i++)
            {
                vetor[i] = 0;
            }
            j = 0;

	}else {
		vetor[j] = letra;
        j++;
	}
	*quantidade = cont;//fucao para ter quatidade de alunos
}

return Nomes;

}


int main()
{
FILE *file = NULL;
file = fopen("Alunos.txt", "r");
int  quantidade=0;

Alunos *Nomes;

if (file ==NULL){
    printf ("Error en el archivo");
    return 1;

}

Nomes = carregaAlunos(file, &quantidade);
   // struct Alunos *carregaAlunos(const char * arquivo, unsigned int * quantidade);
imprimeAlunos(Nomes, quantidade);
fclose(file);
return 0;

}
