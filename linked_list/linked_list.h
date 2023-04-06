#ifndef LL_HEADER
#define LL_HEADER

typedef struct Linked_List
{
    char *val;
    struct Linked_List *next;
} Linked_List;

int ll_find_index(Linked_List *startFrom, char *searchFor);
Linked_List *ll_add_node_to_position(Linked_List *head, int position, char *string);
Linked_List *ll_remove_node(Linked_List *head, int position);
int ll_count_length(Linked_List *startFrom);
void ll_print_all(Linked_List *head);
Linked_List *ll_init_linked_list(char *string);
int ll_free_linked_list(Linked_List *head);
Linked_List *ll_get_last(Linked_List *head);

#endif