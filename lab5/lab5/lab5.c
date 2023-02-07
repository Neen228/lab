#include "lab5.h"
#include "scan.h"
#include "sort.h"

void fprint_struct(Car *cars, int len) {
    char *output = readline("enter output file name:");
    FILE *fp = fopen(output, "w");
    for (int i = 0; i < len; i++) 
        fprintf(fp, "%s,%s,%f\n", (cars[i]).brand, cars[i].name, cars[i].mileage);
} 




    








