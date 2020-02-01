/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 30, 2020
   Filename: main.c  */

#include "GetCurrentDirectory.h"
#include "directoryCheck.h"
#include "CommandOptions.h"

int main(int argc, char **argv) {

    printf("%s\n", getCWD());

    printf("%i\n", isdirectory(getCWD()));

    displayHelpMessage();
}
