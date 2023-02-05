#ifndef LAB4_H
#define LAB4_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

size_t str_len(const char *s);

char* str_cat(char *restrict dest, const char *restrict src);

char * str_dup (const char *s);

char *invert_str(char *str);

char * read_line (char *prompt);

char *str_tok(char *srcString, char *delim);

char*  print_words(const char *str);

size_t is_delim(char c, char *delim);

char *mem_cpy(void *restrict dest, const void *restrict src, size_t n);

#endif 

