#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(){
   int aux = 0;
   int estado = 0;
   int i = 0;

   //int nbytes = sizeof(char);
   //int blocksize = nbytes*10;   
   char comando[5]="ps -l";
   //char *argumentos[] = { "ps","-l",NULL };
   char *arg = (char *) malloc(5);
   char *token = (char *) malloc(5);
   
   strcpy(token, comando); //Asocio los buffers
   token = strtok(comando, " "); //Obtiene el primer token y los va a separar por espacios
   printf("Obtengo el primer token, el cual es %s\n", token);
 
   while( token != NULL ) { //Recorre los otros tokens  
      printf( "%s\n", token );
	  if (aux == 0){
		printf("Entre0\n");
		for (i=0; i<2; i++){
			arg[i] = token[i];
			aux = 1;
			//aux = strlen(token);
			//printf("Muestro longitud: %i\n", aux);
			//printf("Muestro arg: %c\n", arg[i]);
			
		}
	  } else {
		  printf("EL token es %s\n", token);
		  printf("Entre\n");
		  arg[2] = ' ';
		  printf("Tengo que ser el guion vieja...  %c\n", token[0]);
		  arg[3] = token[0];
		  arg[4] = token[1];
	  }  
	  
		  token = strtok(NULL, " "); //pasa al siguiente
	  }
  
  for (i=0; i<5; i++){
	 printf("Muestro arg denuevo: %c\n", arg[i]);
 }
 
 estado = execlp(arg, arg, NULL);
	printf("Error\n");
	exit(estado);

return(0);
}













