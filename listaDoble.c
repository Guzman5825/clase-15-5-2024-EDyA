#include "listaDoble.h"

void crearLista(tListaD* ld){
    *ld=NULL;
}

int insertarEnListaOrdenada(tListaD* ld, void* d, unsigned tam, Cmp cmp){
    int res;
    tNodo* sig,*ant;
    tNodo* act=*ld;
    if(*ld==NULL){
        sig=NULL;
        ant=NULL;
    }else{
        while( act->sig!=NULL && cmp(act->dato,d)>0 )
            act=act->sig;
        while( act->ant!=NULL && cmp(act->dato,d)<0 )
            act=act->ant;
        res=cmp(act->dato,d);
        if( res<0 ){    //considerando que los elementos son distintos
            ant=act->ant;
            sig=act;
        }else{
            ant=act;
            sig=act->sig;
        }
    }
    ///reservar memoria
    tNodo* nue=malloc(sizeof(tNodo));
    if(nue==NULL)
        return SIN_MEMORIA;
    nue->dato=malloc(tam);
    if(nue->dato==NULL){
        free(nue);
        return SIN_MEMORIA;
    }
    ///copiar la imformacion
    nue->tam=tam;
    memcpy(nue->dato,d,tam);
    ///conectar el nodo a la lista
    nue->ant=ant;
    nue->sig=sig;
    ///conectar la lista al nodo
    if(ant)
        ant->sig=nue;
    if(sig)
        sig->ant=nue;
    ///conectar ld al nuevo nodo
    *ld=nue;
    return TODO_OK;
}

void recorrerDerAIzq(tListaD* ld,Accion accion){
tNodo* act=*ld;
while(act!=NULL && act->sig!=NULL)
    act=act->sig;
while(act!=NULL){
    accion(act->dato);
    act=act->ant;
    }
}

void recorrerIzqADer(tListaD* ld,Accion accion){
    tNodo* act=*ld;
    while(act!=NULL && act->ant!=NULL)
        act=act->ant;
    while(act!=NULL){
        accion(act->dato);
        act=act->sig;
    }

}

void vaciarLista(tListaD* ld){
    tNodo* act=*ld,*nae;
    while(act!=NULL && act->ant!=NULL)
        act=act->ant;
    while(act!=NULL){
        nae=act;
        act=act->sig;
        free(nae->dato);
        free(nae);
    }
    *ld=NULL;
}

int insertarAlInicio(tListaD* ld, void* d, unsigned tam){
    tNodo* act=*ld;
    while(act!=NULL && act->ant!=NULL)
        act=act->ant;

    ///reservar memoria
    tNodo* nue=malloc(sizeof(tNodo));
    if(nue==NULL)
        return SIN_MEMORIA;
    nue->dato=malloc(tam);
    if(nue->dato==NULL){
        free(nue);
        return SIN_MEMORIA;
    }
    ///copiar los datos
    nue->tam=tam;
    memcpy(nue->dato,d,tam);
    ///
    nue->ant=NULL;
    nue->sig=act;

    if(act)
        act->ant=nue;

    *ld=nue;
    return TODO_OK;
}

tListaD buscarNodoEnListaOrdenado(tListaD* ld, void* d,Cmp cmp){
    tListaD nodoBuscado=NULL;
    tNodo* act=*ld;

    if(act==NULL)
        return nodoBuscado;

    while(act->sig!=NULL && cmp(act->dato,d)>0)
        act=act->sig;
    while(act->ant!=NULL && cmp(act->dato,d)<0 )
        act=act->ant;

    if( cmp(act->dato,d)==0 )
        nodoBuscado=act;

    return nodoBuscado;
}

int eliminarPrimeraOcurrenciaEnListaOrdenada(tListaD* ld,void * d, unsigned tam,Cmp cmp){
    tNodo* ant,*sig,*act=*ld;

    if(act==NULL)
        return SIN_ELEMENTOS;

    while(act->ant!=NULL)
        act=act->ant;

    while(act!=NULL && cmp(act->dato,d)>0)  ///corroborar despues
        act=act->sig;
    ///ver si esta elemento
    ///verificamos la comparacion

    if(act==NULL || cmp(act->dato,d)!=0)
        return NO_ENCONTRADO;

    ///si es que ese elemento existe,desconectar
    ant=act->ant;
    sig=act->sig;

    if(ant)
        ant->sig=sig;
    if(sig)
        sig->ant=ant;

    if(ant)
        *ld=ant;
    else
        *ld=sig;


    ///liberar ese nodo nae
    free(act->dato);
    free(act);


    return TODO_OK;

}
