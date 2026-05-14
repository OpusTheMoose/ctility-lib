
cmake_minimum_required(VERSION 4.0.0)
project(ctility VERSION 0.1.0 LANGUAGES C)
set(CMAKE_C_STANDARD 23) 
include(FetchContent)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})



add_library(ctility STATIC main.c src/print.c src/arena.c src/string.c src/array.c tests/arena_test.c tests/string_test.c tests/array_test.c src/timer.c)
install(DIRECTORY include/ctility DESTINATION include)
install(TARGETS ctility ARCHIVE DESTINATION lib LIBRARY DESTINATION lib)

if(WIN32)
        option(WINDOWS "OS detected as Windows" ON)
endif()
option(ENABLE_DEBUG "Enable debug features" ON)
option(ENABLE_TESTS "Enables testing" OFF)
if (ENABLE_DEBUG)
        target_compile_options(ctility PRIVATE -Wall -Wextra -Wpedantic -Werror -g -O0)
         
        # target_compile_options(game PRIVATE -Wall -Wextra)
        target_compile_definitions(ctility PRIVATE ENABLE_DEBUG)
endif()
if(ENABLE_TESTS)
  target_compile_options(ctility PRIVATE -Wall -Wextra -Wpedantic -Werror)
         
        # target_compile_options(game PRIVATE -Wall -Wextra)
        target_compile_definitions(ctility PRIVATE ENABLE_TESTS)
endif()

target_include_directories(ctility PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(ctility PUBLIC) 

include(CTest)
enable_testing()
