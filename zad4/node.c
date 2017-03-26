#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "node.h"


ll_node* node_constructor(int value) {
   ll_node* l = malloc(sizeof(ll_node));

   if (!l) {
       fprintf(stderr, "Error - failed to malloc\n");
       exit(1);
   }

   l->value = value;
   l->next = NULL;

   return l;
}


ll_node* create_from_input() {
    int v = 0;
    ll_node* end   = NULL;
    ll_node* start = NULL;

    while(scanf("%d", &v) != EOF) {
        end = ((!start) ? (start = node_constructor(v)) : (end->next = node_constructor(v)));
    }

    return start;
}


ll_node* insert_into_ascending(ll_node* l, int value) {

    ll_node* t = l;
    ll_node* new_node = node_constructor(value);

    if (!l || l->value > value) {
        new_node->next = t;
        return new_node;
    }

    while (t->next && (t->next->value < value)) { t = t->next; }

    new_node->next = t->next;
    t->next = new_node;
    return l;
}


/* Creates new ll in O(n^2) using insert_into_ascending */
ll_node* insertion_sort(ll_node* l) {
    ll_node* n = NULL;
    ll_node* t = l;

    while (t) {
        n = insert_into_ascending(n, t->value);
        t = t->next;
    }

    return n;
}


void debug_print(ll_node* l) {
    ll_node* t = l;
    printf("[Linked List]\n");
    while (t) {
#ifdef USE_COLOR
#define RED_ANSI  "\x1B[31m"
#define RESET_ANSI "\x1B[0m"
#define YELLOW_ANSI "\x1B[33m"
        printf("Value: " RED_ANSI "%d" RESET_ANSI " MemoryAddress: " YELLOW_ANSI "%p" RESET_ANSI "\n", t->value, t);
#else
        printf("Value: %d MemoryAddress: %p\n", t->value, t);
#endif
        t = t->next;
    }
    printf("\n\n");
}


bool is_ll_sorted(ll_node* l) {
    ll_node* t = l;
    while (t->next) {
        if (t->next->value < t->value)
            return false;
        t = t->next;
    }
    return true;
}
