/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: February 7, 2020
   Filename: Queue.c  */

#include "Queue.h"

void createQueue(void) {
    rear = NULL;
}

void enqueue(char* path) {
    struct Queue *queuePtr;
    char *tempPath;

    if((queuePtr = (struct Queue *)malloc(sizeof(struct Queue))) == NULL) {
        perror("Malloc error");
        exit(1);
    }
    if((tempPath = (char *)malloc(strlen(path) + 1)) == NULL) {
        perror("Malloc error");
        exit(1);
    }

    strcpy(tempPath, path);
    queuePtr-> path = tempPath;

    if(rear == NULL) { 
        queuePtr-> next = queuePtr;
    } else {
        queuePtr-> next = rear-> next;
        rear-> next = queuePtr;
    }
 
    rear = queuePtr;
    //printf("Enqueue: %s\n", queuePtr-> path);
} 

char* dequeue(char *path) {
    struct Queue *queuePtr;
    char *tempPath;

    if(!rear) {
        perror("bt: Error: Empty Queue");
        exit(1);
    }

    queuePtr = rear-> next;
    tempPath = queuePtr-> path;

    if(queuePtr == rear)
        rear = NULL;
    else
        rear-> next = queuePtr-> next;
    //printf("Dequeued: %s\n", queuePtr-> path);
    free(queuePtr);
    strcpy(path, tempPath);
    free(tempPath);
    return path;
}


