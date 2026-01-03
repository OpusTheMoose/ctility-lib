#include "../include/array.h"
#include <assert.h>
#include "../include/print.h"
#include "../include/tests.h"
void array_tests(void)
{
  array_test_create_and_free();

}
void array_test_create_and_free(void)
{
  Array* new_array = array_create(0);
  assert(new_array == NULL);
  
  Array* new_array1 = array_create(sizeof(int));
  assert(new_array1 != NULL);

  array_free(new_array);
  assert(new_array == NULL);

  array_free(new_array1);

  cLib_logMessage("Tests passed | Created and free'd arrays of 0 and non-zero sizes.");

}

