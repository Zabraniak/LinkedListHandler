#ifndef MAIN_C_DEFS_H
#define MAIN_C_DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum option_t {
    EXIT = 0,
    PUSH_BACK,
    POP_BACK,
    PUSH_FRONT,
    POP_FRONT,
    INSERT,
    REMOVE,
    BACK,
    FRONT,
    IS_EMPTY,
    SIZE,
    CLEAR,
    AT,
    DISPLAY,
    BEGIN,
    END,
    HELP
};

#define CREATE_MENU() \
    printf("##### ##### ##### ##### ##### MAIN PAGE ##### ##### ##### ##### #####\n"); \
    printf("\tChoose option:\n"); \
    printf("\t0 - exit\n");       \
    printf("\t1 - push back\n");  \
    printf("\t2 - pop back\n");   \
    printf("\t3 - push front\n"); \
    printf("\t4 - pop front\n");  \
    printf("\t5 - insert\n");     \
    printf("\t6 - remove\n");     \
    printf("\t7 - back\n");       \
    printf("\t8 - front\n");      \
    printf("\t9 - is empty\n");   \
    printf("\t10 - size\n");      \
    printf("\t11 - clear\n");     \
    printf("\t12 - at\n");        \
    printf("\t13 - display\n");   \
    printf("\t14 - begin\n");     \
    printf("\t15 - end\n");       \
    printf("\t16 - help\n");      \
    printf("##### ##### ##### ##### ##### ##### ##### ##### ##### #####\n"); \
    printf("\tOption =>");

#define CREATE_DETAILED_MENU() \
    printf("##### ##### ##### ##### ##### HELP PAGE ##### ##### ##### ##### #####\n"); \
    printf("\tExit - Exit program\n"); \
    printf("\tPushBack - Add element to the end of the list\n"); \
    printf("\tPopBack - Remove element from the end of the list\n"); \
    printf("\tPushFront - Add element to the beginning of the list\n"); \
    printf("\tPopFront - Remove element from the beginning of the list\n"); \
    printf("\tInsert - Insert element at given index\n"); \
    printf("\tRemove - Remove element at given index\n"); \
    printf("\tBack - Return element from the end of the list\n"); \
    printf("\tFront - Return element from the beginning of the list\n"); \
    printf("\tIsEmpty - Return 1 if list is empty, 0 otherwise\n"); \
    printf("\tSize - Return number of elements in the list\n"); \
    printf("\tClear - Remove all elements from the list\n"); \
    printf("\tAt - Return element at given index\n"); \
    printf("\tDisplay - Display all elements in the list\n"); \
    printf("\tBegin - Return element from the beginning of the list full node\n"); \
    printf("\tEnd - Return element from the end of the list full node\n"); \
    printf("\tHelp - Display this menu\n"); \
    printf("##### ##### ##### ##### ##### ##### ##### ##### ##### #####\n");

#define GET_NUMBER() \
    printf("\tProvide number:\n"); \
    if(scanf("%d", &value) != 1) { \
        printf("Incorrect number\n"); \
        ll_clear(ll); \
        free(ll); \
        return 1; \
    }

#define GET_INDEX() \
    printf("\tProvide index:\n"); \
    if(scanf("%d", &index) != 1) { \
        printf("Incorrect index\n"); \
        ll_clear(ll); \
        free(ll); \
        return 1; \
    }

struct node_t {
    int data;
    struct node_t *next;
};

struct linked_list_t {
    struct node_t *head;
    struct node_t *tail;
};

struct linked_list_t* ll_create(void);

int ll_push_back(struct linked_list_t* ll, int value);
int ll_push_front(struct linked_list_t* ll, int value);
int ll_pop_front(struct linked_list_t* ll, int *err_code);
int ll_pop_back(struct linked_list_t* ll, int *err_code);

int ll_back(const struct linked_list_t* ll, int *err_code);
int ll_front(const struct linked_list_t* ll, int *err_code);

struct node_t* ll_begin(struct linked_list_t* ll);
struct node_t* ll_end(struct linked_list_t* ll);

int ll_size(const struct linked_list_t* ll);
int ll_is_empty(const struct linked_list_t* ll);
int ll_at(const struct linked_list_t* ll, unsigned int index, int *err_code);

int ll_insert(struct linked_list_t* ll, unsigned int index, int value);

int ll_remove(struct linked_list_t* ll, unsigned int index, int *err_code);

void ll_clear(struct linked_list_t* ll);

void ll_display(const struct linked_list_t* ll);

#endif //MAIN_C_DEFS_H
