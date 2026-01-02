#include "include/array.h"
#include "include/tests.h"
#include "include/ctility.h"

int main(void)
{
  arena_tests();
  string_tests();   
  Array* arr = array_create(sizeof(int));
  int test = 2;
  array_pushback(arr, &test);
  int* index_got = (int*)array_get(arr, 0);
  printf("%i \n", *index_got);
  array_free(arr);

  return 0;
}
