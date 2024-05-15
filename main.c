#include <stdio.h>
#include <stdlib.h>
#include "listaDoble.h"
#include "stock.h"
#include <string.h>

int main()
{
    tListaD listaD;
    //tNodo* nodo;
    //tProducto productoAbuscar={"carne",0};
    int i;
    tProducto productos[]={ {"arroz",50}
                            ,{"fideos",20},
                            {"fideos",30},
                            {"aceite",50}
                            ,{"carne",20},
                            {"arroz",30},
                            };

    crearLista(&listaD);

    for(i=0;i<sizeof(productos)/sizeof(tProducto);i++)
        //insertarAlInicio(&listaD,productos+i,sizeof(tProducto));
        insertarEnListaOrdenada(&listaD,productos+i,sizeof(tProducto),compararProducto);

    puts("mostrar productos");
    recorrerIzqADer(&listaD,mostrarProducto);

    tProducto productoEliminar={"fideos",2},prod2={"carne",0},prod3={"aceite",0},prod4={"arroz",0};

    eliminarPrimeraOcurrenciaEnListaOrdenada(&listaD,&productoEliminar,sizeof(tProducto),compararProducto);
    eliminarPrimeraOcurrenciaEnListaOrdenada(&listaD,&productoEliminar,sizeof(tProducto),compararProducto);
    eliminarPrimeraOcurrenciaEnListaOrdenada(&listaD,&productoEliminar,sizeof(tProducto),compararProducto);
    eliminarPrimeraOcurrenciaEnListaOrdenada(&listaD,&prod2,sizeof(tProducto),compararProducto);
    eliminarPrimeraOcurrenciaEnListaOrdenada(&listaD,&prod3,sizeof(tProducto),compararProducto);
    eliminarPrimeraOcurrenciaEnListaOrdenada(&listaD,&prod4,sizeof(tProducto),compararProducto);
    eliminarPrimeraOcurrenciaEnListaOrdenada(&listaD,&prod4,sizeof(tProducto),compararProducto);
    puts("-------mostrar productos");
    recorrerIzqADer(&listaD,mostrarProducto);

/*
    puts("mostrar producto buscado");
    nodo=buscarNodoEnListaOrdenado(&listaD,&productoAbuscar,compararProducto);
    if(nodo!=NULL)
        mostrarProducto(nodo->dato);
    else
        puts("PRODUCTO NO ENCONTRADO");
        */
    /*
    tAlumno alumno={1,"julian"};
    crearLista(&listaD);

    insertarEnListaOrdenadaSinDuplicado(&listaD,&alumno,sizeof(tAlumno),cmpLegajos);
    alumno.legajo=2 ;
    strcpy(alumno.nombre,"fabian");

    insertarEnListaOrdenadaSinDuplicado(&listaD,&alumno,sizeof(tAlumno),cmpLegajos);
    puts("mostra de derecha a izquierda");
    recorrerDerAIzq(&listaD,mostrarAlumno);
    puts("mostrar de izquierda a derecha");
    recorrerIzqADer(&listaD,mostrarAlumno);

    vaciarLista(&listaD);
    recorrerDerAIzq(&listaD,mostrarAlumno);*/
    return 0;
}
