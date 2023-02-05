#ifndef SCAN_H
#define SCAN_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "lab5.h"

char *freadline (FILE *fp);
int is_name(char *str);
int is_mileage(char *str);
int is_brand(char *str);
int get_file(Car **cars, int *len);


#endif
