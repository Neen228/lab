#ifndef LAB6_H
#define LAB6_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Str {
    char digit;
    struct Str *next;
} Str;

typedef struct List {
    Str *head;
    Str *tail;
} List;


int is_digit(char c);
int is_op(char c);
int task(void);
void concatenate(List *list, Str *src);
void free_str(List *list);
void pirnt_str(List *list);
void add_elem(List *list, char c);
List *enter_str(List *list);
Str *int_list(int number);
int number_list(Str *list, Str **point);
int result(List *list);

#endif

