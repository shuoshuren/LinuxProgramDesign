#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

/***
 * 协调性文件锁
 *
 *
 * */

const char *lock_file = "lock.test";

int main(){

	int file_desc;
	int tries = 10;
	
	while(tries--){
		file_desc = open(lock_file,O_RDWR|O_CREAT|O_EXCL,0444);
		if( file_desc == -1){
			printf("%d - lock already present \n",getpid());
			sleep(3);
		}else{
			printf("%d - I have exclusive access\n",getpid());
			sleep(1);
			(void)close(file_desc);
			(void)unlink(lock_file);

			sleep(2);
		
		}
	
	}

	exit(0);

}
