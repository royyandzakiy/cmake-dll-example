#pragma once

#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)
#else
#define MYLIBRARY_API __declspec(dllimport)
#endif

extern "C" {
    MYLIBRARY_API int add_numbers(int a, int b);
    MYLIBRARY_API void print_message(const char* message);
}