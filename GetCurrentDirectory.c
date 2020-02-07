/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 29, 2020
   Filename: GetCurrentDirectory.c  */

#include "GetCurrentDirectory.h"
#include "CommandOptions.h"
#include "DirectoryCheck.h"

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
    char fullPath[1024];
    char buffer[512];
    DIR *dirp;
    struct dirent *direntp;
    struct stat typeStats;
    struct passwd *pwd;
    struct group *grp;    
    

    if(!(dirp = opendir(path)))
        return;

    while((direntp = readdir(dirp)) != NULL) {
        if(isDirectory(path)){
            if(strcmp(direntp-> d_name, ".") != 0 && strcmp(direntp-> d_name, "..") != 0) {
                
                snprintf(buffer, sizeof(buffer), "%s/%s", path, direntp-> d_name); 
                stat(buffer, &typeStats);               
        
                strcpy(fullPath, path);
                strcat(fullPath, "/");
                strcat(fullPath, direntp-> d_name);       
            
                //-t
                if(fileTypeInfoFlg) {
                    //printf("TestMessage");
                    switch(typeStats.st_mode &S_IFMT) {
                        case S_IFREG:
                            printf("%12s", "Regular File");
                            break;
                        case S_IFDIR:
                            printf("%-12s", "Directory");
                            break;
                        case S_IFLNK:
                            printf("%12s", "SymLink");
                            break;
                        default:
                            printf("%12s", "Unknown");
                            break;                         
                    }
                    printf("  ");
                }
            
                //-p
                if(permissionFlg) {
                    printf((S_ISDIR(typeStats.st_mode)) ? "d" : "-");
                    printf((typeStats.st_mode & S_IRUSR) ? "r" : "-");
                    printf((typeStats.st_mode & S_IWUSR) ? "w" : "-");
                    printf((typeStats.st_mode & S_IXUSR) ? "x" : "-");
                    printf((typeStats.st_mode & S_IRGRP) ? "r" : "-");
                    printf((typeStats.st_mode & S_IWGRP) ? "w" : "-");
                    printf((typeStats.st_mode & S_IXGRP) ? "x" : "-");
                    printf((typeStats.st_mode & S_IROTH) ? "r" : "-");
                    printf((typeStats.st_mode & S_IWOTH) ? "w" : "-");
                    printf((typeStats.st_mode & S_IXOTH) ? "x" : "-");
                    printf("  ");
                }
               
                //-i
                if(linksToFileFlg) {
                    printf("%3d", typeStats.st_nlink);
                    printf("  ");
                }
        
                //-u
                if(fileUIDFlg) {
                    if((pwd = getpwuid(typeStats.st_uid)) != NULL)
                        printf("%4s", pwd-> pw_name);
                    else
                        printf("%4d", typeStats.st_uid);
                    printf("  ");
                }
                
                //-g
                if(fileGIDFlg) {
                    if((grp = getgrgid(typeStats.st_gid)) != NULL)
                        printf("%4s", grp-> gr_name);
                    else
                        printf("%4d", typeStats.st_gid);
                    printf("  ");
                } 
     
                //-s
                if(fileByteSizeFlg) {
                    
                    long long int byte = (long long)typeStats.st_size;
                    if(byte >= 1000000000) {
                        byte = (long long)(byte/1000000000);
                        printf("%3dG", byte);
                    }
                    else if(byte >= 1000000) {
                        byte = (long long)(byte/1000000);
                        printf("%3dM", byte);
                    }
                    else if(byte >= 1000) {
                        byte = (long long)(byte/1000);
                        printf("%3dK", byte);
                    }   
                    else
                        printf("%4d", byte);

                    printf("  ");
                } 
                
                //-d
                if(lastModTimeFlg) {
                    if(stat(path, &typeStats) == -1)   
                        perror("bt: Error: Unable to get file last modification time");
                    else {       
                        char formDate[80];
                        time_t t  = typeStats.st_mtime;
                        struct tm lt;
                        localtime_r(&t, &lt);       
                        strftime(formDate, sizeof(formDate), "%b %e, %Y", &lt);
                        printf("%s", formDate);
                    }

                    printf("  ");
                }

                printf("%s/%s\n", path, direntp-> d_name);           
                searchFileSystem(fullPath);
            }
        }
    }     
}
