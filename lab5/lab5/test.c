#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int is_brand(char *str) {
    int len = strlen(str);
    if (len > 16)
        fprintf(stderr, "brand shiel must be less than 17 symbols"); 
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
            putchar('f');
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
        putchar('l'); 
        return 0;
    }
}


int main(void) {
    int a = is_mileage("10.2");
    printf("%d\n", a);
    return 0;
}


