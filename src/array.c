#include "../include/array.h"
#include "../include/print.h"
#include <string.h> // memcpy 


Array cLib_array_create(size_t elem_size)
{

  Array array; 
  array.capacity = ARRAY_INITIAL_CAPACITY;
  array.len = 0;
  array.element_size = elem_size;

  if (elem_size == 0)
  {
    cLib_errorMessage("Element size is 0 for array, returning empty array", FATAL);
    array.data = NULL;
    return array;
  }
  array.data = malloc(elem_size * ARRAY_INITIAL_CAPACITY);
  
  
  return array;
}
void cLib_array_pushback(Array *arr, void *elem)
{
  const size_t array_capacity = arr->capacity;
  const size_t array_length = arr->len;
  const size_t array_elem_size = arr->element_size;
  if (array_capacity == 0) 
  {
    cLib_errorMessage("Dynamic array is size 0", FATAL);
    return;
  }
  // Create a pointer to the new position in the data array to add the value 
  void* new_data = arr->data + (array_elem_size * array_length); 
  memcpy(new_data, elem, array_elem_size); 
  // New element added, increase length by 1
  arr->len += 1;
  // Right shift to divide by 2, left shift to multiply by 2
  // Not really a needed optimization (compiler probably does the same)
  if ((array_capacity >> 1) < array_length)
  {
    
    char* new_data = realloc(arr->data, (array_capacity * array_elem_size) << 1);
    if (new_data == NULL)
    {
      cLib_errorMessage("Unable to reallocate memory for array.", FATAL);
    }
    arr->data = new_data;
    arr->capacity *= 2;
  }

}
void* array_at_type(Array* arr, size_t index)
{
  if (index > arr->len)
  {
    cLib_errorMessage("Index out of bounds, returning NULL", FATAL);
    return NULL;
  }
  return arr->data + (index * arr->element_size); 
}
void cLib_array_free(Array* arr)
{
   if (arr == NULL) return;
   free(arr->data);
   arr->data = NULL;
    return;
}
