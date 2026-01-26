#include "../include/ctility.h"
#include <stdlib.h>

void cLib_arena_init(Arena* arena, void* region, size_t size)
{
  if (!arena)
  {
    cLib_errorMessage("Arena is NULL, returning uninitalised arena!", FATAL);
    return;
  }
  if ((region == NULL) || (size == 0))
  {
    cLib_errorMessage("Null region specified or size is 0. Returning uninitalised arena!", FATAL);
    return; 
  }

  arena->index = 0;
  arena->size = size;
  arena->region = region;


}
// Specifies the number of bytes you want to allocate
Arena* cLib_arena_create(size_t size)
{
  if (size == 0)
  {
     cLib_errorMessage("Specified size is 0, returning NULL arena!", FATAL);
     return NULL;
  }
  Arena* arena = NULL;
  void* region = NULL;

  arena = malloc(sizeof(Arena));
  if (arena == NULL)
  {
    cLib_errorMessage("Out of memory trying to allocate Arena, returning NULL!", FATAL);
    return NULL;
  }
  region = malloc(size);
  if (region == NULL)
  {
    cLib_errorMessage("Out of memory trying to allocate region, return NULL!", FATAL);
    free(arena);
    return NULL;
  }

  cLib_arena_init(arena, region, size);



  return arena;
}

void* cLib_arena_alloc(Arena* arena, size_t size)
{
  if (size == 0)
  {
    cLib_errorMessage("Cannot alloc, size is 0", FATAL);
    return NULL;
  }
  if  (arena == NULL || arena->region == NULL)
  {
    cLib_errorMessage("Cannot alloc, arena is NULL", FATAL);
    return NULL;
  }
  
  if (arena->index + size > arena->size)
  {
    cLib_errorMessage("Arena out of memory", FATAL);
    return NULL;
  }

  void* ptr = arena->region + arena->index;
  arena->index += size;

  return ptr;

}

static size_t _align_forward(size_t ptr, size_t align)
{
  size_t mod = ptr & (align - 1);
  if (mod != 0)
      ptr += align - mod;
  return ptr;
}

void* arena_alloc_aligned(Arena* arena, size_t size, size_t align)
{
  if (!arena || !arena->region || size == 0)
  {
    cLib_errorMessage("Arena or region is NULL, or size is 0.", FATAL);
    return NULL;
  }
  size_t aligned_index = _align_forward(arena->index, align);

  if (aligned_index + size > arena->size)
  {
    cLib_errorMessage("Arena out of memeory", FATAL);
      return NULL;
  }
 
  void* ptr = arena->region + aligned_index;
  arena->index = aligned_index + size;
  return ptr;
 }

void cLib_arena_reset(Arena* arena)
{
  if (!arena) return;
  arena->index = 0;
}
// Free all data malloc'd with this arena.
void cLib_arena_destroy(Arena* arena)
{
   
  if (arena != NULL)
  {
    if (arena->region != NULL) free (arena->region);
    free(arena);
  }


}
