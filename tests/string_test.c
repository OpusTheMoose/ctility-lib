#include "../include/ctility.h"
#include "../include/tests.h"
#include <assert.h>
#include <string.h>

void string_tests()
{
  string_test_concat();
  string_test_copy();
  
  string_test_substring();
  string_test_split();
  string_test_contain();
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


void string_test_substring(void)
{
     Arena* string_arena = cLib_arena_create(1024);

     const String test_string = String("Hello, world!");
     String empty = str_substr(test_string, 0, 100, string_arena);
     assert(str_cmp(empty, String("")) == 0);
     cLib_logMessage("Test passed | Substr length > string length");

     empty = str_substr(test_string, 100, 200, string_arena);
     assert(str_cmp(empty, String("") ) == 0);
     cLib_logMessage("Test passed | Substr start exceeds string length");    

     String result;
     result = str_substr(test_string, 0, 5,  string_arena);
     assert(str_cmp(result, String("Hello")) == 0);
     cLib_logMessage("Test passed | Substr from 0 to len 5 matches");
    
    
}

void string_test_split(void)
{
    Arena* string_arena = cLib_arena_create(1024);

      String test_string = String("Hello, world! This is a test.");
      Array split = str_split(test_string, string_arena, ' ');
      
      assert(split.len == 6);
      String s1 = ((String*)split.data)[0];
      String s2 = ((String*)split.data)[1];
      String s3 = ((String*)split.data)[2];
      String s4 = ((String*)split.data)[3];
      String s5 = ((String*)split.data)[4];
      String s6 = ((String*)split.data)[5];
 
      assert(str_cmp(s1, String("Hello,")) == 0);
      assert(str_cmp(s2, String("world!")) == 0);
      assert(str_cmp(s3, String("This")) == 0);
      assert(str_cmp(s4, String("is")) == 0);
      assert(str_cmp(s5, String("a")) == 0);
      assert(str_cmp(s6, String("test.")) == 0);
  
        cLib_logMessage("Test passed | Split string by space character");
  
        cLib_arena_destroy(string_arena); 
}

void string_test_contain(void)
{
    Arena* string_arena = cLib_arena_create(1024);

    String test_string = String("Hello, world!");
    String substr1 = String("world");
    String substr2 = String("test");

    assert(str_contain(test_string, substr1) == 7);
    cLib_logMessage("Test passed | Substring is contained in the string");

    assert(str_contain(test_string, substr2) == 0);
    cLib_logMessage("Test passed | Substring is not contained in the string");

    cLib_arena_destroy(string_arena);
}
