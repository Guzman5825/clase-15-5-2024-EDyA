#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

#include <stdio.h>
#include <string.h>

typedef struct{
    char nombre[20];
    int cant;
}tProducto;

void mostrarProducto(void *d );
int compararProducto(const void *d1,const void *d2);


#endif // STOCK_H_INCLUDED
