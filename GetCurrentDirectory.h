/* Author: Chase Richards
   Project: Homework 1 CS4760
   Date: January 29, 2020
   Filename: GetCurrentDirectory.h  */

#ifndef GETCURRENTDIRECTORY_H
#define GETCURRENTDIRECTORY_H

#include "DirectoryCheck.h"
#include "CommandOptions.h"

#include <unistd.h>
#include <stddef.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <time.h>

void searchFileSystem(char *basePath);

#endif
