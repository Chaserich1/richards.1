/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 29, 2020  
   Filename: DirectoryCheck.c  */

#include "DirectoryCheck.h"

char *getCWD(char *path){	
    long maxpath;
    char *mycwdp;
    //Find the maximum pathname length
    if ((maxpath = pathconf(".", _PC_PATH_MAX)) == -1) {
        perror("bt: Error: Failed to determine the pathname length");
        return NULL;
    }
    //Allocate space for the pathname dynamically
    if ((mycwdp = (char *) malloc(maxpath)) == NULL) {
        perror("bt: Error: Failed to allocate space for pathname");
        return NULL;
    }
    //If it fails, return NULL
    if (getcwd(mycwdp, maxpath) == NULL) {
        perror("bt: Error: Failed to get current working directory");
        return NULL;
    }
    //Return the current working directory
    return mycwdp;
}

//Pass the path to determine if it's a directory
int isDirectory(char *path) {
    struct stat statBuf;
    //Return 0 if not a directory
    if(stat(path, &statBuf) == -1)
        return 0;
    else //Return true (nonzero) if it is a directory
        return S_ISDIR(statBuf.st_mode);
}

