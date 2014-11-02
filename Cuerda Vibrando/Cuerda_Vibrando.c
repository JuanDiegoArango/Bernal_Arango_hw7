#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void condicion_inicial(float *y_pasado, int particion, float L, float delta_x);
void el_tiempo_avanza(float *y_pasado, float *y_presente, float *y_futuro);
void  evolucion_en_el_timepo(float *y_futuro, float *y_pasado, float *y_presente,int t,int particion,float r);



int main(int argc, char *argv[])

{
float L;
float T;
int t;
int i;
float rho;
int particion = 10000*L;
float delta_x=L/particion;
float delta_t=0.00005;
float *x,*y_pasado,*y_futuro,*y_presente;
float r=(delta_t/delta_x)*sqrt(T/rho);
x=malloc(delta_x*sizeof(float));
y_pasado=malloc(delta_x*sizeof(float));
y_presente=malloc(delta_x*sizeof(float));
y_futuro=malloc(delta_x*sizeof(float));
    
condicion_inicial(y_pasado,particion,L,delta_x);
    
    
for (i=1; i<particion-1; i++)

{
    y_presente[i]=y_pasado[i]+pow(r,2)/2*(y_pasado[i+1]-2.0*y_pasado[i]+y_pasado[i-1])
    
    
}






return 0;
    
}

void condicion_inicial(float *y_pasado, int particion, float L, float delta_x){
    int i=0;
    
    for (i=1; i<particion; i++) {
        if (i<=0.8*L)
        {
            y_pasado[i]=1.25*(delta_x*i/L)
            
        }
        
        
        if (i>0.8*L)
        {
            y_pasado[i]=5-5*(delta_x*i/L)
           
        }
        
        x[0]=0;
        x[particion-1]=0;
        
    }

    
    void  evolucion_en_el_timepo(float *y_futuro, float *y_pasado, float *y_presente,int t,int particion,float r)
    
    
    { int i:
      int j;
     for(i=0,i<t,i++){
         
         for (j=1;j<particion-1; j++) {
             
             y_futuro[j]=2*(1-r*r)*y_presente[j]-y_pasado+[j]+r*r(y_presente[j+1]+y_presente[j-1])
             
         }
         
         el_tiempo_avanza(y_pasado, y_presente, y_futuro,particion);
     
     }
    
    
    
    
    
    
    }
    
    
    
    void el_tiempo_avanza(float *y_pasado, float *y_presente, float *y_futuro,int particion)
    {
        int i;
        
        for (i=0; i<particion; i++)
        {   y_pasado[i]=y_presente[i];
            y_presente[i]=y_futuro[i];
            
        }
    
    
    
    
    }
    
    
    




}