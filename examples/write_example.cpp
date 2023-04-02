#include "matrix_rw.hpp"
#include <string>
#include <vector>

using matrix_rw::Real_T;
using matrix_rw::size_t;

/** relative to the directory of the executable */
const std::string file1_path = "../dat/write_example-1.csv";
const std::string file2_path = "../dat/write_example-2.csv";

int
main()
{
	{
		/** if you know both the row and column size */
		constexpr size_t n_dim = 3;
		constexpr size_t m_dim = 3;
		Real_T matrix[n_dim][m_dim];

		for (size_t i = 0; i < n_dim; ++i) {
			for (size_t j = 0; j < m_dim; ++j) {
				matrix[i][j] = i * m_dim + j;
			}
		}
		matrix_rw::write(file1_path, matrix); /** write to file */
	}
	{
		/** if you only know the column size */
		constexpr size_t m_dim = 3;
		std::vector<std::array<Real_T, m_dim>> matrix;
		std::array<Real_T, m_dim> row;

		for (size_t i = 0; i < 5; ++i) {
			for (size_t j = 0; j < m_dim; ++j) {
				row[j] = i * m_dim + j;
			}
			matrix.push_back(row);
		}
		matrix_rw::write(file2_path, matrix); /** write to file */
	}

	return 0;
}