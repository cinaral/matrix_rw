# `matrix_rw`: Matrix Read/Write
This is a simple header-only C++ library to read/write .csv files to read/write matrices from/to file. It is indended to be used for variable row size matrices represented via std::array:
```Cpp
template <Size M_COL> using Row_T = std::array<Real, M_COL>;
```

# Installation

Include the headers in ```include/``` into your project.

Alternatively, you can use [FetchContent()](https://cmake.org/cmake/help/latest/module/FetchContent.html) in your ```CMakeLists.txt```:
```CMake
FetchContent_Declare(matrix_rw URL https://github.com/cinaral/matrix_rw/releases/download/<RELEASE_TAG>/src.zip)
FetchContent_MakeAvailable(matrix_rw)
```

# Usage:

## Read:
```Cpp
Reader<m_col> readmatrix;
std::vector<Row_T<m_col>> mat;
readmatrix(file_path, mat); /** read from file */
```

## Write:
```Cpp
std::vector<Row_T<m_col>> mat;
//...
Writer<m_col> writematrix;
writematrix(file_path, mat); /** write to file */
```

The formatting is compatible with MATLAB's ```writematrix``` and ```readmatrix```. Each row in the file corresponds to a matrix row. The file should contain ```N``` lines and ```M``` comma-separated numbers in each line for a ```N``` by ```M``` matrix.
```MATLAB
writematrix(matrix, file, 'Delimiter', ',');  
matrix = readmatrix(file);  
```