#define MAX_DIRECTOR 500

typedef struct
{
 int id;
 char nombre[51];
 char fechaNacimiento[12];
 char pais[51];
 int isEmpty;
} sDirector;

int inicializarDirectoresEstado(sDirector* arrayDirectores, int capacidad);
int buscarLibreDirector(sDirector* arrayDirectores, int capacidad);
int agregarDirector(sDirector* arrayDirectores, int capacidad, int auxiliarIdDirector, char auxiliarNombre[], char auxiliarFechaNacimiento[], char auxiliarPais[]);
int mostrarListaDirectores(sDirector* arrayDirectores, int cantidad);
int encontrarDirectorPorID(sDirector* arrayDirectores, int capacidad, int id);
int eliminarDirector(sDirector* arrayDirectores, int capacidad, int id);
