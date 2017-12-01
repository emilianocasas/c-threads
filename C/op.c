#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int main(int argc, char **argv){
	
	int op = 0;
	op = 2;
	
	//switch (op){ 
	  //case 0:{
		  if (op == 0){ 
		  printf("OP ES 0\n");
	  }
		  //else ;
	  //}
	  //case 1:{
			if (op == 1) {
				printf("OP ES 1\n");
		}
			//else ;
	  //}
	  //case 2:{
		if (op == 2) { 
		printf("OP ES 2\n");
	}
		//else;
		//}
//}	 
	
	return 0;
}

