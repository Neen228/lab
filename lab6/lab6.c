#include "lab6.h" 
 
int is_op(char c) {
    if (c == '+' || c == '-')
        return 1;
    return 0;
}
  
List *enter_str(List *list) {
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
            free_str(list);
            return NULL;
        }
    }
    free(pointer);
	tmp = prev;
    tmp->next = NULL;
    list->tail = tmp;
    list->head = save_ptr;
    return list;
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
        



void print_str(List *list) {
    Str *tmp = list->head;
    while (tmp != NULL) {
        putchar(tmp->digit);
        tmp = tmp->next;
    }
}
  
int number_list(Str *string, Str **point) {
    Str *tmp = string;
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
 
 

int result(List *list) {
    Str *tmp = list->head, *point = NULL;
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

void add_elem(List *list, char c) {
    Str *tmp = (Str*)malloc(sizeof(Str));
    tmp->digit = c;
    tmp->next = NULL;
    list->tail->next = tmp;
    list->tail = tmp;
}

int task(void) {
    List *list = (List *)malloc(sizeof(List)); 
    list->tail = NULL;    
    list = enter_str(list);   
    if (list == NULL)
        return 1;
    int res = result(list);
    if (res < 0) {
        res = -res;
        add_elem(list, '=');
        add_elem(list, '-');
    }
    else 
        add_elem(list, '=');
    Str *result = int_list(res);
    concatenate(list, result);
    print_str(list);
    free_str(list);
    return 0;
}

 
int is_digit(char c) {
    if ((c >= 48) && (c <= 57))
        return 1;
    return 0;
}

void concatenate(List *list, Str *src) {
    list->tail->next = src;
}




void free_str(List *list) {
    Str *tmp = list->head, *tmp_prev;
    while (tmp != NULL) {
        tmp_prev = tmp;
        tmp = tmp->next;
        free(tmp_prev);
    }
    free(list);
}

