/*
 * matrix_rw
 *
 * MIT License
 *
 * Copyright (c) 2022 Cinar, A. L.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef WRITE_HPP_CINARAL_220924_0019
#define WRITE_HPP_CINARAL_220924_0019

#include "config.hpp"
#include "types.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

namespace matrix_rw
{
const size_t precision = std::numeric_limits<Real_T>::digits10 + 1;

template <size_t N_ROW, size_t M_COL>
void
write(const std::string file_name, const Real_T (&matrix)[N_ROW * M_COL])
{
	std::ofstream file;
	file.open(file_name);

	if (file.is_open()) {

		for (size_t i = 0; i < N_ROW; i++) {

			for (size_t j = 0; j < M_COL; j++) {
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