#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>


typedef struct {
  size_t len;
  size_t capacity;
  size_t element_size;
  char* data;

} Array;

Array* array_create(size_t elem_size);
void array_pushback(Array* arr, void* elem);
void* array_get(Array* arr, size_t index);
void array_free(Array* arr);
#endif
