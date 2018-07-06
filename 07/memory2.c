#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define A_MEGABYTE (1024*1024)

#define PHY_MEM_MEGS 1024

/***
 *请求全部的物理内存
 *
 *
 */


int main(){

	char *some_memory;
	size_t size_to_allocate = A_MEGABYTE;
	int megs_obtained = 0;

	int exit_code = EXIT_FAILURE;

	while(megs_obtained<(PHY_MEM_MEGS * 2)){
	
		some_memory = (char *)malloc(size_to_allocate);
		if(some_memory != NULL){
			megs_obtained++;
			sprintf(some_memory,"Hello world");
			printf("%s - now allocated %d Megabytes\n",some_memory,megs_obtained);


		}else{
		
			exit(EXIT_FAILURE);
		}
	
	}

	exit(EXIT_SUCCESS);
}
