/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 29, 2020
   Filename: GetCurrentDirectory.c  */

#include "GetCurrentDirectory.h"

//Program 5.2 - Page 150 Robbins Robbins for getting current working directory

char *getCWD(){	
    long maxpath;
    char *mycwdp;

    if ((maxpath = pathconf(".", _PC_PATH_MAX)) == -1) {
        perror("Failed to determine the pathname length");
        return NULL;
    }

    if ((mycwdp = (char *) malloc(maxpath)) == NULL) {
        perror("Failed to allocate space for pathname");
        return NULL;
    }

    if (getcwd(mycwdp, maxpath) == NULL) {
        perror("Failed to get current working directory");
        return NULL;
    }

    return mycwdp;
}

char *getFileInDir(mycwd) {
    struct dirent *direntp;
    DIR *dirp;

    if((dirp = opendir(mycwd)) == NULL) {
        perror("Failed to open directory");
        return 1;
    }

    while((direntp = readdir(dirp)) != NULL)
        printf("%s\n", direntp-> d_name);
    while((closedir(dirp) == -1) && (errno == EINTR)) ;
    return 0;
}
