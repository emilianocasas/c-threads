#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char* ingresoLinea();
void mostrarLinea(char *str);

char *comando;
int salir = 0;

int main(void){
  ingresoLinea();
  mostrarLinea(comando);
  return 0;
}

char *ingresoLinea() {
       char c = ' ';
       int nbytes = sizeof(char); //
       int blocksize = nbytes*10;  // buffer size es de solo 10 caracteres, ampliarlo para mejorar performance
       int nbuf = 0; // cuenta caracteres almacenados en buf
       int nbufsize = blocksize; // tamanio actual del buffer
       char *buf = (char *) malloc(blocksize);
       c = (char) getc(stdin);
       while (c != 10 && c != 13){
               buf[nbuf++] = c;
               if ( (nbuf % blocksize) == 0 ){
                       nbufsize+=blocksize;
                       buf = realloc(buf,nbufsize);
               }
               c = (char) getc(stdin);
       }
       buf[nbuf]='\0';
        if (salir) {
          free(buf);
          comando=NULL;
		} else comando = buf;
        
        return buf;
}

void mostrarLinea(char *str){
	printf("Usted ingreso la linea: ");
	printf("%s\n", str);
}


