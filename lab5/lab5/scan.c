#include "scan.h"



char *freadline (FILE *fp) {
    char *ptr = (char *)malloc(1);
    char buf [81];
    int n, len = 0;
    *ptr = '\0';
    do  {
            n = fscanf(fp, "%80[^\n]", buf);
            if (n < 0) {
                free(ptr);
                ptr = NULL;
                continue;
            }
            if(n == 0)
                fscanf(fp, "%*c");
            else {
                len += strlen(buf);
                ptr = (char *) realloc(ptr, len + 1);
                strcat(ptr, buf);
            }
        } while(n > 0);
        return ptr;
}


int is_name(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90) || (str[i] == ' ') ))
            return 0;
    }
    return 1;
}

int is_brand(char *str) {
    int len = strlen(str);
    if (len > 16)
        fprintf(stderr, "brand shield must be less than 17 symbols\n"); 
    for (int i = 0; i < len; i++) {
        if (!((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90) || (str[i] == ' ') || (str[i] == '-')))
            return 0;
    }
    return 1;
}


int is_mileage(char *str) {
    int len = strlen(str);
    int flag = 0;
    for (int i = 0; i < len; i++) {
        if (!((str[i] >= 48 && str[i] <= 57) || (str[i] == '.'))) {
            return 0;
        }
        else {
            if (str[i] == '.')
                flag += 1;
        }
    }
    if (flag < 2) 
        return 1;
    else {
        return 0;
    }
}


int get_file(Car **cars, int *len) {
    FILE *fp;
    char *input = readline("input file name:");
    fp = fopen(input, "r");
    if (fp == NULL) {
        fprintf(stderr, "invalid file\n");
        return 1;
    }
    free(input);
    char *str = freadline(fp);
    int amount = atoi(str);
    if (amount == 0) {
        fprintf(stderr, "invalid amount structs\n");
        return 2;
    }
    (*cars) = (Car*)malloc(amount * sizeof(Car));
    char *brand, *mileage, *name;
    int num_struct = 0, num_str = 1, flag = 1;
    while ((str = freadline(fp)) != NULL) {
        flag = 1;
        brand = strtok(str, ",");
        if (is_brand(brand))
            (*cars)[num_struct].brand = brand;
        else {
            fprintf(stderr, "invalid brand in %d str\n", num_str);
            flag = 0;
        }
        name = strtok(NULL, ","); 
        if (is_name(name))
            (*cars)[num_struct].name = name;
        else {
            fprintf(stderr, "invalid name in %d str\n", num_str);
            flag = 0;
        }
        mileage = strtok(NULL, ","); 
        if (is_mileage(mileage))
            (*cars)[num_struct].mileage = atof(mileage);
        else {
            fprintf(stderr, "invalid mileage in %d str\n", num_str);
            flag = 0;
        }
        if (flag)
            num_struct += 1;
        num_str += 1;
    }
    (*cars) = (Car*)realloc((*cars), (num_struct) * sizeof(Car));
    (*len) = num_struct;
    return 0;
}



