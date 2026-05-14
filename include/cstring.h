#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "../include/arena.h"

typedef struct {
   char* str;
   size_t len; // Does NOT include null terminator  
} String;
#define String(x) (String){x, strlen(x)}

String str_init(size_t len_, Arena* allocator);
String str_concat(String  str1, String str2, Arena* allocator);

#endif // !STRING_H

