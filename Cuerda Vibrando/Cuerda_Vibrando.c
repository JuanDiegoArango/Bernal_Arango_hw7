#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void condicion_inicial(float *y_pasado, int particion, float L, float delta_x);
void el_tiempo_avanza(float *y_pasado, float *y_presente, float *y_futuro,int particion);
void  evolucion_en_el_timepo(float *y_futuro, float *y_pasado, float *y_presente,int t,int particion,float r,float rho);



int main(int argc, char *argv[])

{

int L=100;
int T=40;
int t=120;
int i;
float rho=atof(argv[1]);;
int particion = 100;
float delta_x=L/particion;
float delta_t=0.0005;
float *y_pasado,*y_futuro,*y_presente;
float r=(delta_t/delta_x)*sqrt(T/rho);


y_pasado=malloc(particion*sizeof(float));
y_presente=malloc(particion*sizeof(float));
y_futuro=malloc(particion*sizeof(float));
    
condicion_inicial(y_pasado,particion,L,delta_x);
    
for (i=1; i<particion-1; i++)

{
    y_presente[i]=y_pasado[i]+r*r/2*(y_pasado[i+1]-2.0*y_pasado[i]+y_pasado[i-1]);
    
    
}
    
evolucion_en_el_timepo(y_futuro,y_pasado,y_presente,t,particion,r,rho);
    
return 0;
    
}

void condicion_inicial(float *y_pasado, int particion, float L, float delta_x){
    int i=0;
    for (i=1; i<particion; i++)
    {
            if (i<=0.8*L)
            {
                y_pasado[i]=1.25*(delta_x*i/L);
                
            }
        
        
            if (i>0.8*L)
            {
                y_pasado[i]=5-5*(delta_x*i/L);
           
            }
    }
    
        y_pasado[0]=0;
        y_pasado[particion-1]=0;
        
    }

    
void evolucion_en_el_timepo(float *y_futuro, float *y_pasado, float *y_presente,int t,int particion,float r,float rho)
{
    int i;
    int j;
    int k;
    FILE *fileout;
    char filename[100000];
    sprintf(filename, "string_%f.dat",rho);
    fileout= fopen(filename, "w");
    
    
    for(i=0;i<t;i++)
    {
            for (k=0; k<particion; k++)
            {
                fprintf(fileout," %f  " , y_presente[k]);
            }
        
            fprintf(fileout, "\n");
    
            for (j=1;j<particion-1; j++)
            {
                
                y_futuro[j]=2.0*(1.0-r*r)*y_presente[j]-y_pasado[j]+r*r*(y_presente[j+1]+y_presente[j-1]);
                
            }
         
            el_tiempo_avanza(y_pasado, y_presente, y_futuro,particion);
    
    }
    
    
    for (k=0; k<particion; k++)
    {
        fprintf(fileout," %f  " , y_presente[k]);
    }
    
    
    
    
    fclose(fileout);

    
}
    
    
    
void el_tiempo_avanza(float *y_pasado, float *y_presente, float *y_futuro,int particion)
    {
        int i;
            for (i=0; i<particion; i++)
            {
                y_pasado[i]=y_presente[i];
            }
        
            for (i=0; i<particion; i++)
            {
                y_presente[i]=y_futuro[i];
            }
    
    }
    
    
   



