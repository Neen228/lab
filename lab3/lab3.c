#include "lab3.h"
#include "clean.h"



int create_array (int **data, int *capacity) {
    printf ("enter capacity\n");
    if (*data != NULL) {
        printf("array already created\n");
        return 3;
    }
    if (scaner_int(capacity, (*data))) {
        printf("capacity must be integer number");
        return 1;
    }
    if (capacity <= 0) {
        printf("capacity must be integer number\n");
        return 2;
    }
    create_array_c(data, (*capacity));
    return 0;
}



int enter_array (int *data, int *len, int capacity) {
    if (data == NULL) {
        printf("create an array\n");
        return 4;
    }
    printf ("enter len\n");
    if (scaner_int(len, data)) {
        printf("len must be integer number");
        return 1;
    }
    if ((*len) > capacity) {
        printf("len must be less than capacity");
        return 2;
    }
    if (*len < 1) {
        printf("len must be natural number");
        return 3;
    }
    enter_array_c(data, len);
    return 0;
}


int print_array(int *data, int len) {
    if (len == 0) {
        printf("array is empty\n");
        return 2;
    }
	if (data == NULL){
		printf("create an array\n");
		return 1;
	}
    for (int i = 0; i < len; i++){
        printf ("%d\t", data[i]);
    }
    printf("\n");
    return 0;
}

int enter_elem (int *data, int *len, int capacity) {
    if (data ==NULL) {
    	printf("create an array");
    	return 5;
    }
    int index, value; 
    printf("enter elem value:");
    if (scaner_int(&value, data)) {
        printf("value must be integer number");
        return 1;
    }
    printf ("enter elem index:");
    if (scaner_int(&index, data)) {
        printf("index must be integer number");
        return 2;
    }
    if (index < 0) {
        printf("index must be natural number");
        return 3;
    }
    if ((*len) >= capacity) {
        printf("no place, change capacity");
        return 4;
    }
    enter_elem_c(data, len, index, value);
    return 0;
}




int remove_elem (int *data, int *len) {
    if ((*len) == 0) {
        printf("array is empty\n");
        return 6;
    }
    
    if (data == NULL) {
        printf ("create array\n");
        return 4;
    }
    if ((*len) < 1) {
        printf("array is already empty\n");
        return 5;
    }

    int index;
    printf ("enter elem index:");
    if (scaner_int(&index, data)) {
        printf("index must be integer number\n");
        return 1;
    }
    if (index > (*len)) {
        printf ("index must be less than len\n");
        return 2;
    }
    if (index < 0) {
        printf("index must be natural number\n");
        return 3;
    }
    remove_elem_c(data, len, index);
    return 0;
	
}




int remove_sum_digits (int *data, int *len) {
    if (data == NULL) { 
        printf ("create array\n");
        return 3;
    }
    if ((*len) == 0) {
        printf("array is empty\n");
        return 4;
    }
    int sum;
    printf ("enter sum of digits:");
    if (scaner_int (&sum, data)) {
        printf ("sum must be intger number\n");
        return 1;
    }
    if (sum < 0) {
        printf ("sum must be natural\n");
        return 2;
    }
    for (int i = 0; i < (*len); i++) {
        if (sum_digits (data[i], sum)) {
            remove_elem_c (data, len, i);
            i -= 1;
        }
    }
    return 0;
}

int change_capacity (int **data, int *capacity, int *len) {
    printf ("enter new capacity\n");
    if (scaner_int(capacity, (*data))) {
        printf ("capacity maust be integer number\n");
        return 1;
    }
    if ((*capacity) < 1) {
        printf ("capacity must be natural number\n");
        return 2;
    }
    if (data == NULL) {
        printf ("create array\n");
        return 3;
    }
    if ((*len) > (*capacity)) {
        printf("%d\n", (*capacity));
        printf("error\n");
        printf("%d\n", (*len));
        (*len) = (*capacity);
    }
    change_capacity_c (data, (*capacity));
    return 0;
}
    



int scaner_int (int *x, int *data) {
    int val = scaner_int_c (x, data);
    if (val == 1) 
    	return 1;
    else 
    return 0;
}

