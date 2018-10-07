#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"
#include "directores.h"
#include "utn.h"


int inicializarPeliculasEstado(sPelicula* arrayPeliculas, int capacidad)
{
    int retorno = -1;
    if(arrayPeliculas != NULL && capacidad!=0)
    {
        retorno = 0;
        for(int i=0; i<capacidad; i++)
        {
            arrayPeliculas[i].isEmpty = 1;
        }
    }
    return retorno;
}

int menu()
{
    int opcion;
    fflush(stdin);
    printf("MENU:\n"
           "1. Alta pelicula\n"
           "2. Modificar\n"
           "3. Baja pelicula\n"
           "4. Alta director\n"
           "5. Baja director\n"
           "6. Mostrar\n"
           "7. Salir\n"
           "Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 7)
    {
        printf("Por favor, ingrese una opcion valida\n");
        system("pause");
        system("cls");
        fflush(stdin);
        printf("MENU:\n"
           "1. Alta pelicula\n"
           "2. Modificar\n"
           "3. Baja pelicula\n"
           "4. Alta director\n"
           "5. Baja director\n"
           "6. Mostrar\n"
           "7. Salir\n"
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

int subMenuMostrar()
{
    int opcion;
    fflush(stdin);
    printf("1. Mostrar lista peliculas\n"
           "2. Mostrar lista directores\n"
           "Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 2)
    {
        printf("Por favor, ingrese una opcion valida\n");
        system("pause");
        system("cls");
        fflush(stdin);
        printf( "1. Mostrar lista peliculas\n"
                "2. Mostrar lista directores\n"
                "Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    return opcion;
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
    static int id=0;

    id++;

    return id;
}

int agregarPelicula(sPelicula* arrayPeliculas, int capacidad, int auxiliarId, char auxiliarTitulo[], int auxiliarAnio, char auxiliarNacionalidad[], int auxiliarDirector)
{

    int retorno = -1;
    int id = 0;
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
            arrayPeliculas[index].id=id+1;
            while(strlen(auxiliarTitulo)>50)
            {
                printf("El titulo es demasiado largo, ingreselo nuevamente: ");
                fflush(stdin);
                gets(auxiliarTitulo);
            }
            auxiliarTitulo[0]=toupper(auxiliarTitulo[0]);

            while(strlen(auxiliarNacionalidad)>50)
            {
                printf("La nacionalidad es demasiado larga, ingresela nuevamente: ");
                fflush(stdin);
                gets(auxiliarNacionalidad);
            }
            auxiliarNacionalidad[0]=toupper(auxiliarNacionalidad[0]);
            strcpy(arrayPeliculas[index].titulo, auxiliarTitulo);
            strcpy(arrayPeliculas[index].nacionalidad, auxiliarNacionalidad);
            arrayPeliculas[index].anio = auxiliarAnio;
            arrayPeliculas[index].director = auxiliarDirector;
            arrayPeliculas[index].isEmpty = OCUPADO;
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

int eliminarPelicula(sPelicula* arrayPeliculas, int capacidad, int id)
{
    int retorno = -1;
    int auxiliarId;
    char opcion;

    printf("Ingrese el ID a buscar: \n");
    scanf("%d", &auxiliarId);
    int idPelicula=encontrarPeliculaPorID(arrayPeliculas, MAX, auxiliarId);
    if (idPelicula>=0)
    {
        printf("Confirma la baja? S/N\n");
        opcion=getChar("");
        switch(opcion)
        {
        case 's':
            arrayPeliculas[idPelicula].isEmpty = 1;
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

void modificarPelicula(sPelicula* arrayPeliculas, int capacidad)
{
    char auxiliarNuevoTitulo[51];
    char auxiliarNuevaNacionalidad[51];
    int auxiliarNuevoAnio;
    int auxiliarNuevoDirector;
    char opcion;
    int auxiliarId;

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
            getString("Ingrese el nuevo titulo: ", auxiliarNuevoTitulo);
            fflush(stdin);
            while(strlen(auxiliarNuevoTitulo)>50)
            {
                printf("El titulo es demasiado largo, ingreselo nuevamente: ");
                fflush(stdin);
                gets(auxiliarNuevoTitulo);
            }
            auxiliarNuevoTitulo[0]=toupper(auxiliarNuevoTitulo[0]);
            strcpy(arrayPeliculas[idPelicula].titulo, auxiliarNuevoTitulo);
            system("pause");
            system("cls");
            break;
        case 2:
            auxiliarNuevoAnio = getInt("Ingrese el año: ");
            arrayPeliculas[idPelicula].anio = auxiliarNuevoAnio;
            system("pause");
            system("cls");
            break;
        case 3:
            getString("Ingrese la nueva nacionalidad : ", auxiliarNuevaNacionalidad);
            fflush(stdin);
            auxiliarNuevaNacionalidad[0]=toupper(auxiliarNuevaNacionalidad[0]);
            strcpy(arrayPeliculas[idPelicula].nacionalidad, auxiliarNuevaNacionalidad);
            system("pause");
            system("cls");
            break;
        case 4:
            auxiliarNuevoDirector = getInt("Ingrese el director: ");
            arrayPeliculas[idPelicula].director = auxiliarNuevoDirector;
            system("pause");
            system("cls");
            break;
        }
//        printf("Confirma la modificacion? S/N\n");
//        opcion=getChar("");
//        switch(opcion)
//        {
//        case 's':
//            auxiliarNacionalidad[0]=toupper(auxiliarNacionalidad[0]);
//            strcpy(arrayPeliculas[idPelicula].titulo, auxiliarTitulo);
//            strcpy(arrayPeliculas[idPelicula].nacionalidad, auxiliarNacionalidad);
//            arrayPeliculas[idPelicula].anio = auxiliarAnio;
//            arrayPeliculas[idPelicula].director = auxiliarDirector;
//            printf("Modificacion realizada con exito.\n");
//            system("pause");
//            system("cls");
//            break;
//        case 'n':
//            printf("Se cancelo la modificacion.\n");
//            system("pause");
//            system("cls");
//            break;
//        default:
//            printf("Ingrese una opcion valida.\n");
//            break;
//        }
    }
    else
    {
        printf ("ID vacio, intente nuevamente.\n");
        system ("pause");
        system("cls");
    }
}

//int sortEmployees(sPelicula* arrayPeliculas, int cantidad)
//{
//    int retorno = -1;
//    sPelicula aux;
//    if(cantidad > 0 && arrayPeliculas != NULL)
//    {
//        for(int i=0; i<cantidad - 1; i++)
//        {
//            for(int j=i+1; j<cantidad; j++)
//            {
//                if(strcmp(arrayPeliculas[j].lastName, arrayPeliculas[i].lastName) < 0)
//                {
//                    aux = arrayPeliculas[i];
//                    arrayPeliculas[i] = arrayPeliculas[j];
//                    arrayPeliculas[j] = aux;
//                }
//                else if(strcmp(arrayPeliculas[j].lastName, arrayPeliculas[i].lastName) == 0 && arrayPeliculas[j].sector < arrayPeliculas[i].sector)
//                {
//                    aux = arrayPeliculas[i];
//                    arrayPeliculas[i] = arrayPeliculas[j];
//                    arrayPeliculas[j] = aux;
//                }
//            }
//        }
//        retorno = 0;
//    }
//    return retorno;
//}

int mostrarListaPeliculas(sPelicula* arrayPeliculas, int cantidad)
{
    int retorno = -1;
    int i;
    printf("%5s %25s %9s %28s %10s \n", "ID","TITULO","ANIO","NACIONALIDAD","DIRECTOR");
    for(i=0; i<cantidad; i++)
    {
        if(arrayPeliculas[i].isEmpty == 0)
        {
            printf("%5d %25s %9d %28s %7d\n", arrayPeliculas[i].id, arrayPeliculas[i].titulo, arrayPeliculas[i].anio, arrayPeliculas[i].nacionalidad, arrayPeliculas[i].director);
        }
    }
    retorno = 0;
    return retorno;
}
