#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "peliculas.h"
#include "directores.h"

int main()
{
    int opcion;
    int flagValidacion = 0;
    int auxiliarId;
    char auxiliarTitulo[51];
    int auxiliarAnio;
    char auxiliarNacionalidad[51];
    int auxiliarDirector;
    int lugarLibre;

    sPelicula arrayPeliculas[MAX];
//    sDirector arrayDirectores[MAX];
    inicializarPeliculasEstado(arrayPeliculas, MAX);
//    inicializarDirectoresEstado(arrayDirectores, MAX);
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
                printf("Ingrese el Titulo: ");
                fflush(stdin);
                scanf("%s", auxiliarTitulo);
                auxiliarTitulo[0]=toupper(auxiliarTitulo[0]);
                printf("Ingrese el año: ");
                fflush(stdin);
                scanf("%d", &auxiliarAnio);
                printf("Ingrese la nacionalidad: ");
                fflush(stdin);
                scanf("%s", auxiliarNacionalidad);
                auxiliarNacionalidad[0]=toupper(auxiliarNacionalidad[0]);
                printf("Ingrese el director: ");
                fflush(stdin);
                scanf("%d", &auxiliarDirector);
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
                mostrarListaPeliculas(arrayPeliculas, MAX);
                system("pause");
                system("cls");
                break;
            }
            else
            {
                printf("No se ingreso ningun dato\n");
                system("pause");
                system("cls");
                break;
            }
            break;
        case 4:
            printf("\nGracias por utilizar nuestro sistema\n\n");
            break;
        }
    }
    while(opcion != 4);


    return 0;
}




//2. MODIFICAR DATOS DE UNA PELÍCULA: Se ingresará el identificador de la película, permitiendo modificar:
//
//• Titulo
//• Año
//• Nacionalidad
//• Director
//
//El usuario elegirá qué dato modificar.
//3. BAJA DE PELÍCULA: Se ingresará el identificador de película y se marcará a esta como inhabilitada.
//4. --
//5. --
//6. LISTAR:
//a)	Peliculas
//b)	--
