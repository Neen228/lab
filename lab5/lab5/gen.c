#include <stdio.h>
#include <stdlib.h>
#include "gen.h"

char *getName() {
    int len = rand() % 30 + 5;
    char *name = (char *)calloc(len +1, sizeof(char));
    for (int i = 0; i < len; i++)
        name[i] = rand() % 26 + 97;
    name[len] = '\0';
    return name;
}


char *getBrand(void) {
    int len = rand() % 10 + 7;
    char *brand = (char *) calloc(len +1, sizeof(char));
    for (int i = 0; i < len; i++)
        brand[i] = rand() % 26 + 97;
    brand[len] = '\0';
    return brand;
}

float getMileage(void) {
    return (float)rand() / RAND_MAX * 400;
}


void getElem(Car *cars, int num) {
    cars[num].name = getName();
    cars[num].mileage = getMileage();
    cars[num].brand = getBrand();
}


