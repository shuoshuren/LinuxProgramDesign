#include<unistd.h>
#include<stdlib.h>

int main(){
	if(18!=(write(1,"here is some data\n",18))){
		write(2,"A write error has occurred on file descriptor 1\n",46);		
	}
	exit(0);
}
