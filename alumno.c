#include "alumno.h"

void mostrarAlumno(void* d){
tAlumno* a=d;
printf("legajo:%d nombre:%s\n",a->legajo,a->nombre );
}

int cmpLegajos(const void* d1,const void* d2){
const tAlumno* a1=d1;
const tAlumno* a2=d2;
return a2->legajo-a1->legajo;
}
