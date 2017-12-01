#include <pthread.h>
#include <unistd.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_SUC 5

double mivta[NUM_OF_SUC][31]; 
double totalgral=0.0;
double totalsuc[NUM_OF_SUC];

void *sumoVentas(void *sucursalid);
void *cargoVentas(void *);

pthread_mutex_t cargada_mutex1;
pthread_mutex_t cargada_mutex[NUM_OF_SUC];

int cargadas[NUM_OF_SUC];
pthread_cond_t sucursales[NUM_OF_SUC];

int main (int argc, char *argv[]){
	  int a = 0;
      int rc, t, status;
      memset(&mivta,0,sizeof(double)*NUM_OF_SUC*31); //pone en 0 la variable mi vta (todas las posiciones)
      memset(&totalsuc,0,sizeof(double)*NUM_OF_SUC); // pone en 0 la variable total suc (todas las posiciones)
 
	  pthread_t thread_cargo; //Para introducir los valores
      pthread_t threads[NUM_OF_SUC]; //Para sumar las sucursales
      pthread_attr_t attr;
      pthread_attr_init(&attr);
      pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); //Al hilo que le ponga el atributo attr, sera joinable
     
     //Inicializo mutex
      pthread_mutex_init(&cargada_mutex1, NULL);
      
      for (a=0; a<5; a++){
      pthread_mutex_init(&cargada_mutex[a], NULL);
		}
	  //Termino inicializar mutex mutex
	
	 //	Creo hilo para cargar ventas
      //printf("main(): creando thread para carga de ventas\n");
      pthread_create(&thread_cargo,NULL,cargoVentas,NULL);
 
         
	//Creo hilos para sumar cada sucursal
      for(t=0; t<NUM_OF_SUC; t++){
        // printf("main(): creando thread %d\n", t);
        pthread_create(&threads[t], &attr, sumoVentas, (void *)  t);
     
      }
      
      // libero recurso que ya no necesito
      pthread_attr_destroy(&attr);
      
      // hago joins
      //rc = pthread_join(thread_cargo,NULL);
      
      for(t=0; t<NUM_OF_SUC; t++){
        // printf("main(): haciendo join con thread %d\n", t);
         rc = pthread_join(threads[t],NULL);
         if (rc){ 
            printf("main(): Error, pthread_join() retorna %d\n", rc);
            exit(-3);
         }
        // printf("main(): termino join con thread %d status= %d\n",t, status);
      }

      // hago total gral
      for(t=0; t<NUM_OF_SUC; t++) totalgral+=totalsuc[t];
      printf("main():Total Gral $ %d\n",totalgral);

      // libero recurso que ya no necesito
      pthread_mutex_destroy(&cargada_mutex1);
      
      printf("fin main():1\n");
   pthread_exit(NULL);
}

//============================================================
//                FUNCIONES
//============================================================
void *sumoVentas(void *sucursalid) {
   int sucid;
   sucid = (int) sucursalid;
   printf("thread %d esperando carga de sucursal %d \n", sucid,sucid);
   pthread_mutex_lock(&cargada_mutex[sucid]);
   if ( cargadas[sucid] == 0 ) {
	    printf("thread %d esperando condicion de cargada para sucursal %d \n", sucid,sucid); 
	     pthread_cond_wait(&sucursales[sucid], &cargada_mutex[sucid]); 
	} else {
   printf("thread %d sumoVentas sucursal %d \n", sucid,sucid);
   
   totalsuc[sucid]=0.0;
   int d;
   for(d=0;d<31;d++) {
      totalsuc[sucid]+=mivta[sucid][d];
   }
   printf("fin thread %d sumatoria de sucursal %d  : %d $\n",sucid,sucid,totalsuc[sucid]);
   pthread_mutex_unlock(&cargada_mutex[sucid]);
}
   pthread_exit( NULL);
}

void *cargoVentas(void *p) {
   int s,d;
   //printf("thread cargoVentas\n");
   pthread_mutex_lock(&cargada_mutex1);
   //printf("Entre al mutex cargo ventas\n");
   for(s=0;s<NUM_OF_SUC;s++) {
      for(d=0;d<31;d++) {
         mivta[s][d] = ((double) random())/10000000.0;
		   cargadas[s] = 1;
           pthread_cond_signal(&sucursales[s]);
      }
      printf("Termine de cargar sucursal %i\n", s);
      sleep(4);
     }
     
     
   pthread_mutex_unlock(&cargada_mutex1);
   printf("fin thread cargoVentas\n");
   pthread_exit(NULL);
}

