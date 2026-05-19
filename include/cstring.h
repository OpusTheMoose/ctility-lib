#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "../include/arena.h"
#include "../include/array.h"

typedef struct {
   char* str;
   size_t len; // Does NOT include null terminator  
} String;
#define String(string) (String){string, strlen(string)}

String str_init(size_t len_, Arena* allocator);
String str_concat(String  str1, String str2, Arena* allocator);
// Copy from src_string into dst_string. Only if dst_string has a string buffer >= src buffer
String str_copy_alloc(const String src_string, Arena* allocator);
String str_substr(const String s, size_t const start_pos, const size_t length, Arena* allocator);
Array str_split(String str, Arena* alloc, const char delim);
i32 str_cmp(String s1, String s2);
i32 str_find_char(String s, char c);
String str_f32_to_str(float f, Arena* arena);
String str_f64_to_str(double d);




#endif // !STRING_H

