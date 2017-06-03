#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define ARCH	"/C:/Users/leeoe/Desktop/tp3_laboratorio_1/peliculas.html"
#define A 10

int main()
{
    xMovie pelis[A];
    xMovie *pelicula=&pelis[0];
    char seguir='s';
    int opcion=0;
    int agregarPeli;
    int borrarPeli;
    int modificarPeli;

    FILE* HTML;
    FILE* Binario;
    Binario=fopen("peliculas.html","ab+");


    inicializar(pelicula,A);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                  agregarPeli=agregarPelicula(pelicula,A);
                if(agregarPeli==1)
                {
                    printf("no se a podido agregar la pelicula\n");
                }
                else
                {
                    printf("la pelicula fue agregada con exito\n");
                }
                break;
            case 2:
            borrarPeli=borrarPelicula(pelicula,A);
                if(borrarPeli==1)
                {
                    printf("no se a podido borrar la pelicula\n");
                }
                else
                {
                    printf("la pelicula fue borrada con exito con exito\n");
                }
                break;
            case 3:
                 modificarPeli=modificarPelicula(pelicula,A);
                if(modificarPeli==1)
                {
                    printf("no se a podido modificar la pelicula\n");
                }
                else
                {
                    printf("la pelicula fue modificada con exito con exito\n");
                }

               break;
            case 4:
                 mostrarPelicula(pelicula,A);
                fclose(HTML);

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
