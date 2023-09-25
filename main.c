#include "defs.h"

int main(void) {

    struct linked_list_t *ll = ll_create();
    if (ll == NULL) {
        printf("Failed to allocate memory\n");
        return 8;
    }

    int err_code;
    bool status = true;
    while(status) {

        CREATE_MENU()
        int input;
        if(scanf("%d", &input) != 1) {
            printf("Incorrect input\n");
            ll_clear(ll);
            free(ll);
            return 1;
        }

        int test, value, index;
        switch (input) {
            case EXIT:
                status = false;
                break;
            case PUSH_BACK: {
                GET_NUMBER()
                test = ll_push_back(ll, value);
                if(test == 2) {
                    printf("Failed to allocate memory\n");
                    ll_clear(ll);
                    free(ll);
                    return 8;
                }
                break;
            }
            case POP_BACK: {
                value = ll_pop_back(ll, &err_code);
                if(err_code == 1) printf("List is empty\n");
                else printf("%d\n", value);
                break;
            }
            case PUSH_FRONT: {
                GET_NUMBER()
                test = ll_push_front(ll, value);
                if(test == 2) {
                    printf("Failed to allocate memory\n");
                    ll_clear(ll);
                    free(ll);
                    return 8;
                }
                break;
            }
            case POP_FRONT: {
                value = ll_pop_front(ll, &err_code);
                if(err_code == 1) printf("List is empty\n");
                else printf("%d\n", value);
                break;
            }
            case INSERT: {
                GET_NUMBER()
                GET_INDEX()
                test = ll_insert(ll, index, value);
                if(test == 2) {
                    printf("Failed to allocate memory\n");
                    ll_clear(ll);
                    free(ll);
                    return 8;
                } else if(test == 1) printf("Index out of range\n");
                break;
            }
            case REMOVE: {
                if(ll_is_empty(ll)) printf("List is empty\n");
                else {
                    GET_INDEX()
                    value = ll_remove(ll, index, &err_code);
                    if(err_code == 1) printf("Index out of range\n");
                    else printf("%d\n", value);
                }
                break;
            }
            case BACK: {
                value = ll_back(ll, &err_code);
                if(err_code == 1) printf("List is empty\n");
                else printf("%d\n", value);
                break;
            }
            case FRONT: {
                value = ll_front(ll, &err_code);
                if(err_code == 1) printf("List is empty\n");
                else printf("%d\n", value);
                break;
            }
            case IS_EMPTY: {
                printf("%d\n", ll_is_empty(ll));
                break;
            }
            case SIZE: {
                printf("%d\n", ll_size(ll));
                break;
            }
            case CLEAR: {
                ll_clear(ll);
                break;
            }
            case AT: {
                if(ll_is_empty(ll)) printf("List is empty\n");
                else {
                    GET_INDEX()
                    value = ll_at(ll, index, &err_code);
                    if(err_code == 1) printf("Index out of range\n");
                    else printf("%d\n", value);
                }
                break;
            }
            case DISPLAY: {
                if (ll_is_empty(ll)) printf("List is empty\n");
                else ll_display(ll);
                printf("\n");
                break;
            }
            case BEGIN: {
                if(ll_is_empty(ll)) printf("List is empty\n");
                else printf("%d\n", ll_begin(ll)->data);
                break;
            }
            case END: {
                if(ll_is_empty(ll)) printf("List is empty\n");
                else printf("%d\n", ll_end(ll)->data);
                break;
            }
            case HELP: {
                CREATE_DETAILED_MENU()
                break;
            }
            default:
                printf("Incorrect input data\n");
        }
    }

    ll_clear(ll);
    free(ll);

    return 0;
}
