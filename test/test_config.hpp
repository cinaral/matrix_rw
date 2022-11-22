#ifndef TEST_CONFIG_HPP_CINARAL_221122_1101
#define TEST_CONFIG_HPP_CINARAL_221122_1101

#include "matrix_rw.hpp"
#include <chrono>
#include <iostream>
#include <string>

using matrix_rw::Real_T;
using matrix_rw::size_t;

namespace test_config
{
//* relative to the directory of the executable
const std::string dat_dir = "../dat";                       //* temporary data directory
const std::string ref_dat_dir = "../../test/reference_dat"; //* reference data directory
const std::string in_arr_fname = "in_arr.dat";
const std::string out_arr_fname = "out_arr.dat";
} // namespace test_config

#endif