/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 29, 2020
   Filename: SearchFileSystem.c  */

#include "SearchFileSystem.h"
#include "CommandOptions.h"
#include "DirectoryCheck.h"
#include "Queue.h"

void breadthFirstTraversal(char *path) {
    char buf[512];
    char *tempBuf;
    char *dqPath;
    struct dirent *direntp;
    DIR *dirp;        
   
    //printOptions(path);
    //printf("%s\n", path);   

    //Create the queue
    struct Queue *queuePtr = createQueue();
    
    //Enqueue the orginal directory that is passed in
    enqueue(queuePtr, path);

    //While the queue is not empty
    while(!emptyQueue(queuePtr)) {  
        //Dequeue first in and assign it to dequeued path
        dqPath = dequeue(queuePtr);
        //Return if the directory does not open
        if(!(dirp = opendir(dqPath))) {
            perror("bt: Error: Unable to open directory");
            return; 
        }
    
        //Read the files and directories in the current directory        
        while((direntp = readdir(dirp)) != NULL) {
            //Don't process current or parent
            if(strcmp(direntp-> d_name, ".") != 0 && strcmp(direntp-> d_name, "..") != 0) {              
                /*Store the formatted (next/direntp-> d_name) c string in the buffer 
                  pointed to by buf, sizeof(buf) is the max size to fill */ 
                snprintf(buf, sizeof(buf), "%s/%s", dqPath, direntp-> d_name); 
                lstat(buf, &typeStats);               
                
                //Pass buf to the options to determine which were specified
                printOptions(buf);
                
                //Print the path
                printf("%s\n", buf);
                
                //If buf is a directory we need to enqueue it
                if(isDirectory(buf)) {
                    /*tempBuf is a ptr to a newly allocated string which 
                      is a duplicate of the string pointed to by buf  */ 
                    tempBuf = strdup(buf);
                    //Enqueue the tempBuf
                    enqueue(queuePtr, tempBuf);
                }  
            }
            else
                continue;            
        }
    }

    //Pass queuePtr and tempBuf to free to avoid memory leak
    free(queuePtr);
    free(tempBuf);     
}
