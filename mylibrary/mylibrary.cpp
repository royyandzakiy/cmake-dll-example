#include "mylibrary.h"
#include <iostream>

MYLIBRARY_API int add_numbers(int a, int b) {
    return a + b;
}

MYLIBRARY_API void print_message(const char* message) {
    std::cout << "From DLL: " << message << std::endl;
}