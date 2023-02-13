#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <time.h>


char *inv_str(char *str) {
    size_t index = strlen(str) - 1;
    for (size_t i  = 0; i <= index / 2; i++) {
        char tmp = str[i];
        str[i] = str [index - i];
        str[index - i] = tmp;
    }
    return str;
}

char* words(const char *str) {
	char *s = strdup (str);
	int str_len = strlen(str);
	char *out = calloc(str_len + 1, sizeof(char));
	int out_len = 0;
	char *w = strtok(s, " \t");
	while (w != NULL) {
		int w_len = strlen(w);
        w = inv_str(w);
		memcpy(out + out_len, w, w_len * sizeof(char));
		out_len += w_len;
		out[out_len] = ' ';
		++out_len;
		w = strtok(NULL, " \t");
	}
	free(s);
    if (out_len > 0) {
        --out_len;
    }
    out[out_len] = '\0';
    out = realloc(out, (out_len + 1) * sizeof(char));
    return out;
}
	
int main() {
	char *input;
    clock_t start, end;
    while ((input = readline("write string:")) != NULL) {
        start = clock();
        char *inv = words(input);
        printf("\"%s\"\n", input);
        printf("\"%s\"\n", inv);
        free(input);
        free(inv);
        end = clock();
        printf("%lf\n",(double)(end - start) / (CLOCKS_PER_SEC));
    }
    return 0;
}

