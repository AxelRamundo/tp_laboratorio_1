#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include "funciones.h"
#define C 20

int main()
{
    Persona lista[C];
    char cont='N';
    int i;

    for(i=0; i<C; i++)
    {
        lista[i].estado=0;
        lista[i].edad=0;
    }

    do
    {
        switch(menu())
        {
        case '1':
            system("cls");
            alta(lista);
            break;
        case '2':
            system("cls");
            baja(lista);
            break;
        case '3':
            system("cls");
            ordAlfa(lista);
            break;
        case '4':
            system("cls");
            graf(lista);
            break;
        case '5':
            cont=salir();
            break;
        default:
            notOp();
        }
    }while(cont=='N');

    return 0;
}
