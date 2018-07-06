#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// 处理Ctrl+C信号
//

void ouch(int sig){
	
	printf("OUCH! i got signal %d\n",sig);
	(void) signal(SIGINT,SIG_DFL);

}

int main(){

	(void) signal(SIGINT,ouch);

	while(1){
	
		printf("Hello world\n");
		sleep(1);
	}
}
