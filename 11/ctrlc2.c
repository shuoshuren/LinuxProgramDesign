#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// 使用sigaction函数 处理Ctrl+C信号
//

void ouch(int sig){
	
	printf("OUCH! i got signal %d\n",sig);
	(void) signal(SIGINT,SIG_DFL);

}

int main(){

	struct sigaction act;
	act.sa_handler = oach;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGINT,&act,0);

	while(1){
	
		printf("Hello world\n");
		sleep(1);
	}
}
