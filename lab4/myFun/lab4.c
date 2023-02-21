#include "lab4.h"









// strchr





int main() {
	char *input;
    clock_t start, end;
    while ((input = read_line("write string:")) != NULL) {
        start = clock();
        char *inv = words(input);
        printf("\"%s\"\n", input);
        printf("\"%s\"\n", inv);
        free(input);
        free(inv);
        end = clock();
        printf("%lf\n", (double)(end - start) / (CLOCKS_PER_SEC));
    }
    return 0;
}
