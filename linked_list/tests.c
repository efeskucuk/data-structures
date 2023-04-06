#include "linked_list.h"
#include <stdio.h>

void test_insert_end()
{
    printf("Test name: test_insert_end\n");
    printf("--------------------\n");

    printf("->Initiating a linked list and pushing 4 extra nodes\n");
    Linked_List *head = ll_init_linked_list("aaa");
    ll_add_node_to_position(head, -1, "baa");
    ll_add_node_to_position(head, -1, "caa");
    ll_add_node_to_position(head, -1, "daa");
    ll_add_node_to_position(head, -1, "eaa");
    printf("->Printing linked list\n");
    ll_print_all(head);

    ll_free_linked_list(head);
    printf("--------------------\n\n");
}

void test_insert_middle()
{
    printf("Test name: test_insert_middle\n");
    printf("--------------------\n");

    printf("->Initiating a linked list\n");
    Linked_List *head = ll_init_linked_list("aaa");
    ll_print_all(head);
    printf("\n");

    printf("->Pushing 3 nodes to end of the list\n");
    ll_add_node_to_position(head, -1, "baa");
    ll_add_node_to_position(head, -1, "caa");
    ll_add_node_to_position(head, -1, "daa");
    ll_print_all(head);
    printf("\n");

    printf("->Pushing a node to position 1\n");
    ll_add_node_to_position(head, 1, "new");
    ll_print_all(head);

    ll_free_linked_list(head);
    printf("--------------------\n\n");
}

void test_search()
{
    printf("Test name: test_search\n");
    printf("--------------------\n");
    printf("->Initiating a linked list and pushing 5 nodes\n");
    Linked_List *head = ll_init_linked_list("aaa");
    ll_add_node_to_position(head, -1, "baa");
    ll_add_node_to_position(head, -1, "caa");
    ll_add_node_to_position(head, -1, "daa");
    ll_add_node_to_position(head, -1, "eaa");
    ll_print_all(head);
    printf("\n");

    printf("->Searching for eaa\n");
    printf("Position: %d\n", ll_find_index(head, "eaa"));
    printf("\n");

    printf("->Searching for baa\n");
    printf("Position: %d\n", ll_find_index(head, "baa"));

    ll_free_linked_list(head);
    printf("--------------------\n\n");
}

void test_remove()
{
    printf("Test name: test_remove\n");
    printf("--------------------\n");
    printf("->Initiating a linked list and pushing 5 nodes\n");
    Linked_List *head = ll_init_linked_list("aaa");
    ll_add_node_to_position(head, -1, "baa");
    ll_add_node_to_position(head, -1, "caa");
    ll_add_node_to_position(head, -1, "daa");
    ll_add_node_to_position(head, -1, "eaa");
    ll_print_all(head);
    printf("\n");

    printf("->Removed position 1, printing\n");
    head = ll_remove_node(head, 1);
    ll_print_all(head);
    printf("\n");

    printf("->Removed position 0, printing\n");
    head = ll_remove_node(head, 0);
    ll_print_all(head);

    ll_free_linked_list(head);
    printf("--------------------\n\n");
}