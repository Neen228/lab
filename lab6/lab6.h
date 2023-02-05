#ifndef LAB6_H
#define LAB6_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Str {
    char digit;
    struct Str *next;
} Str;

int is_digit(char c);
int is_op(char c);
int task(void);
void concatenate(Str *dest, Str *last, Str *src);
void free_str(Str *save_ptr);
void pirnt_str(Str *save_ptr);
void add_elem(Str *stroka, Str **last, char c);
Str *enter_str(Str **last);
Str *int_list(int number);
int number_list(Str *list, Str **point);
int result(Str *first);

#endif

