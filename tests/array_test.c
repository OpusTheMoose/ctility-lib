#include "../include/array.h"
#include <assert.h>
#include "../include/print.h"
#include "../include/tests.h"

void array_tests(void)
{
  array_test_create_and_free();
  array_test_pushback();
}
void array_test_create_and_free(void)
{
  Array* new_array = cLib_array_create(0);
  assert(new_array == NULL);
  
  Array* new_array1 = cLib_array_create(sizeof(i32));
  assert(new_array1 != NULL);

  cLib_array_free(new_array);
  assert(new_array == NULL);

  cLib_array_free(new_array1);

  cLib_logMessage("Tests passed | Created and free'd arrays of 0 and non-zero sizes.");

}
void array_test_pushback(void)
{

  Array* new_array = cLib_array_create(sizeof(i32));
  // Pushback 1024 integers
  for (i32 i = 0; i < 1024; i++)
  {
    cLib_array_pushback(new_array, &i);
  }
  // Verify the same values are stored
  for (i32 i = 0; i < 1024; i++)
  {
    // Upcasting is probably safer
    assert(i == cLib_array_at(i32, new_array, (size_t)i)); 
  }
 
  cLib_logMessage("Test passed | Pushed back 1024 elements into array.");

  cLib_array_free(new_array);
}
