cmake_minimum_required(VERSION 3.15)
project(MyDLLExample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output all to same directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add subdirectories for both projects
add_subdirectory(mylibrary)
add_subdirectory(myapp)