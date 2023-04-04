#include "matrix_rw.hpp"

using matrix_rw::Real;
using matrix_rw::Row;
using matrix_rw::Size;

/** relative to the directory of the executable */
constexpr Size m_col = 3;
constexpr Size n_row = 3;
const std::string fprefix = "../data/";
const std::string fname = "write_example.csv";

int
main()
{
	std::vector<Row<m_col>> mat;
	mat.reserve(n_row);
	Row<m_col> row;

	/** fill the matrix */
	for (Size i = 0; i < n_row; ++i) {
		for (Size j = 0; j < m_col; ++j) {
			row[j] = i * m_col + j;
		}
		mat.push_back(row);
	}
	matrix_rw::Writer<m_col> writematrix;
	writematrix(fprefix + fname, mat); /** write to file */

	return 0;
}