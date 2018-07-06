#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// fork 函数
//
//

int main(){


	pid_t pid;
	char *message;
	int n;

	printf("fork program starting\n");
	pid = fork();
	switch(pid){
	
		case -1://Error
			perror("fork failed");
			exit(1);
			break;
		case 0:// child
			message = "This is the child";
			n = 5;
			break;
		default:// parent
			message = "this is the parent";
			n = 3;
			break;

	}

	for(;n>0;n--){
		puts(message);
		sleep(1);
	}

	exit(0);
}
