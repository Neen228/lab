#ifndef LAB5_H
#define LAB5_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <string.h>

typedef struct Car {
    char *brand;
    char *name;
    float mileage;
} Car;

void fprint_struct(Car *cars, int len);



#endif

