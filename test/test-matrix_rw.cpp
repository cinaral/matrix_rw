#include "matrix_rw.hpp"

//********
//* setup
//********
const std::string dat_dir = "../../dat";
const std::string test_dat_dir = "../../test/dat";
const std::string test_name = "test-matrix_rw";
const std::string dat_prefix = dat_dir + "/" + test_name + "-";
const std::string test_dat_prefix = test_dat_dir + "/" + test_name + "-";
const std::string in_arr_fname = "in_arr.dat";
const std::string out_arr_fname = "out_arr.dat";

constexpr uint_t n_dim = 150;
constexpr uint_t m_dim = 75;

#ifdef __USE_SINGLE_PRECISION__
constexpr real_t error_thres = 1e-8;
#else
constexpr real_t error_thres = 1e-16;
#endif
real_t in_arr[n_dim * m_dim];
real_t out_arr[n_dim * m_dim];

int
main()
{
	//*****************
	//* read test data
	//*****************
	matrix_rw::read<n_dim, m_dim>(test_dat_prefix + in_arr_fname, in_arr);

	//******************
	//* write test data
	//******************
	matrix_rw::write<n_dim, m_dim>(dat_prefix + out_arr_fname, in_arr);

	//*****************
	//* read test data
	//*****************
	matrix_rw::read<n_dim, m_dim>(dat_prefix + out_arr_fname, out_arr);

	//*********
	//* verify
	//*********
	real_t max_error = 0.;

	for (uint_t i = 0; i < n_dim * m_dim; ++i) {

		real_t error = std::abs(in_arr[i] - out_arr[i]);
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