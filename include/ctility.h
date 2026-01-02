#ifndef DBG_H
#define DBG_H

#define CTILITY_VERSION_MAJOR 0
#define CTILITY_VERSION_MINOR 1

// Use a naming convention more similar to rust
#include <stdint.h>
#include <stdio.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#include "types.h"
#include "arena.h"
#include "string.h"
#include "array.h"
typedef enum {
  FATAL,
  WARNING
} clib_error_type;

void cLib_logMessage_(const char* msg, const char* file,  i32 line );
#define cLib_logMessage(msg) cLib_logMessage_(msg, __FILE__,  __LINE__)

void cLib_errorMessage_(const char* msg, const char* file, i32 line, clib_error_type error);
#define cLib_errorMessage(msg, error) cLib_errorMessage_(msg, __FILE__,  __LINE__, error)


#endif
