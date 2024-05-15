#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include <stdio.h>

void mostrarAlumno(void* d);

typedef struct{
    int legajo;  //CC
    char nombre[50];

}tAlumno;

void mostrarAlumno(void* d);
int cmpLegajos(const void* d1,const void* d2);


#endif // ALUMNO_H_INCLUDED
