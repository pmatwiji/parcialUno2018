#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"
#include "directores.h"
#include "utn.h"

int main()
{
    sPelicula arrayPeliculas[MAX];
    sDirector arrayDirectores[MAX];
    inicializarPeliculasEstado(arrayPeliculas, MAX);
    inicializarDirectoresEstado(arrayDirectores, MAX);

    int opcion;
    int flagValidacion = 0;
    int flagValidacionDirector = 0;
    int lugarLibre;
    int auxiliarId = 1;
    char auxiliarTitulo[51];
    int auxiliarAnio;
    char auxiliarNacionalidad[51];
    int auxiliarDirector;

    int auxiliarIdDirector = 1;
    char auxiliarNombre[51];
    char auxiliarFechaNacimiento[12];
    char auxiliarPais[51];
    int lugarLibreDirector;

    do
    {
        opcion = menu();
        switch(opcion)
        {
        case 1:
            flagValidacion++;
            lugarLibre=buscarLibre(arrayPeliculas, MAX);
            if (lugarLibre!=-1)
            {
                getString("Ingrese el nombre: ", auxiliarTitulo);
                auxiliarAnio = getInt("Ingrese el anio: ");
                getString("Ingrese la nacionalidad: ", auxiliarNacionalidad);
                auxiliarDirector = getInt("Ingrese el director: ");
            }
            else
            {
                printf("No hay mas espacio\n");
                system("pause");
                system("cls");
            }
            agregarPelicula(arrayPeliculas, MAX, auxiliarId, auxiliarTitulo, auxiliarAnio, auxiliarNacionalidad, auxiliarDirector);
            break;
        case 2:
            if(flagValidacion != 0)
            {
                modificarPelicula(arrayPeliculas, MAX);
                break;
            }
            else
            {
                printf("No se ingreso ningun dato\n");
                system("pause");
                system("cls");
                break;
            }
        case 3:
            if(flagValidacion != 0)
            {
                eliminarPelicula(arrayPeliculas, MAX, auxiliarId);
                break;
            }
            else
            {
                printf("No se ingreso ningun dato\n");
                system("pause");
                system("cls");
                break;
            }
        case 4:
            flagValidacionDirector++;
            lugarLibreDirector=buscarLibreDirector(arrayDirectores, MAX);
            if (lugarLibre!=-1)
            {
                getString("Ingrese el nombre: ", auxiliarNombre);
                getString("Ingrese la fecha de nacimiento (01/01/1900): ", auxiliarFechaNacimiento);
                getString("Ingrese el pais: ", auxiliarPais);
            }
            else
            {
                printf("No hay mas espacio\n");
                system("pause");
                system("cls");
            }
            agregarDirector(arrayDirectores, MAX, auxiliarIdDirector, auxiliarNombre, auxiliarFechaNacimiento, auxiliarPais);
            break;
        case 5:
             if(flagValidacionDirector != 0)
            {
                eliminarDirector(arrayDirectores, MAX, auxiliarId);
                break;
            }
            else
            {
                printf("No se ingreso ningun dato\n");
                system("pause");
                system("cls");
                break;
            }
        case 6:
            if(flagValidacion != 0 && flagValidacionDirector != 0)
            {
                opcion = subMenuMostrar();
                switch(opcion)
                {
                case 1:
                    mostrarListaPeliculas(arrayPeliculas, MAX);
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    mostrarListaDirectores(arrayDirectores, MAX);
                    system("pause");
                    system("cls");
                    break;
                }
                break;
            }
            else
            {
                printf("No se ingreso ningun dato\n");
                system("pause");
                system("cls");
                break;
            }
        case 7:
            printf("\nGracias por utilizar nuestro sistema\n\n");
            break;
        }
    }
    while(opcion != 7);


    return 0;
}





