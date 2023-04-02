#include "matrix_rw.hpp"
#include <array>
#include <string>
#include <vector>

using matrix_rw::Real_T;
using matrix_rw::size_t;

//* relative to the directory of the executable
const std::string dat_prefix = "../dat/matrix_rw-test-";
const std::string ref_dat_prefix = "../../test/reference_dat/matrix_rw-test-";
const std::string in_arr_fname = "in_arr.dat";
const std::string out_arr_fname = "out_arr.dat";

#ifdef USE_SINGLE_PRECISION
constexpr Real_T error_thres = 1e-7;
#else
constexpr Real_T error_thres = 1e-15;
#endif

int
main()
{
	Real_T max_error = 0.;
	{
		/** if you know both the row and column size */
		constexpr size_t n_dim = 150;
		constexpr size_t m_dim = 75;

		/** read reference data */
		Real_T in_arr[n_dim][m_dim];
		matrix_rw::read<n_dim, m_dim>(ref_dat_prefix + in_arr_fname, in_arr);

		/** test */
		matrix_rw::write<n_dim, m_dim>(dat_prefix + out_arr_fname, in_arr);

		Real_T out_arr[n_dim][m_dim];
		matrix_rw::read<n_dim, m_dim>(dat_prefix + out_arr_fname, out_arr);

		/** verify */
		for (size_t i = 0; i < n_dim; ++i) {
			for (size_t j = 0; j < m_dim; ++j) {
				const Real_T error = std::abs(in_arr[i][j] - out_arr[i][j]);

				if (error > max_error) {
					max_error = error;
				}
			}
		}
	}
	{
		/** if you only know the column size */
		constexpr size_t m_dim = 75;

		/** read reference data */
		std::vector<std::array<Real_T, m_dim>> in_arr;
		matrix_rw::read<m_dim>(ref_dat_prefix + in_arr_fname, in_arr);

		/** test */
		matrix_rw::write<m_dim>(dat_prefix + out_arr_fname, in_arr);

		std::vector<std::array<Real_T, m_dim>> out_arr;
		matrix_rw::read<m_dim>(dat_prefix + out_arr_fname, out_arr);

		/** verify */
		for (size_t i = 0; i < n_dim; ++i) {
			for (size_t j = 0; j < m_dim; ++j) {
				const Real_T error = std::abs(in_arr[i][j] - out_arr[i][j]);

				if (error > max_error) {
					max_error = error;
				}
			}
		}
	}

	if (max_error < error_thres) {
		return 0;
	} else {
		return 1;
	}
}