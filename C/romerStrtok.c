#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int estado = 0 , i = 0;
   char *token            = (char *)malloc(16 * sizeof(char)) ;
   char *comandoingresado = (char *)malloc(16 * sizeof(char)) ;
   //char comandoingresado[5]="ps -l";
   char *comandotokens [32] ;
   //char *argumentos[] = { "ps","-l",NULL };
   
   printf("MI PROMPT=> ");
	gets(comandoingresado);

    token = strtok(comandoingresado, " "); //Obtiene el primer token y los separa los tokens por espacios
    while( token != NULL )
     {
          comandotokens[i]= token;
          i++;
          token = strtok(NULL, " ");
      }
      comandotokens[i] = token;

		printf("%s\n", comandotokens[0]);
		printf("%s\n", comandotokens[1]);
	
	
		printf("%s\n", comandotokens[2]);

    //estado = execvp(comandotokens[0],comandotokens);

     printf("Error\n");
     exit(estado);

}

