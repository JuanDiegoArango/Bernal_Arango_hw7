#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//Este codigo corre el caso de 2 gases ideales en un tubo inicialmente separado por una membrana y su evolucion en el tiempo. Se ha verificado este codigo al correrlo a 0.01s obteniendo perfiles de densidad, velocidad y presion equivalentes a los obtenidos analiticamente y reportados en la pagina http://nbviewer.ipython.org/github/numerical-mooc/numerical-mooc/blob/master/lessons/03_wave/03_05_Sods_Shock_Tube.ipynb
int main(int argc, char **argv){
    //Definicion de constantes del problema
  double rhoL=1.0;      //Densidad a la izquierda
  double vL=0.0;        //Velocidad a la izquierda
  double pL=100000.0;   //Presion a la izquierda
  double rhoR=0.125;    //Densidad a la derecha
  double vR=0.0;        //Velocidad a la derecha
  double pR=10000.0;    //Presion a la derecha
  double x0=-10.0;      //Longitud inicial
  double xf=10.0;       //Longitud final
  double gamma=1.4;     //Coeficiente adiabatico
  double dt=0.00001;    //Discretizacion en tiempo
  int N=1000;           //Numero de discretizaciones en espacio
  int i,j;
    //Vectores que almacenan las variables x, u1, u2, u3, f1, f2, f3, rho, v y P para estados iniciales, finales y medios (utilizados en el metodo de Richtmyer)
  double x[N];
  double f1_initial[N];
  double f1_past[N];
  double f1_half[N];
  double f2_initial[N];
  double f2_past[N];
  double f2_half[N];
  double f3_initial[N];
  double f3_past[N];
  double f3_half[N];
  double u1_initial[N];
  double u1_past[N];
  double u1_half[N];
  double u2_initial[N];
  double u2_past[N];
  double u2_half[N];
  double u3_initial[N];
  double u3_past[N];
  double u3_half[N];
  double rho_initial[N];
  double v_initial[N];
  double p_initial[N];
  double rho_final[N];
  double v_final[N];
  double p_final[N];
  FILE *fileout;
  double tf;

  tf=atof(argv[1]);     // Tiempo final ingresado por consola

  int Ntime=tf/dt;      //Discretizacion en tiempo
  double u1_future[N];
  double u2_future[N];
  double u3_future[N];
  double dx;
  dx=(xf-x0)/(N-1.0);
    //Definicion de las condiciones iniciales
  for(i=0;i<N;i++){
    x[i]=x0+i*dx;
    if(x[i]<0){
      rho_initial[i]=rhoL;
      v_initial[i]=vL;
      p_initial[i]=pL;
    }
    else{
      rho_initial[i]=rhoR;
      v_initial[i]=vR;
      p_initial[i]=pR;
    }
    u1_future[i]=rho_initial[i];
    u2_future[i]=rho_initial[i]*v_initial[i];
    u3_future[i]=(p_initial[i]/(gamma-1)+rho_initial[i]*v_initial[i]*v_initial[i]/2.0);

  }

  for(j=0;j<Ntime-1;j++){
      //Fijar los valores extremos dado que no se calculan por el metodo de Richtmyer
    u1_future[0]=rho_initial[0];
    u2_future[0]=rho_initial[0]*v_initial[0];
    u3_future[0]=(p_initial[0]/(gamma-1)+rho_initial[0]*v_initial[0]*v_initial[0]/2.0);   
    u1_future[N-1]=rho_initial[N-1];
    u2_future[N-1]=rho_initial[N-1]*v_initial[N-1];
    u3_future[N-1]=(p_initial[N-1]/(gamma-1)+rho_initial[N-1]*v_initial[N-1]*v_initial[N-1]/2.0);   
    for(i=0;i<(N);i++){
      u1_initial[i]=u1_future[i];
      u2_initial[i]=u2_future[i];
      u3_initial[i]=u3_future[i];
      f1_initial[i]=u2_initial[i];
      f2_initial[i]=u2_initial[i]*u2_initial[i]/u1_initial[i]+(gamma-1)*(u3_initial[i]-u2_initial[i]*u2_initial[i]/(2.0*u1_initial[i]));
      f3_initial[i]=(u3_initial[i]+(gamma-1)*(u3_initial[i]-u2_initial[i]*u2_initial[i]/(2.0*u1_initial[i])))*u2_initial[i]/u1_initial[i];
      u1_half[i]=u1_initial[i];
      u2_half[i]=u2_initial[i];
      u3_half[i]=u3_initial[i];
      f1_half[i]=f1_initial[i];
      f2_half[i]=f2_initial[i];
      f3_half[i]=f3_initial[i];
    }
    for(i=1;i<(N-1);i++){
        //Actualizacion de los valores para la siguiente iteracion
      u1_half[i]=(u1_initial[i+1]+u1_initial[i])/2.0-(f1_initial[i+1]-f1_initial[i])*dt/(2.0*dx);
      u2_half[i]=(u2_initial[i+1]+u2_initial[i])/2.0-(f2_initial[i+1]-f2_initial[i])*dt/(2.0*dx);
      u3_half[i]=(u3_initial[i+1]+u3_initial[i])/2.0-(f3_initial[i+1]-f3_initial[i])*dt/(2.0*dx);
      f1_half[i]=u2_half[i];
      f2_half[i]=u2_half[i]*u2_half[i]/u1_half[i]+(gamma-1)*(u3_half[i]-u2_half[i]*u2_half[i]/(2.0*u1_half[i]));
      f3_half[i]=(u3_half[i]+(gamma-1)*(u3_half[i]-u2_half[i]*u2_half[i]/(2.0*u1_half[i])))*u2_half[i]/u1_half[i];
      u1_future[i]=u1_initial[i]-(f1_half[i]-f1_half[i-1])*dt/(dx);
      u2_future[i]=u2_initial[i]-(f2_half[i]-f2_half[i-1])*dt/(dx);
      u3_future[i]=u3_initial[i]-(f3_half[i]-f3_half[i-1])*dt/(dx);
    }
  }
//Calculo de propiedades al final
  for(i=0;i<N;i++){
    rho_final[i]=u1_future[i];
    v_final[i]=u2_future[i]/rho_final[i];
    p_final[i]=(gamma-1)*(u3_future[i]-u2_future[i]*u2_future[i]/(2.0*u1_future[i]));
  }
//Definicion de nombre de archivo de salida
  char name[10];
  sprintf(name, "_%f",tf);
  char new_name[20], end_name[10];
  strcpy(new_name,"estado");
  strcpy(end_name,".dat");
  strcat(new_name, name);
  strcat(new_name, end_name);
//Impresion de los valores en el archivo de datos
  fileout=fopen(new_name,"w");
  for(i=0;i<N;i++){
    fprintf(fileout,"%f %f %f %f\n",x[i],v_final[i],p_final[i],rho_final[i]);
    //   printf("%f %f %f %f\n",x[i],v_final[i],p_final[i],rho_final[i]);
  }
  fclose(fileout);
  return 0;
}

