#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int op1(x)
{
    /*REALIZAMOS EN INGRESO DEL 1ER OPERANDO*/
    printf("Ingrese el 1er operando: ");
    scanf("%d",&x);
    system("cls");
    return x;
}

int op2 (y)
{
    /*REALIZAMOS EL INGRESO DEL 2DO OPERANDO*/
    printf("Ingrese el 2do operando: ");
    scanf("%d",&y);
    system("cls");
    return y;
}

void suma (x,y)
{
    /*SUMAMOS AMBOS OPERANDOS*/
    printf("El resultado de la suma es: %d\n",x+y);
}

void resta (x,y)
{
    /*RESTAMOS AMBOS OPERANDOS*/
    printf("El resultado de la resta es: %d\n",x-y);
}

void division (x,y)
{
    float a=x,b=y;
    /*VERIFICAMOS QUE EL DIVISOR (2DO OPERANDO) NO SEA 0*/
    if(y==0)
    {
        printf("Imposible dividir por 0\n");
    }
    /*SI EL DIVISOR (2DO OPERANDO) ES DISTINTO A 0 PROCEDEMOS CON LA DIVISION*/
    else
    {
        printf("El resultado de la division es: %.2f\n",a/b);
    }
}

void multiplicacion (x,y)
{
    /*MULTIPLICAMOS AMBOS OPERANDOS*/
    printf("El resultado de la multiplicacion es: %d\n",x*y);
}

void factorial (x)
{
    /*BUSCAMOS EL NUMERO FACTORIAL DEL PRIMER OPERANDO*/
    int i=x;
    double fac=1;

    while(i!=0)
    {
        fac=fac*i;
        i--;
    }

    printf("El numero factorial de %d es: %lg\n",x,fac);
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
