#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int num1(x)
{
    /*REALIZAMOS EN INGRESO DEL 1ER OPERANDO*/
    printf("\nIngrese el 1er operando: ");
    scanf("%d",&x);
    system("cls");
    return x;
}

int num2 (y)
{
    /*REALIZAMOS EL INGRESO DEL 2DO OPERANDO*/
    printf("\nIngrese el 2do operando: ");
    scanf("%d",&y);
    system("cls");
    return y;
}

void suma (x,y)
{
    /*SUMAMOS AMBOS OPERANDOS*/
    printf("\nEl resultado de la suma es: %d\n",x+y);
}

void resta (x,y)
{
    /*RESTAMOS AMBOS OPERANDOS*/
    printf("\nEl resultado de la resta es: %d\n",x-y);
}

void division (x,y)
{
    /*VERIFICAMOS QUE EL DIVISOR (2DO OPERANDO) NO SEA 0*/
    if(y==0)
    {
        printf("\nImposible dividir por 0\n");
    }
    /*SI EL DIVISOR (2DO OPERANDO) ES DISTINTO A 0 PROCEDEMOS CON LA DIVISION*/
    else
    {
        printf("\nEl resultado de la division es: %d\n",x/y);
    }
}

void multiplicacion (x,y)
{
    /*MULTIPLICAMOS AMBOS OPERANDOS*/
    printf("\nEl resultado de la multiplicacion es: %d\n",x*y);
}

void factorial (x)
{
    /*BUSCAMOS EL NUMERO FACTORIAL DEL PRIMER OPERANDO*/
    int i;
    double fac=1;

    if (x<-170)
    {
        printf("\nEl numero factorial de %d es: -INFINITO\n",x);
    }
    else if (x>170)
    {
        printf("\nEl numero factorial de %d es: INFINITO\n",x);
    }
    else if (x<0)
    {
        for(i=x;i!=0;i++)
        {
            fac=fac*i;
        }

        printf("\nEl numero factorial de %d es: %lg\n",x,fac);
    }
    else
    {
        for(i=x;i!=0;i--)
        {
            fac=fac*i;
        }

        printf("\nEl numero factorial de %d es: %lg\n",x,fac);
    }
}

void error()
{
    /*SI LA OPCION INGRESADA NO ES VALIDA MOSTRAMOS UN MENSAJE DE ERROR Y VOLVEMOS AL MENU*/
    system("cls");
    printf("===============ERROR================\n");
    printf("= LA OPCION INGRESADA NO ES VALIDA =\n");
    printf("====================================\n");
    system("pause");
    system("cls");
}
#endif // FUNCIONES_H_INCLUDED

