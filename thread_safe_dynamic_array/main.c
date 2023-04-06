#include <stdio.h>
#include <pthread.h>
#include "tests.h"
#include "dynamic_array.h"

int main()
{
    // Remove an element at some index
    testRemoveIndex();

    // Lock with one thread, try to access with another
    testLock();
    

    return 0;
}