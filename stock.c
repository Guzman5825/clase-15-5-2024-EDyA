#include "stock.h"

void mostrarProducto(void *d ){
    tProducto* p=d;
    if(d!=NULL)
        printf("nombre:%s cant:%d\n",p->nombre,p->cant);
    else
        printf("PRODUCTO NULO \n");
}

int compararProducto(const void *d1,const void *d2){
    const tProducto* p1=d1;
    const tProducto* p2=d2;
    return strcmpi(p2->nombre,p1->nombre);
}
