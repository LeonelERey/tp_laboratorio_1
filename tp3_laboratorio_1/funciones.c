#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int agregarPelicula(xMovie* pelicula,int tam)
{
    int lugar;
    int flag=0;

    lugar=buscarLugar(pelicula,tam);
    if(lugar==-1)
    {
        printf("no hay mas lugar!!!");
        flag=1;
    }
    else
    {

        (pelicula+lugar)->idPelicula=lugar+1;
        printf("================================================================================\n");
        printf("ingrese el nombre de la pelicula: ");
        fflush(stdin);
        gets((pelicula+lugar)->titulo);
        printf("================================================================================\n");
        printf("ingrese el genero de la pelicula: ");
        fflush(stdin);
        gets((pelicula+lugar)->genero);
        printf("================================================================================\n");
        printf("ingrese la duracion de la pelicula en minutos:");
        scanf("%d", &(pelicula+lugar)->duracion);
        while((pelicula+lugar)->duracion<60||(pelicula+lugar)->duracion>190)
        {
            printf("================================================================================\n");
            printf("ingrese una duracion coherente:");
            scanf("%d", &(pelicula+lugar)->duracion);

        }
        printf("================================================================================\n");
        printf("ingrese la descripcion de la pelicula: ");
        fflush(stdin);
        gets((pelicula+lugar)->descripcion);
        printf("================================================================================\n");
        printf("ingrese la puntuaion de la pelicula entre 1 y 10:");
        scanf("%d", &(pelicula+lugar)->puntaje);
        while((pelicula+lugar)->puntaje<1||(pelicula+lugar)->puntaje>10)
        {
            printf("================================================================================\n");
            printf("ingrese una puntuacion entre 1 y 10:");
            scanf("%d", &(pelicula+lugar)->puntaje);

        }
        printf("================================================================================\n");
        fflush(stdin);
        printf("\nLink De Imagen: ");
        gets((pelicula+lugar)->linkImagen);
    }
    return flag;
}
void inicializar(xMovie* pelicula,int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        strcpy((pelicula+i)->titulo,"");
        strcpy((pelicula+i)->genero,"");
        (pelicula+i)->duracion=-1;
        strcpy((pelicula+i)->descripcion,"");
        (pelicula+i)->puntaje=-1;
        strcpy((pelicula+i)->linkImagen,"");
        (pelicula+1)->idPelicula=-1;

    }
}
int buscarLugar(xMovie* pelicula,int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
    {
        if((pelicula+1)->idPelicula==-1)
        {
            flag=i;
            break;
        }
    }
    return flag;
}
int borrarPelicula(xMovie* pelicula,int tam)
{
    int respuesta;
    int auxID;
    int flag;
    int i;
    //mostrarPelicula(pelicula,tam);
    printf("\nIngrese ID de la pelicula que va a borrar: ");
    scanf("%d",&auxID);
    respuesta = buscarId(pelicula,tam,auxID);
    while(respuesta == -1)
    {
        printf("\nel id ingresado no existe ingrese nuevamente: ");
        scanf("%d",&auxID);
        respuesta=buscarId(pelicula,tam,auxID);
    }

    strcpy((pelicula+respuesta)->titulo,"");
    strcpy((pelicula+respuesta)->genero,"");
    (pelicula+respuesta)->duracion = -1;
    strcpy((pelicula+respuesta)->descripcion,"");
    (pelicula+respuesta)->puntaje = -1;
    (pelicula+respuesta)->idPelicula = -1;
    strcpy((pelicula+respuesta)->linkImagen,"");
    flag = 0;

    return flag;
}
int buscarId (xMovie* pelicula,int tam,int aux)
{
    int flag=-1;
    int i;
    for(i=0+1; i<tam+1; i++)
    {
        if((pelicula+i)->idPelicula==aux)
        {
            flag = i;
        }
    }
    return flag;
}
int modificarPelicula(xMovie *pelicula,int tam)
{
    int i;
    int flag;
    int respuesta;
    int auxID;

    /* for(i=0; i<tam; i++)
     {
         if((pelicula+i)->idPelicula==-1)
         {
             flag = 1;
             return flag;

         }
     }*/
    printf("\nIngrese ID de la pelicula que desea modificar: ");
    scanf("%d",&auxID);
    respuesta=buscarId(pelicula,tam,auxID);

    while(respuesta == -1)
    {
        printf("\nel id no existe ingrese uno valido: ");
        scanf("%d",&auxID);
        respuesta=buscarId(pelicula,tam,auxID);
    }
    fflush(stdin);
    (pelicula+respuesta)->idPelicula=respuesta+1;
    printf("================================================================================\n");
    printf("ingrese el nurvo nombre de la pelicula: ");
    fflush(stdin);
    gets((pelicula+respuesta)->titulo);
    printf("================================================================================\n");
    printf("ingrese el nuevo genero de la pelicula: ");
    fflush(stdin);
    gets((pelicula+respuesta)->genero);
    printf("================================================================================\n");
    printf("ingrese la duracion de la nueva pelicula en minutos:");
    scanf("%d", &(pelicula+respuesta)->duracion);
    while((pelicula+respuesta)->duracion<60||(pelicula+respuesta)->duracion>190)
    {
        printf("================================================================================\n");
        printf("ingrese una duracion coherente:");
        scanf("%d", &(pelicula+respuesta)->duracion);

    }
    printf("================================================================================\n");
    printf("ingrese la descripcion de la pelicula: ");
    fflush(stdin);
    gets((pelicula+respuesta)->descripcion);
    printf("================================================================================\n");
    printf("ingrese la puntuaion de la pelicula entre 1 y 10:");
    scanf("%d", &(pelicula+respuesta)->puntaje);
    while((pelicula+respuesta)->puntaje<1||(pelicula+respuesta)->puntaje>10)
    {
        printf("================================================================================\n");
        printf("ingrese una puntuacion entre 1 y 10:");
        scanf("%d", &(pelicula+respuesta)->puntaje);
        printf("================================================================================\n");
        fflush(stdin);
        printf("\nnuevo link De Imagen: ");
        gets((pelicula+respuesta)->linkImagen);

    }

    flag = 0;
    return flag;
}
void mostrarPelicula(xMovie* pelicula,int tam)
{
    int i;
    FILE* HTML;
    char bufer[1000]= {};

    HTML=fopen("C:peliculas.html","r+w");
    for(i=0; i<tam; i++)
    {
        while((pelicula+i)->idPelicula!=-1)
        {

            fprintf(HTML,"<article class='col-md-4 article-intro'>\
                    <a href='#'>\
                    <img class='img-responsive img-rounded' src='%s'\
                    alt=''>\
                    </a>\
                    <h3>\
                    <a href='#'>%s</a>\
                    </h3>\
                    <ul>\
                    <li>Género:%s</li>\
                    <li>Puntaje:%d</li>\
                    <li>Duración:%d</li>\
                    </ul>\
                    <p>%s.</p>\
                    </article>",(pelicula+i)->linkImagen,(pelicula+i)->titulo,(pelicula+i)->genero,(pelicula+i)->puntaje,(pelicula+i)->duracion,(pelicula+i)->descripcion);


            fclose(HTML);
        }
    }
}
