#include "../include/tests.h"
#include <assert.h>
#include <stdalign.h>
// Forward declare some tests to make it look nice
void arena_test_init(void);


void arena_tests(void)
{
   // Test arena create
   arena_test_init();
  // Test arena alloc 
   arena_test_alloc_aligned();
}

void arena_test_init(void)
{
   // Try to allocate 0 bytes. Should return NULL
   Arena* arena1 = arena_create(0);
   assert(arena1 == NULL);
   cLib_logMessage("Test passed | Initalized arena of size 0 is NULL");

   arena_destroy(arena1);
   // Allocate 1024 bytes (1kb)
   Arena* arena2 = arena_create(1024);
   assert(arena2 != NULL);
   cLib_logMessage("Test passed | Arena of size 1024 created sucessfully.");
   assert(arena2->region != NULL);
   cLib_logMessage("Test passed | Arena region is not null.");
   assert(arena2->size == 1024);
   cLib_logMessage("Test passed | Arena size is 1024 bytes.");
   assert(arena2->index == 0);
   cLib_logMessage("Test passed | Arena index starts at 0.");
   arena_destroy(arena2);
   cLib_logMessage("All tests passed for arena_test_init()");
   
}
void arena_test_alloc_aligned(void)
{ 
   int* final = (int*)arena_alloc_type(NULL, int);
   assert(final == NULL);
   cLib_logMessage("Test passed | Cannot alloc a NULL arena.");
}
