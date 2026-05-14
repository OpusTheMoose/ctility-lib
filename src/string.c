#include "../include/cstring.h"

// A lot of implementation pulled from this article: https://www.bytesbeneath.com/p/custom-strings-in-c
// (With some changes ;) ) 
String str_init(size_t len_, Arena* allocator)
{
   String s = {
    .str = (char*)arena_alloc_aligned(allocator, len_+1, _Alignof(char)),
    .len = len_,
  };
  // Set null terminator
  s.str[len_] = 0;
  return s;

}
String str_concat(String str1, String str2, Arena* allocator)
{
  size_t len = str1.len + str2.len;
  String s = str_init(len, allocator);
  memcpy(s.str, str1.str, str1.len );
  memcpy(&s.str[str1.len], str2.str, str2.len);
  return s;

}

