#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

// 打印目录

void print_dir(char *dir,int depth);

int main(int argc,char* grav[]){

	char *topdir = ".";
	if( argc >= 2){
		topdir = argv[1];
	}

	printf("Directory scan of %s\n",topdir);
	print_dir(topdir,0);
	printf("doen\n");

	exit(0);
}
void print_dir(char *dir,int depth){

	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;

	if(( dp = opendir(dir)) == NULL){
		fprintf(stderr,"cannot open directory: %s\n",dir);
		return;
		
	}
	chdir(dir);
	while(( entry = readdir(dp)) != NULL){
		lstat(entry->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode)){
			/* found a directory,buf ignore . and .. **/
			if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name)==0){
				continue;
			}
			printf("%*s%s/\n",depth,"",entry->d_name);
			/**
			 * recurse at a new indent level
			 * */
			print_dir(entry->d_name,depth+4);

		}else{
			printf("%*s%s\n",depth,"",entry->d_name);
		}

	}

	chdir("..");
	closedir(dp);
}



