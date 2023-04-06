#include <stdio.h>
#include <pthread.h>
#include "tests.h"
#include "linked_list.h"

int main()
{
    test_insert_end();
    test_insert_middle();
    test_search();
    test_remove();

    return 0;
}