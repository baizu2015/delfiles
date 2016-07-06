#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>

int delfile(char *);

int main (void){
	char *destDir="/usr/local/development/test";
	delfile(destDir);
	return 0;
}
int delfile(char *path){
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if((dp = opendir(path)) == NULL){
		fprintf(stderr,"cannot open director:%s \n",path);
		return -1;
	}
	chdir(path);
	while((entry=readdir(dp))!=NULL){
		lstat(entry->d_name,&statbuf);
		if(S_ISREG(statbuf.st_mode)){
			remove(entry->d_name);
		}
	}
	return 0;
}
