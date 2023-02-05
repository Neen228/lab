#include "scan.h"
#include "lab5.h"
#include "compars.h"
#include "sort.h"






void out(int sort, int comp, int rev, char *output) {
    int len;
    Car *cars = NULL;
        if ((!get_file(&cars, &len)) || sort == 1) {
            FILE *out = fopen(output, "w");
            if (comp == 1) {
                if (rev == 1)
                    qsort(cars, len, sizeof(Car),
                    (int (*)(const void *, const void *)) cmp_brand);
                else 
                    qsort(cars, len, sizeof(Car),
                    (int (*)(const void *, const void *)) cmp_brand_rev);
                fprint_struct(out, cars, len);
                free(cars);
            }
            if (comp == 2) {
                if (rev == 1)
                    qsort(cars, len, sizeof(Car),
                    (int (*)(const void *, const void *)) cmp_name);
                else 
                    qsort(cars, len, sizeof(Car),
                    (int (*)(const void *, const void *)) cmp_name_rev);
                fprint_struct(out, cars, len);
                free(cars);           
            }
             if (comp == 3) {
                if (rev == 1)
                    qsort(cars, len, sizeof(Car),
                    (int (*)(const void *, const void *)) cmp_mile);
                else 
                    qsort(cars, len, sizeof(Car),
                    (int (*)(const void *, const void *)) cmp_mile_rev);
                fprint_struct(out, cars, len);
                free(cars);           
            }
        }
         if ((!get_file(&cars, &len)) || sort == 2) {
            FILE *out = fopen(output, "w");
            if (comp == 1) {
                if (rev == 1)
                    comb_sort(cars, len, cmp_brand);
                else 
                    comb_sort(cars, len, cmp_brand_rev);
                fprint_struct(out, cars, len);
                free(cars);
            }
            if (comp == 2) {
                if (rev == 1)
                    comb_sort(cars, len, cmp_name);
                else 
                    comb_sort(cars, len, cmp_name_rev);
                fprint_struct(out, cars, len);
                free(cars);           
            }
             if (comp == 3) {
                if (rev == 1)
                    comb_sort(cars, len, cmp_mile);
                else 
                    comb_sort(cars, len, cmp_mile_rev);
                fprint_struct(out, cars, len);
                free(cars);           
            }
        }   
         if ((!get_file(&cars, &len)) || sort == 3) {
            FILE *out = fopen(output, "w");
            if (comp == 1) {
                if (rev == 1)
                    ins_sort(cars, len, cmp_brand);
                else 
                    ins_sort(cars, len, cmp_brand_rev);
                fprint_struct(out, cars, len);
                free(cars);
            }
            if (comp == 2) {
                if (rev == 1)
                    ins_sort(cars, len, cmp_name);
                else 
                    ins_sort(cars, len, cmp_name_rev);
                fprint_struct(out, cars, len);
                free(cars);           
            }
             if (comp == 3) {
                if (rev == 1)
                    ins_sort(cars, len, cmp_mile);
                else 
                    ins_sort(cars, len, cmp_mile_rev);
                fprint_struct(out, cars, len);
                free(cars);           
            }
        }
    }


int main(void) {
    int x, sort, comp, rev;
    printf("Choose sort\n");
    printf("1:qsotr\n2:comb sort\n3:insert sort with binary search\nanoter to exit\n");
    scanf("%d", &x);
    if (x == 1 || x == 2 || x == 3){
        sort = x;
        printf("Choose sort field\n");
        printf("1:Car brand\n2:Owner name\n3:Car mileage\nanother to exit\n");
        scanf("%d", &x);
        if (x == 1 || x == 2 || x == 3){
            comp = x;
            printf("1:direct sorting\n2:reverse sorting\nanother to exit\n");
            scanf("%d", &x);
            if (x == 1 || x == 2) {
                rev = x;
                char * output;
                if(scanf("%s", output))
                    printf("l");
                    out(sort, comp, rev, output);
            }
            else 
                return 0;
        }
        else
            return 0;
    }
    else 
        return 0;


    return 0;
}
