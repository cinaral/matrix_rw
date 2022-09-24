# matrix_rw
Simple header-only C++ library to write/read matrices to/from files. This library is used for testing and verification using MATLAB in my other projects.

# Installation

Include the headers in ```include/``` into your project.

Alternatively, you can use [FetchContent()](https://cmake.org/cmake/help/latest/module/FetchContent.html) in your ```CMakeLists.txt```:
```CMake
FetchContent_Declare(matrix_rw URL https://github.com/cinaral/matrix_rw/releases/download/<RELEASE_TAG>/matrix_rw-src.zip)
FetchContent_MakeAvailable(matrix_rw)
set(matrix_rw_INCLUDE_DIR ${matrix_rw_SOURCE_DIR}/include)
```

Use the MATLAB test and CTest to test the library before using. 

**WARNING:** Running the MATLAB test is required since this library's intended use case is interfacing with MATLAB functions.

# Usage:

## Read:
```Cpp
matrix_rw::read<n_dim, m_dim>(file, matrix);
```

## Write:
```Cpp
matrix_rw::write<n_dim, m_dim>(file, matrix);
```

See the [test](./test/test-matrix_rw.cpp) for an example.

The input and output files are comma and newline delimited, and their extension is ```*.dat``` by default. The formatting is compatible with MATLAB's ```writematrix``` and ```readmatrix```. Each row in the file corresponds to a matrix row. The file should contain ```N``` lines and ```M``` comma-separated numbers in each line for a ```N``` by ```M``` matrix.
```MATLAB
writematrix(matrix, file, 'Delimiter', ',');  
matrix = readmatrix(file);  
```
