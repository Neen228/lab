#include "lab5.h"
#include "scan.h"
#include "sort.h"

void fprint_struct(FILE *fp, Car *cars, int len) {
    for (int i = 0; i < len; i++) 
        fprintf(fp, "%s,%s,%f\n", (cars[i]).brand, cars[i].name, cars[i].mileage);
} 




    








