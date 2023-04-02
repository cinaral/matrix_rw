#include "matrix_rw.hpp"
#include <cstdio>
#include <string>

using matrix_rw::Real_T;
using matrix_rw::size_t;

/** relative to the directory of the executable */
const std::string file1_path = "../../examples/read_example-1.csv";
const std::string file2_path = "../../examples/read_example-2.csv";

int
main()
{
	{
		/** if you know both the row and column size */
		constexpr size_t n_dim = 3;
		constexpr size_t m_dim = 3;
		Real_T matrix[n_dim][m_dim];
		matrix_rw::read(file1_path, matrix); /** read from file */

		for (size_t i = 0; i < n_dim; ++i) {
			for (size_t j = 0; j < m_dim; ++j) {
				printf("%8.5g ", matrix[i][j]);
			}
			printf("\n");
		}
	}
	printf("\n");
	{
		/** if you only know the column size */
		constexpr size_t m_dim = 3;
		std::vector<std::array<Real_T, m_dim>> matrix;
		matrix_rw::read(file2_path, matrix); /** read from file */
		size_t n_dim = matrix.size();

		for (size_t i = 0; i < n_dim; ++i) {
			for (size_t j = 0; j < m_dim; ++j) {
				printf("%8.5g ", matrix[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}