# CMake DLL Project

A minimal example demonstrating how to create and use a DLL with CMake on Windows.

## Why is this interesting?
`Real business case`: You want to create a library (.dll) that you will sell to different clients. You will ship the .dll as the end product, and clients will create their own custom applications while utilizing the library that you have created.

## Key Concepts

**Shared vs Static Libraries**: DLLs (shared) are loaded at runtime, allowing updates without recompiling dependent applications. Static libraries (.lib) are embedded into the executable during compilation.

**C Wrapper & ABI Stability**: Using `extern "C"` prevents C++ name mangling, creating clean function names and stable ABI. This enables cross-language compatibility (Python, C#, Rust) and binary stability across compiler versions.

## Project Structure
```
cmake-dll-example/
├── CMakeLists.txt
├── mylibrary/
│   ├── CMakeLists.txt
│   ├── mylibrary.h
│   └── mylibrary.cpp
└── myapp/
    ├── CMakeLists.txt
    └── main.cpp
```

## Building
```bash
cmake -B build && cmake --build build --config Release

# Run
build\bin\Release\myapp.exe
```

All binaries (DLL and EXE) will be output to `build/bin/`.

## Library Generation Explained

### Key Components for DLL Creation:

1. **CMake**: `add_library(mylibrary SHARED ...)` creates a shared library (DLL on Windows)

2. **Export Macro**: 
   - `__declspec(dllexport)` when building the DLL
   - `__declspec(dllimport)` when using the DLL

3. **Header File Pattern**:
```cpp
#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)
#else
#define MYLIBRARY_API __declspec(dllimport)
#endif

extern "C" {
    MYLIBRARY_API int add_numbers(int a, int b);
}
```

### How It Works:
- The DLL project defines `MYLIBRARY_EXPORTS` which enables `__declspec(dllexport)`
- Client code includes the same header but gets `__declspec(dllimport)`
- CMake handles linking and ensures both DLL and EXE are built to the same directory

The executable automatically loads the DLL at runtime when calling the exported functions.