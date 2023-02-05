#include "lab4.h"


size_t str_len(const char *s) {
    size_t counter = 0;
    int i = 0;
    while (s[i] != '\0'){
        counter += 1;
        i += 1;
    }
    return counter;
}

char* str_cat(char *restrict dest, const char *restrict src) {
    size_t len_src = str_len(src);
    mem_cpy(dest, src, len_src + 1);
    return dest;
}

char * str_dup (const char *s) {
    char *dup = (char*) malloc(sizeof(char) * (str_len(s) + 1));
    mem_cpy(dup, s, str_len(s) +1);
    return dup;
}




char *inv_str(char *str) {
    size_t index = str_len(str) - 1;
    for (size_t i  = 0; i <= index / 2; i++) {
        char tmp = str[i];
        str[i] = str [index - i];
        str[index - i] = tmp;
    }
    return str;
}



char *read_line (char *prompt) {
    char *ptr = (char *)malloc(1);
    char buf [81];
    int n, len = 0;
    *ptr = '\0';
    printf("%s", prompt);
    do  {
            n = scanf("%80[^\n]", buf);
            if (n < 0) {
                free(ptr);
                ptr = NULL;
                continue;
            }
            if(n == 0)
                scanf("%*c");
            else {
                len += str_len(buf);
                ptr = (char *) realloc(ptr, len + 1);
                str_cat(ptr, buf);
            }
        } while(n > 0);
        return ptr;
}

size_t is_delim(char c, char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return 1;
        delim++;
    }
    return 0;
}




// strchr
char *str_tok(char *str, char *delim) {
    static char *save_ptr; 
    if(!str) {
        str = save_ptr;
    }
    if(!str)
        return NULL;
    while(1) {
        if(is_delim(*str, delim)) {
            str++;
            continue;
        }
        if(*str == '\0') {
            return NULL;
        }
        break;
    }
    char *res = str;
    while(1) {
        if(*str == '\0') {
            save_ptr = str;
            return res;
        }
        if(is_delim(*str, delim)) {
            *str = '\0';
            save_ptr = str + 1;
            return res;
        }
        str++;
    }
}





char* words(const char *str) {
	char *s = str_dup (str);
	int len_str = str_len(str);
	char *out = calloc(len_str + 2, sizeof(char));
	int out_len = 0;
	char *w = str_tok(s, " \t");
	while (w != NULL) {
		int w_len = str_len(w);
        w = inv_str(w);
		mem_cpy(out + out_len, w, w_len * sizeof(char));
		out_len += w_len;
		out[out_len] = ' ';
		++out_len;
		w = str_tok(NULL, " \t");
		}
	free(s);
    if (out_len > 0) {
        --out_len;
    }
    out[out_len] = '\0';
    out = realloc(out, (out_len + 1) * sizeof(char));
    return out;
}
	




char *mem_cpy(void *restrict dest, const void *restrict src, size_t n) {
    char *dest_char = (char*)dest;
    const char *src_char = (const char*)src;
    for (int i = 0; i < n; i++) {
        *(dest_char++) = *(src_char++); 
    }
    return dest;
}




int main() {
	char *input;
    while ((input = read_line("write string:")) != NULL) {
        char *inv = words(input);
        printf("\"%s\"\n", input);
        printf("\"%s\"\n", inv);
        free(input);
        free(inv);
    }
    return 0;
}
