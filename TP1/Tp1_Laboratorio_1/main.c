#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0, x=0, y=0,v=0,w=0;

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%d)\n",x);
        printf("2- Ingresar 2do operando (B=%d)\n",y);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                x = num1(x);
                break;
            case 2:
                y = num2(y);
                break;
            case 3:
                suma(x,y);
                system("pause");
                system("cls");
                break;
            case 4:
                resta(x,y);
                system("pause");
                system("cls");
                break;
            case 5:
                division(x,y);
                system("pause");
                system("cls");
                break;
            case 6:
                multiplicacion(x,y);
                system("pause");
                system("cls");
                break;
            case 7:
                factorial(x);
                system("pause");
                system("cls");
                break;
            case 8:
                suma(x,y);
                resta(x,y);
                division(x,y);
                multiplicacion(x,y);
                factorial(x);
                system("pause");
                system("cls");
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                error();
        }
    }

    return 0;

}
