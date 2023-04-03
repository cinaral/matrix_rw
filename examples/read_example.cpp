#include "matrix_rw.hpp"
using matrix_rw::Real_T;
using matrix_rw::size_t;
using matrix_rw::VarRowMat_T;

constexpr size_t m_col = 3;
/** relative to the directory of the executable */
const std::string fprefix = "../../examples/";
const std::string fname = "read_example.csv";

int
main()
{
	matrix_rw::Reader<m_col> readmatrix;
	VarRowMat_T<m_col> mat;
	readmatrix(fprefix + fname, mat); /** read from file */
	const size_t n_dim = mat.size();  /** determine size */

	/** print the matrix */
	for (size_t i = 0; i < n_dim; ++i) {
		for (size_t j = 0; j < m_col; ++j) {
			printf("%8.5g ", mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}