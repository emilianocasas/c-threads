#include <pthread.h>
#include <unistd.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double mivta[5][31]; 
double totalgral=0.0;
double totalsuc[5];

int cargadas[5];
pthread_mutex_t cargada_mutex[5];
pthread_cond_t cargada_cv[5];

void *sumoVentas(void *sucursalid);
void *cargoVentas(void *);

int main (int argc, char *argv[]){
      //int s, i, d ;
      int i, s;
      
      memset(&mivta,0,sizeof(double)*5*31); 
      memset(&totalsuc,0,sizeof(double)*5); 
      memset(&cargadas,0,sizeof(int)*5); //cargadas[n] indica falso (cero) 
 
	  pthread_t hiloCarga; //Para introducir los valores
      pthread_t hilosSuma[5]; //Para sumar las sucursales
      pthread_attr_t attr;
      pthread_attr_init(&attr);
      pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); //Al hilo que le ponga el atributo attr, sera joinable
     
      
      pthread_create(&hiloCarga,&attr,cargoVentas,NULL); //	Creo hilo para cargar ventas
     
      
      for(i=0; i<5; i++){ //Creo hilos para sumar cada sucursal y los voy esperando
         pthread_create(&hilosSuma[i], &attr, sumoVentas, (void *)  i);
       }
      
      s = pthread_join(hilosSuma[4],NULL);
      pthread_attr_destroy(&attr); // libero recurso que ya no necesito
      
      for(i=0; i<5; i++) totalgral+=totalsuc[i]; // hago total gral
      printf("main():Total Gral %f\n",totalgral);

      printf("fin main()\n");
      pthread_exit(NULL);
}

void *sumoVentas(void *sucursalid) {
   int sucid;
   sucid = (int) sucursalid;
   pthread_mutex_lock(&cargada_mutex[sucid]);
   if ( !cargadas[sucid] ) printf("esperando carga de sucursal %d\n",sucid);
   pthread_cond_wait(&cargada_cv[sucid],&cargada_mutex[sucid]);
   printf("Arranco sumatoria sucursal %d\n", sucid);
   totalsuc[sucid]=0.0;
   int i;
   for(i=0;i<31;i++) {
      totalsuc[sucid]+=mivta[sucid][i];
   }
   printf("fin sumatoria de sucursal con total %f \n", totalsuc[sucid]);
   pthread_exit(NULL);
}

void *cargoVentas(void *p) {
   int s,d;
   printf("thread cargoVentas\n");
      
  	for (s=0; s<5; s++){
		for (d=0; d<31; d++){
			mivta[s][d] = ((double) random())/10000000.0; 
		}
		 cargadas[s]=1;
		 printf("Señalizo variable de condicion %d\n", s);
	     pthread_cond_signal(&cargada_cv[s]); 
	}
	
   
   printf("fin thread cargoVentas\n");
   pthread_exit(NULL);
}


