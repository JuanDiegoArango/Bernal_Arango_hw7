#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void condicion_inicial(float *y_pasado, int particion, float L, float pasos)

int main(int argc, char *argv[])

{
float L;
float T;
float t;
int i;
int particion = 10000*L;
float pasos=L/particion;
float *x,*y_pasado,*y_futuro;
x=malloc(pasos*sizeof(float));
y_pasado=malloc(pasos*sizeof(float));
y_futuro=malloc(pasos*sizeof(float));
condicion_inicial(y_pasado,particion,L,pasos);
    
    
for (i=1; i<particion; i++)
{
  
    
    
    
    
    
}






return 0;
    
}

void condicion_inicial(float *y_pasado, int particion, float L, float pasos){
    int i=0;
    
    for (i=1; i<particion; i++) {
        if (i<=0.8*L)
        {
            y_pasado[i]=1.25*(pasos*i/L)
            
        }
        
        
        if (i>0.8*L)
        {
            y_pasado[i]=5-5*(pasos*i/L)
           
        }
        
        x[0]=0;
        x[particion-1]=0;
        
    }






}