#include "../include/array.h"
#include "../include/ctility.h"


#define ARRAY_INITIAL_CAPACITY 8

Array* array_create(size_t elem_size)
{
  Array* array = malloc(sizeof(Array));
  array->capacity = ARRAY_INITIAL_CAPACITY;
  array->len = 0;
  array->data = malloc(elem_size * ARRAY_INITIAL_CAPACITY);
  array->element_size = elem_size;
  return array;
}
void array_pushback(Array *arr, void *elem)
{
  if (arr->capacity == 0) 
  {
    cLib_errorMessage("Dynamic array is size 0", FATAL);
    return;
  }
  
  void* new_data = arr->data + (arr->element_size * arr->len); 
  memcpy(new_data, elem, arr->element_size); 

  arr->len += 1;
  if (arr->capacity / 2 < arr->len)
  {
    char* new_data = realloc(arr->data, arr->capacity * 2);
    if (new_data == NULL)
    {
      cLib_errorMessage("Unable to reallocate memory for array.", FATAL);
    }
    arr->data = new_data;
    arr->capacity *= 2;
  }

}
void* array_get(Array* arr, size_t index)
{
  if (index > arr->len)
  {
    cLib_errorMessage("Index out of bounds, returning NULL", FATAL);
    return NULL;
  }
  return arr->data + (index * arr->element_size); 
}
void array_free(Array* arr)
{
   if (arr == NULL) return;
   free(arr->data);
   arr->data = NULL;
   free(arr);
   return;
}
