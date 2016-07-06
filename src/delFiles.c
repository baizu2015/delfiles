#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
int main (void){
	char *destDir="/usr/local/development/test";
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if((dp = opendir(destDir)) == NULL){
		fprintf(stderr,"cannot open director:%s \n",destDir);
		return -1;
	}
	chdir(destDir);
	while((entry=readdir(dp))!=NULL){
		lstat(entry->d_name,&statbuf);
		if(S_ISREG(statbuf.st_mode)){
			remove(entry->d_name);
		}
	}
	return 0;
}
