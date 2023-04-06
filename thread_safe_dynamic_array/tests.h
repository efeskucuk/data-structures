#ifndef TESTS_HEADER
#define TESTS_HEADER

// Thread functions
void *wait5unlock(void *arg);
void *tryToAccess(void *arg);

// Test functions
void testLock();
void testRemoveIndex();

#endif