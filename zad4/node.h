#ifndef NODE_H_WDI_
#define NODE_H_WDI_

#include <stdbool.h>


/* structs */
typedef struct ll_node {
    int value;
    struct ll_node *next;
} ll_node;


/* public functions */
ll_node* insert_into_ascending(ll_node* l, int value);
ll_node* create_from_input();
ll_node* insertion_sort(ll_node* l);

/* private functions */
ll_node* node_constructor(int value);
void debug_print(ll_node* l);
bool is_ll_sorted(ll_node* l);

#endif
