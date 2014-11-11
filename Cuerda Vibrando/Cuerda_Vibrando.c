#include <math.h>
#include <stdio.h>
#include <stdlib.h>
void condicion_inicial(float *y_pasado, int particion, float L, float delta_x);
void el_tiempo_avanza(float *y_pasado, float *y_presente, float *y_futuro,int particion);
void  evolucion_en_el_timepo(float *y_futuro, float *y_pasado, float *y_presente,int t,int particion,float r,float rho,float delta_t,float delta_x);


//**Se toman valores de delta x y delta y apropiados para que el caso de 0.01 que se da en el enunciado **//
int main(int argc, char *argv[])

{
float delta_x=0.05;
float delta_t=0.0005;
int L=100;
int T=40;
int i;
float rho=atof(argv[1]);
int particion =(int)100/delta_x;
float *y_pasado,*y_futuro,*y_presente;
float r=(delta_t/delta_x)*sqrt(T/rho);
int t=(int)120/delta_t;
//**En caso de valores mas bajos de ponen este cambio de variable para permitir que se pueda realisar la integracion **//

if(rho<=0.004)
{
    delta_x=1;
    delta_t=0.0001;
}
    

//**se defiene puntero para pasado, presente y futuro de y **//
y_pasado=malloc(particion*sizeof(float));
y_presente=malloc(particion*sizeof(float));
y_futuro=malloc(particion*sizeof(float));
//*condicion inicial del sistema*//
condicion_inicial(y_pasado,particion,L,delta_x);
//**se define primer tiempo  despues de la condicion inicial**//
for (i=1; i<particion; i++)

{
    y_presente[i]=y_pasado[i]+r*r/2*(y_pasado[i+1]-2.0*y_pasado[i]+y_pasado[i-1]);
    
    
}
    //**se inicia la evolucion en el tiempo**//
    
evolucion_en_el_timepo(y_futuro,y_pasado,y_presente,t,particion,r,rho,delta_t,delta_x);
    
return 0;
    
}

void condicion_inicial(float *y_pasado, int particion, float L, float delta_x){
    int i;
    int j;
    for (i=0; i<=particion; i++)
    {       j=i*delta_x;
        
            if (j<=0.8*L)
            {
                y_pasado[i]=1.25*(j/L);
                
            }
        
        
            if (j>0.8*L)
            {
                y_pasado[i]=5-5*(j/L);
           
            }
    }
    
    }

    
void evolucion_en_el_timepo(float *y_futuro, float *y_pasado, float *y_presente,int t,int particion,float r,float rho,float delta_t,float delta_x)
{
    int i;
    int j;
    int k;
    int u=0;
    FILE *fileout;
    char filename[100000];
    sprintf(filename, "string_%f.dat",rho);
    fileout= fopen(filename, "w");
    int p=(int)1/delta_x;
    
    for(i=0;i<t;i++)
    {
        if (i==u)
        {
            for (k=0; k<=100; k++)
            {
                fprintf(fileout," %f  " , y_presente[p*k]);
            }
            
        fprintf(fileout, "\n");
            u=u+1/delta_t;
        }
        
    
        
        for (j=1;j<particion; j++)
            {
                
                y_futuro[j]=2.0*(1.0-r*r)*y_presente[j]-y_pasado[j]+r*r*(y_presente[j+1]+y_presente[j-1]);
                
            }
         
            el_tiempo_avanza(y_pasado, y_presente, y_futuro,particion);
    
    }
    
    
    for (k=0; k<=100; k++)
    {
        fprintf(fileout," %f  " , y_presente[p*k]);
    }
    
    
    
    
    fclose(fileout);

    
}
    
    
    
void el_tiempo_avanza(float *y_pasado, float *y_presente, float *y_futuro,int particion)
    {
        int i;
            for (i=1; i<particion; i++)
            {
                y_pasado[i]=y_presente[i];
            }
        
            for (i=1; i<particion; i++)
            {
                y_presente[i]=y_futuro[i];
            }
    
    }
    
    
   



