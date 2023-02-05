#include "clean.h"
#include "lab3.h"

int create_array_c (int **data, int capacity) {
        *data = (int*)malloc(sizeof(int) * capacity);
        return 0;
}



int enter_array_c (int *data, int *len) {
    for (int i = 0; i < *len; i++) {
        printf("enter element number %d:", i);
        if (scaner_int (&data[i], data)) {
            printf("elem must be integer number\n");
            *len = i;
        	break;
        }
    }
    return 0;
}



int enter_elem_c (int *data, int *len, int index, int value) {
    if (index >= *len) {
        data[(*len)] = value;
        *len += 1;
        return 0;
    }
    if (index < *len) {
       *len += 1; 
        for (int i = (*len - 2); i >= index ; i -= 1) {
            data[i + 1] = data[i];
        }
        data[index] = value;
        return 0;
    }
}


int remove_elem_c (int *data, int *len, int index) {
    for (int i = index; i < (*len - 1); i++)
        data[i] = data[i+1];
    *len -= 1;
    return 0;
}




int change_capacity_c (int ** data, int capacity) {
    *data = (int*)realloc((*data), sizeof(int) * capacity);
    return 0;
}



int sum_digits (int number, int sum_input) {
    int sum = 0;
    while (number != 0) {
        int digit = number % 10;
        number = number / 10;
        sum += digit;
    }
    return (sum == sum_input);
}



int scaner_int_c (int *x, int *data) {
 	char c = 's';
 	int val = (scanf("%d%c", x, &c)) + (c == '\n') ;
    switch(val) {
        case -1:
        	free(data);
            exit(1);
        case 0:
            scanf("%*[^\n]");
            return 1;
        case 2:
        	scanf("%*[^\n]");
            return 1;
        case 3: 
            return 0;
    }
}
