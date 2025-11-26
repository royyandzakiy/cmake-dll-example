#include <iostream>
#include "../mylibrary/mylibrary.h"

int main() {
    std::cout << "Hello from executable!" << std::endl;
    
    // Use functions from the DLL
    int result = add_numbers(5, 3);
    std::cout << "5 + 3 = " << result << std::endl;
    
    print_message("Hello from main application!");
    
    return 0;
}