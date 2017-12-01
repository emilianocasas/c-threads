#include <pthread.h>
#include <unistd.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double mivta[5][31]; 

int main(int argc, char **argv){
	int i, d;
	
	for (i=0; i<5; i++){
		for (d=0; d<31; d++){
			mivta[i][d] = ((double) random())/10000000.0; 
		}
	}
	
	for (i=0; i<5; i++){
		for (d=0; d<31; d++){
			printf("%f\n", mivta[i][d]);
		}
	}
	
	
	return 0;
}

