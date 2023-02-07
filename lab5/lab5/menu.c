#include "scan.h"
#include "lab5.h"
#include "compars.h"
#include "sort.h"



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

void srt_q(Car *cars,int len, int comp, int rev) {
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
}


int srt(int sort, int comp, int rev) {
    Car *cars = NULL;
    int len = 0;
    if (get_file(&cars, &len))
        return 2;
    switch (sort) {
        case 1:
            srt_q(cars, len, comp, rev);
            break;    
    }
    fprint_struct(cars, len);
    return 0;
}



int main(void) {
    int x, sort, comp, rev;
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
    srt(sort, comp, rev);

    return 0;
}

