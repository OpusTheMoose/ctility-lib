#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
// https://stackoverflow.com/questions/29052877/once-only-pseudo-generic-header-in-c
#define ARRAY_INITIAL_CAPACITY 8

typedef struct {
  size_t len; // Current array length
  size_t capacity; // Maximum capacity for array
  size_t element_size; // sizeof(type), usually
  char* data; // Char* for pointer arthmetic

} Array;

Array cLib_array_create(size_t elem_size);
void cLib_array_pushback(Array* arr, void* elem);
void* array_at_type(Array* arr, size_t index);
#define cLib_array_at(type, da, index) *(type*)array_at_type(da, index) 
void cLib_array_free(Array* arr);

#endif
