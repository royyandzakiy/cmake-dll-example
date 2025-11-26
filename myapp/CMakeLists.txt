project(MyApp)

# Create executable
add_executable(myapp main.cpp)

# Link against the library
target_link_libraries(myapp PRIVATE mylibrary)