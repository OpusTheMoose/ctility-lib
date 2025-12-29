#include "../include/ctility.h"


void cLib_logMessage_(const char* msg, const char* file, i32 line)
{
  printf("[File: %s | Line: (%i)] %s \n"  RESET, file, line, msg); 
}

void cLib_errorMessage_(const char* msg, const char* file, i32 line, clib_error_type error)
{
  switch (error)
  {
    case FATAL:
      printf(RED "[ERROR FATAL: %s] \n", msg);
      printf("[File: %s | Line: (%i)]  \n"  RESET, file, line ); 
    break;
    case WARNING:
      printf(YEL "[WARNING: %s] \n", msg);
      printf("[File: %s | Line: (%i)]  \n"  RESET, file, line ); 
    break;
    default:
      printf("%i is not a valid error type!", error);
      
      
    
      
  }
}
 
