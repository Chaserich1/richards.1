/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: February 7, 2020
   Filename: Queue.c  */

#include "Queue.h"

struct Queue *createQueue() {
    struct Queue *queuePtr = malloc(sizeof(struct Queue));
    queuePtr-> head = -1;
    queuePtr-> tail = -1;
    return queuePtr;
}

void enqueue(struct Queue *queuePtr, char *path) {
    if(queuePtr-> tail == QBUF - 1)
        perror("bt: Error: The queue is full");
    else {
        if(queuePtr-> head == -1)
            queuePtr-> head = 0;
        queuePtr-> tail++;
        queuePtr-> fileOrDirectory[queuePtr-> tail] = path;
    }
} 

char* dequeue(struct Queue *queuePtr) {
    char *path;

    path = queuePtr-> fileOrDirectory[queuePtr-> head];
    queuePtr-> head++;
    if(queuePtr-> head > queuePtr-> tail) 
        queuePtr-> head = queuePtr-> tail = -1;
    
    return path;
}

int emptyQueue(struct Queue *queuePtr) {
    if(queuePtr-> tail == -1)
        return 1;
    else
        return 0;
}

