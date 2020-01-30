/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 29, 2020
   Filename: GetCurrentDirectory.c  */

#include "GetCurrentDirectory.h"

//Program 5.2 - Page 150 Robbins Robbins for getting current working directory
int main(void)
{
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

        printf("Current working directory: %s\n", mycwdp);
        return mycwdp;
    }

    getCWD();
}
