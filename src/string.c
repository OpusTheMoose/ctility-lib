#include "../include/cstring.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define CONVERSION_BUFFER 32
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
// This copies into an existing string, assuming the string has allocated space 
String str_copy_alloc(const String src_string, Arena* allocator){
      String s = str_init(src_string.len, allocator);
     memcpy(s.str, src_string.str, src_string.len); 
     return s;
}

// Compares two strings. Returns 0 if it's match, negative otherwise
i32 str_cmp(String s1, String s2)
{
  if (s1.len != s2.len) return -1;
  for (size_t i = 0; i < s1.len; i++)
  {
     if (s1.str[i] !=  s2.str[i] ) return -1; 
  }
  return 0;
      
}

// Returns the position of the character if it's in the string, -1 if it's not
i32 str_find_char(String s, char c)
{
   for (size_t i = 0; i < s.len; i++)
   {
       if (s.str[i] == c) return i;
   }
   return -1;
}

// Returns a substring with the given start and end pos. Returns an empty string if it finds nothing
String str_substr(const String s, const size_t start, const size_t len, Arena* alloc)
{ 
    if (start + len > s.len || start > s.len) return String("");
   String string = str_init(len, alloc);
   memcpy(string.str, &s.str[start], len);


   return string;
}

Array str_split(String str, Arena* alloc, const char delim)
{
    Array array = cLib_array_create(sizeof(String));
    size_t last_found_match = 0;
    for (size_t i = 0; i < str.len; i++)
    {
       if (delim == str.str[i])
       {
           String s = str_substr(str, last_found_match, i - last_found_match, alloc);
           cLib_array_pushback(&array, &s); 
           last_found_match = i +  1; 
       }
    } 
    String final_substring = str_substr(str, last_found_match, str.len - last_found_match, alloc);
    cLib_array_pushback(&array, &final_substring);

    return array;
}


// Conversion functions 
String str_f32_to_str(float f, Arena* alloc)
{
  char buf[CONVERSION_BUFFER];
  snprintf(buf, CONVERSION_BUFFER, "%f", f);

  size_t str_size = strnlen(buf, CONVERSION_BUFFER);
  String str = str_init(str_size, alloc);
  strncpy(str.str, buf, str_size);
  return str; 
}
String str_f64_to_str(double d)
{
  char buf[32];
  snprintf(buf, sizeof(buf), "%lf", d); 
  return String(buf);

}

