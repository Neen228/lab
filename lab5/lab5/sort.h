#ifndef SORT_H
#define SORT_H
#include "lab5.h"
#include "compars.h"



void ins_sort(Car *cars, int len, int(*compar)(const Car *, const Car*));

void comb_sort(Car *cars, int len, int(*compar)(const Car *, const Car*));

int binarySearch(Car *cars, Car *item, int low, int high, int(*compar)(const Car *, const Car *));


#endif

