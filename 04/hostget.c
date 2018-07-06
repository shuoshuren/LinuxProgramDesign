#include <sys/utsname.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/***
 * 获取主机信息
 *
 * */

int main(){

	char computer[256];
	struct utsname uts;

	if(gethostname(computer,255)!=0 || uname(&uts)<0){
		printf("could not get host information\n");
		exit(1);
	}

	printf("host name is %s\n",computer);
	printf("System is %s on %s hardware\n",uts.sysname,uts.machine);
	printf("Nodename is %s\n",uts.nodename);
	printf("Version is %s,%s\n",uts.release,uts.version);

	exit(0);
}
