#include "lab4.h"

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




char *inv_str(char *str) {
    size_t index = str_len(str) - 1;
    for (size_t i  = 0; i <= index / 2; i++) {
        char tmp = str[i];
        str[i] = str [index - i];
        str[index - i] = tmp;
    }
    return str;
}
