#include "test_config.hpp"

//* setup
const std::string test_name = "matrix_rw";
const std::string dat_prefix = test_config::dat_dir + "/" + test_name + "-test-";
const std::string ref_dat_prefix = test_config::ref_dat_dir + "/" + test_name + "-test-";

constexpr size_t n_dim = 150;
constexpr size_t m_dim = 75;

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
	matrix_rw::read<n_dim, m_dim>(ref_dat_prefix + test_config::in_arr_fname, in_arr);

	//* test
	matrix_rw::write<n_dim, m_dim>(dat_prefix + test_config::out_arr_fname, in_arr);

	Real_T out_arr[n_dim * m_dim];
	matrix_rw::read<n_dim, m_dim>(dat_prefix + test_config::out_arr_fname, out_arr);

	//* verify
	Real_T max_error = 0.;

	for (size_t i = 0; i < n_dim * m_dim; ++i) {
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