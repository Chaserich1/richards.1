/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 31, 2020
   Filename: CommandOptions.c  */

#include "CommandOptions.h"


//Initialize all flags as false until they are entered
int helpMessageFlg = 0;    // -h
int symbolicLinkFlg = 0;   // -L
int fileTypeInfoFlg = 0;   // -t
int permissionFlg = 0;     // -p
int linksToFileFlg = 0;    // -i
int fileUIDFlg = 0;        // -u
int fileGIDFlg = 0;        // -g
int fileByteSizeFlg = 0;   // -s
int lastModTimeFlg = 0;    // -d
int tpiugsFlg = 0;         // -l

void flgsPassedIn(int argc, char **argv) {

// User getopt to go through the parameter flgs that the user passes
//   I used gnu.org Example-of-Getopt for guidance with this  
    int c = 0;
    int opterr = 0;

    while((c = getopt(argc, argv, "hLdgipstuI:l")) != -1) {
 
        switch(c) {
            case 'h':
                helpMessageFlg = 1;
                break;
            case 'L':
                symbolicLinkFlg = true;
                break;
            case 'd':
                lastModTimeFlg = true;
                break;
            case 'g':
                fileGIDFlg = true;
                break;
            case 'i':
                linksToFileFlg = true;
                break;
            case 'p':
                permissionFlg = true;
                break;
            case 's':
                fileByteSizeFlg = true;
                break;
            case 't':
                fileTypeInfoFlg = true;
                break;
            case 'u':
                fileUIDFlg = true;
                break;
            case '?':
                printf("Please enter a valid option. User bt -h for available options");
                abort();
                break;
            case 'l':
                tpiugsFlg = true, fileTypeInfoFlg = true, permissionFlg = true, linksToFileFlg = true, fileUIDFlg = true, fileGIDFlg = true, fileByteSizeFlg = true;
                break; 
        }
    }
    
}

void displayHelpMessage() {
    printf("\n---------------------------------------------------------\n");
    printf("See below for the options:\n\n");
    printf("-h   : Print help message.\n");
    printf("-L   : Follow symbolic links, if any.\n"); 
    printf("-d   : Show the time of the last modification.\n");
    printf("-g   : Print the GID associated with the file.\n");
    printf("-i   : Print the number of links to file in inode table.\n");
    printf("-p   : Print permission bits.\n");
    printf("-s   : Print the size of file in bytes.\n");
    printf("-t   : Print information on file type.\n");
    printf("-u   : Print the UID associated with the file.\n");
    printf("-I n : Change indentation to n spaces for each level.\n");
    printf("-l   : Print information for -t -p -i -u -g -s\n");
    printf("\n---------------------------------------------------------\n"); 
}















