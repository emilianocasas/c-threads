/*
 * practicaProcesos1c.c
 * 
 * Copyright 2015 Emiliano <emiliano@emiliano-To-be-filled-by-O-E-M>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{   int status = 0;
	pid_t wpid;
	pid_t pid;
	system("ps");
	pid = fork();
	//Si el fork devolvia -1 (numero negativo), es por que se produjo un error y no se puede
	// crear al proceso hijo (falta de memoria)
	if (pid < 0)
		{ printf("Ha ocurrido un error.\n");
			exit(pid);
	      }
	// La variable pid la tendran los dos procesos, el padre y el hijo. En la variable pid del padre
	// se almacenara el pid (identificador) del proceso hijo. En la variable pid del hijo, se va a 
	// almacenar un 0, para saber que este es el hijo. Esto no quiere decir que su pid sea 0, solo su
	// variable pid que nosotros creamos (se podria haber llamado de otra manera), es 0. El proceso 
	// hijo cuenta con su propio pid (identificador).      
		  
	if (pid > 0)
		 {
		   wpid = wait(&status);
			if (wpid < 0)
				printf("El nene no esta bien.\n");
				else if (wpid == 0)
				printf("A ver que sale.\n");
				else
				printf("Somos nosotros, lo que sale es un %d.\n", wpid);
					
				
		  
		  printf("Soy el padre y mi pid es %d.\n", getppid() );
	     }
	else
		{ 
	      sleep(2);
	      printf("Soy el hijo y mi pid es %d.\n", getppid() );
	      
	  	}
    return 0;
   }
