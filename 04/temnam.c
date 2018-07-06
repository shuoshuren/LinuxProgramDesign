//
// Created by Qi on 2018/5/2.
//临时文件
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    char tempname[L_tmpnam];
    char *filename;
    FILE *tmpfp;

    filename = tmpnam(tempname);
    printf("Temporary file name is : %s\n",filename);
    tmpfp = tmpfile();
    if (tmpfp){
        printf("Opened a temporary file ok\n");
    }else{
        perror("tmpfile");
    }

    exit(0);
}

