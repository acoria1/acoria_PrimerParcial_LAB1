#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ac_getFunciones.h"
#include "funciones_adicionales.h"
#include "ac_dataStorage.h"

#define TAMTRABAJOS 20
#define TAMMOTOS 30
#define TAMSERVICIOS 4
#define TAMCOLORES 5
#define TAMTIPOS 4
#define CANT_HARDCODE 10

typedef struct
{
    int day;
    int month;
    int year;
} e_fecha;

typedef struct
{
    int id;
    char descripcion [20];
} e_tipoDeMoto;

typedef struct
{
    int id;
    char nombreColor [20];
} e_Color;

typedef struct
{
    int id;
    char descripcion[25];
    int precio;
} e_Servicio;

typedef struct
{
    int id;
    char marca [20];
    int idTipo;
    int idColor;
    int cilindrada;
    int isFull;
} e_Moto;

typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    e_fecha fechaDeTrabajo;
    int isFull;
} e_Trabajo;

char menu();
int buscarMoto (int id,e_Moto vec[],int size);
int getEmptySlotMoto (e_Moto vec[],int size);
int getEmptySlotTrabajo (e_Trabajo vec[],int size);
void hardcodearMotos (e_Moto vec[],int size);
void hardcodearTrabajos (e_Trabajo vec[],int size);
void inicializarMotos (e_Moto vec[],int size);
void inicializarTrabajos (e_Trabajo vec[],int size);
void listarColoresDeMotos(e_Color colores[],int size);
void listarServiciosDeMotos (e_Servicio servicios[],int size);
void listarTiposDeMotos (e_tipoDeMoto tipos[],int size);
void modificarMoto (e_Moto vec[],int size,e_tipoDeMoto tipos[],int sizeTipos,e_Servicio servicios[],int sizeServicios,e_Color colores[], int sizeColores);
void mostrarCilindradas ();
void mostrarMoto (e_Moto moto,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos);
void mostrarMotos(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos);
void mostrarPrimerMoto (e_Moto moto,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos);


int main()
{
    char opcion;
    int opcionOrdenar;
    int idOrigenMoto = 100000;
    int idOrigenTrabajo = 100;

    e_Moto motos[TAMMOTOS];
    e_Trabajo trabajos[TAMTRABAJOS];
    e_Servicio servicios [TAMSERVICIOS] = {{20000,"Limpieza",250}, {20001,"Ajuste",300}, {20002,"Balanceo",17}, {20003,"Cadena",190}};
    e_Color colores[TAMCOLORES] = {{10000,"Gris"},{10001,"Negro"},{10002,"Blanco"},{10003,"Azul"},{10004,"Rojo"}};
    e_tipoDeMoto tiposDeMoto[TAMTIPOS] = {{1000,"Enduro"},{1001,"Chopera"},{1002,"Scooter"},{1003,"Ciclomotor"}};

    inicializarMotos(motos,TAMMOTOS);
    inicializarTrabajos(trabajos,TAMTRABAJOS);
    hardcodearMotos(motos,CANT_HARDCODE);
    hardcodearTrabajos(trabajos,CANT_HARDCODE);

    idOrigenMoto += CANT_HARDCODE;
    idOrigenTrabajo += CANT_HARDCODE;

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 'a':
        getMoto(motos,TAMMOTOS,tiposDeMoto,TAMTIPOS,servicios,TAMSERVICIOS,colores,TAMCOLORES);
        system("pause");
            break;
        case 'b':
        modificarMoto(motos,TAMMOTOS,tiposDeMoto,TAMTIPOS,servicios,TAMSERVICIOS,colores,TAMCOLORES);
        system("pause");
            break;
        case 'c':
        printf("CASO C");
        system("pause");
            break;
        case 'd':
        mostrarMotos(motos,TAMMOTOS,colores,TAMCOLORES,tiposDeMoto,TAMTIPOS);
        system("pause");
            break;
        case 'e':
        system("cls");
        listarTiposDeMotos(tiposDeMoto,TAMTIPOS);
        system("pause");
            break;
        case 'f':
        system("cls");
        listarColoresDeMotos(colores,TAMCOLORES);
        system("pause");
            break;
        case 'g':
        system("cls");
        listarServiciosDeMotos(servicios,TAMSERVICIOS);
        system("pause");
            break;
        case 'h':
        printf("CASO H");
        system("pause");
            break;
        case 'i':
        printf("CASO I");
        system("pause");
            break;
        case 'j':
        printf("CASO J");
        system("pause");
            break;
        }
    }
    while (opcion != 'j');

    return 0;
}

void hardcodearMotos (e_Moto vec[],int size){
for (int i = 0;i<size;i++){
    vec[i].id = idsMoto[i];
    strcpy(vec[i].marca,marcasMoto[i]);
    vec[i].cilindrada = cilindradas[i];
    vec[i].idTipo = tiposMoto[i];
    vec[i].idColor = idsColor[i];
    vec[i].isFull = 1;
}
}

void hardcodearTrabajos (e_Trabajo vec[],int size){
for (int i = 0;i<size;i++){
    vec[i].id = idsTrabajo[i];
    vec[i].idServicio = idsServicio[i];
    vec[i].idMoto = idsMoto[i];
    vec[i].isFull = 1;
    vec[i].fechaDeTrabajo.day = days[i];
    vec[i].fechaDeTrabajo.month = months[i];
    vec[i].fechaDeTrabajo.year = years[i];
}
}

void inicializarMotos (e_Moto vec[],int size)
{
    for (int i = 0; i<size; i++)
    {
        vec[i].isFull = 0;
    }
}

void inicializarTrabajos (e_Trabajo vec[],int size)
{
    for (int i = 0; i<size; i++)
    {
        vec[i].isFull = 0;
    }
}

char menu()
{
    char opcion;
    system("cls");
    printf("****MENU DE OPCIONES****\n\n");
    printf("A- NUEVA ALTA DE MOTO \n");
    printf("B- MODIFICAR MOTO \n");
    printf("C- BAJA DE MOTO \n");
    printf("D- LISTAR MOTOS \n");
    printf("E- LISTAR TIPOS DE MOTOS \n");
    printf("F- LISTAR COLORES DE MOTOS \n");
    printf("G- LISTAR SERVICIOS \n");
    printf("H- ALTA DE TRABAJO \n");
    printf("I- LISTAR TRABAJOS \n");
    printf("J- SALIR \n");

    ac_getChar(&opcion,"Ingrese opcion: ",'0','0','0','0','0',3);
    opcion = tolower(opcion);
    while (opcion != 'a' && opcion != 'b' && opcion != 'c' && opcion != 'd' && opcion != 'e' && opcion != 'f' && opcion != 'g' && opcion != 'h' && opcion != 'i' && opcion != 'j'){
        ac_getChar(&opcion,"Error. Ingrese opcion: ",'0','0','0','0','0',3);
    }
    return opcion;
}

void listarTiposDeMotos (e_tipoDeMoto tipos[],int size){
printf("*TIPOS DE MOTO*\n");
for (int i = 0;i<size;i++){
printf("%d- %s\n",i+1,tipos[i].descripcion);
}
}
void listarColoresDeMotos(e_Color colores[],int size){
printf("*COLORES DE MOTO*\n");
for (int i = 0;i<size;i++){
printf("%d- %s\n",i+1,colores[i].nombreColor);
}
}

void listarServiciosDeMotos (e_Servicio servicios[],int size){
printf("*SERVICIOS*\n");
for (int i = 0;i<size;i++){
printf("%d- %s ($%d)\n",i+1,servicios[i].descripcion,servicios[i].precio);
}
}

void mostrarCilindradas (){
printf("CILINDRADA: \n");
printf("1- 50 \n");
printf("2- 125 \n");
printf("3- 500 \n");
printf("4- 600 \n");
printf("5- 750 \n");
}

int getEmptySlotMoto (e_Moto vec[],int size)
{
    int lugar = -1;
    int flag = 0;
    for (int i = 0; i<size && flag == 0; i++)
    {
        if (vec[i].isFull == 0)
        {
            lugar = i;
            flag = 1;
        }
    }
    return lugar;
}

int getEmptySlotTrabajo (e_Trabajo vec[],int size)
{
    int lugar = -1;
    int flag = 0;
    for (int i = 0; i<size && flag == 0; i++)
    {
        if (vec[i].isFull == 0)
        {
            lugar = i;
            flag = 1;
        }
    }
    return lugar;
}

int getMoto (e_Moto vec[],int size,e_tipoDeMoto tipos[],int sizeTipos,e_Servicio servicios[],int sizeServicios,e_Color colores[], int sizeColores)
{
    system("cls");
    int i = getEmptySlotMoto(vec,size);
    int todoBien = 0;
    int aux;
    int auxTipo;
    int auxColor;
    int auxCilindrada;

    if (i != -1)
    {
        printf("****ALTA DE MOTO****\n");
            do {
            if (ac_getInt(&aux,100000,999999,"Ingese ID de moto: (xxxxxx)",3)== -1){
                break;
            } else if (buscarMoto(aux,vec,size)== -1){
            vec[i].id = aux;
            if (ac_getString(vec[i].marca,20,5,"Ingrese marca de la moto: ") == -1){
                break;
            }
            normalizeString( vec[i].marca);
            listarTiposDeMotos(tipos,sizeTipos);
            if (ac_getInt(&auxTipo,1,sizeTipos,"Ingrese tipo de moto: ",3)==-1){
                break;
            }
            vec[i].idTipo = auxTipo+999;
            listarColoresDeMotos(colores,sizeColores);
            if (ac_getInt(&auxColor,1,sizeColores,"Ingrese color de la moto",3) == -1){
            break;
            }
            vec[i].idColor = auxColor+9999;
            mostrarCilindradas();
            if (ac_getInt(&auxCilindrada,1,5,"Ingrese tipo de cilindrada: ",3)==-1){
                break;
            }
            switch (auxCilindrada){
            case 1:
            vec[i].cilindrada = 50;
            break;
            case 2:
            vec[i].cilindrada = 125;
            break;
            case 3:
            vec[i].cilindrada = 500;
            break;
            case 4:
            vec[i].cilindrada = 600;
            break;
            case 5:
            vec[i].cilindrada = 750;
            break;
            }
            } else {
            printf("El ID que ha ingresado ya corresponde a una moto en el sistema.");
            break;
            }
            vec[i].isFull = 1;
            printf("\nAlta de moto realizada con exito. \n");
            todoBien = 1;
            system("pause");
            } while (todoBien == 0);
    }
    else
    {
        printf("No hay lugar disponible.\n");
        system("pause");
    }
    return todoBien;
}


void modificarMoto (e_Moto vec[],int size,e_tipoDeMoto tipos[],int sizeTipos,e_Servicio servicios[],int sizeServicios,e_Color colores[], int sizeColores)
{
int aux;
int indiceMotoBaja;
int opcion;
int auxTipo;
int auxColor;
int auxCilindrada;
system("cls");
printf("****MODIFICACION DE MOTO****\n");
        ac_getInt(&aux,000000,999999,"Ingrese ID de moto a modificar (xxxxxx)",5);
        indiceMotoBaja = buscarMoto(aux,vec,size);
        if ( indiceMotoBaja == -1)
        {
            printf("La moto que desea modificar no existe.\n");
            system("pause");
        }
        else
        {
            do {
            system("cls");
            printf("Datos de la moto\n");
            mostrarMoto(vec[indiceMotoBaja],colores,sizeColores,tipos,sizeTipos);
            printf("\nDato a modificar:\n");
            printf("1-Marca\n");
            printf("2-Tipo\n");
            printf("3-Color\n");
            printf("4-Cilindrada\n");
            printf("5-Volver a menu principal\n");
            fflush(stdin);
            scanf("%d",&opcion);

            switch (opcion){
            case 1:
            if (ac_getString(vec[indiceMotoBaja].marca,20,3,"Ingrese nueva marca de la moto: ") == -1){
                break;
            }
            normalizeString( vec[indiceMotoBaja].marca);
            printf("Modificacion realizada con exito");
            break;
            case 2:
            listarTiposDeMotos(tipos,sizeTipos);
            if (ac_getInt(&auxTipo,1,sizeTipos,"Ingrese tipo de moto: ",3)==-1){
                break;
            }
            vec[indiceMotoBaja].idTipo = auxTipo+999;
            printf("Modificacion realizada con exito");
            break;
            case 3:
            listarColoresDeMotos(colores,sizeColores);
            if (ac_getInt(&auxColor,1,sizeColores,"Ingrese color de la moto",3) == -1){
            break;
            }
            vec[indiceMotoBaja].idColor = auxColor+9999;
            break;
            case 4:
            mostrarCilindradas();
            if (ac_getInt(&auxCilindrada,1,5,"Ingrese tipo de cilindrada: ",3)==-1){
                break;
            }
            switch (auxCilindrada){
            case 1:
            vec[indiceMotoBaja].cilindrada = 50;
            break;
            case 2:
            vec[indiceMotoBaja].cilindrada = 125;
            break;
            case 3:
            vec[indiceMotoBaja].cilindrada = 500;
            break;
            case 4:
            vec[indiceMotoBaja].cilindrada = 600;
            break;
            case 5:
            vec[indiceMotoBaja].cilindrada = 750;
            break;
            }
            printf("Modificacion realizada con exito");
            break;
            case 5:
            break;
            }
            } while (opcion != 5);
}
}

int buscarMoto (int id,e_Moto vec[],int size)
{
    int lugar = -1;
    for (int i= 0; i<size; i++)
    {
        if (vec[i].id == id && vec[i].isFull == 1)
        {
            lugar = i;
            break;
        }
    }
    return lugar;
}

void mostrarMoto (e_Moto moto,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos){

printf("%6d  %20s        %10s      %10s     %4d\n",moto.id,moto.marca,tipos[moto.idTipo-1000].descripcion,colores[moto.idColor-10000].nombreColor,moto.cilindrada);
}
void mostrarPrimerMoto (e_Moto moto,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos){

printf("ID                     MARCA              TIPO            COLOR     CILINDRADA\n");
printf("%6d  %20s        %10s      %10s     %4d\n",moto.id,moto.marca,tipos[moto.idTipo-1000].descripcion,colores[moto.idColor-10000].nombreColor,moto.cilindrada);
}


void mostrarMotos(e_Moto motos[],int size,e_Color colores[],int sizeColores, e_tipoDeMoto tipos[],int sizeTipos)
{
    int flag = 0;

    printf("****LISTA DE MOTOS****\n\n");
printf("ID                     MARCA              TIPO            COLOR     CILINDRADA\n");

    for (int i = 0; i<size; i++)
    {
        if (motos[i].isFull == 1)
        {
            flag = 1;
        mostrarMoto(motos[i],colores,sizeColores,tipos,sizeTipos);
        }
    }

    if (flag == 0)
        {
            printf("No hay motos que mostrar\n");
        }
        system("pause");
}

