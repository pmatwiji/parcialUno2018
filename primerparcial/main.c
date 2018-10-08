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
    sDirector arrayDirectores[MAX_DIRECTOR];
    inicializarPeliculasEstado(arrayPeliculas, MAX);
    inicializarDirectoresEstado(arrayDirectores, MAX_DIRECTOR);

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
            if (flagValidacionDirector != 0)
            {
                flagValidacion++;
                lugarLibre=buscarLibre(arrayPeliculas, MAX);
                if (lugarLibre!=-1)
                {
                    getStringLetras("Ingrese el nombre: ", auxiliarTitulo);
                    auxiliarAnio = getValidInt("Ingrese el anio: ","El año no es un año valido", 1900, 2018);
                    getStringLetras("Ingrese la nacionalidad: ", auxiliarNacionalidad);
                    mostrarListaDirectores(arrayDirectores, MAX_DIRECTOR);
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
            }
            else
            {
                printf("No hay directores cargados, cargue un director primero.\n");
                system("pause");
                system("cls");
                break;
            }

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
            lugarLibreDirector=buscarLibreDirector(arrayDirectores, MAX_DIRECTOR);
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
            agregarDirector(arrayDirectores, MAX_DIRECTOR, auxiliarIdDirector, auxiliarNombre, auxiliarFechaNacimiento, auxiliarPais);
            break;
        case 5:
            if(flagValidacionDirector != 0)
            {
                eliminarDirector(arrayDirectores, MAX_DIRECTOR, auxiliarId);
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
            if(flagValidacion == 0 && flagValidacionDirector == 0)
            {
                printf("No se ingreso ningun dato\n");
                system("pause");
                system("cls");
                break;
            }
            else
            {
                opcion = subMenuMostrar();
                switch(opcion)
                {
                case 1:
                    if(flagValidacion != 0)
                    {
                        mostrarListaPeliculas(arrayPeliculas, MAX);
                        system("pause");
                        system("cls");
                        break;
                    }
                    else
                    {
                        printf("No hay peliculas cargadas\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                case 2:
                    if(flagValidacionDirector != 0)
                    {
                        mostrarListaDirectores(arrayDirectores, MAX_DIRECTOR);
                        system("pause");
                        system("cls");
                        break;
                    }
                    else
                    {
                        printf("No hay directores cargados\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                case 3:
                    if(flagValidacion != 0)
                    {
                        mostrarPeliculaMasAntigua(arrayPeliculas, MAX);
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        printf("No hay peliculas cargadas\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }
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





