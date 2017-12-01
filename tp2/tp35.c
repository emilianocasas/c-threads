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

pthread_mutex_t MUTEX;


int main (int argc, char *argv[]){
      int s, i, status;
      memset(&mivta,0,sizeof(double)*5*31); 
      memset(&totalsuc,0,sizeof(double)*5); 
 
	  pthread_t hiloCarga; //Para introducir los valores
      pthread_t hilosSuma[5]; //Para sumar las sucursales
      pthread_attr_t attr;
      pthread_attr_init(&attr);
      pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); //Al hilo que le ponga el atributo attr, sera joinable
     
     //Inicializo mutex
      pthread_mutex_init(&MUTEX, NULL);

	  //Termino inicializar mutex mutex

	 //	Creo hilo para cargar ventas
      printf("main(): creando thread para carga de ventas\n");
      s = pthread_create(&hiloCarga,NULL,cargoVentas,NULL);
         if (s){ 
            printf("main(): Error, pthread_create() retorna %d\n", s);
            exit(-2);
         }
         
	//Creo hilos para sumar cada sucursal
      for(i=0; i<5; i++){
         printf("main(): creando thread %d\n", i);
         s = pthread_create(&hilosSuma[i], &attr, sumoVentas, (void *)  i);
         if (s){ 
            printf("main(): Error, pthread_create() retorna %d\n", s);
            exit(-1);
         }
      }
      
      // libero recurso que ya no necesito
      pthread_attr_destroy(&attr);
      
      // hago joins
      for(i=0; i<5; i++){
         printf("main(): haciendo join con thread %d\n", i);
         s = pthread_join(hilosSuma[i],(void **) &status);
         if (s){ 
            printf("main(): Error, pthread_join() retorna %d\n", s);
            exit(-3);
         }
         printf("main(): termino join con thread %d status= %d\n",i, status);
      }

      // hago total gral
      for(i=0; i<5; i++) totalgral+=totalsuc[i];
      printf("main():Total Gral $ %12.2f\n",totalgral);

      // libero recurso que ya no necesito
      pthread_mutex_destroy(&MUTEX);
      

      
      printf("fin main():1\n");
   pthread_exit(NULL);
}

void *sumoVentas(void *sucursalid) {
   int sucid;
   sucid = (int) sucursalid;
   printf("thread %d esperando carga de sucursal %d \n", sucid,sucid);
   pthread_mutex_lock(&MUTEX);
 
   printf("thread %d sumoVentas sucursal %d \n", sucid,sucid);
   
   totalsuc[sucid]=0.0;
   int i;
   for(i=0;i<31;i++) {
      totalsuc[sucid]+=mivta[sucid][i];
   }
   printf("fin thread %d sumatoria de sucursal %d  $%10.2f\n",sucid,sucid,totalsuc[sucid]);
     pthread_mutex_lock(&MUTEX);

   pthread_exit((void *) (sucid+1));
}

void *cargoVentas(void *p) {
   int s,d;
   printf("thread cargoVentas\n");
      pthread_mutex_lock(&MUTEX);
   for(s=0;s<5;s++) {
      for(d=0;d<31;d++) {
         mivta[s][d] = ((double) random())/10000000.0;
      }
      sleep(4);
   }
      pthread_mutex_lock(&MUTEX);
   printf("fin thread cargoVentas\n");
   pthread_exit(NULL);
}
