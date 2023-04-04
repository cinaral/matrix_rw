#include "matrix_rw.hpp"
using matrix_rw::Real;
using matrix_rw::Row;
using matrix_rw::Size;

constexpr Size m_col = 3;
/** relative to the directory of the executable */
const std::string fprefix = "../../examples/";
const std::string fname = "read_example.csv";

int
main()
{
	matrix_rw::Reader<m_col> readmatrix;
	std::vector<Row<m_col>> mat;
	readmatrix(fprefix + fname, mat); /** read from file */
	const Size n_dim = mat.size();    /** determine size */

	/** print the matrix */
	for (Size i = 0; i < n_dim; ++i) {
		for (Size j = 0; j < m_col; ++j) {
			printf("%8.5g ", mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}