#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"
#include "directores.h"

int menu()
{
    int opcion;
    fflush(stdin);
    printf("MENU:\n"
           "1. Alta pelicula\n"
           "2. Modificar\n"
           "3. Mostrar\n"
           "4. Salir\n"
           "Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 3)
    {
        printf("Por favor, ingrese una opcion valida\n");
        system("pause");
        system("cls");
        fflush(stdin);
        printf("MENU:\n"
               "1. Alta pelicula\n"
               "2. Modificar\n"
               "3. Mostrar\n"
               "3. Salir\n"
               "Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    return opcion;
}

int subMenu()
{
    int opcion;
    fflush(stdin);
    printf("1. Titulo\n"
           "2. Año\n"
           "3. Nacionalidad\n"
           "4. Director\n"
           "Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 4)
    {
        printf("Por favor, ingrese una opcion valida\n");
        system("pause");
        system("cls");
        fflush(stdin);
        printf("1. Titulo\n"
               "2. Año\n"
               "3. Nacionalidad\n"
               "4. Director\n"
               "Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    return opcion;
}

int inicializarPeliculasEstado(sPelicula* arrayPeliculas, int capacidad)
{
    int retorno = -1;
    int i;
    if(arrayPeliculas != NULL && capacidad!=0)
    {
        retorno = 0;
        for(i=0; i<capacidad; i++)
        {
            arrayPeliculas[i].isEmpty = 1;
        }
    }
    return retorno;
}

int buscarLibre(sPelicula* arrayPeliculas, int capacidad)
{
    int retorno = -1;
    int i;
    if(capacidad > 0 && arrayPeliculas != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayPeliculas[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int nuevoID()
{
    static int id=-1;

    id ++;

    return id;
}

int mostrarListaPeliculas(sPelicula* arrayPeliculas, int cantidad)
{
    int retorno = -1;
    int i;
    printf("%5s %30s %6s %20s %5s \n", "ID","TITULO","AÑO","NACIONALIDAD","DIRECTOR");
    for(i= 0; i < cantidad; i++)
    {
        if(arrayPeliculas[i].isEmpty == 0)
        {
            printf("%5d %30s %6d %20s %5d\n", arrayPeliculas[i].id, arrayPeliculas[i].titulo, arrayPeliculas[i].anio, arrayPeliculas[i].nacionalidad, arrayPeliculas[i].director);
        }
    }
    retorno = 0;
    return retorno;
}
int agregarPelicula(sPelicula* arrayPeliculas, int capacidad, int auxiliarId, char auxiliarTitulo[], int auxiliarAnio, char auxiliarNacionalidad[], int auxiliarDirector)
{

    int retorno = -1;
    int id;
    int index = buscarLibre(arrayPeliculas,capacidad);
    int posicionPelicula = encontrarPeliculaPorID(arrayPeliculas, MAX, index);
    if(capacidad > 0 && arrayPeliculas != NULL)
    {
        if(index != -1)
        {
            if(arrayPeliculas[posicionPelicula].isEmpty==0)
            {
                id = nuevoID();
            }
            arrayPeliculas[index].id=id;
            while(strlen(auxiliarTitulo)>50)
            {
                printf("El nombre es demasiado largo, ingreselo nuevamente: ");
                fflush(stdin);
                gets(auxiliarTitulo);
            }
            auxiliarTitulo[0]=toupper(auxiliarTitulo[0]);
            strcpy(arrayPeliculas[index].titulo, auxiliarTitulo);
            arrayPeliculas[index].anio = auxiliarAnio;
            strcpy(arrayPeliculas[index].nacionalidad, auxiliarNacionalidad);
            arrayPeliculas[index].director = auxiliarDirector;
            arrayPeliculas[index].isEmpty = 0;
            retorno = 0;

            printf("La pelicula se registro correctamente.\n");
            system("pause");
            system("cls");
        }
    }
    return retorno;
}

int encontrarPeliculaPorID(sPelicula* arrayPeliculas, int capacidad, int id)
{
    int i;
    for(i=0; i<capacidad; i++)
    {
        if(arrayPeliculas[i].id == id && arrayPeliculas[i].isEmpty == 0)
        {
            return i;
            break;
        }
    }
    return -1;
}
void modificarPelicula(sPelicula* arrayPeliculas, int capacidad)
{
    int auxiliarId;
    char auxiliarTitulo[51];
    int auxiliarAnio;
    char auxiliarNacionalidad[51];
    int auxiliarDirector;
    char opcion;

    printf("Ingrese el ID a buscar: \n");
    scanf("%d", &auxiliarId);
    int idPelicula=encontrarPeliculaPorID(arrayPeliculas, MAX, auxiliarId);
    if (idPelicula>=0)
    {
        printf("ID encontrado, modifique los datos a continuacion: \n");
        opcion = subMenu();
        switch(opcion)
        {
        case 1:
            printf("Ingrese el Titulo: ");
            fflush(stdin);
            scanf("%s", auxiliarTitulo);
            while(strlen(auxiliarTitulo)>50)
            {
                printf("El nombre es demasiado largo, ingreselo nuevamente: ");
                fflush(stdin);
                gets(auxiliarTitulo);
            }
            auxiliarTitulo[0]=toupper(auxiliarTitulo[0]);
            strcpy(arrayPeliculas[idPelicula].titulo, auxiliarTitulo);
            break;
        case 2:
            printf("Ingrese el año: ");
            fflush(stdin);
            scanf("%d", &auxiliarAnio);
            break;
        case 3:
            printf("Ingrese la nacionalidad: ");
            fflush(stdin);
            scanf("%s", auxiliarNacionalidad);
            auxiliarNacionalidad[0]=toupper(auxiliarNacionalidad[0]);
            arrayPeliculas[idPelicula].anio = auxiliarAnio;
            strcpy(arrayPeliculas[idPelicula].nacionalidad, auxiliarNacionalidad);
            break;
        case 4:
            printf("Ingrese el director: ");
            fflush(stdin);
            scanf("%d", &auxiliarDirector);
            arrayPeliculas[idPelicula].director = auxiliarDirector;
            break;
        }

        printf("Confirma la modificacion? S/N\n");
        fflush(stdin);
        scanf("%c", &opcion);
        switch(opcion)
        {
        case 's':
            printf("Modificacion realizada con exito.\n");
            system("pause");
            system("cls");
            break;
        case 'n':
            printf("Se cancelo la modificacion.\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("Ingrese una opcion valida.\n");
            break;
        }
    }
    else
    {
        printf ("ID vacio, intente nuevamente.\n");
        system ("pause");
        system("cls");
    }
}
