#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(x,y) ( (x)<(y)? (x) : (y) )

#define FALSE 0
#define TRUE 1
#define SIN_MEMORIA 3
#define SIN_ELEMENTOS 2
#define TODO_OK 1
#define ERROR 0
#define INGRESO_MAS_ELEMENTO 5
#define ELIMINARON_ELEMENTOS 4
#define NO_ENCONTRADO 0

typedef struct sNodo{
    void* dato;
    unsigned tam;
    struct sNodo * sig;
    struct sNodo * ant;
} tNodo;

typedef tNodo* tListaD;


typedef int (*Cmp)(const void*,const void*);
typedef void (*Accion)(void*);
typedef void (*fReduce)(void*,const void*);    //dato a acumular- dato de la lista


void crearLista(tListaD* ld);
void vaciarLista(tListaD* ld);

int insertarAlInicio(tListaD* ld, void* d, unsigned tam);
int insertarEnListaOrdenada(tListaD* ld, void* d, unsigned tam, Cmp cmp);

void recorrerDerAIzq(tListaD* ld,Accion accion);
void recorrerIzqADer(tListaD* ld,Accion accion);

tListaD buscarNodoEnListaOrdenado(tListaD* ld, void* d,Cmp cmp); //devuelve sola la clave

int eliminarPrimeraOcurrenciaEnListaOrdenada(tListaD* ld,void * d, unsigned tam,Cmp cmp);

/*
listaVacia
listaLlena
*/
/// inserciones comunes


///inserciones con clave


#endif // LISTADOBLE_H_INCLUDED
