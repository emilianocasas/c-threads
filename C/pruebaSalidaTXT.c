#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv){

	//int i = 0;
	//int a = 0;

	char *palabra[15];
	//char *e[2];
	
	palabra[0] = 'p';
	palabra[1] = 's';
	palabra[2] = ' ';
	palabra[3] = '>';
	palabra[4] = ' ';
	palabra[5] = 's';
	palabra[6] = 'a';
	palabra[7] = 'l';
	palabra[8] = 'i';
	palabra[9] = 'd';
	palabra[10] = 'a';
	palabra[11] = '.';
	palabra[12] = 't';
	palabra[13] = 'x';
	palabra[14] = 't';
	
	//int longitud = strlen(palabra);
	
	//for (i=0; i<longitud;i++){
		 //aux = strcmp(comandoingresado[i], '>');
		// if (palabra[i] == '>') auxentrada = i;
	//}
	
	printf("%s\n", palabra);
	
	//i = 0;
	//for (a=2; a<4; a++){
		//e[i] = palabra[a];
		//i++;
		//}
	
	//e[0] = palabra[2];
	//e[1] = palabra[3];
		
	//printf("%i\n", i);	
	//printf("%c\n", e[0]);	
	//printf("%c\n", e[1]);	
	return 0;
}

