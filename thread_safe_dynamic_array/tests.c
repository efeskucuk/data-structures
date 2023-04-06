#include "dynamic_array.h"
#include <stdio.h>
#include <pthread.h>

// Pushes an element to array and makes it stay locked for 5 secs
void *wait5unlock(void *arg)
{
    Dynamic_Array *da = (Dynamic_Array *)arg;
    printf("->Thread 1 locks for 3 seconds \n");
    da_push(da, 1, 0);
    da_push(da, 3, 0);
    da_push(da, 5, 3);
    printf("->Thread 1 Unlocked \n");

    return NULL;
}

// Waits 1 seconds, tries to print the array
void *tryToAccess(void *arg)
{
    Dynamic_Array *da = (Dynamic_Array *)arg;

    printf("->Thread 2 tries to print immediately\n");
    da_print_all(da);
    printf("->Thread 2 manages to print \n");

    return NULL;
}

void testLock()
{
    printf("Test name: testLock Start\n");
    printf("--------------------\n");
    Dynamic_Array *da = da_init();

    // One to lock, other to wait
    pthread_t tid[2];

    pthread_create(&tid[0], NULL, wait5unlock, (void *)da);

    // This will attempt to print the whole array immediately, but will instead wait for 5 seconds
    // Because first thread will lock the array for 5 seconds
    pthread_create(&tid[1], NULL, tryToAccess, (void *)da);

    for (int i = 0; i < 2; i++)
    {
        pthread_join(tid[i], NULL);
    }
    printf("--------------------\n\n");
}

void testRemoveIndex()
{
    printf("Test name: testRemoveIndex Start\n");
    printf("--------------------\n");
    Dynamic_Array *da = da_init();
    printf("->Pushing numbers 1 to 5\n");
    da_push(da, 1, 0);
    da_push(da, 2, 0);
    da_push(da, 3, 0);
    da_push(da, 4, 0);
    da_push(da, 5, 0);
    da_print_all(da);

    printf("->Removing number at index 2\n");
    da_remove_at(da, 2);
    da_print_all(da);
    printf("--------------------\n\n");
}