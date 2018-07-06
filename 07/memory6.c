#include <stdlib.h>
#include <stdio.h>

#define ONE_K (1024)


/***
 *
 * 释放内存
 *
 *
 * */

int main(){
	char *some_memory;
	int exit_code = EXIT_FAILURE;
	
	some_memory = (char *)malloc(ONE_K);
	if(some_memory !=NULL){
		free(some_memory);
		printf("memory allocated and freed again\n");
		exit_code = EXIT_SUCCESS;
	}

	exit(exit_code);

}
