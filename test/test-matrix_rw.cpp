#include "matrix_rw.hpp"

using Uint_T = matrix_rw::Uint_T;
using Real_T = matrix_rw::Real_T;

//* setup
const std::string dat_dir = "../dat";
const std::string ref_dat_dir = "../../test/reference_dat";
const std::string test_name = "test-matrix_rw";
const std::string dat_prefix = dat_dir + "/" + test_name + "-";
const std::string ref_dat_prefix = ref_dat_dir + "/" + test_name + "-";
const std::string in_arr_fname = "in_arr.dat";
const std::string out_arr_fname = "out_arr.dat";

constexpr Uint_T n_dim = 150;
constexpr Uint_T m_dim = 75;

#ifdef __USE_SINGLE_PRECISION__
constexpr Real_T error_thres = 1e-7;
#else
constexpr Real_T error_thres = 1e-15;
#endif

int
main()
{
	//* read reference data
	Real_T in_arr[n_dim * m_dim];
	matrix_rw::read<n_dim, m_dim>(ref_dat_prefix + in_arr_fname, in_arr);

	//* test
	matrix_rw::write<n_dim, m_dim>(dat_prefix + out_arr_fname, in_arr);

	Real_T out_arr[n_dim * m_dim];
	matrix_rw::read<n_dim, m_dim>(dat_prefix + out_arr_fname, out_arr);

	//* verify
	Real_T max_error = 0.;

	for (Uint_T i = 0; i < n_dim * m_dim; ++i) {
		const Real_T error = std::abs(in_arr[i] - out_arr[i]);

		if (error > max_error) {
			max_error = error;
		}
	}

	if (max_error < error_thres) {
		return 0;
	} else {
		return 1;
	}
}