/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 29, 2020
   Filename: GetCurrentDirectory.h  */

#ifndef GETCURRENTDIRECTORY_H
#define GETCURRENTDIRECTORY_H

#include "directoryCheck.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

char *getCWD();
void searchFileSystem(char *path);

#endif
