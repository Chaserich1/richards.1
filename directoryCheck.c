/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 29, 2020
   Filename: directoryCheck.c  */

#include "directoryCheck.h"

int isdirectory(char *path) {
    struct stat statbuf;

    if(stat(path, &statbuf) == -1)
        return 0;
    else
        return S_ISDIR(statbuf.st_mode);
} 
