
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char **argv){
	while(1) {
		printf("Bloqueo proceso %d a la espera de senial\n",getpid());
		pause();
		printf("Proceso %d sali de bloqueo!\n",getpid());
	}
	return 0;
}

