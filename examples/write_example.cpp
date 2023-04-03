#include "matrix_rw.hpp"

using matrix_rw::Real_T;
using matrix_rw::Row_T;
using matrix_rw::size_t;
using matrix_rw::VarRowMat_T;

/** relative to the directory of the executable */
constexpr size_t m_col = 3;
constexpr size_t n_row = 3;
const std::string fprefix = "../data/";
const std::string fname = "write_example.csv";

int
main()
{
	VarRowMat_T<m_col> mat;
	mat.reserve(n_row);
	Row_T<m_col> row;

	/** fill the matrix */
	for (size_t i = 0; i < n_row; ++i) {
		for (size_t j = 0; j < m_col; ++j) {
			row[j] = i * m_col + j;
		}
		mat.push_back(row);
	}
	matrix_rw::Writer<m_col> writematrix;
	writematrix(fprefix + fname, mat); /** write to file */

	return 0;
}