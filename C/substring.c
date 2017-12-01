#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv){
	int i = 0;
	int i2 = 0;
	int aux = 0;
	// a es un conjunto de string, osea, un conjunto de conjunto de chars.
	char cadena[15] = "hola como te va";
	char *token = (char *) malloc(15);
	char *arg = (char *) malloc(15);
	
   strcpy(token, cadena); //Asocio los buffers
   token = strtok(cadena, " "); //Obtiene el primer token y los va a separar por espacios
	
	while(token != NULL){
		if (i==0){
		printf("El primer token es %s\n",token);
		aux = strlen(token);
		for (i2=0; i2<aux; i2++){
			arg[i2]=token[i2];
		}
		token = strtok(NULL, " "); //pasa al siguiente
		i++;
		}else{
			printf("Entre en el else\n");
			token = strtok(NULL, " "); //pasa al siguiente
		}
		
	}
	
	printf("Muestro arg\n");
	for (i=0; i<aux; i++){
		
		printf("%c",arg[i]);
	}
	
	printf("\n");
	return 0;
}

