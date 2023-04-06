#include "linked_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Searches for a string
int ll_find_index(Linked_List *startFrom, char *searchFor)
{
    Linked_List *curr = startFrom;
    int index = 0;
    while (curr->next != NULL)
    {
        if (strcmp(curr->val, searchFor) == 0)
        {
            return index;
        }
        index++;
        curr = curr->next;
    }
    if (strcmp(curr->val, searchFor) == 0)
    {
        return index;
    }

    return -1;
}

// Returns head, if position is -1, will add to end of list
Linked_List *ll_add_node_to_position(Linked_List *head, int position, char *string)
{
    Linked_List *node = malloc(sizeof(Linked_List));

    if(string) {
        node->val = malloc(strlen(string) + 1);
        strcpy(node->val, string);
    } else {
        node->val = NULL;
    }
    

    Linked_List *curr = head;
    Linked_List *prev = NULL;
    int curr_position = 0;

    if (position == 0)
    {
        node->next = NULL;
        return node;
    }

    while (curr->next != NULL)
    {
        if (curr_position == position)
        {
            prev->next = node;
            node->next = curr;
            return head;
        }

        curr_position++;
        prev = curr;
        curr = curr->next;
    }
    if (curr_position == position)
    {
        prev->next = node;
        node->next = curr;
        return head;
    }
    if (curr_position + 1 == position || position == -1)
    {
        curr->next = node;
    }

    return NULL;
}

Linked_List *ll_remove_node(Linked_List *head, int position)
{

    if (position == 0)
    {
        Linked_List *next = head->next;
        if(head->val) free(head->val);
        free(head);

        return next;
    }

    Linked_List *curr = head;
    Linked_List *prev = NULL;
    int counter = 0;

    while (curr->next != NULL)
    {
        if (counter == position)
        {
            prev->next = curr->next;
            if(curr->val) free(curr->val);
            free(curr);
            return head;
        }

        counter++;
        prev = curr;
        curr = curr->next;
    }
    if (counter == position)
    {
        prev->next = curr->next;
        if(curr->val) free(curr->val);
        free(curr);
    }

    return head;
}

// Prints the amount of nodes currently on linked list
int ll_count_length(Linked_List *startFrom)
{
    if (!startFrom)
        return 0;

    Linked_List *curr = startFrom;
    int count = 1;
    while (curr->next != NULL)
    {
        count++;
        curr = curr->next;
    }

    printf("Count: %d\n", count);
}

// Prints all nodes of the linked list
void ll_print_all(Linked_List *head)
{
    Linked_List *curr = head;
    while (curr->next != NULL)
    {
        printf("%s, ", curr->val);
        curr = curr->next;
    }
    printf("%s\n", curr->val);
}

// Inits and returns linked list
Linked_List *ll_init_linked_list(char *string)
{
    return ll_add_node_to_position(NULL, 0, string);
}

// Frees the whole linked list
int ll_free_linked_list(Linked_List *head)
{
    Linked_List *curr = head;

    while (curr->next != NULL)
    {
        Linked_List *next = curr->next;
        if(curr->val) free(curr->val);
        free(curr);
        curr = next;
    }

    if(curr->val) free(curr->val);
    free(curr);

    return 0;
}

// Gets last element of linked list
Linked_List *ll_get_last(Linked_List *head)
{
    Linked_List *curr = head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    return curr;
}