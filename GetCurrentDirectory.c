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

void searchFileSystem(char *path) {
    struct dirent *direntp;
    DIR *dirp;
    char fullPath[1024];

    if(!(dirp = opendir(path)))
        return;

    while((direntp = readdir(dirp)) != NULL) {
        if(strcmp(direntp-> d_name, ".") != 0 && strcmp(direntp-> d_name, "..") != 0) {
            printf("%s%s\n", strcat(getCWD(), "/"), direntp-> d_name);
            
            strcpy(fullPath, path);
            strcat(fullPath, "/");
            strcat(fullPath, direntp-> d_name);
            
            searchFileSystem(fullPath);
        }
    }
        
}
