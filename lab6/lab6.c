#include "lab6.h" 
 
int is_op(char c) {
    if (c == '+' || c == '-')
        return 1;
    return 0;
}
  
Str *enter_str(Str **last) {
    int flag = 0;
    Str *tmp = (Str*)malloc(sizeof(Str)), *pointer = NULL;
    Str *save_ptr = tmp;
    char c = 'f';
	Str *prev = NULL;
    while ((c = getchar()) != '\n') {
        if ((is_op(c) || is_digit(c)) && (flag < 2)) {
            if (is_op(c))
                flag += 1;
            if (is_digit(c))
                flag = 0;
            pointer = (Str*)malloc(sizeof(Str));
            tmp->digit = c;
            tmp->next = pointer;
		    prev = tmp;
            tmp = pointer;
        }
        else {
            printf("invalid input");
            free_str(save_ptr);
            return NULL;
        }
    }
    free(pointer);
	tmp = prev;
    tmp->next = NULL;
    (*last) = tmp;
    return save_ptr;
}


Str *int_list(int number) {
    Str *tmp = (Str*)malloc(sizeof(Str)), *prev;
    tmp->next = NULL;
    tmp->digit = (number % 10) +48;
    number /= 10;
    while (number != 0) {
        prev = (Str*)malloc(sizeof(Str));
        prev->digit = (number % 10) + 48;
        prev->next = tmp;
        number = number / 10;
        tmp = prev;
    }
    return tmp;
}
        



void print_str(Str* save_ptr) {
    Str *tmp = save_ptr;
    while (tmp != NULL) {
        putchar(tmp->digit);
        tmp = tmp->next;
    }
}
  
int number_list(Str *list, Str **point) {
    Str *tmp = list;
    int number = 0;
    while ((tmp != NULL) && (is_digit(tmp->digit))){
        number *= 10;
        int digit = tmp->digit - 48;
        number += digit;
        tmp = tmp->next;
    }
    (*point) = tmp;
    return number;
} 
 
 

int result(Str *first) {
    Str *tmp = first, *point = NULL;
    int res = 0, number;
    number = number_list(tmp, &point);
    res += number;
    tmp = point;
    while (tmp) {
        if (tmp->digit == 43) {
            tmp = tmp->next;
            res += number_list(tmp, &point);
        }
        if (tmp->digit == 45) {
            tmp = tmp->next;
            res -= number_list(tmp, &point);
        }
        tmp = point;
    } 
    return res;
}

void add_elem(Str* stroka, Str **last, char c) {
    Str *tmp = (Str*)malloc(sizeof(Str));
    tmp->digit = c;
    tmp->next = NULL;
    (*last)->next = tmp;
    (*last) = tmp;
}

int task(void) { 
    Str *tail = NULL;    
    Str *string = enter_str(&tail);   
    if (string == NULL)
        return 1;
    int res = result(string);
    if (res < 0) {
        res = -res;
        add_elem(string, &tail, '=');
        add_elem(string, &tail, '-');
    }
    else 
        add_elem(string, &tail, '=');
    Str *result = int_list(res);
    concatenate(string, tail, result);
    print_str(string);
    free_str(string);
    return 0;
}

 
int is_digit(char c) {
    if ((c >= 48) && (c <= 57))
        return 1;
    return 0;
}

void concatenate(Str *dest, Str *last, Str *src) {
    last->next = src;
}




void free_str(Str* string) {
    Str *tmp = string, *tmp_prev;
    while (tmp != NULL) {
        tmp_prev = tmp;
        tmp = tmp->next;
        free(tmp_prev);
    }
}

