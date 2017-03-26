#include <stdio.h>
#include <stdlib.h>

#include "node.h"

int main() {

    // Create
    printf("Input values for linked list\n");
    printf("Insert EOF to end (ctrl-D)\n");
    ll_node* start = create_from_input();
    debug_print(start);

    // Sort
    printf("Linked list after sorting\n");
    start = insertion_sort(start);
    if (is_ll_sorted(start)) printf("success\n");
    debug_print(start);

    // Insert
    int v;
    printf("Input value to insert into ascending list\n");
    scanf("%d", &v);
    debug_print(insert_into_ascending(start, v));

    return 0;
}
