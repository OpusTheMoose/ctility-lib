#ifndef TESTS_H
#define TESTS_H

#include "ctility.h"

void arena_test_init(void);
void arena_test_alloc_aligned(void);
void arena_tests(void);

void string_test_init(void);
void string_test_concat(void);
void string_test_copy(void);
void string_test_conversions(void);
void string_test_substring(void);
void string_tests(void);

void array_test_create_and_free(void);
void array_test_pushback(void);
void array_tests(void);

#endif // !TESTS_H



