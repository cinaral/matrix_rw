#include "matrix_rw.hpp"
#include <limits> /** std::numeric_limits */
#include <string>

using matrix_rw::Real_T;
using matrix_rw::size_t;
using matrix_rw::VarRowMat_T;

constexpr size_t m_col = 75;
constexpr size_t n_row_default = 150;
constexpr Real_T error_threshold = std::numeric_limits<Real_T>::epsilon();

//* relative to the directory of the executable
const std::string test_name = "matrix_rw-test";
const std::string fpath = "../data/" + test_name + "-";
const std::string ref_fpath = "../../test/ref_data/" + test_name + "-";
const std::string mat_ref_fname = "ref_mat.csv";
const std::string mat_fname = "mat.csv";

int
main()
{
	matrix_rw::Reader<m_col> read;
	matrix_rw::Writer<m_col> write;

	/** read the reference data */
	VarRowMat_T<m_col> mat_ref;
	mat_ref.reserve(n_row_default);
	read(ref_fpath + mat_ref_fname, mat_ref); /** read from file */
	const size_t n_row = mat_ref.size();

	/** write the data back */
	write(fpath + mat_fname, mat_ref);

	/** read it again */
	VarRowMat_T<m_col> mat;
	mat.reserve(n_row);
	read(fpath + mat_fname, mat);

	/** verify */
	Real_T max_error = 0;

	for (size_t i = 0; i < n_row; ++i) {
		for (size_t j = 0; j < m_col; ++j) {
			const Real_T error = std::abs(mat[i][j] - mat_ref[i][j]);

			if (error > max_error) {
				max_error = error;
			}
		}
	}

	if (n_row > 0 && max_error < error_threshold) {
		return 0;
	} else {
		return 1;
	}
}