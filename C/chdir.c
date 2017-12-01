#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	

	
		char *directory = "practicasProcesos";
		int ret;

		ret = chdir (directory);
		//chdir (*directory);
	
		printf("%i\n", ret);
	 
	
	return(0);

}

