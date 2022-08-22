# matrix_wr
Light-weight header-only C++ library to write/read matrices to/from files.

# Usage:

## Read:
```Cpp
matrix_rw::read<n_dim, m_dim>(file, matrix);
```

## Write:
```Cpp
matrix_rw::write<n_dim, m_dim>(file, matrix);
```

See the [test](./test/test-matrix_rw.cpp) for details.

The input and output files are comma and newline delimited, and their extension is ```*.dat``` by default. The formatting is compatible with MATLAB's ```writematrix``` and ```readmatrix```. Each row in the file corresponds to a matrix row. The file should contain ```N``` lines and ```M``` comma-separated numbers in each line for a ```N``` by ```M``` matrix.
```MATLAB
writematrix(matrix, file, 'Delimiter', ',');  
matrix = readmatrix(file);  
```
