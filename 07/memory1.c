#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define A_MEGABYTE (1024*1024)

/***
 *简单的内存分配
 *
 *
 */


int main(){

	char *some_memory;
	int megabyte = A_MEGABYTE;
	int exit_code = EXIT_FAILURE;

	some_memory = (char *) malloc(megabyte);

	if(some_memory!=NULL){
	
		sprintf(some_memory,"hello world\n");
		printf("%s",some_memory);
		exit_code = EXIT_SUCCESS;
	}

	exit(exit_code);
}
