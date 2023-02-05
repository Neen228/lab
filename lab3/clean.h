#ifndef CLEAN_H
#define CLEAN_H

#include <stdlib.h>
#include <stdio.h>
#include "lab3.h"

int create_array_c (int **data, int capacity);

int enter_array_c (int *data, int *len);

int enter_elem_c (int *data, int *len, int index, int value);

int remove_elem_c (int *data, int *len, int index);

int change_capacity_c (int **data, int capacity);

int scaner_int_c (int *x, int *data);

int sum_digits (int number,int sum);

#endif

