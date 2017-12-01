#include <pthread.h>
#include <unistd.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double mivta[5][31]; 
double totalgral=0.0;
double totalsuc[5];

void *sumoVentas(void *sucursalid);
void *cargoVentas(void *);

int main (int argc, char *argv[]){
      //int s, i, d ;
      int i;
      
      memset(&mivta,0,sizeof(double)*5*31); 
      memset(&totalsuc,0,sizeof(double)*5); 
 
	  pthread_t hiloCarga; //Para introducir los valores
      pthread_t hilosSuma[5]; //Para sumar las sucursales
      pthread_attr_t attr;
      pthread_attr_init(&attr);
      pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); //Al hilo que le ponga el atributo attr, sera joinable
     
      pthread_create(&hiloCarga,NULL,cargoVentas,NULL); //	Creo hilo para cargar ventas
      pthread_join(hiloCarga, NULL);
        
      for(i=0; i<5; i++){ //Creo hilos para sumar cada sucursal y los voy esperando
         pthread_create(&hilosSuma[i], &attr, sumoVentas, (void *)  i);
         pthread_join(hilosSuma[i],NULL);
      }
      
      pthread_attr_destroy(&attr); // libero recurso que ya no necesito

      for(i=0; i<5; i++) totalgral+=totalsuc[i]; // hago total gral
      printf("main():Total Gral %f\n",totalgral);

      printf("fin main()\n");
      pthread_exit(NULL);
}

void *sumoVentas(void *sucursalid) {
   int sucid;
   sucid = (int) sucursalid;
   printf("thread %d sumoVentas sucursal %d \n", sucid,sucid);
   totalsuc[sucid]=0.0;
   int i;
   for(i=0;i<31;i++) {
      totalsuc[sucid]+=mivta[sucid][i];
   }
   printf("fin sumatoria de sucursal con total %f \n",totalsuc[sucid]);
   pthread_exit(NULL);
}

void *cargoVentas(void *p) {
   int s,d;
   printf("thread cargoVentas\n");
      
  	for (s=0; s<5; s++){
		for (d=0; d<31; d++){
			mivta[s][d] = ((double) random())/10000000.0; 
		}
	}
	
   
   printf("fin thread cargoVentas\n");
   pthread_exit(NULL);
}
