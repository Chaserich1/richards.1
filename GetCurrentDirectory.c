/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 29, 2020
   Filename: GetCurrentDirectory.c  */

#include "GetCurrentDirectory.h"
#include "CommandOptions.h"
#include "directoryCheck.h"

//Program 5.2 - Page 150 Robbins Robbins for getting current working directory

char *getCWD(char *path){	
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
    char fullPath[1000];
    struct stat dirStats;
    struct passwd *pwd;    
    char buffer[512];
    if(!(dirp = opendir(path)))
        return;

    while((direntp = readdir(dirp)) != NULL) {
        if(isdirectory(path)){
            if(strcmp(direntp-> d_name, ".") != 0 && strcmp(direntp-> d_name, "..") != 0) {
                
                snprintf(buffer, sizeof(buffer), "%s/%s", path, direntp-> d_name); 
                stat(buffer, &dirStats);     
                //printf("%s\n", strcat((path), direntp-> d_name));
                //printf("%s/%s\n", /*strcat((path), "/")*/path, direntp-> d_name);
                //printf("%s%s\n", path, strcat("/", direntp-> d_name));           
        
                strcpy(fullPath, path);
                strcat(fullPath, "/");
                strcat(fullPath, direntp-> d_name);       
            
                //-t
                if(fileTypeInfoFlg) {
                    //printf("TestMessage");
                    switch(dirStats.st_mode &S_IFMT) {
                        case S_IFREG:
                            printf("%s", "Regular File");
                            break;
                        case S_IFDIR:
                            printf("%s", "Directory");
                            break;
                        case S_IFLNK:
                            printf("%s", "SymLink");
                            break;
                        default:
                            printf("%s", "Unknown");
                            break;                         
                    }
                    printf("\t");
                }
            
                //-p
                if(permissionFlg) {
                    printf((dirStats.st_mode & S_IRUSR) ? "r" : "-");
                    printf((dirStats.st_mode & S_IWUSR) ? "w" : "-");
                    printf((dirStats.st_mode & S_IXUSR) ? "x" : "-");
                    printf((dirStats.st_mode & S_IRGRP) ? "r" : "-");
                    printf((dirStats.st_mode & S_IWGRP) ? "w" : "-");
                    printf((dirStats.st_mode & S_IXGRP) ? "x" : "-");
                    printf((dirStats.st_mode & S_IROTH) ? "r" : "-");
                    printf((dirStats.st_mode & S_IWOTH) ? "w" : "-");
                    printf((dirStats.st_mode & S_IXOTH) ? "x" : "-");
                    printf("\t");
                }
               
                //-i
                if(linksToFileFlg) {
                    printf("%4d", dirStats.st_nlink);
                }
        
                //-u
                if(fileUIDFlg) {
                    if((pwd = getpwuid(dirStats.st_uid)) != NULL)
                        printf(" %-8.8s", pwd-> pw_name);
                    else
                        printf(" %-8d", dirStats.st_uid);
                }
            
            
//                snprintf(buffer, sizeof(buffer), "%s/%s", path, direntp-> d_name);
                printf("%s/%s\n", path, direntp-> d_name);   
//                stat(buffer, &dirStats);        
                searchFileSystem(fullPath);
            }
        }
    }     
}
