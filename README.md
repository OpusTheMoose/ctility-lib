<h1>C Utility Library</h1>
<h2>Introduction</h2>
A (very opionionated) C standard library implementation. Written in C23, with the only dependency being the C standard library (likely to change).
Currently had five files:
<ul>
  <li>Arena Memory Allocator</li>
  <li>Dynamic Array </li>
  <li>Print</li>
  <li>String</li>
  <li>Timer</li>
</ul>
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

</ul>
