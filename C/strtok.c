#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main()
{
   //int estado = 0;
   int i = 0;
   //int nbytes = sizeof(char);
   //int blocksize = nbytes*10;   
   char comando[3]="ps";
   //char *argumentos[] = { "ps","-l",NULL };
   
   char *arg = (char *) malloc(20);
   
   char *token = (char *) malloc(20);
   
   strcpy(token, comando); //Asocio los buffers
   token = strtok(comando, " "); //Obtiene el primer token y los va a separar por espacios
   printf("Obtengo el primer token, el cual es %s\n", token);
 
   while( token != NULL ) { //Recorre los otros tokens  
	      arg[i] = token;
		  i++;
		  token = strtok(NULL, " ");
	  }
  
		printf("%s\n", arg[0]);
		printf("%s\n", arg[1]);
 
 //estado = execvp(arg, arg, NULL);
	//printf("Error\n");
	//exit(estado);

return(0);
}













