#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 *
 * 访问空指针
 *
 * */

int main(){
	char *some_memory = (char *)0;
	printf("A read from null %s\n",some_memory);
	sprintf(some_memory,"A write to null \n");
	exit(0);
}
