#include "scan.h"
#include "lab5.h"
#include "compars.h"
#include "sort.h"
#include "gen.h"
#include <time.h>



int scan_opt (int *x,int opt) {
 	char c = 's';
 	int val = (scanf("%d%c", x, &c)) + (c == '\n') + ((*x) > 0 ) + ((*x) <= opt) ;
    switch(val) {
        case -1:
            exit(1);
        case 5:
            return 0; 
        default:
        	scanf("%*[^\n]");
            return 1;
   }
}

void srt_q_brand(Car *cars, int len, int rev) {
    if (rev == 1)
        qsort(cars, len, sizeof(Car), (int (*)(const void *, const void *)) cmp_brand);
    if (rev == 2)
        qsort(cars, len, sizeof(Car), (int (*)(const void *, const void *)) cmp_brand_rev);
}

void srt_q_mile(Car *cars, int len, int rev) {
    if (rev == 1)
        qsort(cars, len, sizeof(Car), (int (*)(const void *, const void *)) cmp_mile);
    if (rev == 2)
        qsort(cars, len, sizeof(Car), (int (*)(const void *, const void *)) cmp_mile_rev);
}

void srt_q_own(Car *cars, int len, int rev) {
    if (rev == 1)
        qsort(cars, len, sizeof(Car), (int (*)(const void *, const void *)) cmp_name);
    if (rev == 2)
        qsort(cars, len, sizeof(Car), (int (*)(const void *, const void *)) cmp_name_rev);
}

double srt_q(Car *cars,int len, int comp, int rev) {
    clock_t start = clock();
    switch (comp) {
        case 1:
            srt_q_brand(cars, len, rev);
            break;
        case 2:
            srt_q_own(cars, len, rev);
            break;
        case 3:
            srt_q_mile(cars, len, rev);
            break;
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}



void srt_comb_brand(Car *cars, int len, int rev) {
    if (rev == 1)
        comb_sort(cars, len, cmp_brand);
    if (rev == 2)
        comb_sort(cars, len, cmp_brand_rev);
}

void srt_comb_mile(Car *cars, int len, int rev) {
    if (rev == 1)
        comb_sort(cars, len, cmp_mile);
    if (rev == 2)
        comb_sort(cars, len, cmp_mile_rev);
}

void srt_comb_own(Car *cars, int len, int rev) {
    if (rev == 1)
        comb_sort(cars, len, cmp_name);
    if (rev == 2)
        comb_sort(cars, len, cmp_name_rev);
}


double srt_comb(Car *cars,int len, int comp, int rev) {
    clock_t start = clock();
    switch (comp) {
        case 1:
            srt_comb_brand(cars, len, rev);
            break;
        case 2:
            srt_comb_own(cars, len, rev);
            break;
        case 3:
            srt_comb_mile(cars, len, rev);
            break;
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}





void srt_bin_brand(Car *cars, int len, int rev) {
    if (rev == 1)
        ins_sort(cars, len, cmp_brand);
    if (rev == 2)
        ins_sort(cars, len, cmp_brand_rev);
}

void srt_bin_mile(Car *cars, int len, int rev) {
    if (rev == 1)
        ins_sort(cars, len, cmp_mile);
    if (rev == 2)
        ins_sort(cars, len, cmp_mile_rev);
}

void srt_bin_own(Car *cars, int len, int rev) {
    if (rev == 1)
        ins_sort(cars, len, cmp_name);
    if (rev == 2)
        ins_sort(cars, len, cmp_name_rev);
}


double srt_bin(Car *cars,int len, int comp, int rev) {
    clock_t start = clock();
    switch (comp) {
        case 1:
            srt_bin_brand(cars, len, rev);
            break;
        case 2:
            srt_bin_own(cars, len, rev);
            break;
        case 3:
            srt_bin_mile(cars, len, rev);
            break;
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}




int srt(int sort, int comp, int rev, int numStruct, int numElem) {
    Car *cars = (Car *)calloc(numElem, sizeof(Car));
    int len = numElem;
    double time = 0;
    for (int j = 0; j < numStruct; j++) {
        for (int i = 0; i < numElem; i++)
            getElem(cars, i);
        for (int k = 0; k < numElem; k++)
        switch (sort) {
            case 1:
                time += srt_q(cars, len, comp, rev);
                break;    
            case 2:
                time += srt_comb(cars, len, comp, rev);
                break;
            case 3: 
                time += srt_bin(cars, len, comp, rev);
                break;
        }
    }
    time = time / numStruct;
    printf("sorted in %lf\n", time);
    free(cars);
    return 0;
}



int main(void) {
    int x, sort, comp, rev, numStruct, numElem;
    printf("Enter num of arrays and num of elements\n");
    scanf("%d%d", &numStruct, &numElem);
    printf("Choose sort\n");
    printf("1:qsotr\n2:comb sort\n3:insert sort with binary search\nanoter to exit\n");
    if (scan_opt(&x, 3))
        return 1;
    sort = x;
    printf("Choose sort field\n");
    printf("1:Car brand\n2:Owner name\n3:Car mileage\nanother to exit\n");
    if (scan_opt(&x, 3))
        return 1;
    comp = x;
    printf("1:direct sorting\n2:reverse sorting\nanother to exit\n");
    if (scan_opt(&x, 2))
        return 1;
    rev = x;
    srt(sort, comp, rev, numStruct, numElem);
    return 0;
}

