project(MyLibrary)

# Create shared library (DLL)
add_library(mylibrary SHARED mylibrary.cpp mylibrary.h)

# Set Windows-specific properties
if(WIN32)
    target_compile_definitions(mylibrary PRIVATE MYLIBRARY_EXPORTS)
endif()