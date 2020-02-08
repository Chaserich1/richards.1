/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: February 7, 2020
   Filename: Queue.h  */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QBUF 256

struct Queue {
    char *path;
    struct Queue *next;
};

struct Queue *rear;

void createQueue(void);
void enqueue(char *path);
char* dequeue(char *path);

#endif
