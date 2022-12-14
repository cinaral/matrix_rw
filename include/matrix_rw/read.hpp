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

#ifndef READ_HPP_CINARAL_220924_0017
#define READ_HPP_CINARAL_220924_0017

#include "config.hpp"
#include "types.hpp"
#include <fstream>
#include <iostream>
#include <string>

namespace matrix_rw
{
template <size_t N_ROW, size_t M_COL>
void
read(const std::string file_name, Real_T (&matrix)[N_ROW * M_COL])
{
	std::ifstream file;
	file.open(file_name);

	if (file.is_open()) {
		std::string line;
		std::string entry;
		size_t str_pos = 0;

		for (size_t i = 0; i < N_ROW; i++) {
			if (std::getline(file, line)) {
				entry = line.substr(0, line.find(delimiter));

				//* parse the line by splitting at the delimiters
				for (size_t j = 0; j < M_COL; j++) {
					if ((str_pos = line.find(delimiter)) != std::string::npos) {
						entry = line.substr(0, str_pos);
						line.erase(0, str_pos + delimiter.length());
#ifdef __USE_SINGLE_PRECISION__
						matrix[i * M_COL + j] = std::stof(entry);
#else
						matrix[i * M_COL + j] = std::stod(entry);
#endif
					} else {
#ifdef __USE_SINGLE_PRECISION__
						matrix[i * M_COL + j] = std::stof(line);
#else
						matrix[i * M_COL + j] = std::stod(line);
#endif
					}
				}
			} else {
				break;
			}
		}
	} else {
		std::cerr << "Could not open file " << file_name << std::endl;
	}
	file.close();
}

} // namespace matrix_rw

#endif