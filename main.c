/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 30, 2020
   Filename: main.c  */

#include "GetCurrentDirectory.h"
#include "DirectoryCheck.h"
#include "CommandOptions.h"

#include <stdio.h>
#include <stdlib.h>

/*
struct node {
    char* item;
    struct node *left, *right;
};

void printBFS(struct node *root) {
    int h = height(root);
    int i;
    for(i = 1; i <= h; i++)
        printCurLevel(root, i);
}

void printCurLevel(struct node *root, int level) {
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d ", root-> item);
    else if (level > 1) {
        printCurLevel(root-> left, level - 1);
        printCurLevel(root-> right, level - 1);
    }
}

int height(struct node *node) {
    if(node == NULL)
        return 0;
    else {
        int leftHeight = height(node-> left);
        int rightHeight = height(node-> right);
        
        if(leftHeight > rightHeight) {
            printf("\nLeft Height is: %d\n", leftHeight + 1);
            return(leftHeight + 1);
        }
        else {
            printf("\nRight Height is: %d\n", rightHeight + 1);
            return(rightHeight + 1);
        }
    }
}

struct node *newNode(int item) {
    struct node *node = (struct node*) malloc(sizeof(struct node));
    node-> item = item;
    node-> left = NULL;
    node-> right = NULL;
    return(node);
}

*/

int main(int argc, char* argv[]) {
 
    int i;
    char* dirname = NULL;
   
    //If there are option(s) and directory or just a directory (ex: bt -p -i testDir)
    for(i = optind; i < argc; i++) { 
        if(argv[i] != NULL)
            dirname = argv[i];        
    }
    
    //If there is nothing passed in (ex: bt)
    if(dirname == NULL) { 
        dirname = getCWD(".");
    }

    //Need to make sure the directory passed in is a directory (ex: bt -p)
    if(!(isDirectory(dirname)))
        dirname = getCWD(".");

    //printf("%i\n", isdirectory(argv[1]));
    
    //Call function with getopt switch
    flgsPassedIn(argc, argv);
    
    //Print information on the options available and return
    if(helpMessageFlg) {
        displayHelpMessage();
        return 0;
    }
    
    //Pass the directory whether specified or current default to searchFileSystem (in GetCurrentDirectory.c)
    searchFileSystem(dirname);
    
    /*//BFS Traversal Test
    struct node *root = newNode(1);
    root-> left = newNode(2);
    root-> right = newNode(3);
    root-> left-> left = newNode(4);
    root-> right-> right = newNode(5);
    root-> left-> left-> left = newNode(6);
    
    printBFS(root); */
    return 0;
}
