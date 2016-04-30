#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char dni[25];
    char nombre[25];
    int edad;
    int estado;

}Persona;

char menu(void);
void notOp();
int buscEs(Persona lista[]);
int ingDNI(Persona lista[], int pos);
void ingN(Persona lista[], int pos);
void ingE(Persona lista[], int pos);
int buscDNI(Persona lista[]);
void eliminar(Persona lista[], int pos);
void mostrar(Persona lista[], int pos);
void alta(Persona lista[]);
void baja(Persona lista[]);
void ordAlfa(Persona lista[]);
void graf(Persona lista[]);
char salir(void);

#endif // FUNCIONES_H_INCLUDED
