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








char *mem_cpy(void *restrict dest, const void *restrict src, size_t n) {
    char *dest_char = (char*)dest;
    const char *src_char = (const char*)src;
    for (int i = 0; i < n; i++) {
        *(dest_char++) = *(src_char++); 
    }
    return dest;
}
