/*
 * practicaProcesos8.c
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
{	//1 proceso
	pid_t pid = fork();
	//2 procesos
	//Los procesos que se crean en las bifurcaciones siguen vigentes al salir de las mismas. Entonces, un proceso creado con la variable pid = 0, entrara
	// en todas las bifurcaciones que digan eso
	
	
	
	if (pid > 0)
	//1 proceso (el padre) 
	{   printf("Soy el padre, mi pid es %d y el de mi hijo es %d. La variable pid tiene un %d.\n", getpid(), pid, pid);
		pid = fork();
	//2 procesos (el padre y el nuevo hijo)
	       if (pid > 0)
			//1 proceso, el padre
			printf("Soy el padre DENUEVO, mi pid es %d y el de mi nuevo hijo es %d. La variable pid tiene un %d.\n", getpid(), pid, pid);
	       if (pid == 0)
	       //1 proceso, el nuevo hijo
			printf("Soy el hijo n2, mi pid es %d y el de mi padre es %d. La variable pid tiene un %d.\n", getpid(), getppid(), pid);
	 } 
	      
	if (pid == 0){
	//Aca entran dos procesos, los dos hijos, por que tienen los dos 0 en la variable pid.
		printf("Soy el hijo n1, mi pid es %d y el de mi padre es %d. La variable pid tiene un %d.\n", getpid(), getppid(), pid);	
		pid = fork();
			if (pid >0)
				printf("Soy el hijo n1 DENUEVO, mi pid es %d y el de mi padre es %d. La variable pid tiene un %d.\n", getpid(), getppid(), pid);	
			if (pid ==0)
				printf("Soy el hijo del hijo n1, mi pid es %d y el de mi padre es %d. La variable pid muestra %d.\n", getpid(), getppid(), pid);	
	}
		
	return 0;
}

