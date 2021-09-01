/*
 * Biblioteca para exibir torres de Hanoi e movimentar discos
 *
 * Prof. Daniel Cavalcanti Jeronymo
 * Fundamentos de Programação CP41F
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TORRE 4

typedef enum tagDisco
{
    VERDE = BACKGROUND_GREEN | BACKGROUND_INTENSITY, /* maior disco */
    AZUL = BACKGROUND_BLUE | BACKGROUND_INTENSITY,
    AMARELO = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY,
    VERMELHO = BACKGROUND_RED | BACKGROUND_INTENSITY,  /* menor disco */
    VAZIO = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY
} Disco;


typedef struct tagTorre
{
    Disco nivel[TAMANHO_TORRE];
} Torre;

Torre criaTorreCheia()
{
    Torre t;

    t.nivel[0] = VERMELHO;
    t.nivel[1] = AMARELO;
    t.nivel[2] = AZUL;
    t.nivel[3] = VERDE;

    return t;
}

Torre criaTorreVazia()
{
    unsigned int i = 0;
    Torre t;

    for(i = 0; i < TAMANHO_TORRE; ++i)
        t.nivel[i] = VAZIO;

    return t;
}

unsigned int tamanhoDisco(Disco d)
{
    int n = 0;

    switch(d)
    {
        case VAZIO: n = 1; break;
        case VERMELHO: n = 2; break;
        case AMARELO: n = 3; break;
        case AZUL: n = 4; break;
        case VERDE: n = 5; break;
    }

    return n;
}

void imprimeDisco(Disco d)
{
    int tamMaiorDisco = 2*5 - 1, tamDisco = 0;

    tamDisco = 2*tamanhoDisco(d) - 1;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); /* imprime em preto */
    printf("%*s", (tamMaiorDisco - tamDisco)/2, "");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), d); /* imprime cor do disco */
    printf("%*s", tamDisco, "");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); /* imprime fundo em preto e volta a cor padrão do stdout */
    printf("%*s\n", (tamMaiorDisco - tamDisco)/2, "");
}

void imprimeTorre(const Torre *t)
{
    unsigned int i = 0;

    for(i = 0; i < TAMANHO_TORRE; ++i)
        imprimeDisco(t->nivel[i]);

    printf("\n");
}

void imprimeTorres(const Torre *t1, const Torre *t2, const Torre *t3)
{
    system("cls");

    imprimeTorre(t1);
    imprimeTorre(t2);
    imprimeTorre(t3);

    printf("\nAperte ENTER para continuar\n");
    getchar();
}

int moveDisco(Torre *de, Torre *para)
{
    int i = 0, j = 0;
    Disco d = VAZIO;

    if(para->nivel[0] != VAZIO)
    {
        printf("ERRO: Torre de destino cheia\n");
        return 0;
    }
    else if(de->nivel[TAMANHO_TORRE-1] == VAZIO)
    {
        printf("ERRO: Torre de origem vazia\n");
        return 0;
    }

    /* encontra o primeiro nivel com disco na torre de origem*/
    for(i = 0; i < TAMANHO_TORRE && de->nivel[i] == VAZIO; ++i);

    /* encontra o ultimo nivel sem disco na torre de destino*/
    for(j = TAMANHO_TORRE - 1; j >= 0 && para->nivel[j] != VAZIO; --j);

    if(j != TAMANHO_TORRE - 1 && tamanhoDisco(de->nivel[i]) > tamanhoDisco(para->nivel[j + 1]))
    {
        printf("ERRO: Nao pode colocar disco maior em cima de disco menor\n");
        return 0;
    }

    para->nivel[j] = de->nivel[i];
    de->nivel[i] = VAZIO;

    return 1;
}
