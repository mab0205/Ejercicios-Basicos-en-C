#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/*MARTIN AVILA RA 02274183*/
/*
Desarrolle una función "imprimible" con la siguiente sintaxis:

vacío coloreado (estructura textocolorido texto);

Esta función recibirá un solo parámetro, una estructura de "texto en color" con dos campos.
El primer campo debe ser un vector de caracteres, el texto a imprimir.
El segundo campo debe ser un enumerador de colores.
La función debería imprimir el texto del primer campo en la pantalla con el color especificado por el segundo campo.
El enumerador de colores debe especificar un color entre las opciones: gris, azul, verde, cian, rojo, morado, amarillo, blanco.

Después de desarrollar la función, cree un programa que reciba pares de argumentos por línea de comando
(terminal, indicador, no use scanf), el primer elemento del par es el color y el segundo elemento es el texto.
Se adjuntaron a la actividad ejemplos de llamadas de programa y posibles colores.

NOTA: En Windows, incluya la biblioteca "windows.h" y use la función SetConsoleTextAttribute.
Un ejemplo de uso se puede encontrar en la biblioteca "hanoi.h" del ejercicio Torres de Hanoi que se ve al principio del curso.
En los sistemas Linux es necesario utilizar el subconjunto "Select Graphic Rendition" (SGR) de las secuencias de escape ANSI.*/

enum listacor {
azul=1,
verde=2,
ciano=3 ,
vermelho=4 ,
roxo=5,
cinza= 7,
amarelo= 14,
branco=15,

};

struct textocolorido{
char res[100][100];
int color[100];
int args;
enum listacor cor;
};

void imprimecolorido(struct textocolorido texto){
int i=0,j=0;

for(i=2, j=1; i<texto.args;  i+=2, j+=2){

    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( color ,texto.color[j]);
    printf("%s\n",texto.res[i]);

    }
}


int main(int args, char *argv[]){
    int i,j;

	if(args == 1){
	printf("sin linea de argumentos");
	return 0;

	}

   struct textocolorido texto;

    for(i=1; i<args; i+=2){

    if(strcmp(argv[i], "azul") == 0){//devuelve 0 cuando son iguales
   	texto.color[i]=azul; //Pega o numero da core de enum

    }else if(strcmp(argv[i], "cinza") == 0){
    texto.color[i]=cinza;//Pega o numero da core de enum

    }else if(strcmp(argv[i],"vermelho") == 0){
    texto.color[i]=vermelho;//Pega o numero da core de enum

    }else if(strcmp(argv[i], "verde") == 0){
    texto.color[i]=verde;//Pega o numero da core de enum

    }else if(strcmp(argv[i], "ciano") == 0){
    texto.color[i]=ciano;//Pega o numero da core de enum

    }else if(strcmp(argv[i], "roxo") == 0){
    texto.color[i]=roxo;//Pega o numero da core de enum

    }else if(strcmp(argv[i],"amarelo") == 0){
    texto.color[i]=amarelo;//Pega o numero da core de enum

    }else if(strcmp(argv[i],"branco") == 0){
    texto.color[i]=branco;//Pega o numero da core de enum

    }else {
    printf("Valor invalido\n");}//nao ingreso o nome correto
	}

   for(i=2;i<args;i+=2){
        strcpy(texto.res[i],argv[i]);
	}
	texto.args=args;
    imprimecolorido(texto);
    HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color,15);

    return 0;
}
