#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float num1;
    float num2;
    int flag=0;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    float respuesta3;
    float respuesta4;
    float respuesta5;
    float respuesta6;
    float respuesta7;


    while(seguir=='s')
    {
        if(flag1==1)
        {
            printf("1- Ingresar 1er operando (A=%.2f)\n",num1);
            printf("2- Ingresar 2do operando (B=y)\n");
            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operacione\n");
            printf("9- Salir\n");

            scanf("%d",&opcion);
        }
        else
        {
            if(flag==1)
            {
                printf("1- Ingresar 1er operando (A=%.2f)\n",num1);
                printf("2- Ingresar 2do operando (B=%.2f)\n",num2);
                printf("3- Calcular la suma (A+B)\n");
                printf("4- Calcular la resta (A-B)\n");
                printf("5- Calcular la division (A/B)\n");
                printf("6- Calcular la multiplicacion (A*B)\n");
                printf("7- Calcular el factorial (A!)\n");
                printf("8- Calcular todas las operacione\n");
                printf("9- Salir\n");

                scanf("%d",&opcion);
                flag3=1;

            }
            else
            {
                if(flag2==1)
                {
                    printf("1- Ingresar 1er operando (A=x)\n");
                    printf("2- Ingresar 2do operando (B=%.2f)\n",num2);
                    printf("3- Calcular la suma (A+B)\n");
                    printf("4- Calcular la resta (A-B)\n");
                    printf("5- Calcular la division (A/B)\n");
                    printf("6- Calcular la multiplicacion (A*B)\n");
                    printf("7- Calcular el factorial (A!)\n");
                    printf("8- Calcular todas las operacione\n");
                    printf("9- Salir\n");

                    scanf("%d",&opcion);
                }
                else
                {
                    printf("1- Ingresar 1er operando (A=x)\n");
                    printf("2- Ingresar 2do operando (B=y)\n");
                    printf("3- Calcular la suma (A+B)\n");
                    printf("4- Calcular la resta (A-B)\n");
                    printf("5- Calcular la division (A/B)\n");
                    printf("6- Calcular la multiplicacion (A*B)\n");
                    printf("7- Calcular el factorial (A!)\n");
                    printf("8- Calcular todas las operacione\n");
                    printf("9- Salir\n");

                    scanf("%d",&opcion);
                }
            }
        }
        switch(opcion)
        {
        case 1:
            num1=operando1(num1);
            flag1=1;
            if(flag2==1)
            {
                flag=1;
                flag2=0;
                flag1=0;
            }
            break;
        case 2:
            num2=operando2(num2);
            if(flag1==1)
            {
                flag=1;
                flag1=0;
            }
            else
            {
                flag2=1;
            }
            break;
        case 3:
            if(flag3!=1)
            {
                printf("para realizar la operacion debe registrar dos numeros en la opcion (1 y 2) \n");
            }
            else
            {
                respuesta3=sumar(num1,num2);
                printf("%.2f \n",respuesta3);

            }
            break;
        case 4:
            if(flag3!=1)
            {
                printf("para realizar la operacion debe registrar dos numeros en la opcion (1 y 2) \n");
            }
            else
            {
                respuesta4=restar(num1,num2);
                printf("%.2f \n",respuesta4);
            }
            break;
        case 5:
            if(flag3!=1)
            {
                printf("para realizar la operacion debe registrar dos numeros en la opcion (1 y 2) \n");
            }
            else
            {
                respuesta5=division(num1,num2);
                printf("%.2f \n",respuesta5);
            }
            break;
        case 6:
            if(flag3!=1)
            {
                printf("para realizar la operacion debe registrar dos numeros en la opcion (1 y 2) \n");
            }
            else
            {
                respuesta6=multiplicacion(num1,num2);
                printf("%.2f \n",respuesta6);
            }
            break;
        case 7:
            if(flag==1)
            {
                printf("no se puede realizar la operacion con dos numeros ingresados.  \n");
            }
            else
            {
                if(flag1==0)
                {
                    printf("para realizar esta operacion debe tener un numero cargados en la opcion 1. \n");
                }
                else
                {
                    respuesta7=factorial(num1);
                    printf("%.2f \n",respuesta7);
                }
            }
            break;
        case 8:
            if(flag==0)
            {
                printf("para realizar esta operacion debe tener dos numeros cargados en ala opcion 1 y 2. \n");
            }
            else
            {
                if(flag==1)
                {
                    respuesta3=sumar(num1,num2);
                    respuesta4=restar(num1,num2);
                    respuesta5=division(num1,num2);
                    respuesta6=multiplicacion(num1,num2);
                    respuesta7=factorial(num1);
                    printf("la sumatoria de los numeros es: %.2f \n",respuesta3);
                    printf("la resta de los numeros es: %.2f \n",respuesta4);
                    printf("la divicion de los numeros es: %.2f \n",respuesta5);
                    printf("la multiplicacion de los numeros es: %.2f \n",respuesta6);
                    printf("el factorial es: %.2f \n",respuesta7);

                }
            }

            break;
        case 9:
            seguir = 'n';
            break;
        }
    }
    return 0;
}
