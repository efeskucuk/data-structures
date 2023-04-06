#ifndef DYNAMIC_ARR_HEADER
#define DYNAMIC_ARR_HEADER

#include <pthread.h>

typedef struct Dynamic_Array
{
   int size;
   int len;
   int *body;
   pthread_mutex_t lock;
} Dynamic_Array;

int da_push(Dynamic_Array *da, int num, int sleepSecs);
int da_pop(Dynamic_Array *da);
void da_print_all(Dynamic_Array *da);
int da_get_index(Dynamic_Array *da, int index);
int da_remove_at(Dynamic_Array *da, int index);
Dynamic_Array *da_init();

#endif