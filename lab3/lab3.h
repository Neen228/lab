#ifndef LAB3_H
#define LAB3_H

#include <stdlib.h>
#include <stdio.h>
#include "clean.h"

int remove_elem(int *data, int *len);

int print_array(int *data, int len);

int enter_array(int *data, int *len, int capacity);

int enter_elem(int *data, int *len, int capacity);

int create_array(int **data, int *capacity);

int change_capacity(int **data, int *capacity, int *len);

int scaner_int (int *x, int *data);

int remove_sum_digits (int *data, int *len);

#endif 

