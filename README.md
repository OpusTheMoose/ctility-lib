<h1>C Utility Library</h1>
<h2>Introduction</h2>
A (very opionionated) C standard library implementation. Written in C23, with the only dependency being the C standard library (likely to change).
Current features include:
<ul>
  <li>Standard types</li>
  <li>Arena Memory Allocator</li>
  <li>Dynamic Array </li>
  <li>Print</li>
  <li>String</li>
  <li>Timer</li>
</ul>
<h1>Types</h1>
An override of the <i>stdint.h</i> header, based on Rust's type naming scheme. Currently supports signed and unsigned 8, 16, 32, and 64 bit values (i8-i64, u8-u64 respectively)
<h1>Arena</h1>
A linear (bump) memory allocator. <br>
Arena { <br>
  &emsp;size_t index; <br>
  &emsp;size_t size; <br>
  &emsp;u8* region; <br>
} <br>
<h2>Functions</h2>
<ul>
  <li><b>Arena* arena_create(size_t size)</b></li>
  Allocate <i>size</i> number of bytes for the arena allocator. Calls arena_init (see below), and returns the arena object.
  <li><b>void arena_init(Arena* arena, void* region, size_t size)</b></li>
  Initalizes arena, with a region pointer (malloc'd area of memory) and specified size. Returns Arena struct.
  <li><b>void* arena_alloc_type(arena, T)</b></li>
  Used for aliging the data in the region. Specify the arena in the first parameter, and the type of data. Returns a pointer to the current index of the region
</ul>
<h1>Array</h1>
  A generic dynamic array implementation. <br>
    Array { <br>
      &emsp;size_t len; // Current array length <br>
      &emsp;size_t capacity;  // Maximum array capacity <br>
      &emsp;size_t element_size; // Size of each element in array, used for indexing <br>
      &emsp;char* data; // Raw byte data, used for pointer arthmetic <br>
    } <br>
<h2>Functions</h2>
  <ul>
    <li>Array* cLib_array_create(sizet elem_size)</li>
    Initalizes an empty array with length 0, capacity 8 (default), elem_size, and data*
    <li>void cLib_array_pushback(Array* arr, void* elem)</li>
    Pushes back an element into the given array.
    <li> *(type*)cLib_array_at(type, array, index)</li>
    A macro for the array_at_type(array, index) function. Returns the element at the specified index, or NULL if it can't be found (note this causes a null pointer exception, will probably be fixed)
  </ul>

