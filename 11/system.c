#include <stdlib.h>
#include <stdio.h>

// 使用system函数运行ps命令

int main(){

	printf("Running ps with system\n");
	system("ps ax");
	printf("Done.\n");
	exit(0);
}
