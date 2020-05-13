#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ac_getFunciones.h"
#include "funciones_adicionales.h"

int ac_getInt(int *num,int minimo,int maximo,char mensaje[],int tries)
{
    int aux;
    int contador = 0;
    int isOkay = -1;

    if (minimo<=maximo)
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%d",&aux);
        contador++;
        while ((aux<minimo || aux>maximo)&&contador<tries)
        {
            printf("Error. %s",mensaje);
            fflush(stdin);
            scanf("%d",&aux);
            contador++;
        }
        if (contador == tries && (aux<minimo || aux>maximo))
        {
            printf("Se ha superado el numero maximo de intentos\n");
            system("pause");
        }
        else
        {
            *num = aux;
            isOkay = 1;
        }
    }
    return isOkay;
}

int ac_getFloat(float *num,float minimo,float maximo,char mensaje[],int tries)
{
    float aux;
    int contador = 0;
    int isOkay = -1;
    if (minimo<=maximo)
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%f",&aux);
        contador++;
        while ((aux<minimo || aux>maximo)&&contador<tries)
        {
            printf("Error. %s",mensaje);
            fflush(stdin);
            scanf("%f",&aux);
            contador++;
        }
        if (contador == tries && (aux<minimo || aux>maximo))
        {
            printf("Se ha superado el numero maximo de intentos\n");
            system("pause");
        }
        else
        {
            *num = aux;
            isOkay = 1;
        }
    }
    return isOkay;
}

int ac_getChar (char* a,char mensaje[],char b, char c, char d, char e, char f,int tries)
{
    char aux;
    int contador = 0;
    int isOkay = -1;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&aux);
    aux = tolower(aux);
    contador++;
    while (aux!=b && aux!=c && aux!=d && aux!=e && aux!=f && b!= '0' && contador<tries)
    {
        printf("Error. %s",mensaje);
        fflush(stdin);
        scanf("%c",&aux);
        aux = tolower(aux);
        contador++;
    }
    if (contador == tries)
    {
        printf("Se ha superado el numero maximo de intentos.\n");
        system("pause");
    }
    else
    {
        *a = aux;
        isOkay = 1;
    }
    return isOkay;
}

int ac_getDate (int* d,int* m, int* a,char mensaje[], int minYear, int maxYear,int tries)
{
    int aux1;
    int aux2;
    int aux3;
    int contador = 0;
    int isOkay = -1;

    if (minYear<=maxYear)
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%d/%d/%d",&aux1,&aux2,&aux3);
        contador++;
        while ((aux1<1 || (aux1>29 && aux2 ==2) || aux1 > 31 || (aux1 > 30 && aux2 != 1 && aux2 != 3 && aux2 != 5 && aux2 != 7 && aux2 != 8 && aux2 != 10 && aux2 != 12) || aux2<1 || aux2>12 || aux3<minYear || aux3 > maxYear) && contador<tries)
        {
            printf("Error. %s",mensaje);
            fflush(stdin);
            scanf("%d/%d/%d",&aux1,&aux2,&aux3);
            contador++;
        }
        if (contador == tries)
        {
            printf("Se ha superado el numero maximo de intentos.\n");
            system("pause");
        }
        else
        {
            *d = aux1;
            *m = aux2;
            *a = aux3;
            isOkay = 1;
        }
    }
    return isOkay;
}

int ac_getString(char chain[],int lenght,int tries,char mensaje[])
{
    char aux[200];
    int contador = 1;
    int isOkay = 1;
    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);
    while (strlen(aux)>=lenght && contador<tries)
    {
        printf("Error. %s",mensaje);
        fflush(stdin);
        gets(aux);
        contador++;
    }
    if (strlen(aux)<lenght)
    {
        strcpy(chain,aux);
    }
    else
    {
        printf("Se ha superado el numero maximo de intentos.\n");
        isOkay = -1;
        system("pause");
    }
    return isOkay;
}
