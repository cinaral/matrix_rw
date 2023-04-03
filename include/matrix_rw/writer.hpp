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

#include "types.hpp"
#include <fstream>
#include <iomanip> /** std::setprecision */
#include <limits>  /** std::numeric_limits */
#include <string>

namespace matrix_rw
{
template <size_t M_COL> class Writer
{
  public:
	Writer(std::string_view delimiter = ",") : delimiter(delimiter){};
	~Writer(){};

	void
	operator()(const std::string &file_name, VarRowMat_T<M_COL> &mat)
	{
		std::ofstream file;
		file.open(file_name);

		if (!file.is_open()) {
			printf("Could not open file: %s", file_name.c_str());
			return;
		}
		const size_t n_row = mat.size();
		/** set write precision */
		file << std::setprecision(std::numeric_limits<Real_T>::digits10 + 1);

		for (size_t i = 0; i < n_row; i++) {
			for (size_t j = 0; j < M_COL; j++) {
				file << std::scientific << mat[i][j];

				if (j < M_COL - 1) {
					file << delimiter;
				}
			}

			/** add newline except for the last line */
			if (i < n_row) {
				file << std::endl;
			}
		}
		file.close();
	}

  private:
	const std::string_view delimiter;
};
} // namespace matrix_rw

#endif