/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 30, 2020
   Filename: main.c  */

#include "GetCurrentDirectory.h"
#include "directoryCheck.h"

int main(void) {

    printf("%s\n", getCWD());

    printf("%i\n", isdirectory(getCWD()));

}
