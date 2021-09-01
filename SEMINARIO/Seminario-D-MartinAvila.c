#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/* -------------------------------------------------------------------------- */

void emailCleaner(char *email)
{
    char cleanEmail[100] = {0};

    int i = 0, n = 0;
    int mais = 1, aux = 1;

    /* -------------------------------------------------------------------------- */

    for (i = 0; i < strlen(email); i++)
    {
        if (mais == 1 && (email[i] != '@'))
        {
            if ((email[i] == '.') && (aux == 1))
            {
                continue;
            }
            else if ((email[i] == '+') && (aux == 1))
            {
                mais = 0;
            }
            else
            {
                cleanEmail[n] = email[i];
                n++;
            }
        }
        else if (email[i] == '@')
        {
            cleanEmail[n] = email[i];
            mais = 1;
            aux = 0;
            n++;
        }
    }

    /* -------------------------------------------------------------------------- */

    strcpy(email, cleanEmail);
    memset(cleanEmail, 0, 100);
}

/* -------------------------------------------------------------------------- */

char **getEmails(const char *fileName, unsigned int *n)
{
    FILE *file = NULL;
    file = fopen(fileName, "r");

    char **emails = NULL;
    int i = 0, aux = 0;
    char c = 0;
    char str[100] = {0};
    int x = 0;

    /* -------------------------------------------------------------------------- */

    if (file == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    /* -------------------------------------------------------------------------- */

    while ((c = fgetc(file)) != '\n')
    {
        str[aux] = c;
        aux++;
    }

    x = atoi(str);
    memset(str, 0, 100);

    emails = (char **)malloc(x * sizeof(char *));
    memset(emails, 0, x);

    for (i = 0; i < x; i++)
    {
        emails[i] = (char *)malloc(100);
        memset(emails[i], 0, 100);
    }

    aux = 0;
    x = 0;

    /* -------------------------------------------------------------------------- */

    do
    {
        c = fgetc(file);
        if (c == '\n')
        {
            emailCleaner(str);
            strcpy(emails[x], str);
            memset(str, 0, 100);
            x++;
            aux = 0;
        }
        else
        {
            str[aux] = c;
            aux++;
        }

    } while (c != EOF);

    /* -------------------------------------------------------------------------- */

    *n = x;
    return emails;
}

/* -------------------------------------------------------------------------- */

void emailsCompare(char **emails, int n)
{
    int i = 0, j = 0, aux = 0, exist = 0;
    FILE *file = NULL;
    file = fopen("output.txt", "w+");
    char **newEmails;

    newEmails = (char **)malloc(n * sizeof(char *));
    memset(newEmails, 0, n);

    /* -------------------------------------------------------------------------- */

    for (i = 0; i < n; i++)
    {
        newEmails[i] = (char *)malloc(100);
        memset(newEmails[i], 0, 100);
    }

    /* -------------------------------------------------------------------------- */

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {

            if (strcmp(emails[i], newEmails[j]) == 0)
            {
                exist = 1;
                break;
            }
        }

        if (exist == 0)
        {
            strcpy(newEmails[aux], emails[i]);
            aux++;
        }

        exist = 0;
    }

    /* -------------------------------------------------------------------------- */

    fprintf(file, "%d\n", aux);
}

/* -------------------------------------------------------------------------- */

int main(void)
{
    int i = 0;
    unsigned int n = 0;
    char **emails = NULL;
    char fileName[] = "input.txt";

    /* -------------------------------------------------------------------------- */

    emails = getEmails(fileName, &n);

    /* -------------------------------------------------------------------------- */

    emailsCompare(emails, n);

    /* -------------------------------------------------------------------------- */

    for (i = 0; i < n; i++)
    {
        free(emails[i]);
    }

    free(emails);

    return 0;
}

