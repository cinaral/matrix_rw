#ifndef WRITE_HPP_CINARAL_220924_0019
#define WRITE_HPP_CINARAL_220924_0019

#include "matrix_rw/types.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

namespace matrix_rw
{
const uint_t precision = std::numeric_limits<real_t>::digits10 + 1;

template <uint_t N_ROW, uint_t M_COL>
void
write(const std::string file_name, const real_t (&matrix)[N_ROW * M_COL])
{
	std::ofstream file;
	file.open(file_name);

	if (file.is_open()) {

		for (uint_t i = 0; i < N_ROW; i++) {

			for (uint_t j = 0; j < M_COL; j++) {
				file << std::setprecision(precision) << std::scientific << matrix[i * M_COL + j];

				if (j < M_COL - 1) {
					file << delimiter;
				}
			}

			if (i < N_ROW) {
				file << std::endl;
			}
		}
	} else {
		std::cerr << "Could not open file " << file_name << std::endl;
	}
	file.close();
}

} // namespace matrix_rw

#endif