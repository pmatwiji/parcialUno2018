#define MAX 2
#define ILOGICO -1
#define LIBRE 1
#define OCUPADO 0

typedef struct
{
 int id;
 char titulo[51];
 int anio;
 char nacionalidad[51];
 int director;
 int isEmpty;
} sPelicula;

int menu();
int subMenu();
int subMenuMostrar();
int inicializarPeliculasEstado(sPelicula* arrayPeliculas, int capacidad);
int buscarLibre(sPelicula* arrayPeliculas, int capacidad);
int agregarPelicula(sPelicula* arrayPeliculas, int capacidad, int auxiliarId, char auxiliarTitulo[], int auxiliarAnio, char auxiliarNacionalidad[], int auxiliarDirector);
int encontrarPeliculaPorID(sPelicula* arrayPeliculas, int capacidad, int id);
int mostrarListaPeliculas(sPelicula* arrayPeliculas, int cantidad);
void modificarPelicula(sPelicula* arrayPeliculas, int capacidad);
int eliminarPelicula(sPelicula* arrayPeliculas, int capacidad, int id);
