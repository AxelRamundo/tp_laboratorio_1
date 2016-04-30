#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include "funciones.h"

#define C 20//DDEFINE LA CANTIDAD DE ESPACIOS EN LA MATRIZ LISTA//

/**
 * \brief Se muestra el menu principal y se pide un numero al usuario para ejecutar la funcion correspondiente.
 * \return op Se devuelve la opcion seleccionada por el usuario.
 */

 char menu()
 {
     char op;
     system("cls");
     printf("===============MENU===============\n");
     printf("=    *** ELIJA UNA OPCION ***    =\n");
     printf("==================================\n");
     printf("=  1. DAR DE ALTA A UNA PERSONA  =\n");
     printf("=  2. DAR DE BAJA A UNA PERSONA  =\n");
     printf("=  3. MOSTRAR LISTA DE PERSONAS  =\n");
     printf("=  4. GRAFICO DE EDADES          =\n");
     printf("=  5. SALIR                      =\n");
     printf("==================================\n\n");
     op=getche();
     return op;
 }//FIN DE LA FUNCION MENU//

/**
 * \brief Muestra un mensaje de error en pantalla.
 */

 void notOp()
{
    system("cls");
    printf("===============ERROR==============\n");
    printf("=   *** OPCION  INCORRECTA ***   =\n");
    printf("==================================\n\n");
    system("pause");
}//FIN DE LA FUNCION NOTOP//

/**
 * \brief Busca una posicion libre en la estructura.
 * \param lista El array se pasa como parametro.
 * \return pos Se devuelve la primer posicion libre en la lista.
 */

int buscEs(Persona lista[])
{
    int pos, i;

    for(i=0; i<C; i++)
    {
        if(lista[i].estado!=1)
        {
            pos=i;
            i=C;
        }
    }
    return pos;
}//FIN DE LA FUNCION BUSCES//

/**
 * \brief Se ingresa el DNI de una persona y se valida que no este repetido en la estructura.
 * \param lista El array se pasa como parametro.
 * \param pos La variable pasa indicando la posicion de la lista en la que se ejecuta la funcion.
 * \return valid Se devuelve 1 si el DNI se ingreso correctamente y 0 si se cancela el ingreso.
 */

int ingDNI(Persona lista[], int pos)
{
    char auxDNI[50]={' '}, reIng;
    int i, c=0, valid=1;
    long int dniInt;

    do
    {
        do
        {
            system("cls");
            printf("INGRESE DNI: ");
            fflush(stdin);
            gets(auxDNI);

            for(i=0; i<50; i++)
            {
                while(auxDNI[i]=='.')
                {
                    i++;
                }
                lista[pos].dni[c]=auxDNI[i];
                c++;
            }
            c=0;
            dniInt=atol(lista[pos].dni);

            if(dniInt<1000000||dniInt>99999999)
            {
                system("cls");
                printf("===========================ERROR===========================\n");
                printf("= *** EL DNI DEBE ESTAR ENTRE  1.000.000 y 99.999.999 *** =\n");
                printf("===========================================================\n\n");
                system("pause");
            }

        }while(dniInt<1000000||dniInt>99999999);
        sprintf(auxDNI,"%ld",dniInt);
        if(dniInt<10000000)
        {
            for(i=0; i<9; i++)
            {
                if(i==1||i==4)
                {
                    lista[pos].dni[c]='.';
                    c++;
                    lista[pos].dni[c]=auxDNI[i];
                }else{
                    lista[pos].dni[c]=auxDNI[i];
                }
                c++;
            }
        }else{

            for(i=0; i<10; i++)
            {
                if(i==2||i==5)
                {
                    lista[pos].dni[c]='.';
                    c++;
                    lista[pos].dni[c]=auxDNI[i];
                }else{
                    lista[pos].dni[c]=auxDNI[i];
                }
                c++;
            }
        }

        for(i=0; i<C; i++)
        {
            if(lista[i].estado!=0)
            {
                if(strcmp(lista[pos].dni,lista[i].dni)==0)
                {
                    do
                    {
                        printf("=======================ERROR======================\n");
                        printf("= *** EL DNI YA ESTABA INGRESADO EN LA LISTA *** =\n");
                        printf("=                      * * *                     =\n");
                        printf("=     *** DESEA REINGRESAR EL DNI? [S/N] ***     =\n");
                        printf("==================================================\n\n");
                        reIng=getch();
                        reIng=toupper(reIng);
                        if(reIng!='S' && reIng!='N')
                        {
                            notOp();
                        }
                    }while(reIng!='S' && reIng!='N');
                    valid=0;

                }else{
                    reIng='N';
                    valid=1;
                }
            }
        }
    }while(reIng=='S');

    return valid;
}//FIN DE LA FUNCION INGDNI//

/**
 * \brief Se ingresa el nombre de una persona.
 * \param lista el array se pasa como parametro.
 * \param pos La variable pasa indicando la posicion de la lista en la que se ejecuta la funcion.
 */

void ingN(Persona lista[], int pos)
{
    char auxN[25];
    do
    {
        printf("INGRESE NOMBRE: ");
        fflush(stdin);
        gets(auxN);
        if(strlen(auxN)>20)
        {
            system("cls");
            printf("====================ERROR==================\n");
            printf("=   *** CARACTERES MAXIMOS EXEDIDOS ***   =\n");
            printf("=                   * * *                 =\n");
            printf("=     *** [MAXIMO  20  CARACTERES] ***    =\n");
            printf("===========================================\n\n");
            system("pause");
        }
    }while(strlen(auxN)>20);

    strlwr(auxN);
    auxN[0]=toupper(auxN[0]);
    strcpy(lista[pos].nombre,auxN);

}//FIN DE LA FUNCION INGN//

/**
 * \brief Se ingresa la edad de una persona y se la valida (entre 1 y 120).
 * \param lista el array se pasa como parametro.
 * \param pos La variable pasa indicando la posicion de la lista en la que se ejecuta la funcion.
 */

void ingE(Persona lista[], int pos)
{
    int auxE;
    do
    {
        printf("INGRESE EDAD: ");
        scanf("%d",& auxE);
        if(auxE<1 || auxE>120)
        {
            system("cls");
            printf("=====================ERROR======================\n");
            printf("=   *** LA EDAD DEBE ESTAR ENTRE 1 y 120 ***   =\n");
            printf("================================================\n\n");
            system("pause");
        }

    }while(auxE<1 || auxE>120);

    lista[pos].edad=auxE;
}//FIN DE LA FUNCION INGE//

/**
 * \brief Se busca a una persona por DNI
 * \param lista el array se pasa como parametro
 * \return pos Es devuelve la posicion en la que de encuentra el DNI (de noencontrarse el DNI se devuelve -1)
 */

int buscDNI(Persona lista[])
{
    int i, c=0, pos=-1;
    char auxDNI[50]={' '}, dniCh[25]={' '};
    long int dniInt;

    do
    {
        system("cls");
        printf("INGRESE DNI: ");
        fflush(stdin);
        gets(auxDNI);

        for(i=0; i<50; i++)
        {
            while(auxDNI[i]=='.')
            {
                i++;
            }
            dniCh[c]=auxDNI[i];
            c++;
        }
        c=0;
        dniInt=atol(dniCh);

        if(dniInt<1000000||dniInt>99999999)
        {
            system("cls");
            printf("===========================ERROR===========================\n");
            printf("= *** EL DNI DEBE ESTAR ENTRE  1.000.000 y 99.999.999 *** =\n");
            printf("===========================================================\n\n");
            system("pause");
        }

    }while(dniInt<1000000||dniInt>99999999);
    sprintf(auxDNI,"%ld",dniInt);
    if(dniInt<10000000)
    {
        for(i=0; i<9; i++)
        {
            if(i==1||i==4)
            {
                dniCh[c]='.';
                c++;
                dniCh[c]=auxDNI[i];
            }else{
                dniCh[c]=auxDNI[i];
            }
            c++;
        }
    }else{

        for(i=0; i<10; i++)
        {
            if(i==2||i==5)
            {
                dniCh[c]='.';
                c++;
                dniCh[c]=auxDNI[i];
            }else{
                dniCh[c]=auxDNI[i];
            }
            c++;
        }
    }

    for(i=0;i<C;i++)
    {
        if(lista[i].estado!=0)
        {
            if(strcmp(lista[i].dni,dniCh)==0)
            {
                pos=i;
                i=C;
            }
        }
    }

    return pos;
}//FIN DE LA FUNCION BUSCDNI//

/**
 * \brief Se elimina a una persona de la lista
 * \param lista el array se pasa como parametro
 * \param pos La variable pasa indicando la posicion de la lista en la que se ejecuta la funcion.
 */

void eliminar(Persona lista[], int pos)
{
        char cont;
        do
        {
            system("cls");
            printf("==============================================\n");
            printf("= *** SE ELIMINARAN LOS SIGUIENTES DATOS *** =\n");
            mostrar(lista, pos);
            printf("==============================================\n");
            printf("=       *** DESEA CONTINUAR? [S/N] ***       =\n");
            printf("==============================================\n");
            cont=getch();
            cont=toupper(cont);
            if(cont!='S' && cont!='N')
            {
                notOp();
            }
        }while(cont!='S' && cont!='N');

        if(cont=='S')
        {
            system("cls");
            lista[pos].estado=0;
            printf("==============================================\n");
            printf("=     *** LOS DATOS SE HAN ELIMINADO ***     =\n");
            printf("==============================================\n");
            system("pause");

        }else{
            system("cls");
            printf("==============================================\n");
            printf("=     *** LOS DATOS NO SE ELIMINARON ***     =\n");
            printf("==============================================\n");
            system("pause");
        }

}//FIN DE LA FUNCION ELIMINAR//

/**
 * \brief Se muestran por pantalla los datos de una persona.
 * \param lista el array se pasa como parametro.
 * \param pos La variable pasa indicando la posicion de la lista en la que se ejecuta la funcion.
 */

void mostrar(Persona lista[], int pos)
{
    printf("==============================================\n");
    printf("   NOMBRE: %s\n", lista[pos].nombre);
    printf("   EDAD: %d\n", lista[pos].edad);
    printf("   DNI: %s\n", lista[pos].dni);

}//FIN DE LA FUNCION MOSTRAR//

/**
 * \brief Se ingresan los datos de una persona a la estructura.
 * \param lista el array se pasa como parametro.
 */

void alta(Persona lista[])
{
    int pos=-1,valid;
    char reIng;

    pos=buscEs(lista);
    valid=ingDNI(lista,pos);
    if(valid!=0)
    {
        ingN(lista,pos);
        ingE(lista,pos);
        do
        {
            system("cls");
            printf("==============================================\n");
            printf("=          *** DATOS INGRESADOS ***          =\n");
            mostrar(lista,pos);
            printf("==============================================\n");
            printf("=         *** ES CORRECTO? [S/N] ***         =\n");
            printf("==============================================\n\n");
            reIng=getch();
            reIng=toupper(reIng);
            if(reIng!='S' && reIng!='N')
            {
                notOp();
            }
        }while(reIng!='S' && reIng!='N');

        if(reIng=='S')
        {

            lista[pos].estado=1;
            system("cls");
            printf("==========================================\n");
            printf("= *** DATOS INGRESADOS CORRECTAMENTE *** =\n");
            printf("==========================================\n\n");
            system("pause");

        }else{
            system("cls");
            printf("=========================================\n");
            printf("= *** LOS DATOS NO SE HAN INGRESADO *** =\n");
            printf("=========================================\n\n");
            system("pause");
        }

    }else{
        system("cls");
        printf("=====================================\n");
        printf("= *** NO SE HAN INGRESADO DATOS *** =\n");
        printf("=====================================\n\n");
        system("pause");
    }

}//FIN DE LA FUNCION ALTA//

/**
 * \brief Se busca a una persona por DNI y se la elimina de la estructura.
 * \param lista el array se pasa como parametro.
 */

void baja(Persona lista[])
{
    int pos=-1;

    pos=buscDNI(lista);
    if(pos!=-1)
    {
        eliminar(lista, pos);
    }else{
        system("cls");
        printf("=====================ERROR====================\n");
        printf("= *** EL DNI NO SE ENCUENTRA EN LA LISTA *** =\n");
        printf("==============================================\n\n");
        system("pause");
    }
}//FIN DE LA FUNCION BAJA//

/**
 * \brief Se mueatran en pantalla los datos de todas las personas en orden alfabetico.
 * \param lista el array se pasa como parametro.
 */

void ordAlfa(Persona lista[])
{
    int i, j, cont=0, uPos;
    Persona aux;

    uPos = buscEs(lista);
    for(i=0;i<uPos-1;i++)
    {
        for(j=i+1; j<uPos ;j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
        }
    }
    printf("==============================================\n");
    printf("=         *** LISTA DE PERSONAS ***          =\n");
    for(i=0;i<C;i++)
    {
        if(lista[i].estado!=0)
        {
            mostrar(lista, i);
            cont++;
        }
    }
    if(cont==0)
    {
        printf("==============================================\n");
        printf("=        *** SIN DATOS QUE MOSTRAR ***       =\n");
    }
    printf("==============================================\n");
    system("pause");
}//FIN DE LA FUNCION ORDALFA//

/**
 * \brief Se muestra un grafico organizado por edades (menor de 18, de 18 a 35 y mayor de 35).
 * \param lista el array se pasa como parametro.
 */

void graf(Persona lista[])
{
    int i, max=0, men18=0, ent18_35=0, may35=0;

    for(i=0;i<C;i++)
    {
        if(lista[i].edad>0)
        {
            if(lista[i].edad<18)
            {
                men18++;

            }else{
                if(lista[i].edad<35)
                {
                    ent18_35++;

                }else{

                    may35++;
                }
            }
        }
    }
    if(max<men18)
    {
        max=men18;
    }
    if(max<ent18_35)
    {
        max=ent18_35;
    }
    if(max<may35)
    {
        max=may35;
    }
    printf("=============================\n");
    printf("= *** GRAFICO DE EDADES *** =\n");
    printf("=============================\n");
    if(max==0 && men18==0 && ent18_35==0 && may35==0)
    {
        printf("=    *** NO HAY DATOS ***   =\n");
        printf("=============================\n");
    }else{
        for(i=max; i>0; i--)
        {
            if(men18<max)
            {
                printf("|\t|");
            }else
            {
                printf("|   *   |");
            }
            if(ent18_35<max)
            {
                printf("|\t   |");
            }else
            {
                printf("|    *    |");
            }
            if(may35<max)
            {
                printf("|\t    |");
            }else
            {
                printf("|   *   |");
            }
                printf("\n");
        }
    }
    printf("|  -18  || 19 - 35 ||  +35  |\n");
    system("pause");
}//FIN DE LA FUNCION GRAF//

/**
 * \brief Se muestra un mensaje que pregunta al usuario si desea salir del programa.
 */

char salir()
{

    int cont;

    do
    {
        system("cls");
        printf("=====================ERROR====================\n");
        printf("=     *** EL PROGRAMA VA A FINALIZAR ***     =\n");
        printf("=                    * * *                   =\n");
        printf("=       *** DESEA CONTINUAR? [S/N] ***       =\n");
        printf("==============================================\n\n");
        cont=getch();
        cont=toupper(cont);
        if(cont!='S' && cont!='N')
        {
            notOp();
        }
    }while(cont!='S' && cont!='N');

    return cont;
}//FIN DE LA FUNCION SALIR//
