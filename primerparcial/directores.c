#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"
#include "directores.h"
#include "utn.h"

int inicializarDirectoresEstado(sDirector* arrayDirectores, int capacidad)
{
    int retorno = -1;
    if(arrayDirectores != NULL && capacidad!=0)
    {
        retorno = 0;
        for(int i=0; i<capacidad; i++)
        {
            arrayDirectores[i].isEmpty = 1;
        }
    }
    return retorno;
}

int buscarLibreDirector(sDirector* arrayDirectores, int capacidad)
{
    int retorno = -1;
    int i;
    if(capacidad > 0 && arrayDirectores != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayDirectores[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int nuevoIDDirector()
{
    static int idDirector=0;

    idDirector++;

    return idDirector;
}

int agregarDirector(sDirector* arrayDirectores, int capacidad, int auxiliarIdDirector, char auxiliarNombre[], char auxiliarFechaNacimiento[], char auxiliarPais[])
{

    int retorno = -1;
    int idDirector = 0;
    int indexDirector = buscarLibreDirector(arrayDirectores,capacidad);
    int posicionDirector = encontrarDirectorPorID(arrayDirectores, MAX, indexDirector);
    if(capacidad > 0 && arrayDirectores != NULL)
    {
        if(indexDirector != -1)
        {
            if(arrayDirectores[posicionDirector].isEmpty==0)
            {
                idDirector = nuevoIDDirector();
            }
            arrayDirectores[indexDirector].id=idDirector+1;
            while(strlen(auxiliarNombre)>50)
            {
                printf("El nombre es demasiado largo, ingreselo nuevamente: ");
                fflush(stdin);
                gets(auxiliarNombre);
            }
            auxiliarNombre[0]=toupper(auxiliarNombre[0]);

            while(strlen(auxiliarFechaNacimiento)>12)
            {
                printf("Fecha de nacimiento invalida, ingresela nuevamente (01/01/1900) ");
                fflush(stdin);
                gets(auxiliarFechaNacimiento);
            }

            while(strlen(auxiliarPais)>50)
            {
                printf("El nombre del pais es demasiado largo, ingresela nuevamente (01/01/1900) ");
                fflush(stdin);
                gets(auxiliarPais);
            }

            strcpy(arrayDirectores[indexDirector].nombre, auxiliarNombre);
            strcpy(arrayDirectores[indexDirector].fechaNacimiento, auxiliarFechaNacimiento);
            strcpy(arrayDirectores[indexDirector].pais, auxiliarPais);
            arrayDirectores[indexDirector].isEmpty = OCUPADO;
            retorno = 0;

            printf("El director se registro correctamente.\n");
            system("pause");
            system("cls");

        }
    }
    return retorno;
}

int encontrarDirectorPorID(sDirector* arrayDirectores, int capacidad, int id)
{
    int i;
    for(i=0; i<capacidad; i++)
    {
        if(arrayDirectores[i].id == id && arrayDirectores[i].isEmpty == 0)
        {
            return i;
            break;
        }
    }
    return -1;
}


int mostrarListaDirectores(sDirector* arrayDirectores, int cantidad)
{
    int retorno = -1;
    int i;
    printf("%5s %25s %20s %15s\n", "ID","NOMBRE","FECHA DE NACIMIENTO","PAIS");
    for(i=0; i<cantidad; i++)
    {
        if(arrayDirectores[i].isEmpty == 0)
        {
            printf("%5d %25s %15s %15s\n", arrayDirectores[i].id, arrayDirectores[i].nombre, arrayDirectores[i].fechaNacimiento, arrayDirectores[i].pais);
        }
    }
    retorno = 0;
    return retorno;
}

int eliminarDirector(sDirector* arrayDirectores, int capacidad, int id)
{
    int retorno = -1;
    int auxiliarId;
    char opcion;

    printf("Ingrese el ID a buscar: \n");
    scanf("%d", &auxiliarId);
    int idDirector=encontrarDirectorPorID(arrayDirectores, MAX, auxiliarId);
    if (idDirector>=0)
    {
        printf("Confirma la baja? S/N\n");
        opcion=getChar("");
        switch(opcion)
        {
        case 's':
            arrayDirectores[idDirector].isEmpty = 1;
            printf("Baja realizada con exito.\n");
            system("pause");
            system("cls");
            break;
        case 'n':
            printf("Se cancelo la baja.\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("Ingrese una opcion valida.\n");
            system("pause");
            system("cls");
            break;
        }
    }
    else
    {
        printf ("ID vacio, intente nuevamente.\n");
        system ("pause");
        system("cls");
    }

    return retorno;
}

