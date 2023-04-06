#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "dynamic_array.h"

// Initialize and return dynamic array
Dynamic_Array *da_init()
{
    Dynamic_Array *da = malloc(sizeof(Dynamic_Array));
    pthread_mutex_init(&(da->lock), NULL);
    da->size = 2;
    da->len = 0;
    da->body = malloc(da->size * sizeof(int));
    return da;
}

// Push to array (sleepSecs is there for testing)
int da_push(Dynamic_Array *da, int num, int sleepSecs)
{
    pthread_mutex_lock(&(da->lock));
    if (da == NULL)
        return -1;
    if (da->size == da->len)
    {
        da->body = realloc(da->body, da->size * 2);
        da->size = da->size * 2;
    }
    da->len++;
    da->body[da->len - 1] = num;

    sleep(sleepSecs);
    pthread_mutex_unlock(&(da->lock));
    return 0;
}

// Pop from array
int da_pop(Dynamic_Array *da)
{
    pthread_mutex_lock(&(da->lock));
    if (da == NULL)
        return 0;
    if (da->len == 0)
        return 0;
    da->len--;

    pthread_mutex_unlock(&(da->lock));
    return da->body[da->len];
}

// Print contents of array
void da_print_all(Dynamic_Array *da)
{
    pthread_mutex_lock(&(da->lock));
    if (da == NULL)
        return;
    printf("Array Contents: ");
    for (int i = 0; i < da->len; i++)
    {
        printf("%d ", da->body[i]);
    }
    printf("\n");

    pthread_mutex_unlock(&(da->lock));
}

// Get element on index
int da_get_index(Dynamic_Array *da, int index)
{
    pthread_mutex_lock(&(da->lock));
    if (da->len <= index)
    {
        // Runtime exception, we don't tolerate mistakes
        exit(-1);
    }

    return da->body[index];
    pthread_mutex_unlock(&(da->lock));
}

// Remove from index and move the right side 1 step left
int da_remove_at(Dynamic_Array *da, int index)
{
    pthread_mutex_lock(&(da->lock));
    if (da->len <= index)
    {
        // Runtime exception, we don't tolerate mistakes
        exit(-1);
    }

    memcpy(&da->body[index], &da->body[index+1], (da->len - (index + 1))*sizeof(int));
    da->len -= 1;

    pthread_mutex_unlock(&(da->lock));
}
