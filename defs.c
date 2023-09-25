#include "defs.h"

struct linked_list_t* ll_create(void) {

    struct linked_list_t* ll = malloc(sizeof(struct linked_list_t));
    if(ll == NULL) return NULL;

    ll->head = NULL;
    ll->tail = NULL;

    return ll;
}

int ll_push_back(struct linked_list_t* ll, int value) {
    if(ll == NULL) return 1;

    struct node_t* node = malloc(sizeof(struct node_t));
    if(node == NULL) return 2;

    node->data = value;

    int test = ll_is_empty(ll);
    if(test == 1) {
        node->next = NULL;
        ll->head = node;
        ll->tail = node;
    } else {
        node->next = NULL;
        ll->tail->next = node;
        ll->tail = node;
    }

    return 0;
}

int ll_push_front(struct linked_list_t* ll, int value) {
    if(ll == NULL) return 1;

    struct node_t* node = malloc(sizeof(struct node_t));
    if(node == NULL) return 2;

    node->data = value;

    int test = ll_is_empty(ll);
    if(test == 1) {
        node->next = NULL;
        ll->head = node;
        ll->tail = node;
    } else {
        node->next = ll->head;
        ll->head = node;
    }

    return 0;
}

int ll_pop_front(struct linked_list_t* ll, int *err_code) {
    if(ll == NULL || ll_is_empty(ll) == 1) {
        if(err_code != NULL) *err_code = 1;
        return 1;
    }

    int value;
    if(ll_size(ll) > 1) {
        struct node_t* node = ll->head;
        value = ll->head->data;
        ll->head = ll->head->next;
        free(node);
    } else {
        value = ll->head->data;
        free(ll->head);
        ll->head = NULL;
        ll->tail = NULL;
    }

    if(err_code != NULL) *err_code = 0;
    return value;
}

int ll_pop_back(struct linked_list_t* ll, int *err_code) {
    if(ll == NULL || ll_is_empty(ll) == 1) {
        if(err_code != NULL) *err_code = 1;
        return 1;
    }

    int value;
    if(ll_size(ll) > 1) {
        value = ll->tail->data;
        struct node_t* node = ll->head;
        while(node->next->next) {
            node = node->next;
        }
        free(ll->tail);
        ll->tail = node;
        node->next = NULL;
    } else {
        value = ll->head->data;
        free(ll->head);
        ll->head = NULL;
        ll->tail = NULL;
    }

    if(err_code != NULL) *err_code = 0;
    return value;
}

int ll_front(const struct linked_list_t* ll, int *err_code) {
    if(ll == NULL || ll_is_empty(ll) == 1) {
        if(err_code != NULL) *err_code = 1;
        return 1;
    }

    if(err_code != NULL) *err_code = 0;
    return ll->head->data;
}

int ll_back(const struct linked_list_t* ll, int *err_code) {
    if(ll == NULL || ll_is_empty(ll) == 1) {
        if(err_code != NULL) *err_code = 1;
        return 1;
    }

    if(err_code != NULL) *err_code = 0;
    return ll->tail->data;
}

struct node_t* ll_begin(struct linked_list_t* ll) {
    if(ll == NULL || ll_is_empty(ll) == 1) return NULL;
    return ll->head;
}

struct node_t* ll_end(struct linked_list_t* ll) {
    if(ll == NULL || ll_is_empty(ll) == 1) return NULL;
    return ll->tail;
}

int ll_size(const struct linked_list_t* ll) {
    if(ll == NULL) return -1;

    int counter = 0;
    struct node_t* node = ll->head;
    while(node) {
        node = node->next;
        counter++;
    }

    return counter;
}

int ll_is_empty(const struct linked_list_t* ll) {
    if(ll == NULL) return -1;

    if(ll->head == NULL) return 1;
    else return 0;
}

int ll_at(const struct linked_list_t* ll, unsigned int index, int *err_code) {
    if(ll == NULL || (int)index > ll_size(ll)) {
        if(err_code != NULL) *err_code = 1;
        return 1;
    }

    unsigned int curr_index = 0;
    struct node_t* node = ll->head;
    while(node) {
        if(curr_index == index) {
            if(err_code != NULL) *err_code = 0;
            return node->data;
        }
        node = node->next;
        curr_index++;
    }
    return 666;
}

int ll_insert(struct linked_list_t* ll, unsigned int index, int value) {
    if(ll == NULL || (int)index < 0 || (int)index > ll_size(ll)) return 1;

    if(index == 0) return ll_push_front(ll, value);
    if((int)index == ll_size(ll)) return ll_push_back(ll, value);
    else {
        struct node_t* node = ll->head;
        struct node_t* tmp = malloc(sizeof(struct node_t));
        if(tmp == NULL) return 2;

        for(int i = 1; i < (int)index; i++) {
            node = node->next;
        }
        tmp->data = value;
        tmp->next = node->next;
        node->next = tmp;
    }

    return 0;
}

int ll_remove(struct linked_list_t* ll, unsigned int index, int *err_code) {
    if(ll == NULL || ll_is_empty(ll) == 1 || (int)index >= ll_size(ll) || (int)index < 0) {
        if(err_code != NULL) *err_code = 1;
        return 1;
    }

    int value;
    if(index == 0) return ll_pop_front(ll, err_code);
    if((int)index == ll_size(ll) - 1) return ll_pop_back(ll, err_code);
    else {
        struct node_t* node = ll->head;
        struct node_t* tmp;

        for(int i = 1; i < (int)index; i++) {
            node = node->next;
        }

        tmp = node->next;
        value = tmp->data;
        node->next = tmp->next;
        free(tmp);
        if(err_code != NULL) *err_code = 0;
    }

    if(err_code != NULL) *err_code = 0;
    return value;
}

void ll_clear(struct linked_list_t* ll) {
    if(ll == NULL || ll->head == NULL || ll->tail == NULL) return;

    struct node_t* node = ll->head;
    struct node_t* tmp_node;

    while(node != NULL) {
        tmp_node = node->next;
        free(node);
        node = tmp_node;
    }
    ll->tail = NULL;
    ll->head = NULL;
}

void ll_display(const struct linked_list_t* ll) {
    if(ll == NULL || ll->head == NULL || ll->tail == NULL) return;

    struct node_t *node = ll->head;
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
