#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int tarea(int);

int main(int argc, char **argv){
	pid_t pid,pidTer;
	int status1 = 0, status2 = 0, status3 = 3;
	pid = fork();
	if (pid == 0){
		pid = fork();
		if (pid > 0){
			pid = fork();
			if (pid == 0){
				 printf("Soy el proceso %d, 4\n", getpid());
				 exit(tarea(getpid()));
		    }else{
				printf("Soy el proceso %d, 2\n", getpid());
				pidTer = wait(&status1);
				printf("Termino %d con %d\n", pidTer, (status1/256));
				pidTer = wait(&status2);
				printf("Termino %d con %d\n", pidTer, (status2/256));
				exit(status1 && status2);
			}
		} else{
			 printf("Soy el proceso %d, 3\n", getpid());
			 exit(tarea(getpid()));
			}
	}else{
		if (pid>0){
			pidTer = wait(&status3);
			printf("Soy el proceso %d, 1\n", getpid());
			printf("Termino %d con %d\n", pidTer, (status3/256));
		}
	}	
	exit(pid);
}

int tarea(int num){
	printf("tarea %d, soy %d\n", num, getpid());
	return(num/2000);
}
