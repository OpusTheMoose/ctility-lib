#include "../include/ctility.h"
#include "../include/tests.h"
#include <assert.h>
#include <string.h>

void string_tests()
{
  string_test_concat();
  string_test_copy();
  string_test_conversions();
}
void string_test_init()
{
    
}
void string_test_concat()
{
  // Use a static string arena for the following tests. Max size of 1024 bytes
  // Test concat of two regular strings
  Arena* string_arena = cLib_arena_create(1024);
  String s1 = String("Abcde");
  String s2 = String("12345");
  String concat = str_concat(s1, s2, string_arena);

  String compare1 = String("Abcde12345");
  assert(memcmp(concat.str, compare1.str, 10) == 0);
  cLib_logMessage("Test passed | Concat of two strings");
  cLib_arena_reset(string_arena);

  // Concat with a null character should just return the orignial string
  String s3 = String(""); // Empty string 
  String s4 = String("12345");
  String concat2 = str_concat(s3, s4, string_arena);
  String compare2 = String("12345");
  
  assert(memcmp(concat2.str, compare2.str, 5) == 0);
  cLib_logMessage("Test passed | Concat of empty string and non-empty string.");

  cLib_arena_destroy(string_arena);

  
}
void string_test_copy()
{
   Arena* string_arena = cLib_arena_create(1024);
   String s1 = String("Hello");
   String s2 = str_copy_alloc(s1, string_arena);
   assert(s1.len == s2.len); 
   assert(memcmp(s1.str, s2.str, s1.len) == 0);
    cLib_logMessage("Test passed | Copy one string into another");


}
void string_test_conversions(void)
{
   Arena* string_arena = cLib_arena_create(1024);

   //String float1 = String("123.45");
   String float_convert = str_f32_to_str(123.45, string_arena);
   printf("%s\n", float_convert.str);
   //assert(str_cmp(float1, str_f32_to_str(123.45)) == 0); 
}
