/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 29, 2020
   Filename: SearchFileSystem.c  */

#include "SearchFileSystem.h"
#include "CommandOptions.h"
#include "DirectoryCheck.h"
#include "Queue.h"

void breadthFirstTraversal(char *path) {
    char fullPath[1024];
    char buf[512];
    char qBuffer[QBUF];
    DIR *dirp;
    struct dirent *direntp;    
    char *next;    

    
    createQueue();

    enqueue(fullPath);
      
    next = dequeue(path);
    
    if(!(dirp = opendir(path)))
        return; 
    
         
    while((direntp = readdir(dirp)) != NULL) {
        if(isDirectory(path)){
            if(strcmp(direntp-> d_name, ".") != 0 && strcmp(direntp-> d_name, "..") != 0) {
                
                snprintf(buf, sizeof(buf), "%s/%s", path, direntp-> d_name); 
                stat(buf, &typeStats);               
        
                strcpy(fullPath, path);
                strcat(fullPath, "/");
                strcat(fullPath, direntp-> d_name);
                  
         
                char* str;
                if(isDirectory(buf)) {
                   printOptions(buf);
                    printf("%s/%s\n", path, direntp-> d_name);
                    str = strdup(buf);
                    enqueue(str);
                }
                else {
                    printOptions(buf);
                    printf("%s/%s\n", path, direntp-> d_name);
                }
               
                //printOptions(fullPath);
                                                                                                                        
                //printf("%s/%s\n", path, direntp-> d_name);           
                breadthFirstTraversal(fullPath);
            }
        }
    }     
}
