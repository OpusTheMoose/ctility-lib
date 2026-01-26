#ifndef ARENA_H
#define ARENA_H


#include "types.h"
#include <stdio.h>

typedef struct {
  size_t index;
  size_t size;
  u8* region;
} Arena;

void cLib_arena_init(Arena* arena, void* region, size_t size);
Arena* cLib_arena_create(size_t size);
void* arena_alloc_aligned(Arena* arena, size_t size, size_t align);
void cLib_arena_reset(Arena* arena);
void cLib_arena_destroy(Arena* arena);
#define cLib_arena_alloc_type(arena, T) \
  ((T*)arena_alloc_aligned((arena), sizeof(T), _Alignof(T)))


#endif // !ARENA_H
